/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107



*/

//Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, n = nums.size(), cnt = 0;
        // for(int i = 0; i<n; i++){
        //     sum += nums[i];
        // }
        int curr = 0;
        for(int i = 0; i<n; i++){
            int curr = 0;
            for(int j = i; j<n; j++){
                curr += nums[j];
                if(curr == k) cnt++;
            }
        }
        return cnt;
    }
};

//Optimized
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), cnt = 0;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i = 0; i<n; i++){
            if(prefix[i] == k){
                cnt++;
            }
            if(mp.find(prefix[i] - k) != mp.end()){
                cnt += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }
        return cnt;
    }
};
