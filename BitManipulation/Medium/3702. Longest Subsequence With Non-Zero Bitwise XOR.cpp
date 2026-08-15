/*
You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

 

Example 1:

Input: nums = [1,2,3]

Output: 2

Explanation:

One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

Example 2:

Input: nums = [2,3,4]

Output: 3

Explanation:

The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109

  */

public class Solution {
    public int LongestSubsequence(int[] nums) {
        int n = nums.Length;
        int xor = 0;
        bool hasNonZero = false;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                hasNonZero = true;
            }
            xor = xor ^ nums[i];
        }

        if(xor != 0) return n;
        return hasNonZero ? n - 1 : 0;
    }
}


/**

Case-by-Case Analysis
Case 1: XOR(all n elements) != 0
The whole array already works.
Answer = n — done!
Case 2: XOR(all n elements) == 0
Now the full array is invalid. Can we save n-1 elements?
If we drop just one element x:
plain
XOR(remaining n-1 elements) = 0 ^ x = x
This is the crucial step! The remaining XOR equals exactly the element you dropped.
So:
If you drop a non-zero element x, then XOR(remaining) = x ≠ 0 ✓
This means n-1 elements are always enough, as long as at least one non-zero element exists in the array.
You never need to drop 2, 3, or more elements. One strategic drop is sufficient.
Case 3: All elements are 0
XOR(all) = 0
Every element is 0
Drop any element: remaining XOR = 0 (still bad)
Any subsequence of any length will XOR to 0
Answer = 0
Why Not n-2 or Less?
Because in Case 2, we proved that dropping exactly one non-zero element always fixes the problem. There's no scenario where:
Total XOR is 0
A non-zero element exists
But we need to drop 2 or more elements
The moment you drop one non-zero element x, the remaining n-1 elements automatically XOR to x (which is non-zero). It's guaranteed.
Visual Summary
Table
Total XOR	Contains Non-Zero?	What happens if we drop 1 non-zero element x	Answer
!= 0	Yes/No	Don't need to drop anything	n
== 0	Yes	Remaining XOR = x != 0 ✓	n-1
== 0	No (all zeros)	Remaining XOR = 0 ✗ (always)	0
Example Walkthrough
nums = [5, 1, 4]
XOR(all) = 5 ^ 1 ^ 4 = 0 ❌
Drop 5: remaining XOR = 1 ^ 4 = 5 != 0 ✓
Drop 1: remaining XOR = 5 ^ 4 = 1 != 0 ✓
Drop 4: remaining XOR = 5 ^ 1 = 4 != 0 ✓
See? No matter which non-zero element you drop, the remaining n-1 elements XOR to that exact value. You'd never think about dropping 2 elements.
nums = [0, 0, 7, 7]
XOR(all) = 0 ^ 0 ^ 7 ^ 7 = 0 ❌
Drop 7: remaining XOR = 0 ^ 0 ^ 7 = 7 != 0 ✓
Answer = 3 (which is n-1)
The Intuition
Think of it this way: when total XOR is 0, the array is "perfectly balanced" in binary. Removing any single element x "unbalances" it by exactly x. If x is non-zero, the imbalance is non-zero — and that's exactly what we want!

**/
