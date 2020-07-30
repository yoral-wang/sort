//给定一个由0和1组成的二维矩阵，求解其中的连通域的数量
//所谓连通域，就是由1组成的一个区域，其中每两个1的位置是一个四邻域的关系

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void find_path(vector<vector<int>>& v,int i,int j){
     if(i<0 || i>=v.size() || j<0 || j>=v[0].size() || v[i][j]==0) return;
     v[i][j] = 0;
     find_path(v,i+1,j);
     find_path(v,i-1,j);
     find_path(v,i,j+1);
     find_path(v,i,j-1);
}

int one_num(vector<vector<int>>& input){
     int count = 0;
     vector<vector<int>> v = input;
     int m = v.size();
     int n = v[0].size();
     for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
             if(v[i][j]==1){
                 find_path(v,i,j);
                 count++;
             } 
        }
    return count;
} 

int main(){
    vector<vector<int>> input={{1,1,0,0,1},{1,0,0,1,0},{1,1,1,1,0},{0,0,1,0,0}};
    cout<<one_num(input)<<endl;
    system("pause");
    return 0;
}
