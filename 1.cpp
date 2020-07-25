#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        map<int,int,greater<int>> m;
        for(int x:v) m[x]++;
        int fist=-1,second = -1;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==4 && fist== -1) {
                fist = second = it->first;
                break;
            }
            else{
                if(it->second>=2){
                if(fist== -1) fist = it->first;
                else {second = it->first;break;}
            }
            }
        }
        if(fist== -1 || second== -1) cout<<-1<<endl;
        else cout<<fist*second<<endl;
    }
    return 0;
}