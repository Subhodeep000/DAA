/*Quick sort is based on the divide-and-conquer approach based on the idea of choosing one element as a pivot element and partitioning the array around it such that: Left side of pivot contains all the elements that are less than the pivot element Right side contains all elements greater than the pivot

It reduces the space complexity and removes the use of the auxiliary array that is used in merge sort. Selecting a random pivot in an array results in an improved time complexity in most of the cases.

Input Format

The first line contains a single integers N denoting the size of the array. The next line contains N space separated integers denoting the contents of the array.

Constraints

1<=N<=10^6 1<=A[I]<=10^9

Output Format

Print N space separated integers, i.e. the final sorted array.

Sample Input 0

5
4 3 1 5 2
Sample Output 0

1 2 3 4 5*/
#include<stdio.h>
int parition(int a[],int min,int max)
{
    int pivot=min,t;
    while(max>min)
    {
        while(a[min]<=a[pivot])
          min++;
        while(a[max]>a[pivot])
           max--;
        if(max>min)
        {
            t=a[max];
            a[max]=a[min];
            a[min]=t;
        }
    }
    t=a[pivot];
    a[pivot]=a[max];
    a[max]=t;
    return max;
}
void qsort(int a[],int min,int max)
{
    int p;
    if(max>min)
    {
        p=parition(a,min,max);
        qsort(a,min,p-1);
        qsort(a,p+1,max);
    }
}
int main()
{
    int a[30],n,i;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    qsort(a,0,n-1);

    for(i=0;i<n;i++)
      printf("%d ",a[i]);
}