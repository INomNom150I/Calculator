#include <iostream>
using namespace std;
int arr[] = { 8, 2, 3 }; 
int n;

int maxWeight(int w1, int w2,int c ){
    if(c == n) return 0;
    int m = maxWeight(w1,w2,c+1);
    if(w1 >= arr[c]){
        m = max(m,maxWeight(w1-arr[c],w2,c+1)+arr[c]); 
    }
    if(w2 >= arr[c]){
        m = max(m,maxWeight(w1,w2-arr[c],c+1)+arr[c]);
    }
    return m;
}

int main() 
{ 
  
    n = sizeof(arr) / sizeof(arr[0]); 
    int w1 = 10, w2 = 3; 

  
    cout << maxWeight(w1,w2,0) << endl; 
    return 0; 
} 
