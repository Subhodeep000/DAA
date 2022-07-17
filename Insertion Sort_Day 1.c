/*You have been given an A array consisting of N integers. All the elements in this array are guaranteed to be unique. For each position i in the array A you need to find the position A[i] should be present in, if the array was a sorted array. You need to find this for each i and print the resulting solution.

Input Format

The first line contains a single integer N denoting the size of array A. The next line contains N space separated integers denoting the elements of array A.

Constraints

1<=N<=100 1<=A[i]<=100

Output Format

Print N space separated integers on a single line , where the Ith integer denotes the position of if this array were sorted.

Sample Input 0

5
1 2 3 4 5
Sample Output 0

1 2 3 4 5 */
#include <math.h>
#include <stdio.h>
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
     {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 

int main()
{

    int n;
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    } 
    insertionSort(arr, n);
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}