/**
Kadane's Algorithm
Solved
Difficulty: MediumAccuracy: 36.28%Submissions: 1.3MPoints: 4Average Time: 20m
You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray [-2] has the largest sum -2.
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104

**/

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxSum = INT_MIN;   // max sum initialize to INT_MIN  
        int currSum = 0, n = arr.size(); // curSum = 0
        for(int i = 0; i<n; i++){
            currSum += arr[i];  // Add each element curSum
            maxSum = max(currSum, maxSum);  // Check if maxSum < Cursum then assign maxSum  = Cursum
            
            if(currSum < 0) currSum = 0;  // If curSum < 0 then it creates burden on upcomimg element in sum, so we remove it and assign it to 0.
        }
        return maxSum;
    }
};
