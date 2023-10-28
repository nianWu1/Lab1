// @before-stub-for-debug-begin
#include <vector>
#include <
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void solve(const vector<int>& nums,int start,vector<int>& used){
        for(int i=start;i<nums.size();i++){
            if(i>0&&nums[i-1]==nums[i]&&!used[i-1]){
                //false表明当前递归层的前一个数字被用过

                //这里主要还是要让下一层直到这里可以遍历
                //考虑start 和i的关系
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            res.push_back(path);
            solve(nums,i+1,used);
            path.pop_back();
            used[i]=false;
        }
    }
public:
    /// @brief 
    /// @param nums 整数数组，可能包含重复元素
    /// @return  返回该数组的所有可能子集，注意不能重复
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ///used去重
        res.push_back(vector<int>());
        sort(nums.begin(),nums.end());
        vector<int> used(nums.size(),false);
        solve(nums,0,used);
        return res;
    }
};
// @lc code=end

