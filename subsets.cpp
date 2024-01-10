/* Given an integer array nums of unique elements, return all possible subsets(the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique. 

CODE : 

*/
class Solution {
public:
    void helper(vector<int>&v,int i, vector<int>&curr,vector<vector<int>>&result){
        if(i==v.size()){
            result.push_back(curr);
            return;
        }
        //include element
        curr.push_back(v[i]);
        helper(v,i+1,curr,result);

        //not inlcuding ith element
        curr.pop_back();
        helper(v,i+1,curr,result);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>result;
        helper(nums,0,curr,result);

        return result;
    }
};
