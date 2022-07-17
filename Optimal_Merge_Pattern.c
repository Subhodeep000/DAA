/*Optimal merge pattern is a pattern that relates to the merging of two or more sorted files in a single sorted file. This type of merging can be done by the two-way merging method.

If we have two sorted files containing n and m records respectively then they could be merged together, to obtain one sorted file in time O (n+m).

Input Format

Given a set of unsorted files

Constraints

NA

Output Format

Find Optimal cost

Sample Input 0

5, 3, 2, 7, 9, 13
Sample Output 0

93*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>
#define N 104
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))


int minMergeCost(int i, int j, int* arr)
{
    int dp[N][N];
    _Bool v[N][N];
    if (i == j) return 0;
    if (v[i][j]) return dp[i][j];
    v[i][j] = 1;
    int x = dp[i][j];
    x = INT_MAX;
    int tot = 0;
    for (int k = i; k <= j; k++)
        tot += arr[k];
    for (int k = i + 1; k <= j; k++) {
        x = min(x, tot + minMergeCost(i, k - 1, arr)+ minMergeCost(k, j, arr));
    }
    return x;
}

// Driver code
int main()
{
    int arr[] = { 5, 3, 2, 7, 9, 13};
    int n = sizeof(arr) / sizeof(int);

    printf("%d",minMergeCost(0, n - 1, arr));

    return 0;
}