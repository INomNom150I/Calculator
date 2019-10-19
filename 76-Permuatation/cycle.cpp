#include <iostream>
using namespace std;

int n;
int ar[] = {4,5,3,2,1,0};
bool v[100];

int main(){
    n = sizeof(ar)/sizeof(int);
    int m = 0;
    for(int i = 0; i < n; i++){
        if(!v[ar[i]]){
            int j = ar[i];
            do{
                v[j] = true;
                cout << j << ' ';
                for(int k = 0; k < n; k++){
                    if(ar[k] == j){
                        j = k;
//                        cout << " - " << j << endl;
                        break;
                    }
                }
            } while(!v[j]);
            cout << endl;
            m++;
        }
    }
    cout << m << endl;
}
