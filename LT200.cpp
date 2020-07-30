/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

输入:
[
['1','1','1','1','0'],
['1','1','0','1','0'],
['1','1','0','0','0'],
['0','0','0','0','0']
]
输出: 1
输入:
[
['1','1','0','0','0'],
['1','1','0','0','0'],
['0','0','1','0','0'],
['0','0','0','1','1']
]
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

*/
//和求解连通域是相同的
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
