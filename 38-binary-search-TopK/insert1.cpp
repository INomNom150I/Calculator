#include <iostream>
using namespace std;

int N = 10;
int ar[100];

void print(){
    for(int i = 0; i < N; i++){
        cout << ar[i] << ' ';
    }
    cout << endl;
}

void insert(int k){
    int l = 0, r = N-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(k == ar[mid]){
            break;
        }
        if(k < ar[mid]){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    cout << l << endl;
    for(int i = l; i <= N; i++){
        std::swap(ar[i],k);
    }
    N++;
}

int main(){
    for(int i = 0; i < N; i++){
        ar[i] = i * 10;
    }
    insert(65);
    print();
    insert(100);
    print();
}
