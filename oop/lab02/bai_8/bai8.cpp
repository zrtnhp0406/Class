#include<bits/stdc++.h>
using namespace std;

list <int> ds;
int main(){

    while(true){

        int n;

        cin>>n;

        if(n==-1) break;
        if(n==0){
            int x;
            cout<<"Nhap x can them: ";
            cin>>x;
            ds.push_back(x);
        }
        if(n==1){
            int x;
            cout<<"Nhap x can xoa: ";
            cin>>x;
            for(auto v=ds.begin(); v!=ds.end(); v++){
                if(*v==x) {ds.erase(v); break;}
            }
        }

        if(n==2){
            int x;
            cout<<"Xoa tat ca gia tri x: ";
            cin>>x;
            ds.remove(x);
        }

        if(n==3){
            int x,y;
            cout<<"Nhap x va y";
            cin>>x>>y;
            cout<<"Thanh cong thay tat ca "<< x <<" thanh "<< y<<'\n';
            auto st= ds.begin();
            advance(st,x);
            *st=y;

        }

    }
    for(auto v: ds) cout<<v<<' ';

    return 0;

}
