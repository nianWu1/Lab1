// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
// #include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void solve(const vector<int>& candidates,int target,int start,int sum,vector<bool>& used){
        //考虑一下这里需要什么
        //used数组
        for(int i=start;i<candidates.size()&&candidates[i]+sum<=target;i++){
            //重要的是：如果当前等于前一个
            //used数组主要看是不是当前层
            //如果不是同一层则可以继续探索
            if(i>0&&candidates[i-1]==candidates[i]&&used[i-1]==false){
                //这个情况下直接看下一层
                continue;
            }
            sum+=candidates[i];
            used[i]=true;
            path.push_back(candidates[i]);
            if(sum==target){
                res.push_back(path);
            }
            solve(candidates,target,i+1,sum,used);
            //回
            sum-=candidates[i];
            used[i]=false;
            path.pop_back();
        }
    }
public:
    /// @brief 这次组合candidates中的每个数组都只能用一次
    /// 不过candidates中会出现重复数字
    /// @param candidates 
    /// @param target 
    /// @return 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //数字会重复，，但是数字的计数不会重复吧？
        //重新统计一遍candidates，这个开销对于回溯来说应该很少吧
        //用map记录？

        //虽然上面的思路很简单，，也可以实现，，但是还是看看去重的逻辑吧(虽然说我的第一想法是遍历判断是否出现过hh)
        //。。。不过整体肯定还是可以用到上面的map记录个数的思路的
        //先排序，，每次遍历也是遍历相同元素，
        //下一层遍历遍历下一个不同元素。。。
        //完了脑子卡在这个思路里出不来了、、、

        //看看文章转变思路吧
        //。。看了看第一个去重逻辑那块。。。感觉本质还是看当前数字在当前层的出现次数、、
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size(),false);
        solve(candidates,target,0,0,used);
        return res;
    }
};
// @lc code=end

