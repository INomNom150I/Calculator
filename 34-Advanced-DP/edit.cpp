#include <iostream>
#include <string>
using namespace std;
int dp[100][100];

int edit(string s1, int n, string s2,int m){
    if(m < 0) return n+1;
    if(n < 0) return m+1;

    if(s1[n] == s2[m])    return edit(s1,n-1,s2,m-1);
    return 1+min(edit(s1,n-1,s2,m-1),min(edit(s1,n-1,s2,m),edit(s1,n,s2,m-1)));
}

int edit(string s1, string s2){
    return edit(s1,s1.size()-1,s2,s2.size()-1);
}

int ed(string s1, string s2){
    for(int i = 0; i <= s1.size(); i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= s2.size(); i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
        }
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    std::cout << edit("abcdef","bcdefg") << endl;
    std::cout << ed("abcdef","bcdefg") << endl;
}
