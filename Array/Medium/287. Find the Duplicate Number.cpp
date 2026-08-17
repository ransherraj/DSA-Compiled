/*

287. Find the Duplicate Number
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/


//Solution using space: T:O(n), S:O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n+1);
        for(int i = 0; i<n; i++){
            temp[nums[i]]++;
            if(temp[nums[i]] >= 2) return nums[i];
        }
        return -1;
    }
};


//optimsized sol T:O(n), S:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 1) return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
