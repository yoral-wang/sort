/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。
 返回你可以获得的最大乘积。
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/
class Solution {
public:
    int integerBreak(int n) {
       vector<int> v(59,0);
       v[2] = 1;
       v[3] = 2;
       v[4] = 4;
       v[5] = 6;
       v[6] = 9;
       if(n<=6) return v[n];
       for(int i=7;i<=n;i++){
           int t = 0;
           for(int j=1;j<=i-2;j++){
               t = max(j*v[i-j],t);
           }
           v[i] =t;
       }
       return v[n];
    }
};