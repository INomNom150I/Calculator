#include <iostream>
#include <set>
#include <unistd.h>
using namespace std;

void power(string &st, string &b, int i){
    static int num = 0;
    if(i == st.size()){
        cout << ++num << "\t" << b << endl;
        return;
    } 
    for(int j = 0; j < st.size(); j++){
        b.push_back(st[j]);
        power(st,b,i+1);
        b.pop_back();
    }
}

void combo(string &st, string &b, int i){
    static int num = 0;
    if(i == st.size()){
        cout << ++num << "\t" << b << endl;
        return;
    }
    combo(st,b,i+1);
    b.push_back(st[i]);
    combo(st,b,i+1);
    b.pop_back();
}

void combo(string &st){
    int n = 1<<st.size();
    for(int i = 0; i < n; i++){
        cout << i << '\t';;
        for(int j = 0; j < st.size(); j++){
            if((1 << j) & i) cout << st[j];
        } cout << endl;
    }
}

void perm(set<char> &st, string &b){
    static int num = 0;
    if(st.empty()){
        cout << ++num << '\t' << b << endl;
        return;
    }
    int n = st.size();
    for(int i = 0; i < n; i++){
        set<char>::iterator it = next(st.begin(),i);
        char ch = *it;
        st.erase(it);
        b.push_back(ch);
        perm(st,b);
        b.pop_back();
        st.insert(ch);
    }
}

void perm(string &st, int i){
    static int num = 0;
    if(i == st.size()){
        cout << ++num << '\t' << st << endl;
        return;
    }
    for(int j = i; j < st.size(); j++){
        swap(st[i],st[j]);
        perm(st,i+1);       
        swap(st[i],st[j]);
    }
}

void helper(char *program){
    cout << "Usage " << program << " [-h] [-c <case>] [string]\n";
    cout << "0-power\n";
    cout << "1-combo it\n";
    cout << "2-combo rec\n";
    cout << "3-perm \n";
    cout << "4-perm no order\n";
}

int main(int argc, char *argv[], char *argp[]){
    //for(int i = 0; argp[i]; i++) cout << argp[i] << endl;
    int testc = 2;
    string b, s ="1234";
#if 1
    char c;
    while((c = getopt(argc,argv,"c:h")) != -1){
        switch(c){
            case 'h': helper(argv[0]); break;
            case 'c': testc = atoi(optarg); break;
            default: cout << "invalid option " << c << endl;
        }
    }
    if(optind < argc){
        s = argv[optind];
    }
#else
    for(int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            if(argv[i][1] == 'h'){
                helper(argv[0]);
                return 0;
            }
            else{
                if(argv[i][1] == 'c'){
                    testc = atoi(argv[++i]);
                }
                else{
                    cout << "invalid option\n";
                    return 0;
                }
            }
        }
        s = argv[i];
    }
#endif
    set<char> st(s.begin(),s.end());
    switch(testc){
        case 0: power(s,b,0);
                break;
        case 1: combo(s,b,0);
                break;
        case 2: combo(s);
                break;
        case 3: perm(st,b);
                break;
        case 4: perm(s,0);
                break;
        default: cout << "no case\n";
    }
    return 0;
}
