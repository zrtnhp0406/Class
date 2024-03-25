#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int base=300;
int key,n,m,k,T[N],lsp[N],pi,L[N][base],D[N];
string s;
vector<string> listin;
vector<string> listout;
void build(string s){
    for(int i=0; i<s.size(); i++){
        for(int j='a'; j<='z'; j++){
            L[i][j]=-1;
        }
    }
    L[0][s[0]]=0;
    for(int i=1; i<s.size(); i++){
        for(int j='a'; j<='z'; j++){
            L[i][j]=L[i-1][j];
        }
        L[i][s[i]]=i;
    }
}
bool check(string p, string q){
    build(q);
     int s = 0; 
    while (s <= (p.size() - q.size())) {
        int j = q.size() - 1;
 
        while (j >= 0 && p[s + j] == q[j])
            j--;
 
        if (j < 0) {
            return true;
        }
 
        else
            s += max(1ll, j - L[j][p[s+j]]);
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
                cout<<"yes";
                OK=true;
            }
        }
        if(!OK){
            cout<<"no";
        }
        cout<<'\n';
    }




    return 0;
}