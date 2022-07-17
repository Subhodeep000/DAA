/*You have been given a graph consisting of N nodes and M edges. The nodes in this graph are enumerated from 1 to N . The graph can consist of self-loops as well as multiple edges. This graph consists of a special node called the head node. You need to consider this and the entry point of this graph. You need to find and print the number of nodes that are unreachable from this head node.

Input Format

The first line consists of a 2 integers N and M denoting the number of nodes and edges in this graph. The next M lines consist of 2 integers a and b denoting an undirected edge between node a and b. The next line consists of a single integer x denoting the index of the head node.

Constraints

1<=N<=10^5 1<=M<=10^5 1<=x<=N

Output Format

You need to print a single integer denoting the number of nodes that are unreachable from the given head node.

Sample Input 0

10 10
8 1
8 3
7 4
7 5
2 6
10 7
2 8
10 9
2 10
5 10
2
Sample Output 0

0*/
#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
    struct node *next;
    int vertex;
}node;
node *G[20];  

int visited[20];
int n;
void read_graph();
void insert(int,int);  
void DFS(int);
int main()
{
    int i;
    read_graph();
      for(i=0;i<n;i++)
        visited[i]=0;
    DFS(0);
}
void DFS(int i)
{
    node *p;  
    printf("%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
      
    if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
void read_graph()
{
    int i,vi,vj,no_of_edges; 
    scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
        G[i]=NULL;
        scanf("%d",&no_of_edges);
        for(i=0;i<no_of_edges;i++)
        {
            scanf("%d%d",&vi,&vj);
            insert(vi,vj);
        }
    }
}
void insert(int vi,int vj)
{
    node *p,*q;    
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        p=G[vi];      
    while(p->next!=NULL)
         p=p->next;
        p->next=q;
    }
}