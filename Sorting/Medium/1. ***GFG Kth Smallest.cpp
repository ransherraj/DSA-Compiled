/*
Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
Note: The kth smallest element is determined based on the sorted order of the array.

Examples :

Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output: 5
Explanation: 4th smallest element in the given array is 5.
Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
1 ≤ k ≤  arr.size() 
*/


// PYTHON SOL
from queue import PriorityQueue
class Solution:
    def kthSmallest(self, arr, k):
        # Code here
        n = len(arr)
        pq = PriorityQueue()
        
        for i in range(n):
            pq.put(-arr[i])   //By default priority queue in python is min heap unlike in c++, so to implement maxheap we insert it to negative.
            if pq.qsize() > k:
                pq.get()
        return -pq.get()  // return again negative one to get original number


// C++ Sol  time = O(nlogn) ++ BRUTE FORCE, space O(1)
#include<bits/stdc++.h>
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};
  
// C++ Sol  time = O(nlogk), space O(k)
#include<bits/stdc++.h>
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> q;
        int temp;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            q.push(arr[i]);
            if(q.size() > k){
                q.pop();
            }
        };  
        return q.top();
    }
};


// Better optimised sol with Quick select:
#include<bits/stdc++.h>

class Solution {
  private:
    int partition(vector<int> &arr, int l, int r){
        int pivot = arr[r];
        int i = l;
        for(int j = l; j<r; j++){
            if(arr[j] <= pivot){
                swap(arr[j], arr[i]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
    
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        int numIndex = k-1;
        int l = 0, r = n-1;
        
        while (l <= r){
            int pIndex = partition(arr, l, r);
            if(pIndex == numIndex) return arr[pIndex];
            else if(pIndex < numIndex){
                l = pIndex + 1;
            }
            else{
                r = pIndex - 1;
            }
        }
        return -1;
    }
};

    
