/*You have been given an array A of size N . you need to sort this array non-decreasing oder using bubble sort. However, you do not need to print the sorted array . You just need to print the number of swaps required to sort this array using bubble sort

Input Format

The first line consists of a single integer N denoting size of the array. The next line contains N space separated integers denoting the elements of the array.

Constraints

1<=N<=100 1<=a[i]<=100

Output Format

Print the required answer in a single line

Sample Input 0

5
1 2 3 4 5
Sample Output 0

0*/
#include <stdio.h>
int main()
{
    int array[100], n, i, j, swap;
    scanf("%d", &n);
    int ctr=0;

    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
                ctr ++;
            }
        }
    }

    printf("%d", ctr);

    return 0;
}