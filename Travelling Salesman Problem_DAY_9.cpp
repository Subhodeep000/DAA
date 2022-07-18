/*Travelling Salesman Problem (TSP) is a touring problem in which n cities and distance between each pair is given. We have to find a shortest route to visit each city exactly once and come back to the starting point.

Input Format

First line contains an integer N = number of cities

N lines follow

Each line contains label x y

where:

label = label of the city (String)

x = x co-ordinate of the city (Real Valued)

y = y co-ordiate of the city (Real Valued)

Constraints

N/A

Output Format

Output an optimal path in space separated manner.

Sample Input 0

4
0 0 0
1 0 1
2 1 0
3 1 1
Sample Output 0

0 1 2 3*/

#include <bits/stdc++.h>
using namespace std;
#define V 4
int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
         min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
    return min_path;
}
int main()
{
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}