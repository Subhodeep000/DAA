/*In Fractional Knapsack, we can break items for maximizing the total value of knapsack. This problem in which we can break an item is also called the fractional knapsack problem. You are given n elements. Price and weight of each element is also given. Calculate the total price of the products that we can have using fractional knapsack algorithm.

Input Format

n = no of items W = maximum weight that you can have cost[][]= 1st row contains the weights of the items, 2nd row contains the prices of the corresponding items

Constraints

50<=W<=100 2<=n<=15

Output Format

Total price of the final items

Sample Input 0

3
50
10 20 30
60 100 120
Sample Output 0

240*/
#include <stdio.h>

int main()
{
    int capacity, no_items, cur_weight, item;
    int used[10];
    int total_profit;
    int i;
    int weight[10];
    int value[10];
    
    scanf("%d", &no_items);
    scanf("%d", &capacity);
    for (i = 0; i < no_items; i++)
    {
        scanf("%d", &weight[i]);
    }
    for (i = 0; i < no_items; i++)
    {
        scanf("%d", &value[i]);
    }
    for (i = 0; i < no_items; ++i)
        used[i] = 0;
    cur_weight = capacity;
    while (cur_weight > 0)
    {
        item = -1;
        for (i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float) value[i] / weight[i] > (float) value[item] / weight[item])))
                item = i;
        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item];
        if(cur_weight<0){
            int item_percent = (int) ((1 + (float) cur_weight / weight[item]) * 100);
            total_profit -= value[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }
    printf("%d", total_profit);
    return 0;
}