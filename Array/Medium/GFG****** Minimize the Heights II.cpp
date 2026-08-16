/**

Minimize the Heights II
Solved
Difficulty: MediumAccuracy: 15.06%Submissions: 793K+Points: 4Average Time: 25m
Given an array arr[] representing the heights of n towers and a positive integer k. For each tower, perform exactly one of the following operations exactly once:

Increase its height by k, or
Decrease its height by k.
After performing the operation on every tower, the height of any tower must not become negative.

Return the minimum possible difference between the heights of the tallest and the shortest towers after modifying all the towers.

Note: A slight modification of the problem can be found here.

Examples :

Input: k = 2, arr[] = [1, 5, 8, 10]
Output: 5
Explanation: The array can be modified as [1+k, 5-k, 8-k, 10-k] = [3, 3, 6, 8]. The difference between the largest and the smallest is 8-3 = 5.
Input: k = 3, arr[] = [3, 9, 12, 16, 20]
Output: 11
Explanation: The array can be modified as [3+k, 9+k, 12-k, 16-k, 20-k] = [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17-6 = 11. 
Constraints:

1 ≤ k ≤ 107
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 107

**/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Initial answer without partitioning
        int ans = arr[n - 1] - arr[0];
        
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        
        // Step 2: Traverse every potential split point
        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);
            
            // Skip invalid splits where height becomes negative
            if (minHeight < 0) continue;
            
            ans = min(ans, maxHeight - minHeight);
        }
        
        return ans;
    }
};
