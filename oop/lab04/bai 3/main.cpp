#include<bits/stdc++.h>
#include "giasuc.h"

using namespace std;

int event;
COW a;
SHEEP b;
DEEL c;
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);
            cout<<"Cow: "<<a.breed()<<" "<<"con"<< '\n';
            cout<<"Sheep: "<<b.breed()<<" "<<"con"<< '\n';
            cout<<"Deel: "<<c.breed()<<" "<<"con"<< '\n';
    cout<<"nhap so luong su kien sinh va cho sua: ";
    cin>>event;
    for(int i=1; i<=event; i++){
        int type=abs(rand())%2;
        if(type==1){
            cout<<"Sau luot sinh nay, so luong cac loai la:\n ";
            cout<<"Cow: "<<a.breed()<<" "<<"con"<< '\n';
            cout<<"Sheep: "<<b.breed()<<" "<<"con"<< '\n';
            cout<<"Deel: "<<c.breed()<<" "<<"con"<< '\n';
        }
        else {
            cout<<"Sau luot cho sua nay, so luong sua la:\n ";
            cout<<"Cow: "<<a.milk()<<" "<<"lit"<<'\n';
            cout<<"Sheep: "<<b.milk()<<" "<<"lit"<<'\n';
            cout<<"Deel: "<<c.milk()<<" "<<"lit"<<'\n';
        }

    }

}
