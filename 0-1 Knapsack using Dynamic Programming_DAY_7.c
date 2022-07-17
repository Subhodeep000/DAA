/*You are given n elements. Price and weight of each element is also given. You can only have items of total weight W. Calculate the total price of the products that we can have using 0-1 knapsack algorithm.

Input Format

n = no of items W = maximum weight that you can have cost[][]= 1st row contains the weights of the items, 2nd row contains the prices of the corresponding items.

Constraints

50<=W<=100
2<=n<=15

Output Format

Total price of the final items

Sample Input 0

3
50
10 20 30
60 100 120
Sample Output 0

220*/
#include<stdio.h>
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}
int main()
{
    int i, n, val[20], wt[20], W;
    
    scanf("%d", &n);
    
    
    scanf("%d", &W);
    
        
    for(i = 0; i < n; ++i){
     scanf("%d", &wt[i]);
    }      
    
    for(i = 0;i < n; ++i){
     scanf("%d", &val[i]);
    }
 
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}