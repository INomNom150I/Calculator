#include <iostream>
using namespace std;
int c = 10; 
int w[] = {2, 5, 4, 7, 1, 3, 8}; 
int n = sizeof(w) / sizeof(w[0]); 

int fFit(){
    int b = 0;
    int l[n];
    for(int i = 0; i < n; i++){
        int s = c, sin;
        for(int j = 0; j < b; j++){
            int r = l[j] - w[i];
            if(r >= 0 && r < s){
                s = r;
                sin = j;
            }
        }
        if(s == c){
            l[b] = c-w[i];
            b++;
        } else{
            l[sin] = s;
        }
    }
    return b;
}

int main() 
{ 
    cout << "Number of bins required in Next Fit : "
         << fFit() << endl; 
    return 0; 
}
