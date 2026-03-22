/**

1886. Determine Whether Matrix Can Be Obtained By Rotation
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 

Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.

**/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size(), n = target.size();
        if(m != n) return false;

        vector<bool> check(4, true);
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] != target[i][j]) check[0] = false; // 0 degree rotation
                if(mat[i][j] != target[j][m-i-1]) check[1] = false; // 90 degree rotation
                if(mat[i][j] != target[m-i-1][m-j-1]) check[2] = false; // 180 degree rotation
                if(mat[i][j] != target[m-j-1][i]) check[3] = false; // 270 degree rotation
            }

        }
        return check[0] || check[1] || check[2] || check[3] ;
    }
};
