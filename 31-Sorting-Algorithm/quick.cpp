#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

int partition(int ar[], int s, int e){
    int pivot = ar[s];
    int i = s+1, j = e;
    while(i <= j){
        if(ar[i] > pivot){  
            std::swap(ar[i],ar[j]);
            j--;
        } else{
            i++;
        }
    }
    std::swap(ar[s], ar[j]);
    return j;
}

void quicksort(int ar[], int s, int e){
    if(s < e){
        int p = partition(ar,s,e);
        quicksort(ar,s,p-1);
        quicksort(ar,p+1,e);
    }
    return;   
}



int main(){
    int ar[] = {1,2,5,7,3,1,6,1,2};
    int size = sizeof(ar)/sizeof(ar[0]);
    quicksort(ar,0,size-1);
    print(ar,size);
    return 0;
}
