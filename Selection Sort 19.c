/*Consider an Array a of size N Iterate from 1 to N In ith iteration select the i th minimum and swap it with a[i]

You are given an array a, size of the array N and an integer x. Follow the above algorithm and print the state of the array after x iterations have been performed.

Input Format

The first line contains two integer N and x denoting the size of the array and the steps of the above algorithm to be performed respectively. The next line contains N space separated integers denoting the elements of the array.

Constraints

1<=N<=100 1<=a[i]<=100 1<=x<=N

Output Format

Print N space separated integers denoting the state of the array after x steps

Sample Input 0

5 2
1 2 3 4 5
Sample Output 0

1 2 3 4 5*/
#include <stdio.h>
int main()
{
    int n, i, j, position, swap;

    scanf("%d", &n);
     int a[n+1];
    for (i = 0; i < n+1; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < n; i++)
    {
        position = i;
        for (j = i + 1; j < n+1; j++)
        {
            if (a[position] > a[j])
                position = j;
        }
        if (position != i)
        {
            swap = a[i];
            a[i] = a[position];
            a[position]=swap;
        }
    }

    for (i = 1; i < n+1; i++)
        printf("%d ", a[i]);
    return 0;
}