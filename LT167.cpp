#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> twoSum(vector<int>& numbers, int target) {
     /*
      @ numbers是输入数组
      @ target是目标值
      @left,right是左右指针
     */
     int left = 0,right = numbers.size()-1;
     while(left<right){
         int sum = numbers[left] + numbers[right];
         if(sum==target) return {left,right};
         else if(sum>target) right--;
         else left++;
     }
     return {-1,-1};
}

int main(){
    int num;
    cin>>num; //指定输入的大小
    vector<int> input(num);
    for(int i=0;i<num;i++) cin>>input[i];//输入数据
    int target;
    cin>>target;//输入目标数
    vector<int> out;//结果数组
    out = twoSum(input,target);
    cout<<out[0]<<' '<<out[1]<<endl;
    system("pause");
    return 0;
}