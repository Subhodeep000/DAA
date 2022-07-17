/*You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Input Format

n = no of activities start[] = array holding the start times of the activities finish[] = array holding the finish times of the activities

Constraints

2<=n<=50 1<=start[i],finish[i]<=100

Output Format

Print the no of activity that can be performed by a single person

Sample Input 0

3
10 12 20
20 25 30
Sample Output 0

2*/
#include <stdio.h>

int activitySelection(int s[], int f[], int n) {
  int temp_start, temp_finish;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n - 1; j++){
      if(f[j] > f[j+1]) {
        temp_start = s[j];
        temp_finish = f[j];
        f[j] = f[j+1];
        s[j] = s[j+1];
        f[j+1] = temp_finish;
        s[j+1] = temp_start;
      }
    }
  }

int count=0;
  int i = 0;
  for(int j = 1; j < n; j++) {
    if(s[j] >= f[i]) {
        count =j;
      i = j;
    }
  }
    return count;
}

int main(void) {

  int n;
    scanf("%d",&n);
    int start[n],  finish[n];
    for(int i=0;i<n;i++){
        scanf("%d", &start[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &finish[i]);
    }

  printf("%d",activitySelection(start, finish, n));
  return 0;
}