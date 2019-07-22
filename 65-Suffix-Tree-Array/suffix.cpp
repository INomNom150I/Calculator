#include <iostream>
#include <cstring>
using namespace std;

struct cmp{
    cmp(const char * s): s(s) {}
    bool operator() (int i, int j){
        return strcmp(s+i, s+j) < 0;
    } 
    const char * s;
};

const char * ss;

bool cmp1(int i, int j){
    return strcmp(ss + i, ss + j) < 0;
}

void build(char * t, int l, int sa[]){
    for(int i = 0; i < l; i++){
        sa[i] = i;
    }
    //sort(sa,sa+l,cmp(t));
    ss = t;
    sort(sa,sa+l,cmp1);
}

int search(char * p, char * t, int n, int sa[]){
    int m = strlen(p);
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        int an= strncmp(p,t+sa[mid],m);
        //int an = strcmp(p,t+sa[mid]);
        cout << mid << " an " << an << endl;
        if(an == 0) return sa[mid];
        if(an > 0) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int main(){
    char * s = "banana";
    int n = strlen(s);
    int sa[n];
    build(s,n,sa);
    for(int i = 0; i < n; i++){
        cout << sa[i] << ' ';
    }
    cout << endl;

    cout << search("ana",s,n,sa) << endl;
}
