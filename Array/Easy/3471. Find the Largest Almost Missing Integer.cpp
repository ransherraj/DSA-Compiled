/**

3471. Find the Largest Almost Missing Integer
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer array nums and an integer k.

An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.

Return the largest almost missing integer from nums. If no such integer exists, return -1.

A subarray is a contiguous sequence of elements within an array.
 

Example 1:

Input: nums = [3,9,2,1,7], k = 3

Output: 7

Explanation:

1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
3 appears in 1 subarray of size 3: [3, 9, 2].
7 appears in 1 subarray of size 3: [2, 1, 7].
9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
We return 7 since it is the largest integer that appears in exactly one subarray of size k.

Example 2:

Input: nums = [3,9,7,2,1,7], k = 4

Output: 3

Explanation:

1 appears in 2 subarrays of size 4: [9, 7, 2, 1], [7, 2, 1, 7].
2 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
3 appears in 1 subarray of size 4: [3, 9, 7, 2].
7 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
9 appears in 2 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1].
We return 3 since it is the largest and only integer that appears in exactly one subarray of size k.

Example 3:

Input: nums = [0,0], k = 1

Output: -1

Explanation:

There is no integer that appears in only one subarray of size 1.

 

Constraints:

1 <= nums.length <= 50
0 <= nums[i] <= 50
1 <= k <= nums.length

**/

//Brute force
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> subarrayCount;

        // Iterate through all valid starting positions for subarrays of size k
        for (int i = 0; i <= n - k; ++i) {
            std::unordered_set<int> uniqueInSubarray;
            for (int j = i; j < i + k; ++j) {
                uniqueInSubarray.insert(nums[j]);
            }
            for (int num : uniqueInSubarray) {
                subarrayCount[num]++;
            }
        }

        int maxVal = -1;
        for (auto& [num, count] : subarrayCount) {
            if (count == 1) {
                maxVal = std::max(maxVal, num);
            }
        }

        return maxVal;
    }
};

//optimized
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k equals array length
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }

        // Case 2: k == 1
        if (k == 1) {
            std::unordered_map<int, int> freq;
            for (int x : nums) freq[x]++;
            int maxVal = -1;
            for (auto& [num, count] : freq) {
                if (count == 1) maxVal = std::max(maxVal, num);
            }
            return maxVal;
        }

        // Case 3: 1 < k < n
        // Only nums[0] and nums[n-1] can potentially appear in exactly 1 subarray
        std::unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int maxVal = -1;
        if (freq[nums[0]] == 1) maxVal = std::max(maxVal, nums[0]);
        if (freq[nums[n - 1]] == 1) maxVal = std::max(maxVal, nums[n - 1]);

        return maxVal;
    }
};
