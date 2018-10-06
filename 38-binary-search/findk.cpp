#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << ' ';
    } std::cout << endl;
}


int findk(vector<int> v, int k){
    sort(v.begin(),v.end());
    return v[k-1];
}

int partition(vector<int> &v,int s, int e){
    int p = s;
    s++;
    while(s <= e){
        if(v[s] <= v[p]) s++;
        else{
            swap(v[s],v[e]);
            e--;
        }
    }
    swap(v[p],v[e]);
    return e;
}

int findks(vector<int> v, int k){
    int s = 0, e = v.size()-1;
    while(s <= e){
        int p = partition(v,s,e);
        if(p == k-1) return v[p];
        if(k-1 < p) e = p-1;
        else s = p+1;
    }
}

struct cmp{
    int *p;
    cmp(int *p): p(p) {}
    bool operator() (int &a, int &b) const{
        return p[a] < p[b];
    }
};

int findk1(vector<int> v, int k){
    vector<int> v1(v.size());
    for(int i = 0; i<v.size(); i++){
        v1[i] = i;
    }
    //sort(v1.begin(),v1.end(),cmp(v.data()));
    sort(v1.begin(),v1.end(),[&v] (int &a,int &b)->bool{
        return v[a] < v[b];
    });
    print(v1);
    int ret = v[v1[k-1]];
    sort(v.begin(),v.end());
    print(v);
    return v[v1[k-1]];
}

int findk2(vector<int> &v, int k){
    priority_queue<int> q;
    int i;
    for(i = 0; i < k; i++){
        q.push(v[i]);
    } 
    for(; i < v.size(); i++){
        if(v[i] < q.top()){
            q.pop();
            q.push(v[i]);
        }
    }
    return q.top();
}

int count(vector<int> &v, int c){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] <= c) cnt++;
    }
    return cnt;
}

int findk3(vector<int> &v, int k){
    int l = v[0], r = v[0];
    for(int i = 1; i < v.size(); i++){
        l = min(l,v[i]);
        r = max(r,v[i]);
    }
    while(l < r){
        int mid = (l + r)/2;
        int cnt = count(v,mid);
        if(cnt >= k) r = mid;
        else l = mid+1;
    }
    return l;
}

int main(){
    vector<int> v = {1,8,32,6,2,12,132,76,2,90,70};
    print(v);
    std::cout << findks(v,4) << std::endl;;
    print(v);
    std::cout << findk3(v,4) << std::endl;;
    print(v);
    return 0;
}
