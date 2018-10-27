#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

void bubble(int ar[], int size){
    int tmp[size];
    int big = ar[0];
    for(int i = 1; i < size; i++){
        if(big < ar[i]) big = ar[i];
    }
    int div = 1;
    while(big/div){
        int count[10];
        memset(count,0,sizeof(int)*10);
        for(int i = 0; i < size; i++){
            count[(ar[i]/div)%10]++;
        }   

        int prev = count[0];
        count[0] = 0;
        for(int i = 1; i < 10; i++){
            int cur = count[i];
            count[i] = prev;
            prev += cur;
        }
        for(int i = 0; i < size; i++){
            tmp[count[(ar[i]/div)%10]++] = ar[i]; 
        }
        for(int i = 0; i < size; i++){
            ar[i] = tmp[i];
        }
        print(ar,size);
        div*=10;
    }
}

int main(){
    int ar[] = {1,2,5,7,3,1,6,1,2,100,200,150,30};
    int size = sizeof(ar)/sizeof(ar[0]);
    print(ar,size);
    bubble(ar,size);
    std::cout << "result ";
    print(ar,size);
    return 0;
}
