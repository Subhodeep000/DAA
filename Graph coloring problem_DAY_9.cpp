/*You are given a graph with N nodes and M undirected edges. This graph does not contain self loops and multiple edges between same pair of nodes. You plan to give this to Monk for his birthday so you wish to colour it. You want to colour all the nodes of the graph in either red or blue colour such that each edge has endpoints of different colours. As Monk loves red colour, you also want the number of nodes with red colour to be maximum. Output the maximum number of red coloured nodes you can get in the graph after colouring every vertex under the given constraint. If no such colouring is possible output "NO" (without quotes).

Input Format

First line contains T, denoting the number of test cases. Description of input for each input follows. First line contains two integers N and M, the number of nodes in the graph and the number of edges in the graph. Next M lines follow each containing two integers U and V, denoting an undirected edge between them.

Constraints

1<=T<=3 1<=N<=100000 0<=M<=200000 1<=U,V<=N

Output Format

Output T lines each containing the answer for the i th test case.

Sample Input 0

1
3 2
1 2
2 3
Sample Output 0

2*/
#include<bits/stdc++.h>
using namespace std;
#define V 4
void printSolution(int color[]);
bool isSafe(bool graph[V][V], int color[])
{
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}
bool graphColoring(bool graph[V][V], int m, int i,
                int color[V])
{
    if (i == V) {
        if (isSafe(graph, color)) {
            printSolution(color);
            return true;
        }
        return false;
    }
    for (int j = 1; j <= m; j++) {
        color[i] = j;
        if (graphColoring(graph, m, i + 1, color))
            return true;
         color[i] = 0;
    }
 
    return false;
}
void printSolution(int color[])
{
    cout << "Solution Exists:" " Following are the assigned colors \n";
    for (int i = 0; i < V; i++)
        cout << "  " << color[i];
    cout << "\n";
}
int main()
{
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3; 
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
 
    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist";
 
    return 0;
}