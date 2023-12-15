/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

Code : 
*/
class Solution {
public:
    void checkIsland(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1'){
            return;
        }
        grid[i][j]='2';
        checkIsland(grid,i+1,j,m,n);
        checkIsland(grid,i,j+1,m,n);
        checkIsland(grid,i,j-1,m,n);
        checkIsland(grid,i-1,j,m,n);

    }
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        if(m==0){
            return 0;
        }
        string x="";
        int n =grid[0].size();
        int island=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                x=grid[i][j];
                if(grid[i][j]=='1'){
                    checkIsland(grid,i,j,m,n);
                    island+=1;
                }
            }
        }
        return island;
        
    }
};
