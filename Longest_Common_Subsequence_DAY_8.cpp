/*You are given 2 strings and you have to find the Longest Common Subsequence between them.

Input Format

First line contain string s

Second line contain string t

Constraints

1<=|s| |t|<=2000

Output Format

Maximum Length of Longest Common Subsequence.

Sample Input 0

todolomejor

rolcmhjrt
Sample Output 0

5
*/
#include <bits/stdc++.h>
using namespace std;
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
    return 0;
}
 