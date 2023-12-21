/* Given an m x n grid of characters board and a string word, return true if word exists in the grid.The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

*/
class Solution {
public:
    bool search(int i , int j , int n , int m, vector<vector<char>>& board, string& word,int k ){
        if(k==word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i==n || j==m || board[i][j]!=word[k]){
            return false;
        }
        char ch=board[i][j];
        board[i][j]='#';
        bool op1= search(i+1,j,n,m,board,word,k+1);
        bool op2= search(i,j+1,n,m,board,word,k+1);
        bool op3= search(i-1,j,n,m,board,word,k+1);
        bool op4= search(i,j-1,n,m,board,word,k+1);

        board[i][j]=ch;
        return op1 || op2 || op3 || op4;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size();
        int m= board[0].size();

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(search(i,j,n,m,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
