#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

void bubble(int ar[], int size){
    int sizen = size;
    for(int i = 0; i < size;){
        for(int j = 0; j < size-1; j++){
            if(ar[j] > ar[j+1]) std::swap(ar[j],ar[j+1]);
        }
        size--;
        print(ar,sizen);
    }
}

int main(){
    int ar[] = {1,2,5,7,3,1,6,1,2};
    int size = sizeof(ar)/sizeof(ar[0]);
    bubble(ar,size);
    std::cout << "result ";
    print(ar,size);
    return 0;
}
