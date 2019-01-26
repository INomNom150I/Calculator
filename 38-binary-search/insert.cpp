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

void insert(int start, int k){
    int *l = lower_bound(ar+start,ar+N,k);
    cout << *l << endl;
    cout << (l-ar) << endl;
    for(int i = (l-ar); i <= N; i++) swap(ar[i],k);
    N++;
}

int main(){
    for(int i = 0; i < N; i++){
        ar[i] = i * 10;
    }
    insert(2,65);
    print();
    insert(3,100);
    print();
}
