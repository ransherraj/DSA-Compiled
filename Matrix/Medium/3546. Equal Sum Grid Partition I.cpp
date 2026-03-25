/***

3546. Equal Sum Grid Partition I
You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.

 

Example 1:

Input: grid = [[1,4],[2,3]]

Output: true

Explanation:



A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

Example 2:

Input: grid = [[1,3],[2,4]]

Output: false

Explanation:

No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.

 

Constraints:

1 <= m == grid.length <= 105
1 <= n == grid[i].length <= 105
2 <= m * n <= 105
1 <= grid[i][j] <= 105

**/


class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long int m = grid.size();
        long long int n = grid[0].size();
        vector<long long int> vsum(m, 0);
        vector<long long int> hsum(n, 0);
        for(long long int i = 0; i<m; i++){
            long long int temp = 0;
            for(long long int j = 0; j<n; j++){
                temp += grid[i][j];
            }
            vsum[i] = temp;
        }
        for(long long int i = 0; i<n; i++){
            long long int temp = 0;
            for(long long int j = 0; j<m; j++){
                temp += grid[j][i];
            }
            hsum[i] = temp;
        }

        long long int VerSum = accumulate(vsum.begin(), vsum.end(), 0LL);
        long long int HorSum = accumulate(hsum.begin(), hsum.end(), 0LL);

        long long int tempVsum=0, tempHsum=0;
        for(long long int i = 0; i<vsum.size(); i++){
            tempVsum += vsum[i];
            if(2 * tempVsum == VerSum ) return true;
            if(2 * tempVsum > VerSum ) break;
        }

        for(long long int i = 0; i<hsum.size(); i++){
            tempHsum += hsum[i];
            if(2 * tempHsum == HorSum ) return true;
            if(2 * tempHsum > HorSum ) break;
        }
        return false;
    }
};
