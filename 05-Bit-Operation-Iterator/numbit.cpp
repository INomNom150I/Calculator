#include <iostream>
int dp[1000];
using namespace std;

int main(){
    dp[0] = 0;
    for(int i = 1; i < 20; i++){
        dp[i] = dp[i>>1] + (i&1);
    }
    for(int i = 1; i < 20; i++){
        std::cout << i << ':'<< dp[i] << endl;
    }
    return 0;
}
