#include <iostream> 
#include <cstring>

using namespace std; 
  
#define L 4 
#define M 4 
#define N 4 

void print(int a[M][N], int m, int n)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void multiply(int a[L][M],  int b[M][N],  int c[L][N]) 
{ 
    for(int i = 0; i < L; i++){
        for(int j = 0; j < N; j++){
            c[i][j] = 0;
            for(int k = 0; k < M; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
} 

  
int main() 
{ 
    int a[L][M] = {{1, 1, 1, 1}, 
                  {2, 2, 2, 2}, 
                  {3, 3, 3, 3}, 
                  {4, 4, 4, 4}}; 
  
    int b[M][N] = {{1, 1, 1, 1}, 
                  {2, 2, 2, 2}, 
                  {3, 3, 3, 3}, 
                  {4, 4, 4, 4}}; 
    int c[L][N]; 
    memset(c, 0, sizeof(c));
  
    multiply(a, b, c); 

    cout << "matrix a is \n"; 
    print(a, L, M);
  
    cout << "\nmatrix b is \n"; 
    print(b, M, N);
  
    cout << "\nResult matrix is \n"; 
    print(c, L, N);
  
    return 0; 
} 
  
