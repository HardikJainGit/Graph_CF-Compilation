#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b,w;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        a--;
        b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    vector<long long int>d(n,1000000000000);
    vector<int>p(n,-1);
    d[0]=0;
    using pii = pair<int, int>;
    priority_queue <pii, vector<pii>, greater<pii>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    vector<int>shortest_path;
    int i=n-1;
    if(d[n-1]!=1000000000000)
    {
        while(p[i]!=-1)
        {
            shortest_path.push_back(i+1);
            i=p[i];
        }
        shortest_path.push_back(1);
        for(int i=shortest_path.size()-1;i>=0;i--)
        {
            cout<<shortest_path[i]<<' ';
        }
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }  
    
    return 0;
}


/* #include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b,w;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        a--;
        b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    set<pair<long long int,int>>s;
    vector<long long int>dist(n,1000000000000);
    vector<int>parent(n,-1);
    dist[0]=0;
    s.insert({0,0});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto &i:adj[x.second])
        {
            if(dist[i.first]>dist[x.second]+i.second)
            {
                s.erase({dist[i.first],i.first});
                dist[i.first]=dist[x.second]+i.second;
                s.insert({dist[i.first],i.first});
                parent[i.first]=x.second;
            }
        }
    }
    vector<int>shortest_path;
    int i=n-1;
    if(dist[n-1]!=1000000000000)
    {
        while(parent[i]!=-1)
        {
            shortest_path.push_back(i+1);
            i=parent[i];
        }
        shortest_path.push_back(1);
        for(int i=shortest_path.size()-1;i>=0;i--)
        {
            cout<<shortest_path[i]<<' ';
        }
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }  
    
    return 0;
} */