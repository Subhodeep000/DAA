/*You are given a graph with n vertices and the edges can have negative weights. Now find the shortest distance for each of the vertices from vertex 1 (that is the 1st vertex of the graph)

Input Format

n = no of nodes cost[][]= given cost matrix of the graph

Constraints

3<=n<=10 -50<=cost[i][j]<=50

Output Format

dist[] = one dimensional array representing the shortest distance of each vertex from the source vertex.

Sample Input 0

5
0 -1 4 0 0
0 0 3 2 2
0 0 0 0 0
0 1 5 0 0
0 0 0 -3 0
Sample Output 0

0 -1 2 -2 1*/
#include <stdio.h>
#include <stdlib.h>
int Bellman_Ford(int G[20][20] , int V, int E, int edge[20][2])
{
    int i,u,v,k,distance[20],S =1,flag=1;
    for(i=0;i<V;i++)
        distance[i] = 1000;
        distance[S-1]=0 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v];
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
        }
        if(flag)
            for(i=0;i<V;i++)
                printf("%d ",distance[i]);

        return flag;
}
int main()
{
    int V,edge[20][2],G[20][20],i,j,k=0;
    scanf("%d",&V);
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;
        }

    Bellman_Ford(G,V,k,edge);
    return 0;
}