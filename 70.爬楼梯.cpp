/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int x=1;int y=2;int temp;
        while(n>=3){
            temp=y;
            y=x+y;
            x=temp;
            n--;
        }
        return y;
    }
};
// @lc code=end

