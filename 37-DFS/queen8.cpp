#include <iostream>
using namespace std;
#define N 8
int c[N][N];
bool slash[2*N],back[2*N],row[N];

#define BACKTRACK 0
#if BACKTRACK
bool is_safe(int x, int y){
    for(int i = 0; i < y; i++){
        if(c[x][i] == 1) return false;
    }  
    for(int i = x-1, j = y-1; i >= 0 && j>= 0; i--,j--){
        if(c[i][j] == 1) return false;
    }
    for(int i = x+1, j = y-1; i < N && j>= 0; i++,j--){
        if(c[i][j] == 1) return false;
    }
    return true;
}
#else

void seton(int x, int y){
    row[x] = true;
    slash[x+y] = true;
    back[x - y + N - 1] = true;
}

void setoff(int x, int y){
    row[x] = false;
    slash[x+y] = false;
    back[x - y + N - 1] = false;
}

bool is_safe(int x, int y){
    return !(row[x] || slash[x+y] || back[x - y + N - 1]);
}
#endif
void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << c[i][j] << ' ';
        } cout << endl;
    }
}

void dfs(int col){
    static int count = 0;
    if(col == N){
        cout << ++count << endl;
        print();
        return;
    }
    for(int i = 0; i < N; i++){
        if(is_safe(i,col)){
#if BACKTRACK
            c[i][col] = 1;
            dfs(col+1);
            c[i][col] = 0;
#else
            seton(i,col);
            c[i][col] = 1;
            dfs(col+1);
            c[i][col] = 0;
            setoff(i,col);
#endif
        }        
    }
}

int main(){
    dfs(0);
    return 0;
}
