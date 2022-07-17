/*You are given a graph with n vertices. Find all pair shortest paths for that graph

Input Format

n = no of vertices cost[] = cost matrix

Constraints

3<=n<=10
1<=cost[i]<=50

Output Format

min_cost[][] = cost matrix containing the all pair shortest paths

Sample Input 0

4
0 11 1 6
11 0 7 3
1 7 0 2
6 3 2 0
Sample Output 0

0 6 1 3
6 0 5 3
1 5 0 2
3 3 2 0*/
#include <stdio.h>
#define nV 4
void printMatrix(int matrix[][nV]);
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

int main() {
  int graph[nV][nV] = {{0,11,1,6},
             {11,0,7,3},
             {1,7,0,2},
             {6,3,2,0}};
  floydWarshall(graph);
}