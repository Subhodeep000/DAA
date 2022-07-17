/*You are given two square matrices and multiply them using Strassen's matrix multiplication algorithm.

Input Format

n1 = number of rows and columns in the 1st matrix n2 = number of rows and columns in the 2nd matrix a = enter the 1st matrix b = enter the 2nd matrix

Constraints

1<=n1,n2<=100

Output Format

print the output matrix

Sample Input 0

2
2
1 2
2 1
2 4
1 2
Sample Output 0

4 8
5 10*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n,m;
    scanf("%d",&n);
scanf("%d",&m);
  int a[n][n], b[m][m], c[2][2], i, j;
  int m1, m2, m3, m4 , m5, m6, m7;
    
  for(i = 0;i < n; i++)
      for(j = 0;j < n; j++)
           scanf("%d", &a[i][j]);
  for(i = 0; i < m; i++)
      for(j = 0;j < m; j++)
           scanf("%d", &b[i][j]);
 
  m1= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  m2= (a[1][0] + a[1][1]) * b[0][0];
  m3= a[0][0] * (b[0][1] - b[1][1]);
  m4= a[1][1] * (b[1][0] - b[0][0]);
  m5= (a[0][0] + a[0][1]) * b[1][1];
  m6= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
  m7= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
 
  c[0][0] = m1 + m4- m5 + m7;
  c[0][1] = m3 + m5;
  c[1][0] = m2 + m4;
  c[1][1] = m1 - m2 + m3 + m6;
   for(i = 0; i < n ; i++){
      for(j = 0;j < m; j++)
           printf("%d ", c[i][j]);
       printf("\n");
   }
 
   return 0;
}