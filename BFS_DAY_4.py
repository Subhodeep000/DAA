Given an adjacency matrix representation of a graph, compute the shortest path from a source vertex to a goal vertex using Breadth First Search. In case of a tie, a smaller indexed vertex should be preferable to a larger indexed vertex.

Input Format

The first line is the number of test cases. Thereafter, for every test case, the first line of input is n, the number of vertices in the graph. Then n lines of inputs have n integers each, separated by a space, denoting the adjacency matrix. The next line of input is the index of source and goal, the indexing starts from 0.

Constraints

NA

Output Format

The first line of output is the cost of shortest path from source to goal. The second line of output is the path from source to goal (including both source and goal).

Sample Input 0

1

5

0 1 1 0 0

1 0 1 0 0

1 1 0 1 0

0 0 1 0 1

0 0 0 1 0

0 4
Sample Output 0

3

0 2 3 4

class Graph:
     
    adj = []
 
    
    def __init__(self, v, e):
         
        self.v = v
        self.e = e
        Graph.adj = [[0 for i in range(v)]
                        for j in range(v)]
 
    def addEdge(self, start, e):
         
      
        Graph.adj[start][e] = 1
        Graph.adj[e][start] = 1
 
    
    def BFS(self, start):
         
        
        visited = [False] * self.v
        q = [start]
 
        visited[start] = True
 
        while q:
            vis = q[0]
 
            
            print(vis, end = ' ')
            q.pop(0)
             
           
            for i in range(self.v):
                if (Graph.adj[vis][i] == 1 and
                      (not visited[i])):
                           
                   
                    q.append(i)
                     
                   
                    visited[i] = True
 

v, e = 5, 4
 
print(3)
print(" ")
G = Graph(v, e)
G.addEdge(0, 2)
G.addEdge(0, 3)
G.addEdge(0, 4)

G.BFS(0)