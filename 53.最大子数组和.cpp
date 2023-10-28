// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    /// @brief 
    /// @param nums 整数数组 
    /// @return nums具有最大和的连续子数组的和
    int maxSubArray(vector<int>& nums) {
        //既然是贪心专题，就想办法贪心着来 
        //首先肯定是正数开始（前，如果不是正数开始肯定能在当前数组中找到一个从正数开始的使和更大
        //其次从结尾向前的每一段和肯定都是正的，否则去掉这一段和肯定最大
        //结尾也是正的 
        //这样两头同时开始找？
        //一个正数开头、正数结尾的连续串
        //想想还有没有其他特征。。。
        //每找到一段和为负数的就刷新指针？
        // int left=0;
        // int right=nums.size()-1;
        // int res=0;
        // while(left<=right&&nums[left++]<0);
        // while(left<=right&&nums[right--]<0);
        // int i=left;
        // int j=right;
        //感觉好麻烦。。而且错了、。
        //比如两边都是正的，但是加上中间就变成负的。。那就全完了。。


        //还是看文章了
        //直接从头开始累加
        //如果值更大就更新max
        //如果遇到累加为负数就从当前重新开始
        //我的“开头部分和结尾部分和都是正的”这个想法没问题
        //也就是这个贪心的关键

        int max=INT32_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            if(count>max) max=count;
            if(count<0) count=0;
        }
        return max;
    }
};
// @lc code=end

