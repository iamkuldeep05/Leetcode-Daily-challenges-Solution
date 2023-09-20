/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

/*

# Intuition:

The problem requires finding the minimum number of operations to reduce x to 0 by removing elements from either the left or the right end of the array nums. The approach used here involves finding the maximum subarray with a sum equal to totalSum - x, where totalSum is the sum of all elements in the array. The minimum number of operations is then given by subtracting the length of this subarray from the total length of nums.

# Approach:

Calculate the target by subtracting x from the sum of all elements in the array totalSum.

If target is equal to 0, it means the entire array nums can be removed to make x zero. In this case, return the total length of nums.

Initialize two pointers, left and right, to track the current subarray.

Iterate through the array nums with the right pointer:

Increment currSum by adding nums[right] at each step.
Check if currSum is greater than target. If so, enter a while loop to reduce currSum by removing elements from the left side (increment left pointer) until currSum becomes less than or equal to target.

If currSum becomes equal to target, calculate the number of operations needed to remove elements on both sides of the window (subtract (right - left + 1) from the total length of nums) and update maxLen if it's greater.

Continue this process until the right pointer reaches the end of the array.

Finally, return maxLen if it's greater than 0; otherwise, return -1 if it's impossible to reduce x to 0.

# Time Complexity (TC):

The algorithm iterates through the array once with two pointers.
The time complexity is O(n), where n is the number of elements in the nums array.

# Space Complexity (SC):

The space complexity is O(1) because the algorithm uses a constant amount of additional space to store variables, regardless of the input size.

# Code
```
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        if (target == 0) return nums.size();
        
        int maxLen = 0, currSum = 0, left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            currSum += nums[right];
            
            while (currSum > target && left <= right) {
                currSum -= nums[left++];
            }
            
            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen > 0 ? nums.size() - maxLen : -1;
    }
};

```