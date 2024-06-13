// Nattawat Ruensumrit 66070503420 //

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <stdbool.h>
using namespace std;
void DFS(int start , vector<vector<int> >&graph, map<int,bool>& dfs_visited)
{
    stack<int> s;       // create stack //
    s.push(start);      // fill into stack //
    dfs_visited[start] = true;  // this node visited //
    cout << start << " ";

    while(!s.empty())
    {
        int node = s.top();
        int refer = 0;

        while(true)
        {
            if(!dfs_visited[graph[node][refer]]) // if the node not visited //
            {
                dfs_visited[graph[node][refer]] = true;
                node = graph[node][refer];
                s.push(node); // fill a current node into the top of stack //
                cout << node << " "; // output all node from the stack //
                refer = 0; // reset it to zero if any value not visited //
            }else{
                refer++;
            } // just in case when some adj list had been visited it will go to next idx //
            if(refer >= graph[node].size()){
                break;  // max size of adj node from a node //
            }
        }
        s.pop(); // whenever all adj list of the node had visited for all adj node within that node we will pop a node from stack // 
    }
}


void BFS(int start , vector<vector<int> >&graph, map<int,bool>& bfs_visited)
{
    queue<int> q; // create queue //
    q.push(start); //fill in queue this value will be front of queue//
    bfs_visited[start] = true;

    while(!q.empty())
    {
        int node = q.front(); // update node always be the frontmost value within queue //
        q.pop(); // deletion value from the queue //
        cout << node << " ";

        for(int i = 0; i < graph[node].size(); i++)
        {
            if(!bfs_visited[graph[node][i]])
            {
                q.push(graph[node][i]);
                bfs_visited[graph[node][i]] = true; // check visited node //
            }
        }
    }
}

//dfs = stack //
//bfs = queue //

// Breadth-First Search (BFS) function

int main() 
{
    int edge ,start;
    cin >> edge;
    vector<vector<int> > graph(edge);  // created a graph and assign the max size of graph//
         //creating a map //
    map<int, bool> dfs_visited; 
    map<int, bool> bfs_visited;

    for(int i = 0; i < edge; i++)
    {
        int from , to;
        cin >> from >> to;

        //DFS//
        dfs_visited[from] = false; // let assign all value be false before visit each vertices //
        dfs_visited[to] = false;

        // BFS //
        bfs_visited[from] = false;
        bfs_visited[to] = false;

        graph[from].push_back(to); //for undirected graph  to add element
        graph[to].push_back(from); //becareful don't forgot to type it go on and go back to each other between from and to because it (undirected graph)     //
    }

    cin >> start;

    // output call function to show output //
    DFS(start , graph , dfs_visited);
    cout << endl;
    BFS(start , graph , bfs_visited);
    
    return 0;
}
