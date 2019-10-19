#include <iostream>
using namespace std;

struct suff{
    int ind;
    int rnk[2];
    bool operator < (const suff& o) const{
        if(rnk[0] == o.rnk[0]) return rnk[1] < o.rnk[1];
        return rnk[0] < o.rnk[0];
    } 
};

suff sar[6];
void print(){
    for(int i = 0; i < 6; i++){
        cout << sar[i].ind << ' ';   
    }
    cout << "\n\t";
    for(int i = 0; i < 6; i++){
        cout << sar[i].rnk[0] << ' ';   
    }
    cout << "\n\t";
    for(int i = 0; i < 6; i++){
        cout << sar[i].rnk[1] << ' ';   
    }


    cout << endl;
}

void sff(string s){
    for(int i = 0; i < s.size(); i++){
        sar[i].ind = i;
        sar[i].rnk[0] = s[i];
        if(i < s.size()-1) sar[i].rnk[1] = s[i+1];
        else sar[i].rnk[1] = -1;
    }

    print();
    sort(sar,sar+s.size());
    print();
    for(int l = 4; l < s.size(); l*= 2){ 
        int loc[s.size()];
        loc[sar[0].ind] = 0; 
        int pre = sar[0].rnk[0];
        sar[0].rnk[0] = 0;
        for(int i = 1; i < s.size(); i++){
            if(pre == sar[i].rnk[0] && sar[i].rnk[1] == sar[i-1].rnk[1]){
                sar[i].rnk[0] = sar[i-1].rnk[0];        
            } else{
                pre = sar[i].rnk[0];
                sar[i].rnk[0] = sar[i-1].rnk[0]+1;
            }
            loc[sar[i].ind] = i;
        } 
        for(int i = 0; i < s.size(); i++){
            int t = sar[i].ind+l/2;
            if(t < s.size()) sar[i].rnk[1] = sar[loc[t]].rnk[0];
            else sar[i].rnk[1] = -1;
        }
        print();
        sort(sar,sar+s.size());
        print();
    }
}

int main(){
    string s = "banana";
    sff(s);
    return 0;   
}
