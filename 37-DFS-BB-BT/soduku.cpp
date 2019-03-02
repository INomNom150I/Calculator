#include <iostream>
int s[9][9];
using namespace std;

namespace bk{
bool issafe(int i,int j,int x){
    for(int k = 0; k < 9; k++){
        if(s[i][k] == x|| s[k][j] == x){
            return false;
        }
    }
    int a = (i/3)*3,b = (j/3)*3;
    for(int k = a; k < a+3; k++){
        for(int l = b; l < b+3; l++){
            if(s[k][l] == x) return false;
        }
    } 
    return true;
}
}

bool row[9][10],col[9][10],g[9][10];
void build(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            row[i][s[i][j]] = true;
        }
    }
    for(int j = 0; j < 9; j++){
        for(int i = 0; i < 9; i++){
            col[j][s[i][j]] = true;
        }
    }
    for(int k = 0; k < 9; k++){
        int x = (k/3)*3, y = (k%3)*3;
        for(int i = x; i < x+3; i++){
            for(int j = y; j < y+3; j++){
                g[k][s[i][j]] = true;
            }
        }
    }
}

namespace bb{
bool issafe(int i,int j,int x){
    return !(row[i][x] || col[j][x] || g[i/3*3+j/3][x]); 
}
}

void setb(int i, int j,int x){
    row[i][x] = true;
    col[j][x] = true;
    g[i/3*3+j/3][x] = true;
}
void clearb(int i, int j,int x){
    row[i][x] = false;
    col[j][x] = false;
    g[i/3*3+j/3][x] = false;
}

bool btrack=true;
using namespace bk;
#if 0
bool issafe(int i,int j,int x){
    if(btrack) {
        return bk::issafe(i,j,x);
    } else {
        return bb::issafe(i,j,x);
    }
}
#endif

bool dfs(int i, int j){
    if(j == 9){
        j = 0;
        i++;
    }
    if(i == 9) return true;
    bool found = false;
    while(j < 9){
        if(s[i][j] == 0){
            found = true;
            break;
        }
        j++;
    }
    if(found == false){
        for(i++; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(s[i][j] == 0){
                    found = true;
                    break;
                }
            }
            if(found == true) break;
        }
    }
    if(!found) return true;
    for(int x = 1; x < 10; x++){
        if(issafe(i,j,x)){
            s[i][j] = x;
            //setb(i,j,x);
            if(dfs(i,j+1)) return true;
            clearb(i,j,x);
            s[i][j] = 0;
        }
    }
    return false;
}


void print(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << s[i][j] << ' ';
        }cout << endl;
    }
}

int main(){
    char ch;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> ch;
            s[i][j] = ch-'0';
        }
    }
    print();
    if(btrack)build();
    
    bool b = dfs(0,0);
    cout << b << endl;
    print();
}
