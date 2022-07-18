/*Given a chess board having cells, you need to place N queens on the board in such a way that no queen attacks any other queen.

Input Format

The only line of input consists of a single integer denoting N.

Constraints

1<=N<=10

Output Format

If it is possible to place all the N queens in such a way that no queen attacks another queen, then print N lines having N integers. The integer in i th line and j th column will denote the cell (i,j) of the board and should be 1 if a queen is placed at (i,j) otherwise 0. If there are more than way of placing queens print any of them. If it is not possible to place all N queens in the desired way, then print "Not possible" (without quotes).

Sample Input 0

4
Sample Output 0

0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 */
#define N 4
#include <stdbool.h>
#include <stdio.h>
void printSolution(int board[N][N])
{
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}
bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solveNQUtil(board, 0) == false) {
        //printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}
int main()
{
    solveNQ();
    return 0;
}