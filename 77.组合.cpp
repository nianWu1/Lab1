// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> cur;
    void solve(int n,int k,int start){
        if(k==0)return;
        for(int i=start;i<=n-k+1;i++){
            cur.push_back(i);
            if(k==1){
                //k=1说明到最底层
                //直接增加当前vector
                res.push_back(cur);
                cur.pop_back();
            }
            else{
                solve(n,k-1,i+1);
                cur.pop_back();
            }
        }
    }
public:
    /// @brief 给定两个整数n和k，返回[1,n]内所有可能的k个数的组合
    /// @param n 
    /// @param k 
    /// @return 
    vector<vector<int>> combine(int n, int k) {
        //先看回溯的讲解
        //大概就是一种非常暴力的暴力搜索。、。
        //把每个可能都记录下来，然后标记已经探索过的路径
        //我大概可以把它理解为DFS？
        //既然文章模板里写了，，就全都用递归的思路来吧(用栈模拟我也不会啊)

        //开始这道题
        //所有组合。。最简单的想法。。k层for循环
        //循环套循环用迭代肯定是写不出来了
        //而递归很容易就可以实现
        //注意递归的处理
        //第一个从0到结束
        //递归深度和k有关
        //如果k=1就一层递归结束
        solve(n,k,1);
        return res;
    }
};
// @lc code=end

