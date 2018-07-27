#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

void selection(int ar[], int size){
    int s = size;
    for(int i = 0; i < size-1; i++){
        int mindex = i;
        for(int j = i+1; j < size; j++){
            if(ar[mindex] > ar[j]) mindex = j;
        } 
        std::swap(ar[i],ar[mindex]);
        print(ar,s);
   }
}

int main(){
    int ar[] = {1,2,5,7,3,1,6,1,2};
    int size = sizeof(ar)/sizeof(ar[0]);
    selection(ar,size);
    std::cout << "result ";
    print(ar,size);
    return 0;
}
