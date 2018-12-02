#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int mask = (1<<10)-1;

int main(int argc, char* argv[]){
    int size = 10;
    if(argc > 1){
        size = atoi(argv[1]);
    }
    srand(time(NULL));
    while(size--){
        cout << ((rand()&mask)+1) << ' '; 
    }
    std::cout << endl;
    return 0;
}
