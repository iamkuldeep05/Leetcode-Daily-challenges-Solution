/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

/*# Intuition:

The code aims to find the median of two sorted arrays, nums1 and nums2. The intuition behind this code can be summarized as follows:

Combine the two sorted arrays into one sorted array.
If the combined array has an odd length, return the middle element as the median.
If the combined array has an even length, return the average of the two middle elements as the median.

# Approach:

Initialize an empty vector ans to store the combined sorted array.
Handle special cases where one of the input arrays is empty.
Use two pointers (i and j) to iterate through nums1 and nums2 while comparing elements and merging them into the ans vector in sorted order.
After merging, the ans vector will contain the combined sorted array.
Calculate and return the median of the ans vector using the findMedian function.

# Time Complexity (TC):

Merging the two sorted arrays takes O(m + n) time, where m is the size of nums1 and n is the size of nums2.
Finding the median of a vector with m + n elements using the findMedian function takes O(m + n) time.
Therefore, the overall time complexity is O(m + n).

# Space Complexity (SC):

An additional vector ans is used to store the merged sorted array, which has a maximum size of m + n.
The findMedian function creates a temporary vector to store elements, but it doesn't add to the space complexity significantly.
Therefore, the overall space complexity is O(m + n).
# Code
```*/
class Solution {
public:
    template <typename T>
    double findMedian(vector<T>& nums) {
        int size = nums.size();
        if (size % 2 == 0) {
            return (nums[size / 2] + nums[size / 2 - 1]) / 2.0;
        } else {
            return nums[size / 2];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> ans;
        if (nums1.empty() && nums2.empty()) {
            return 0.0; // Both arrays are empty, return 0.0 as median.
        }
        int i=0,j=0,m=nums1.size(),n=nums2.size();
        if(m==0){
            return findMedian(nums2);
        }
        else if(n==0){
            return findMedian(nums1);
        }
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i!=m){
            for(;i<m;i++){
                ans.push_back(nums1[i]);
            }
        }
        if(j!=n){
            for(;j<n;j++){
                ans.push_back(nums2[j]);
            }
        }
        return findMedian(ans);
        
    }
};
