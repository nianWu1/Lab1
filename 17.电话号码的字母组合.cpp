// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    vector<string> res;
    string cur="";
    void solve(const string& digits,int index){
        if(index>=digits.size()) return;
        for(int i=0;i<letterMap[digits[index]-'0'].size();i++){
            cur.push_back(letterMap[digits[index]-'0'][i]);
            if(index==digits.size()-1) res.push_back(cur);
            else solve(digits,index+1);
            cur.pop_back();            sssssssssssssssss
        }
    }
public:
    /// @brief 给定一个仅包含数字2-9的字符串，返回它能表示的字母组合
    /// @param digits 
    /// @return 
    vector<string> letterCombinations(string digits) {
        //得打个表啊。。(偷个懒，，直接偷文章里的，嘻嘻)
        solve(digits,0);
        return res;
    }
};
// @lc code=end

