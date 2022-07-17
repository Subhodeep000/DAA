/*You are given n elements. Price and weight of each element is also given. You can only have items of total weight W. Calculate the total price of the products that we can have using 0-1 knapsack algorithm.

Input Format

n = no of items
W = maximum weight that you can have
cost[][]= 1st row contains the weights of the items, 2nd row contains the prices of the corresponding items.

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
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Recursive Top Down approach
int knapSack(int wts[], int prices[], int n, int w){
    if(n==0 || w==0){return 0;}
    
    int include=0, exclude=0;
    int result=0;
    if(wts[n-1] <= w){
        include = prices[n-1] + knapSack(wts, prices, n-1, w-wts[n-1]);
    }
    exclude = knapSack(wts, prices, n-1, w);
    if(include>exclude){
        result = include;
    }
    else{
        result = exclude;
    }
    return result;
}
int main() {

    int n, w;
    scanf("%d",&n);
    scanf("%d", &w);
    
    int wts[n], prices[n];
    for(int i=0;i<n;i++){
        scanf("%d", &wts[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &prices[i]);
    }   
    printf("%d",knapSack(wts, prices, n, w));   
}