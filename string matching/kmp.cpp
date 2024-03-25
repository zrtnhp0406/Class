#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int base=300;
int key,n,m,k,T[N],lsp[N],pi;
string s;
vector<string> listin;
vector<string> listout;
void build_lsp(string &q){
    for(int i=0; i<q.size(); i++) lsp[i]=-1;
    for(int i=1; i<q.size(); i++){
        pi=lsp[i-1];
        while(1){
            if(q[pi+1]==q[i]){
                lsp[i]=pi+1;
                break;
            }
            else{
                if(pi==-1) break;
                pi=lsp[pi];
            }
            //if(pi<0) break;
        }
    }
}
bool check(string p, string q){
    build_lsp(q);
    int x=0,y=0;
    while(p.size()-x>=q.size()-y){
        if(p[x]==q[y]){
            x++;
            y++;
        }
        if(y==q.size()){
            return true;
        }
        if(x<p.size() && p[x]!=q[y]){
            if(y!=0){
                y=lsp[y-1];
            }
            else{
                x++;
            }
        }
    }
    return false;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //input
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>s;
        listin.push_back(s);
    }
    for(int i=1; i<=m; i++){
        cin>>s;
        listout.push_back(s);
    }
    for(string p: listout){
        bool OK=false;
        for(string q: listin){
            if(check(p,q)){
                OK=true;
                break;
            }
        }
        cout<<(OK?"yes":"no")<<'\n';
    }   




    return 0;
}