#include <iostream>
#include <vector>
using namespace std;
int dp[10];

int fact(int i){
    if(dp[i]) return dp[i];

    if(i == 0 || i == 1){
        dp[i] = 1;
    } else{
        dp[i] = i * fact(i-1);
    }
    return dp[i];
}

void can(string& s, int k){
    int N = k;
    k--;
    string m = s;
    bool v[s.size()]; 
    memset(v,0,sizeof(v));

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(!v[j]){
                int c = fact(s.size()-1-i);
                if(k >= c){
                    k-=c;
                } else{
                    m[i] = s[j];
                    v[j] = true;
                    break;
                }
            }
        }
    }

    cout << N <<" cantor: " << m << endl;
}

int rev(const string& s){
    string m = s;
    sort(m.begin(),m.end());
    bool v[s.size()]; 
    memset(v,0,sizeof(v));
    int n = 0;

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < m.size(); j++){
            if(!v[j]){
                if(s[i] == m[j]){
                    v[j] = true;
                    break;
                } else{
                    int c = fact(s.size()-1-i);
                    n += c;
                }
            }
        }

    }
    n++;
    cout << s << ' ' << n << endl;
    return n;
}

int main(){
    fact(10);    
    string s = "abcd";
    can(s,1);   
    can(s,9);   
    rev("abcd");
    rev("bcad");
}
