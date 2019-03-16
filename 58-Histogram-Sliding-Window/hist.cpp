#include <iostream>
#include <stack>
using namespace std;

int get(int h[], int n){
    int big = 0;
    for(int i = 0; i < n; i++){
        int l = i-1;
        while(l >= 0 && h[l] >= h[i]){
            l--;
        }
        int r = i+1;
        while(r < n && h[r] >= h[i]){
            r++;
        }
        big = max(big, h[i] * (r-l-1));
    }
    return big;
}

int get1(int h[], int n){
    stack<int> s;
    int big = 0;
    for(int i = 0; i < n;){
        if(s.empty() || h[s.top()] <= h[i]){
            s.push(i++);
        } else{
            int tmp = h[s.top()];
            s.pop();
            if(s.empty()) big = max(big,tmp*i);
            else big = max(big,tmp * (i-s.top()-1));
        }
    }   
    return big;
}

int main(){
    int ar[] = {6,2,5,4,5,1,6,0};   
    int n = sizeof(ar)/sizeof(int);

    cout << get(ar,n) << endl;
    cout << get1(ar,n) << endl;
}
