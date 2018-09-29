#include <iostream>
#include <vector>
using namespace std;

bool find(int key, int ar[], int size){
    int l = 0, r = size-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(ar[mid] == key) return true;
        if(ar[mid] > key) r = mid-1;
        else l = mid+1;
    }
    return false;
}

int main(){
    cout << "data: " << endl;
    std::vector<int> v;
    while(1){
        int i;
        std::cin >> i;
        v.push_back(i);
        if(i == 0) break;
    }
    sort(v.begin(), v.end());
    int * ar = v.data();
    std::cout << "1 is " << find(0,ar, v.size()) << endl;;
    return 0;
}
