/***
D - Knapsack 1  / 

Problem Statement
There are 
N items, numbered 
1,2,…,N. For each 
i (
1≤i≤N), Item 
i has a weight of 
w 
i
​
  and a value of 
v 
i
​
 .

Taro has decided to choose some of the 
N items and carry them home in a knapsack. The capacity of the knapsack is 
W, which means that the sum of the weights of items taken must be at most 
W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10 
5
 
1≤w 
i
​
 ≤W
1≤v 
i
​
 ≤10 
9
 
Input
Input is given from Standard Input in the following format:

N 
W
w 
1
​
  
v 
1
​
 
w 
2
​
  
v 
2
​
 
:
w 
N
​
  
v 
N
​
 
Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1
Copy
3 8
3 30
4 50
5 60
Sample Output 1
Copy
90
Items 
1 and 
3 should be taken. Then, the sum of the weights is 
3+5=8, and the sum of the values is 
30+60=90.

Sample Input 2
Copy
5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
Sample Output 2
Copy
5000000000
The answer may not fit into a 32-bit integer type.

Sample Input 3
Copy
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Sample Output 3
Copy
17
Items 
2,4 and 
5 should be taken. Then, the sum of the weights is 
5+6+3=14, and the sum of the values is 
6+6+5=17.

**/

#include <bits/stdc++.h>
using namespace std;

long long int dp[101][100001];

long long int knapsack(int W, int i, vector<int>&wt, vector<int>&val){
    if(W == 0 || i == 0) return 0;
    if(dp[i][W] != -1) return dp[i][W];
    if(wt[i-1] <= W) return dp[i][W] = max(val[i-1]+knapsack(W-wt[i-1], i-1, wt, val), knapsack(W, i-1, wt, val));
    else if(wt[i-1] > W) return dp[i][W] = knapsack(W, i-1, wt, val);
    
    //return 0;
    
}

int main() {

    int n , w;
    cin>>n>>w;
    vector<int>wt(n), val(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<n; i++){
        cin>>wt[i]>>val[i];
    }
    
    long long int ans = knapsack(w, n, wt, val);
    cout<<ans;

}
