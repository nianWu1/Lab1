// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <list>
// #include "commoncppproblem56.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
private:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //返回最后合并后的区间
        //经典排序环节
        sort(intervals.begin(),intervals.end(),cmp);
        if(intervals.size()==1){
            return intervals;
        }
        vector<vector<int>> res;

        vector<int> temp=intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=temp[1]){
                //这个时候更新最大
                temp[1]=max(temp[1],intervals[i][1]);
            }
            else{
                //否则到不能合并的区间
                res.push_back(temp);
                temp=intervals[i];
            }
            if(i==intervals.size()-1){
                res.push_back(temp);
            }
        }

        return res;
    }
};
// @lc code=end

