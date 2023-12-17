/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8 
Code : */
class Solution {
public:
   
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        generateresult(result,"",0,0,n);

        return result;
    }
    void generateresult(vector<string>& result,string curr,int open,int close,int n){

        if(open==n && close==n){
            result.push_back(curr);
            return;
        }
        if(open<n){
            generateresult(result,curr+"(",open+1,close,n);
        }
        if(close<open){
            generateresult(result,curr+")",open,close+1,n);
        }
    }
};
