
/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
*/
/*# Intuition:

The problem is to check if string s is a subsequence of string t. A subsequence is a string that can be formed by deleting some characters from the original string without changing their relative order. To solve this problem, we can iterate through both strings simultaneously and check if we can find each character of s in t in the same order. If we can, it means s is a subsequence of t.

# Approach:

Initialize two pointers, sIndex and tIndex, to 0. These pointers will be used to traverse strings s and t, respectively.

Iterate through both strings while sIndex is less than the length of s and tIndex is less than the length of t:

Compare the character at s[sIndex] with the character at t[tIndex].
If they are equal, increment sIndex to move to the next character in s.
In either case, increment tIndex to move to the next character in t.
After the loop, check if sIndex has reached the length of s. If it has, return true because it means all characters in s were found in t in the same order, and s is a subsequence of t. Otherwise, return false.

 **Time Complexity**: O(max(N, M)), where N is the length of string s, and M is the length of string t. We iterate through both strings once.

**Space Complexity**: O(1) since we use a constant amount of extra space for the pointers and variables.


*/



class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0; // Pointer for string s
        int tIndex = 0; // Pointer for string t

        while (sIndex < s.length() && tIndex < t.length()) {
            if (s[sIndex] == t[tIndex]) {
                sIndex++; // Move to the next character in s
            }
            tIndex++; // Always move to the next character in t
        }

        return sIndex == s.length(); // If sIndex reached the end of s, it's a subsequence.
    }
};
