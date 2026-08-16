/*
Sort 0s, 1s and 2s
Solved
Difficulty: Medium Accuracy: 50.58%Submissions: 881K+Points: 4Average Time: 10m
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
Note: You need to solve this problem without utilizing the built-in sort function.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s, 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s, 1s and 2s are segregated into ascending order.
Follow up: Could you come up with a one-pass algorithm using only constant extra space?

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2

*/

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int l = 0, r = n-1;
        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                swap(arr[i], arr[l]);
                l++;
            }
        }
        for(int i = n-1; i>= l; i--){
            if(arr[i] == 2){
                swap(arr[i], arr[r]);
                r--;
            }
        }
    }
};



// 1pass

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int l = 0, r = n-1;
        
        int ptr = 0;
        
        while(ptr <= r){
            if(arr[ptr] == 0){
                swap(arr[ptr], arr[l]);
                ptr++, l++;
            }
            else if(arr[ptr] == 1){
                ptr++;
            }
            else{
                swap(arr[ptr], arr[r]);
                r--;
            }
        }
    }
};
