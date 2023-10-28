// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem46.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void solve(const vector<int>& nums,vector<bool>& used){
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i]=true;
            if(path.size()==nums.size()) res.push_back(path);
            solve(nums,used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    /// @brief 
    /// @param nums 不含重复数字的数组 
    /// @return 所有可能的全排列
    vector<vector<int>> permute(vector<int>& nums) {
        //全排列。、。。
        //每一层都从头开始遍历
        //used需要加入递归调用
        vector<bool> used(nums.size(),false);
        solve(nums,used);
        return res;
    }
};
// @lc code=end

