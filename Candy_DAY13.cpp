/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
*/
//C++ CODE

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> c(n, 1);
        for(int i = 1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                c[i] = c[i-1] + 1;
            }
        }
        for(int i = n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                if(c[i] <= c[i+1]) 
                    c[i] = c[i+1] + 1;
            }
        }

        return accumulate(c.begin(), c.end(), 0); 
    }
};


//Explanation
/*
The goal is to find the minimum total number of candies needed to achieve this distribution. The code you provided solves this problem efficiently. Here's a step-by-step explanation:

Initialize variables:

n is the number of children (equal to the size of the ratings vector).
Create a new vector c of size n to store the number of candies each child will receive. Initialize all elements to 1 because initially, each child receives at least one candy.
First Pass - Forward:

Loop through the ratings vector starting from the second child (index 1) to the last child (index n-1).
Compare the current child's rating (ratings[i]) with the previous child's rating (ratings[i-1]).
If the current child's rating is higher than the previous child's, increment the number of candies for the current child (c[i]) by 1 compared to the previous child (c[i-1]). This ensures that higher-rated children receive more candies than their left neighbors.
Second Pass - Backward:

Loop through the ratings vector starting from the second-to-last child (index n-2) to the first child (index 0).
Again, compare the current child's rating (ratings[i]) with the next child's rating (ratings[i+1]).
If the current child's rating is higher than the next child's and the number of candies for the current child (c[i]) is less than or equal to the number of candies for the next child (c[i+1]), then update the number of candies for the current child (c[i]) to be one more than the next child. This ensures that higher-rated children receive more candies than their right neighbors, if necessary.
Calculate the Total:

After both passes, the c vector contains the minimum number of candies required for each child while satisfying the given conditions.
Finally, calculate the total number of candies required by summing up all the values in the c vector using the accumulate function from the <numeric> library, and return that value as the result.
*/



//TIME COMPLEXITY - O(N)
//SPACE COMPLEXITY - O(N)


//BY KULDEEP SINGH
