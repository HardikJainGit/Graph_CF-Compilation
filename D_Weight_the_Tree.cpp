/* #include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
const ll inf = 1e18;

int n = 2e5 + 5;
vvi adj(n);
vector<pair<ll,ll>>dp0(n),dp1(n);
vi ans(n);
vb taken(n,false);
//{max number of good vertices, min sum of all weights}
//0 => u is not taken, 1 => u is taken

void dfs(int u,int p)
{
    dp0[u] = {0ll,-1ll};
    dp1[u] = {1ll,-(ll)adj[u].size()};
    pair<ll,ll> mx = {0,-inf};
    for (int v:adj[u]){
        if (v == p)continue;
        dfs(v,u);
        dp1[u].first += dp0[v].first;
        dp1[u].second += dp0[v].second;
        if (dp1[v] > dp0[v]){
            dp0[u].first += dp1[v].first;
            dp0[u].second += dp1[v].second;
        }
        else{
            dp0[u].first += dp0[v].first;
            dp0[u].second += dp0[v].second;
        }
    }
}
void dfs2(int u,int p)
{
    for (int v:adj[u]){
        if (v == p)continue;
        
    if (taken[u] or dp0[v] > dp1[v])
        //0 only allowed
        ans[v] = 1;
    else{
        taken[v] = 1;
        ans[v] = (int)adj[v].size();
    }
    dfs2(v,u);
    }
}
int main()
{
    cin>>n;
    if (n == 2){
        cout<<2<<" "<<2<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    for (int i = 1;i<=n - 1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v),adj[v].push_back(u);
    }
    dfs(1,-1);
    if (dp0[1] > dp1[1]){
        ans[1] = 1;
        cout<<dp0[1].first<<" "<<-dp0[1].second<<endl;
    }
    else{
        ans[1] = (int)adj[1].size();
        taken[1] = true;
        cout<<dp1[1].first<<" "<<-dp1[1].second<<endl;
    }

    for (int v:adj[1]){
        if (taken[1] or dp0[v] > dp1[v])
        //0 only allowed
        ans[v] = 1;
        else{
        taken[v] = 1;
        ans[v] = (int)adj[v].size();
        }
        dfs2(v,1);
    }


    for (int i = 1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

vector<int> g[MAXN];

bool vis[MAXN];
int pa[MAXN];

//DFS to compute the parent of each node
//parent of node i is stored at pa[i]
void dfs(int v){
	vis[v] = 1;
	for(auto i : g[v]){
		if(!vis[i]){
			pa[i] = v;
			dfs(i);
		}
	}
}

pair<int, int> dp[MAXN][2];

//Computes the value of function f, using dp
//the second coordinate of the pair is negated (to take maximums)

//dp[x][y]-> y denotes 0 for bad node 1 for good node
// x denotes the node itself and pair is {no of good nodes in subtree , min wt}

pair<int, int> f(int x, int y){
	pair<int, int> & res = dp[x][y];
	if(res.first != -8) return res;
	res = {y, y ? -((int) g[x].size()) : -1};
	for(auto i : g[x]){
		if(i != pa[x]){
			pair<int, int> maxi = f(i, 0);
			if(y == 0) maxi = max(maxi, f(i, 1));
			res.first += maxi.first;
			res.second += maxi.second;
		}
	}
	return res;
}

vector<int> is_good;

//Recursive construction of the answer
//is_good[i] tells whether vertex i is good or not.
void build(pair<int, int> value, int v){
	if(value == f(v, 0)){
		is_good[v] = 0;
		for(auto i : g[v]){
			if(i != pa[v]){
				build(max(f(i, 0), f(i, 1)), i);
			}
		}
	}else{
		is_good[v] = 1;
		for(auto i : g[v]){
			if(i != pa[v]){
				build(f(i, 0), i);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v; 
		cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n == 2){
		cout<<"2 2\n1 1\n";
		return 0;
	}
	pa[0] = -1;
	dfs(0);
	for(int i = 0; i < n; i++) dp[i][0] = {-8, -1}, dp[i][1] = {-8, -1};
	pair<int, int> res = max(f(0, 0), f(0, 1));
	cout << res.first << " " << -res.second << "\n";
	is_good.resize(n);
	build(res, 0);
	for(int i = 0; i < n; i++){
		if(is_good[i]) cout << g[i].size() << " ";
		else cout << "1 ";
	}
	cout << "\n";
	return 0;
}