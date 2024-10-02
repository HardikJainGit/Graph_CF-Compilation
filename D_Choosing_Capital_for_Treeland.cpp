#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;

}

int n = 2e5 + 5;
vvvi adj(n);
vi numUp(n),numDown(n);
vi vals(n);
int totNumUpwards;

void dfs(int u,int p)
{
    for (auto val:adj[u]){

        int v = val[0],w = val[1];

        //base case already initialised witb=h zeroes

        if (v == p)continue;
        
        if (w == 0)numDown[v] = numDown[u] + 1;//u-->v and is downwards
        else numDown[v] = numDown[u];

        if (w == 1)numUp[v] = numUp[u] + 1;//u<--v and is upwards
        else numUp[v] = numUp[u];

        if (w == 1) totNumUpwards++;

        dfs(v,u);//because we need the values of numDown[v] and 
        //numUp[v] before we find the value for its children

        //Top-Down DP
    }
}

int main()
{
    setIO();
    cin>>n;

    //We mostly root the tree at 1

    for (int i = 0;i<n - 1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb({v,0}),adj[v].pb({u,1});
    }
    
    dfs(1,-1);

    for (int i = 1;i<=n;i++)
        vals[i] = numDown[i] + totNumUpwards - numUp[i];

    int ans = 1e9;

    for (int i = 1;i<=n;i++)
        ans = min(ans,vals[i]);

    cout<<ans<<'\n';

    for (int i = 1;i<=n;i++)
        if (ans == vals[i])cout<<i<<" ";

    return 0;
}