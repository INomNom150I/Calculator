#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}


void merge(int ar[], int l, int mid, int r){
    int size = r-l+1;
    int tmp[size];
    int i = l, j = mid+1;
    int c = 0;
    while(i <= mid && j <= r){
        if(ar[i] > ar[j]){
            tmp[c] = ar[j];
            j++;
        } else{
            tmp[c] = ar[i];
            i++;
        }
        c++;
    }

    while(i <= mid){
        tmp[c++] = ar[i++];
    }

    while(j <= r){
        tmp[c++] = ar[j++];
    }

    for(i = l, c = 0; i <= r; c++, i++){
        ar[i] = tmp[c];
    }
}

void mergesort(int ar[], int l, int r){
    if(l < r){
        int mid = (r+l)/2;
        mergesort(ar,l,mid);
        mergesort(ar,mid+1,r);
        merge(ar,l,mid,r);
    }
    return;
}

int main(){
    int ar[] = {1,2,5,7,3,1,6,1,2};
    int size = sizeof(ar)/sizeof(ar[0]);
    print(ar,size);
    mergesort(ar,0,size-1);
    print(ar,size);
    return 0;
}
