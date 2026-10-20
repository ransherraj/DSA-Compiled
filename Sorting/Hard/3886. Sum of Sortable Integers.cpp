/***

3886. Sum of Sortable Integers
You are given an integer array nums of length n.

An integer k is called sortable if k divides n and you can sort nums in non-decreasing order by sequentially performing the following operations:

Partition nums into consecutive subarrays of length k.
Cyclically rotate each subarray independently any number of times to the left or to the right.
Return an integer denoting the sum of all possible sortable integers k.

 

Example 1:

Input: nums = [3,1,2]

Output: 3

Explanation:​​​​​​​

For n = 3, possible divisors are 1 and 3.
For k = 1: each subarray has one element. No rotation can sort the array.
For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
Only k = 3 is sortable. Hence, the answer is 3.
Example 2:

Input: nums = [7,6,5]

Output: 0

Explanation:

For n = 3, possible divisors are 1 and 3.
For k = 1: each subarray has one element. No rotation can sort the array.
For k = 3: the single subarray [7, 6, 5] cannot be rotated into non-decreasing order.
No k is sortable. Hence, the answer is 0.
Example 3:

Input: nums = [5,8]

Output: 3

Explanation:​​​​​​​

For n = 2, possible divisors are 1 and 2.
Since [5, 8] is already sorted, every divisor is sortable. Hence, the answer is 1 + 2 = 3.
 

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 105

***/

/*

The main idea is to check every divisor \(k\) of n. If the array can be sorted by cyclically rotating each block of size k, add k to the answer.

Important bug fix: prevMax = mn must be prevMax = mx, because we must compare the previous block's maximum with the current block's minimum.
Step 1: The check() function
bool check(vector<int>& nums, int k) {
    int n = nums.size(), prevMax = -1;


- k: size of each block.
- n: total number of elements.
- prevMax: maximum value of the previous block after its best cyclic rotation.
- Initially, -1 works only if all array values are non-negative. A safer optimized version is provided below.
Step 2: Divide the array into blocks
for (int start = 0; start < n; start += k) {
    int desc = 0, pos = -1;


For example, if nums = [4,1,2,3] and k = 2, the blocks are:
- Block 1: [4,1]
- Block 2: [2,3]
desc counts how many times an element is greater than the next element, including the circular comparison between the last and first elements.
Step 3: Count circular descents
for (int j = 0; j < k; j++) {
    int nxt = (j + 1) % k;

    if (nums[start + j] > nums[start + nxt]) {
        desc++;
        pos = j;
    }
}


(j + 1) % k makes the last element compare with the first element.

For block [4,1]:
- 4 > 1 → descent found at position 0.
- 1 > 4 → false.
So desc = 1 and pos = 0.

A block can be sorted by cyclic rotation only if it has at most one circular descent.
Step 4: Reject invalid blocks
if (desc > 1) return false;


If a block has more than one circular descent, no cyclic rotation can make it non-decreasing.
Step 5: Find the minimum and maximum after rotation
int mx, mn;

if (desc == 1) {
    mn = nums[start + (pos + 1) % k];
    mx = nums[start + pos];
} else {
    mn = mx = nums[start];
}


- If there is exactly one descent, the minimum is the element immediately after it, and the maximum is the element at the descent.
- If there are zero descents, all elements in that circular block must be equal.
For [4,1], the rotated block is [1,4], so mn = 1 and mx = 4.
Step 6: Check the boundary between blocks
if (prevMax > mn) return false;

prevMax = mx;


The previous block's maximum must be less than or equal to the current block's minimum.

For [4,1,2,3] with k = 2:
- First block [4,1]: minimum 1, maximum 4.
- Second block [2,3]: minimum 2, maximum 3.
- Since 4 > 2, the blocks cannot form a globally sorted array. Therefore, k = 2 is invalid.
Step 7: Check all possible block sizes
long long ans = 0;

for (int k = 1; k <= n; k++) {
    if (n % k == 0 && check(nums, k)) {
        ans += k;
    }
}


Only values of k that divide n can form equal-sized blocks. If check() returns true, add k to the answer.

For example, for [4,1,2,3], k = 4 works because the whole array can rotate to [1,2,3,4]. The answer is 4.


Approach	                                                                   Time complexity	                                 Extra space
Check every k from 1 to n	                                                  \(O(n^2)\) worst case	                              \(O(1)\)
Check only divisors	                                                      \(O(n\sqrt n)\) as a loose upper bound	              \(O(1)\)

  */


class Solution {
private:
    bool check(vector<int>& nums, int k){
        int n = nums.size() , prevMax = -1;

        for(int start = 0; start < n; start += k){
            int desc = 0, pos = -1;
            for(int j = 0; j < k; j++){
                int nxt = (j + 1) % k;
                if(nums[start + j] > nums[start + nxt]){
                    desc++;
                    pos = j;
                }
            }
            if (desc > 1) return false;
            int mx , mn;
            if(desc == 1){
                mn = nums[start + (pos + 1) % k ];
                mx = nums[start + pos];
            }
            else{
                mn = mx = nums[start];
            }
            if(prevMax > mn) return false;
            prevMax = mx;
        }
        return true;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        long long int ans = 0, n = nums.size();
        for(int i = 1; i<=n; i++){
            if(n % i == 0 && check(nums, i)){
                ans += i;
            }
        }
        return ans;
    }
};



// more optimized

class Solution {
private:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = 0;
        bool firstBlock = true;

        for (int start = 0; start < n; start += k) {
            int desc = 0, pos = -1;

            for (int j = 0; j < k; j++) {
                int nxt = (j + 1) % k;

                if (nums[start + j] > nums[start + nxt]) {
                    desc++;
                    pos = j;
                }
            }

            if (desc > 1) return false;

            int mn, mx;

            if (desc == 1) {
                mn = nums[start + (pos + 1) % k];
                mx = nums[start + pos];
            } else {
                mn = mx = nums[start];
            }

            if (!firstBlock && prevMax > mn)
                return false;

            prevMax = mx;
            firstBlock = false;
        }

        return true;
    }

public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int d = 1; d * d <= n; d++) {
            if (n % d != 0) continue;

            if (check(nums, d))
                ans += d;

            int other = n / d;

            if (other != d && check(nums, other))
                ans += other;
        }

        return ans;
    }
};


