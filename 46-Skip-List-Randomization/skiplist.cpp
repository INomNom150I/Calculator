#include <iostream>
#include <stdio.h>
#define ML 4

struct node{
    int key;
    node * next[ML];
    node(int key): key(key) {
        for(int i = 0; i < ML; i++){
            next[i] = nullptr;
        }
    }
};

node header(-100);
int level(){
    return rand()%ML;
}

void insert(int key){
    node * update[ML];
    node * n = &header;
    for(int i = ML-1; i >= 0; i--){
        node * p = n;
        while(n){
            if(n->key < key){
                p = n;
                n = n->next[i];
            }
            else if(n->key == key) return;
            else break;
        }
        update[i] = p;
        n = p;
    }
    node * j = new node(key);
    int l = level();
    for(int i = 0; i <= l; i++){
        j->next[i] = update[i]->next[i];
        update[i]->next[i] = j;
    }
}

void print(){
    for(int i = ML-1; i >= 0; i--){
        for(node * n = &header; n; n = n->next[i]){
            std::cout << n->key << ' ';
        }
        std::cout << std::endl;
    }
}

int main(){
    for(int i = 1; i < 32; i++){
        insert(i);
    }
    print();
    return 0;   
}
