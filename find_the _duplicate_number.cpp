/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/



/*# Intuition:

The problem requires finding the repeated number in an array without modifying the array and using only constant extra space. We can solve this problem using Floyd's Tortoise and Hare algorithm, which is a cycle detection algorithm. It works by treating the array as a linked list and finding the intersection point within the cycle formed by the repeated number.

# Approach:

Initialize two pointers, slow and fast, both initially pointing to nums[0].
Phase 1: Find the intersection point within the cycle.
In this phase, move slow one step at a time and fast two steps at a time until they meet at some point within the cycle.
The meeting point within the cycle is found using the cycle detection principle.
Phase 2: Find the entrance to the cycle.
Reset one of the pointers (in this case, fast) back to the start of the array (nums[0]).
Move both slow and fast one step at a time until they meet again. The point at which they meet is the entrance to the cycle.
The value at the entrance to the cycle is the repeated number.
Return the repeated number as the result.

# Time Complexity (TC):

The algorithm iterates through the array twice:
Phase 1 takes O(n) time, where n is the size of the array.
Phase 2 takes O(n) time in the worst case.
Thus, the total time complexity is O(n).

# Space Complexity (SC):

The algorithm uses only two integer variables (slow and fast) and does not require any additional data structures.
Therefore, the space complexity is constant, O(1).
The provided code efficiently finds the repeated number in the array while meeting the constraints of not modifying the array and using only constant extra space.

# Code
```*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // Phase 1: Find the intersection point of the two pointers.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Phase 2: Find the entrance to the cycle.
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

```