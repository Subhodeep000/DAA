/*You have been given an array of size N consisting of integers. In addition you have been given an element M you need to find and print the index of the last occurrence of this element M in the array if it exists in it, otherwise print -1. Consider this array to be 1 indexed.

Input Format

The first line consists of 2 integers N and M denoting the size of the array and the element to be searched for in the array respectively . The next line contains N space separated integers denoting the elements of of the array.

Constraints

1<=N<=10^5 1<=A[i]<=10^9 1<=M<=10^9

Output Format

Print a single integer denoting the index of the last occurrence of integer M in the array if it exists, otherwise print -1.

Sample Input 0

5 1
1 2 3 4 1
Sample Output 0

5*/
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int sch,loc;
    scanf("%d",&sch);
    for(int i=0; i<n; i++)
    {
        if(a[i]==sch);
        loc = i+1;
    }

    printf("%d",loc);

return 0;
}