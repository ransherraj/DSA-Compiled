/**


1563. Stone Game V
Solved
Hard
Topics
premium lock icon
Companies
Hint
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's score is initially zero.

Return the maximum score that Alice can obtain.

 

Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28
Example 3:

Input: stoneValue = [4]
Output: 0
 

Constraints:

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 106

**/


//Brute force recursive TLE
class Solution {

private:
    vector<int>prefix;
    int getSum(int i, int j){
        return prefix[j + 1] - prefix[i];
    }
    int findWinner(int i, int j, vector<int>& stoneValue){
        if(i == j) return 0;
        int maxScore = 0;
        for(int k = i; k<j; k++){
            int lsum = getSum(i, k);
            int rsum = getSum(k+1, j);
            if(lsum < rsum){
                maxScore = max(maxScore, lsum + findWinner(i, k, stoneValue));
            }
            else if(rsum < lsum){
                maxScore = max(maxScore, rsum + findWinner(k+1, j, stoneValue));
            }
            else{
                int opt1 = lsum + findWinner(i, k, stoneValue);
                int opt2 = rsum + findWinner(k+1, j, stoneValue);
                maxScore = max(maxScore, max(opt1, opt2));
            }
        }
        return maxScore;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.assign(n+1, 0);
        for(int i = 0; i<n; i++){
            prefix[i+1] = prefix[i]+stoneValue[i];
        }

        int ans = findWinner(0, n-1, stoneValue);
        return ans;
    }
};




//Memoised solution Passed****
class Solution {

private:
    vector<int>prefix;
    vector<vector<int>> dp;
    int getSum(int i, int j){
        return prefix[j + 1] - prefix[i];
    }
    int findWinner(int i, int j, vector<int>& stoneValue){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxScore = 0;
        for(int k = i; k<j; k++){
            int lsum = getSum(i, k);
            int rsum = getSum(k+1, j);
            if(lsum < rsum){
                maxScore = max(maxScore, lsum + findWinner(i, k, stoneValue));
            }
            else if(rsum < lsum){
                maxScore = max(maxScore, rsum + findWinner(k+1, j, stoneValue));
            }
            else{
                int opt1 = lsum + findWinner(i, k, stoneValue);
                int opt2 = rsum + findWinner(k+1, j, stoneValue);
                maxScore = max(maxScore, max(opt1, opt2));
            }
        }
        return dp[i][j]=maxScore;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        prefix.assign(n+1, 0);
        for(int i = 0; i<n; i++){
            prefix[i+1] = prefix[i]+stoneValue[i];
        }

        int ans = findWinner(0, n-1, stoneValue);
        return ans;
    }
};

