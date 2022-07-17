/*you are given an array of size N. You need to select K elements from the array such that the difference between the max number among selected and the min number among selected array elements should be minimum. Print the minimum difference.

Input Format

First line N number i.e., length of array Second line K number Next N lines contains a number for each line

Constraints

0

Output Format

Print the minimum possible difference

Sample Input 0

5
3
1
2
3
4
5
Sample Output 0

2*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max, min;
int a[20];
void maxmin(int i, int j)
{
 int max1, min1, mid;
 if(i==j)
 {
  max = min = a[i];
 }
 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
    max = a[j];
    min = a[i];
   }
   else
   {
    max = a[i];
    min = a[j];
   }
  }
  else
  {
   mid = (i+j)/2;
   maxmin(i, mid);
   max1 = max; min1 = min;
   maxmin(mid+1, j);
   if(max <max1)
    max = max1;
   if(min > min1)
    min = min1;
  }
 }
}
int main ()
{
 int i, num;
int k=0;
 scanf ("%d",&num);
scanf("%d",&k);
 for (i=1;i<=num;i++)
  scanf ("%d",&a[i]);

 max = a[0];
 min = a[0];
 maxmin(1, k);
int diff=max-min;
printf("%d",diff);
 return 0;
}