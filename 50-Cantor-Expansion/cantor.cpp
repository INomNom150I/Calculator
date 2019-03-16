#include <iostream>
#include <vector>
using namespace std;
int f[10];

void fact(int n){
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i < n; i++){
        f[i] = f[i-1] * i;
    }
}

int cantor(int s[], int n){
    int sum = 0;
    vector<bool> v(n+1,false);

    for(int i = n-1; i > 0; i--){
        int c = 0;
        for(int j = 1; j < s[i]; j++){
            if(!v[j]) c++;
        }
        sum += c * f[i];
        v[s[i]] = true;
    }
    return sum + 1;
}

void rev(int s[], int n, int k){
    vector<bool> v(n+1,false);

    k--;
    for(int i = n-1; i >= 0; i--){
        int j;
        int c = k/f[i];
        k %= f[i];
        for(j = 1; j <= n; j++){
            if(!v[j]){
                if(c == 0) break;
                c--;
            }
        }
        s[i] = j;
        v[j] = true;
    }
}

int main(){
    int ar[4] = {1,2,3,4};
    int n = sizeof(ar)/sizeof(int);
    int k = 10;
    fact(10);    
    rev(ar,n,k);
    for(int i = n-1; i  >= 0; i--){
        cout << ar[i] << ' ';
    }
    cout << endl;
    cout << cantor(ar,n) << endl;   
}
