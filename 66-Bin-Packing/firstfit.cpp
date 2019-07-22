#include <iostream>
using namespace std;
int c = 10; 
int w[] = {2, 5, 4, 7, 1, 3, 8}; 
int n = sizeof(w) / sizeof(w[0]); 

int fFit(){
    int b = 0;
    int l[n];
    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < b; j++){
            if(l[j] >= w[i]){
                l[j] -= w[i];
                break;
            }
        }
        if(j == b){
            l[b] = c-w[i];
            b++;
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
