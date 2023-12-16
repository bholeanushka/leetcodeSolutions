/* Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109 

Code :  */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        vector<int>r;
        int i=0;
        while(i!=nums.size()){
            if(nums[i]==target){
                result.push_back(i);
            }
            i++;
            
        }
        if(result.size()==1){
            result.push_back(result[0]);
        }
        if(result.size()==0){
            r={-1,-1};
            return r;
        }
        r.push_back(result[0]);
        r.push_back(result[result.size()-1]);
        return r;
        
    }
};
