/*Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists until each sublist consists of a single element and merging those sublists in a manner that results into a sorted list.

Idea:

Divide the unsorted list into N sublists, each containing 1 element.

Take adjacent pairs of two singleton lists and merge them to form a list of 2        elements.N will now convert into N/2 lists of size 2.
Repeat the process till a single sorted list of obtained.
While comparing two sublists for merging, the first element of both lists is taken into consideration. While sorting in ascending order, the element that is of a lesser value becomes a new element of the sorted list. This procedure is repeated until both the smaller sublists are empty and the new combined sublist comprises all the elements of both the sublists.

Input Format

First line contains one integer, N, size of array. Second line contains N space separated integers denoting the elements of the array A.

Constraints

1<=N<=10^6 1<=A[i]<=10^6

Output Format

Output will be sorted order

Sample Input 0

5
1 4 3 2 5
Sample Output 0

1 2 3 4 5*/
#include<stdio.h>
 
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
int a[30],n,i;

scanf("%d",&n);

for(i=0;i<n;i++)
scanf("%d",&a[i]);
mergesort(a,0,n-1);
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}
 
void mergesort(int a[],int i,int j)
{
int mid;
if(i<j)
{
mid=(i+j)/2;
mergesort(a,i,mid); //left recursion
mergesort(a,mid+1,j); //right recursion
merge(a,i,mid,mid+1,j); //merging of two sorted sub-arrays
}
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
int temp[50]; //array used for merging
int i,j,k;
i=i1; //beginning of the first list
j=i2; //beginning of the second list
k=0;
while(i<=j1 && j<=j2) //while elements in both lists
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=j1) //copy remaining elements of the first list
temp[k++]=a[i++];
while(j<=j2) //copy remaining elements of the second list
temp[k++]=a[j++];
//Transfer elements from temp[] back to a[]
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
}