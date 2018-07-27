#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

void countingsort(int ar[], const int size){
    int c[3];
    memset(c,0,sizeof(c));
    for(int i = 0; i < size; i++){
        c[ar[i]]++;
    }
    int j = 0;
    std::cout << "sort\n"; 
    for(int i = 0; i < 3; i++){
        for(int n = 0; n < c[i]; n++){
            ar[j] = i;
            j++;
        }  
    }
    print(ar,size);
}

int main(){
    int ar[5] = {1,0,0,0,2};
    int size = sizeof(ar)/sizeof(ar[0]);
    countingsort(ar,size);
    return 0;
}
