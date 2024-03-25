#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int base=300;
int key,n,m,k,T[N];
map<int,bool> dshash;
string s;
vector<string> listin;
vector<string> listout;

bool check(string &t){
    if(dshash[key]==true) return true;
    for(int i=k; i<t.size(); i++){
            key=(key-(t[i-k]-'a')*T[k-1])*base+(t[i]-'a');
            if(dshash[key]==true){
                return true;
            }
        }
    return false;
}
int gethash(string s){
    int d=0;
    for(char v: s){
        d=d*base+v-'a';
    }
    return d;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //input
    cin>>n>>m;
    T[0]=1;
    for(int i=1; i<N; i++){
        T[i]=T[i-1]*base;
    }
    for(int i=1; i<=n; i++){
        cin>>s;
        listin.push_back(s);
    }
    for(int i=1; i<=m; i++){
        cin>>s;
        listout.push_back(s);
    }
    for(string s: listout){
        dshash[gethash(s)]=true;
    }
    for(string s: listin){
        for(string v: listout){
             k=v.size();
             key=0;
             for(int i=0; i<k; i++){
             key=key*base+(s[i]-'a');
            }
          if(check(s)){
             cout<<"yes";
            }
            else cout<<"no";
            cout<<'\n';
        }
    }




    return 0;
}