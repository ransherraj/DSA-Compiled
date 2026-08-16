/**

 Move All Negative Numbers To Beginning And Positive To End
Easy
40/40
Average time to solve is 10m
Contributed by
203 upvotes
Asked in companies
Problem statement
You are given an array 'ARR' consisting of 'N' integers. You need to rearrange the array elements such that all negative numbers appear before all positive numbers.

Note:
The order of elements in the resulting array is not important.
Example:
Let the array be [1, 2, -3, 4, -4, -5]. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-3, -5, -4, 2, 4, 1].
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 5 * 10^4
-10^5 <= ARR[i] <= 10^5

Where  ‘T’ represents the number of test cases and ‘N’ represents the number of elements present in the array.

Time Limit: 1 sec
Sample Input 1:
2
5
1 -4 -2 5 3
2
2 1    
Sample Output 1:
Yes
Yes
Explanation for Sample Input 1:
For the first test case we have, array: [1, -4, -2, 5, 3] and N = 5. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-2, -4, 1, 5, 3].

For the second test case we have, array: [2, 1] and N = 2. There are no negative numbers. Hence, we do not require any rearrangement.
Sample Input 2:
3
4
1 -5 -5 3
5
-1 -2 3 4 5
1
-2
Sample Output 2:
Yes 
Yes
Yes
Explanation for Sample Input 2:
For the first test case we have, array: [1, -5, -5,  3] and N = 4. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-5, -5, 1, 3].

For the second test case we have, array: [-1, -2, 3, 4, 5] and N = 5. There are already arranged in required way. Hence, we do not require any rearrangement.

For the third test case we have, array: [-2 ] and N = 1. The array is already arranged in required way. Hence, we do not require any rearrangement.

**/

#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // int n = nums.size(), l = 0, r = n-1;
    // // Write your code here.
    // while(l < r){
    //     while(l < r && nums[l] < 0) l++;
    //     while(l < r && nums[r] > 0) r--;
    //     if(l < r){
    //         swap(nums[l], nums[r]);
    //     }
    // }
    // return nums;

    int i = 0; // Boundary marker for negative numbers
    
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] < 0) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    return nums;
}
