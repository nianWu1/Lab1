// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    int cur=0;
    vector<int> curVec;
    void solve(const vector<int>& candidates,int target,int index){
        if(index>=candidates.size()) return;
        int num=0;
        while(cur<target){
            solve(candidates,target,index+1);
            //问题在于怎么回溯
            //每次删除当前所在层添加的元素
            cur+=candidates[index];
            curVec.push_back(candidates[index]);
        }
        if(cur==target){
            //相等则增加
            res.push_back(curVec);
        }
        int i=curVec.size()-1;
        //这里是回溯
        while(i>=0&&curVec[i--]==candidates[index]){
            curVec.pop_back();
            cur-=candidates[index];
        }
        //和文章不一样的地方在于我没有拷贝这个sum，而是都用全局的cur来操作
        //我的方法回溯的开销比较大

    }
public:
    /// @brief 给定一个无重复元素的整数数组
    /// @param candidates 无重复元素的整数数组[2,40]
    /// @param target 目标整数[1,40]
    /// @return candidates中可以使数字和为target的所有不同组合，candidates中的同一个数字可以被无限制重复被选取
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //同一个数组可以重复选取
        //每个循环都从头开始
        //但是这个情况下可能会出现重复的问题？重复、、。
        //注意不同递归层的控制
        //可以是当前数字出现几次
        //而不是每个循环从头开始
        //ok这个每层数组出现次数这个可行
        //就有点类似。。之前那个九键打字的思路
        solve(candidates,target,0);
        return res;
    }
};
// @lc code=end

