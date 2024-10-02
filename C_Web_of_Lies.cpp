#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    fast
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n + 1);
    while (m--){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v),adj[v].insert(u);
    }
    int ans = 0;
    vb is(n,false);
    
    for (int i = 1;i<=n;i++)
        if (adj[i].lower_bound(i) == adj[i].end())ans++,is[i] = 1;
    
    int q;
    cin>>q;

    while (q--){
        int type,u,v;
        cin>>type;
        if (type == 3)cout<<ans<<endl;
        else{
            cin>>u>>v;

            if (is[u])ans--;
            if (is[v])ans--;
            
            if (type == 1){
                adj[u].insert(v);
                adj[v].insert(u);
            }
            
            else{
                adj[u].erase(v);
                adj[v].erase(u);
            }
            
            if (adj[u].lower_bound(u) != adj[u].end())is[u] = 0;
            else is[u] = 1;

            if (adj[v].lower_bound(v) != adj[v].end())is[v] = 0;
            else is[v] = 1;

            if (is[u])ans++;
            if (is[v])ans++;
        }
    }
    return 0;
}