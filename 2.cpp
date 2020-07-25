#include<iostream>
#include <unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        unordered_map<string,int> m;
        string temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            m[temp] = 0;
        }
        int num;
        cin>>num;
        int invalid = 0;
        for(int i=0;i<num;i++){
            string temp;
            cin>>temp;
            if(m.find(temp)!=m.end()) m[temp]++;
            else invalid++;
        }
        for(auto it=m.begin();it!=m.end();++it){
            cout<<it->first<<" : "<<it->second<<endl;
        }
        cout<<"Invalid : "<<invalid<<endl;
    }
    return 0;
}