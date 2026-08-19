/**

1386. Cinema Seat Allocation
Solved
Medium
Topics
premium lock icon
Companies
Hint


A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.

 

Example 1:



Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4
 

Constraints:

1 <= n <= 109
1 <= reservedSeats.length <= min(10 * n, 104)
reservedSeats[i] == [rowi, seati]
1 <= rowi <= n
1 <= seati <= 10
All reservedSeats[i] are distinct.

**/


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for(auto x : reservedSeats) mp[x[0]].push_back(x[1]);

        int ans = (n - mp.size())*2;

        for(auto x : mp){
            vector<bool> isCnt(11, false);
            for(auto y : x.second){
                isCnt[y] = true;
            }

            //2, 3, 4, 5
            if(!isCnt[2] && !isCnt[3] && !isCnt[4] && !isCnt[5]){
                ans++;
                isCnt[5] = true;
            }

            //4, 5, 6, 7
            if(!isCnt[4] && !isCnt[5] && !isCnt[6] && !isCnt[7]){
                ans++;
                isCnt[7] = true;
            }

            //6, 7, 8, 9
            if(!isCnt[6] && !isCnt[7] && !isCnt[8] && !isCnt[9]){
                ans++;
            }
        }
        return ans;
    }
};
