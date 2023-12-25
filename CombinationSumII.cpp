/* Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

Code : 
*/
class Solution {
public:
    void findCombination(int start,int target,vector<int>& candidates,vector<vector<int>>&result,vector<int>&current){
        if(target==0){
            result.push_back(current);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            current.push_back(candidates[i]);
            findCombination(i+1,target-candidates[i],candidates,result,current);
            current.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>current;
        findCombination(0,target,candidates,result,current);

        return result;
        
    }
};
