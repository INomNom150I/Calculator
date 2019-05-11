#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[100];
int dc[100];

int* ar;


void print(){
    for(int i = 0; i < N; i++){
        cout.width(2);
        cout << ar[i];
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout.width(2);
        cout << dp[i];
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout.width(2);
        cout << dc[i];
    }
    cout << endl;
}

void print(vector<int>& v){
    for(auto& i:v){
        cout << i <<  "(" << ar[i] << ") ";
    }
    cout << endl;
}   

void dfs(vector<int>& v, int k){
    v.push_back(k);
    if(dp[k] == 1){
        print(v);
    } else{
        for(int i = 0; i < k; i++){
            if(dp[i] == dp[k]-1 && ar[i] > ar[k]){
                dfs(v,i);
            }
        }       
    }
    v.pop_back();
}

void lds(){
    for(int i = 0; i < N; i++){
        dp[i] = dc[i] = 1;
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(ar[i] < ar[j]){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    dc[i] = dc[j];
                } else if(dp[i] == dp[j]+1){
                    dc[i] += dc[j];
                }
            }
        }
    }

    int longest = 0;
    for(int i = 0; i < N; i++){
        if(longest < dp[i]){
            longest = dp[i];
        }
    }
    cout << longest << endl;
    print();
    
    vector<int> v;
    for(int i = 0; i < N; i++){
        if(dp[i] == longest){
            dfs(v,i);
        }
    }
}

int main(){
    //int a[] = {6,3,3,1};
    int a[] = {3,2,1,3,2,1};
    N = sizeof(a)/sizeof(int);
    ar = a;
    lds();
}
