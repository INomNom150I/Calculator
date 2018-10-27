#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

void insertion(int ar[], int size){
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0 && ar[j-1] > ar[j]; j--){
            std::swap(ar[j-1],ar[j]);
        } 
        print(ar,size);
    }
}

int main(){
    int ar[] = {1,2,5,7,3,1,6,1,2};
    int size = sizeof(ar)/sizeof(ar[0]);
    insertion(ar,size);
    std::cout << "result ";
    print(ar,size);
    return 0;
}
