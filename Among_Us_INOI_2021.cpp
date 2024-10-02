#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    fast
    int t;
    cin>>t;
    while (t--){
        int n,q;//number of nodes and number of edges (the # of people and the # of statements)
        cin>>n>>q;
        vvvi adj(n + 1);//create a graph of N nodes where an edge from u to v means
        //u and v are either of opposite colours (one is lying and the other is telling the truth) - type 1 edge
        //OR u and v are of same colours (both are lying or both are telling the truth) - type 2 edge
    
        while (q--){
            int type,u,v;
            cin>>type>>u>>v;
            
            if (type == 1){//we know that u is accusing v of being a liar
                //Case 1: u is a liar => v is telling the truth
                //Case 2: u is telling the truth => v is a liar
                //therefore u and v must be of opposite colours (opposite types of people)
                //represent this by an undirected edge between u and v with the edge type 1

                adj[u].pb({v,1});
                adj[v].pb({u,1});
            }
            
            else{//we know that u is accusing v of telling the truth
                //Case 1: u is a liar => v is also a liar
                //Case 2: u is telling the truth => v is also telling the truth
                //therefore u and v must have the same colours (same types of people)
                //represent this by an undirected edge between u and v with the edge type 2

                adj[u].pb({v,2});
                adj[v].pb({u,2});
            }
        }

        //NOW we have built a graph where all edges are of 2 types:
        //type 1: u and v have opposite colours
        //type 2: u and v have same colours

        //NOW colour each node with either colour 1 or colour 2
        //if there is any contradiction between the colours of the nodes and the edges in the graph we built
        //then answer is -1 
        //otherwise we choose the LIARS to be the MAXIMUM colour - the colour WHICH APPEARS THE MOST
        //and the TRUTH TELLERS to be the colours WHICH APPEARS LESSER
        //this is exactly what the problem is asking us to do

        //to COLOUR each node we can use BFS to traverse the graph
        //HOWEVER THERE MAY BE MORE THAN 1 CONNECTED COMPONENT IN THE GRAPH
        //As explained in the whiteboard
        //SO LAUNCH BFS for each unvisited/uncoloured node
        //and in EACH CONNECTED COMPONENT choose the COLOUR WHICH APPEARS THE MOST NUMBER OF TIMES

        vi col(n + 1,-1);//col[i] == -1 MEANS i is UNVISITED 
        queue<int>Q;
        
        int ans = 0;
        bool isContradiction = false;
        
        for (int i = 1;i<=n;i++){
            
            int numColour1 = 0;
            int numColour2 = 0;

            if (col[i] == -1){//i is UNIVISITED so LAUNCH BFS FROM i
                Q.push(i);
                col[i] = 1;//MARK i with colour 1 

                while (!Q.empty()){
                    int u = Q.front();
                    
                    if (col[u] == 1)numColour1++;
                    else numColour2++;
                    
                    Q.pop();

                    for (auto val:adj[u]){
                        int v = val[0],type = val[1];

                        if (col[v] != -1){//v is visited
                            
                            if (type == 1 && col[v] == col[u])isContradiction = true;
                            if (type == 2 && col[v] != col[u])isContradiction = true;

                            continue;//v is VISITED, so just CHECK for a CONTRADICATION
                        }
                        //as mentioned above, if type == 1 then u and v have opposite colours
                        //otherwise they have the same colour
                        
                        if (type == 1)col[v] = 3 - col[u];//because 3 - 1 is 2 and 3 - 2 is 1
                        else col[v] = col[u];

                        Q.push(v);
                    }
                }

                ans += max(numColour1,numColour2);//choose the colour which appears more as the colour
                //of LIARS
            }
        }
        if (isContradiction)cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}