/***

Rotate Array
Solved
Difficulty: MediumAccuracy: 37.06%Submissions: 773K+Points: 4Average Time: 20m
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes [3, 4, 5, 1, 2].
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes [8, 10, 12, 14, 16, 18, 20, 2, 4, 6].
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get [3, 9, 1, 7] as resultant array.
Constraints:
1 ≤  arr.size(), d ≤  105
0 ≤  arr[i] ≤  105

***/

//3 ways

//1. Brute Force(TLE)

class Solution {
  
  public:
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d = d % n;
        
        for (int i = 1; i <= d; i++ ){
            int temp = arr[0];
            for(int j = 1; j<n; j++){
                arr[j-1] = arr[j];
            }
            arr[n-1] = temp;
        }
    }
};


//OPTIMUIZED
// method 2 [EXPECTED]
class Solution {
  
  public:
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d = d % n;
        vector<int> temp(n);
        
        for(int i = 0; i<n; i++){
            temp[i] = arr[(i + d)%n];
        }
        arr = temp;
    }
};

// method 2 

/**

ARR : [1 2 6 4 5 3]
d : 2

ANS: [6 4 5 3 1 2]

DRY RUN : 
1. reverse 1st d=2 elements [2 1]
2. reverse last n-d =  6-2 = 4 elements [3 5 4 6], so combined array : [2 1 3 5 4 6]
3. reverse this array : [6 4 5 3 1 2] =  ANS

  **/

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; // Keep d within array bounds
        if (d == 0) return;
        
        // 1. Reverse first d elements
        reverse(arr.begin(), arr.begin() + d);
        
        // 2. Reverse remaining n - d elements
        reverse(arr.begin() + d, arr.end());
        
        // 3. Reverse the whole array
        reverse(arr.begin(), arr.end());
    }
};




