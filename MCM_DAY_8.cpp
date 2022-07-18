/*you are given n no of 2D matrices to multiply. Find out the minimum no of multiplications you need to perform.

Input Format

n = no of matrices next n lines contain P Q, i.e. the dimensions of the given matrices are PxQ respectively.

Constraints

2<=P<=50 2<=Q<=50 2<=n<=20

Output Format

print the minimum no of multiplications needed

Sample Input 0

4
1 2
2 1
1 4
4 1
Sample Output 0

7*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int f(int i,int j, vector<int>&a,vector<vector<int>>&dp)
{
    if(i==j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;k++)
    {
        int s=a[i-1]*a[k]*a[j]+f(i,k,a,dp)+f(k+1,j,a,dp);
        mini=min(mini,s);
    }
    return dp[i][j]=mini;
}
int matrixMultipication(vector<int>&a,int N)
{
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return f(1,N-1,a,dp);
}
