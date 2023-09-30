/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109
*/
class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        std::stack<int> s;
        int third = INT_MIN; // Initialize the third element to negative infinity

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true; // Found a "132 pattern"
            }

            while (!s.empty() && nums[i] > s.top()) {
                third = s.top(); // Update the third element
                s.pop();
            }

            s.push(nums[i]); // Push the current element onto the stack
        }

        return false; // No "132 pattern" found
    }
};
