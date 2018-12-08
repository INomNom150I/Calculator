#include <iostream>
#include <string>
using namespace std;

bool isequal(string &s1, string &s2, int k){
    for(int i = 0; i <= k; i++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

bool inter(string &s1, string &s2, string &s3, int i, int j, int k){
    //std::cout << i << ' ' << j << endl;
    if(i < 0) return isequal(s2,s3,k);
    if(j < 0) return isequal(s1,s3,k);
    return ((s1[i] == s3[k]) && inter(s1,s2,s3,i-1,j,k-1)) ||((s2[j] == s3[k]) && inter(s1,s2,s3,i,j-1,k-1));
}

bool dp[100][100];
bool inter(string &s1, string &s2, string &s3){
    int m = s1.size(), n = s2.size();
    for(int k = 0; k <= s3.size(); k++){
        for(int i = 0; i <= min(m,k); i++){
            for(int j = 0; j <= min(n,k-i); j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = (s2[j-1] == s3[k]);
                else if(j == 0) dp[i][j] = (s1[i-1] == s3[k]);
                else{
                    dp[i][j] = (((s3[k] == s1[i-1]) && dp[i-1][j]) || (s3[k] == s2[j-1] && (dp[i][j-1])));
                }
            }
        }
    }
    return dp[m][n];
}

bool tinter(string &s1, string &s2, string &s3, int i, int j){
    int k = i+j+1;
    if(dp[i][j]) return true;
    if(i < 0) return isequal(s2,s3,k);
    if(j < 0) return isequal(s1,s3,k);
    dp[i][j] = (((s1[i] == s3[k]) && dp[i-1][j]) || ((s2[j] == s3[k]) && dp[i][j-1]));
    return dp[i][j];
}

int main(){
#if 1
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
#else
    string s1 = "abc";
    string s2 = "def";
    string s3 = "abcdef";
#endif
    //bool j = inter(s1,s2,s3);
    bool j = tinter(s1,s2,s3,s1.size()-1,s2.size()-1);
    bool i = inter(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
    std::cout << j << std::endl;
    std::cout << i << std::endl;
    //dice1(2);
}
