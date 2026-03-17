/****

1727. Largest Submatrix With Rearrangements
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 

Example 1:


Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:


Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is either 0 or 1.

**/


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> height(n, 0);
		
		// view each row and its above as pillars 
        for(int i = 0; i < m; ++i){
			// calculate heights
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }
			
			// sort pillars
            vector<int> order_height = height;
            sort(order_height.begin(), order_height.end());
			
			// iterate to get the maxium rectangle
            for(int j = 0; j < n; ++j){
                ans = max(ans, order_height[j] * (n - j));
            }
        }
        return ans;
    }
};
