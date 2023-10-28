// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
// #include "commoncppproblem47.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void solve(const vector<int>& nums,vector<bool> usedVer){
        unordered_set<int> usedLev;//水平方向
        for(int i=0;i<nums.size();i++){
            if(usedLev.find(nums[i])!=usedLev.end()) continue; //说明当前层已经使用过(查重)
            if(usedVer[i]) continue; //说明竖直方向已经用过
            usedLev.insert(nums[i]);
            path.push_back(nums[i]);
            usedVer[i]=true;
            if(path.size()==nums.size()) res.push_back(path);
            solve(nums,usedVer);
            path.pop_back();
            usedVer[i]=false;
        }
    }
public:
    /// @brief 
    /// @param nums 包含可重复数字的序列 
    /// @return 所有不重复的全排列
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //需要竖直和水平方向两个used数组。。
        vector<bool> usedVer(nums.size(),false);
        solve(nums,usedVer);
        return res;
    }
};
// @lc code=end

