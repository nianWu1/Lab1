// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void solve(const vector<int>& nums,int start){
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            res.push_back(path);
            solve(nums,i+1);
            path.pop_back();
        }
    }
public:
    /// @brief 
    /// @param nums 整数数组，元素各不相同 
    /// @return nums所有可能的子集
    vector<vector<int>> subsets(vector<int>& nums) {的撒后来大家阿斯利康大家离开洒家看
    
        //又是分割。。。
        res.push_back(vector<int>());
        solve(nums,0);
        return res;
    }
};
// @lc code=end

