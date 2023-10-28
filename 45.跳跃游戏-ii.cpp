// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem45.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    /// @brief 和前面一样，不过这次是必到，求最小跳跃次数
    /// @param nums 
    /// @return 
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int i,j;
        int maxLeap=nums[0];
        int leapCount=1;
        i=0;
        j=maxLeap;
        //先把昨晚想的实现一下
        while(i<=j){
            if(j>=nums.size()-1) break;
            for(int temp=i;temp<=j;temp++){
                if(temp+nums[temp]>maxLeap){
                    maxLeap=temp+nums[temp];
                }
            }
            //记录最大的
            leapCount++;
            i=j;
            j=maxLeap;
        }
        return leapCount;
    }
};
// @lc code=end

