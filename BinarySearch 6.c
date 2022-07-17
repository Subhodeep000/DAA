/*You have been given an array A consisting of N integers. All the elements in this array A are unique. You have to answer some queries based on the elements of this array. Each query will consist of a single integer x. You need to print the rank based position of this element in this array considering that the array is 1 indexed. The rank based position of an element in an array is its position in the array when the array has been sorted in ascending order.

Note: It is guaranteed that all the elements in this array are unique and for each x belonging to a query, value x shall exist in the array

Input Format

The first line consists of a single integer N denoting the size of array A. The next line contains N unique integers, denoting the content of array A. The next line contains a single integer q denoting the number of queries. Each of the next q lines contains a single integer x denoting the element whose rank based position needs to be printed.

Constraints

1<=N<=10^5 1<=A[i]<=10^9 1<=q<=10^5 1<=x<=10^9

Output Format

You need to print q integers denoting the answer to each query.

Sample Input 0

5
1 2 3 4 5
5
1
2
3
4
5
Sample Output 0

1
2
3
4
5 */
#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}
  
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n] ;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sch_number;
    scanf("%d", &sch_number);

    int b[sch_number];
    for(int i = 0; i < sch_number; i++)
    {
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < n; i++)
    {
     
     int result = 1+( binarySearch(arr, 0, n - 1, b[i]));
     printf("%d\n", result);
    }

    return 0;
}