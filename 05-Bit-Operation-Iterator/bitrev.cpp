#include <iostream>

unsigned int rev(unsigned int n){
    int x = 0;
    for(int i = 0; i < 32; i++){
        x=x<<1 | (n&1);
        n=n>>1;
    }
    return x;
}

bool is2(int num){
    return (num != 0) && (num & (num-1) == 0);
}

bool is3(int num){
    int x = 1;
    while(x < num){
        x += x<<1;
    }
    return x == num;
}
