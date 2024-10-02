//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class Solution {
    #define f(i, a, b) for (int i = a; i < b; i++)
    private:

bool isCyclicDFS(int &start,vector<int> adj[], vector<int> &visited, vector<int> &dfsVisited, int Node) {
    visited[Node] = dfsVisited[Node] = 1;

    for(int x : adj[Node]) {
        if(visited[x] == 0) {
        bool ans = isCyclicDFS(start,adj, visited, dfsVisited, x);

            if(ans) {
                return true;
            }
        } else if(dfsVisited[x] == 1) {
            start=x;
            return true; //visited true and dfs visited also true
        }
    }

    dfsVisited[Node] = 0; //while returning back mark dfs visited false
    return false;
}


  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int n=V;
        vector<int> visited(n);
        vector<int> dfsVisited(n);

        int start = -1;
        vector<int> ans;



        f(i, 0, n) {
            if (!visited[i]) {
                isCyclicDFS(start, adj, visited, dfsVisited,i);
                //cout<<i<<" "<<start<<endl;

                if (start == -1) {
                    ans.push_back(i);
                }
                f(i,0,n){
                    visited[i]=0;
                    dfsVisited[i]=0;
                }
                start = -1;
            }
        }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends