// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem55.h"

using namespace std;
// @before-stub-for-debug-end

/*

    /// @brief 从第一个下标开始跳跃
    /// @param nums 非负整数数组，每个元素代表在该位置可以跳跃的最大长度
    /// @return 是否可以跳跃到最后一个下标
    bool canJump(vector<int>& nums) {
        //首先，只要没有0就随便都能跳到终点
        //如果有0，保证可以跳过0，所有0之前都有一个index+nums[index]>zeroIndex
        

        //就从开头开始，每次都跳最大
        //如果跳到超过size，则true
        //如果跳到0，并且当前的后一个没有没有去过并且不是0，则用当前的后一个来跳
        //如果跳到0，当前的后一个是0，则向前找到一个没有跳过的
        //如果
        //如果当前过小，则false
        // int i=0;
        // vector<bool> visited(nums.size(),false);
        // while(i>=0&&i<nums.size()-1){
        //     if(nums[i]==0){
        //         if(i==nums.size()-1) return true;
        //         else return false;
        //     }            
        //     else{
        //         visited[i]=true;
                int nextIndex=i+nums[i];
                if(nextIndex>=nums.size()-1) return true;
                while(nextIndex>=i&&nums[nextIndex]==0)nextIndex--;
                while(nextIndex>=0&&(visited[nextIndex]||nums[nextIndex]==0))nextIndex--;
                if(nextIndex<0) return false;
                i=nextIndex;
            }
        }
        return true;

      
    }
};
// @lc code=end

