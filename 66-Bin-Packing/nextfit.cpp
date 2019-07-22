#include <iostream>
using namespace std;
int c = 10; 
int w[] = {2, 5, 4, 7, 1, 3, 8}; 
int n = sizeof(w) / sizeof(w[0]); 

int nextFit(){
    int b = 0;
    int l = 0;
    for(int i = 0; i < n; i++){
        if(l >= w[i]){
            l -= w[i];
        } else{
            l = c-w[i];
            b++;
        }
    }
    return b;
}

int main() 
{ 
    cout << "Number of bins required in Next Fit : "
         << nextFit() << endl; 
    return 0; 
}
