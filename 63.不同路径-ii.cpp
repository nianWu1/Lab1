// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem63.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //初始化最后一行
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==1&&n==1&&obstacleGrid[m-1][n-1]==0) return 1;
        if(obstacleGrid[m-1][n-1]==1) return 0;
        for(int i=n-2;i>=0;i--) {
            if(obstacleGrid[m-1][i]==1){
                obstacleGrid[m-1][i]=0;
                while(i>=0)obstacleGrid[m-1][i--]=0;
                break;
            }
            obstacleGrid[m-1][i]=1;
        }
        for(int i=m-2;i>=0;i--) { 
            if(obstacleGrid[i][n-1]==1){
                obstacleGrid[i][n-1]=0;
                while(i>=0)obstacleGrid[i--][n-1]=0;
                break;
            }
            obstacleGrid[i][n-1]=1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]==1){
                    obstacleGrid[i][j]=0;
                    continue;
                }
                obstacleGrid[i][j]=(int)((long)obstacleGrid[i+1][j]+(long)obstacleGrid[i][j+1]);  
            }
        }

        return obstacleGrid[0][0];
    }
};
// @lc code=end

