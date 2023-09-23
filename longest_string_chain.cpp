/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/
/*
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We aim to find the longest word chain from a given list of words. A word chain is a sequence where each word is a predecessor of the next word, achieved by inserting one letter anywhere in the previous word. To solve this problem, we can use dynamic programming.

# Approach
<!-- Describe your approach to solving the problem. -->
First, we sort the input words by their lengths in ascending order. This is crucial because we want to process shorter words first, ensuring that we have already computed the longest chain for their possible predecessors.

We initialize an unordered_map dp to store the length of the longest chain ending at each word. We also initialize maxLength to 1 since the minimum chain length for any word is 1.

We iterate through the sorted words. For each word:

We set its initial chain length to 1 in the dp map.
We then consider all possible predecessors by removing one character at a time and check if the predecessor exists in the dp map.
If a predecessor exists, we update the chain length for the current word based on the predecessor, ensuring we have the longest chain ending at the current word.
During this process, we keep track of the maximum chain length encountered and update maxLength accordingly.

Finally, we return maxLength as the length of the longest possible word chain.

# Complexity
- Time complexity: O(N * M^2)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->


- Space complexity: O(N)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Sort the words by length so that we can process shorter words first
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_map<string, int> dp; // Store the length of the longest chain ending at each word
        
        int maxLength = 1; // Initialize the maximum chain length to 1
        
        for (const string& word : words) {
            dp[word] = 1; // Initialize the chain length for the current word to 1
            
            // Try removing one character at a time and check if the predecessor exists
            for (int i = 0; i < word.length(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(predecessor)) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            
            // Update the maximum chain length
            maxLength = max(maxLength, dp[word]);
        }
        
        return maxLength;
    }
};