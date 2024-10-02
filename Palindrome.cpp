#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../../ff.h"
#else
#define d(...)
#endif

#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector <int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void dfs_p(vi &par,int node,int p, vi &vis, vvi & adj)
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(it != -1 && it != p)
        {
            par[it] = node;
            dfs_p(par,it,node,vis,adj);
        }
    }
}

void dfs(vector <string> &sv, vvi &adj, vector<char> &S, int node, vi &par)
{
    for(auto it : adj[node])
    {
        if(it != par[node])
        {
            dfs(sv,adj,S,it,par);
            sv[node] += sv[it];
        }
    }

    sv[node] += S[node];
}

bool isP(string s)
{
    string c = s;
    reverse(s.begin(), s.end());
    return s == c;
}

vector<int> Solve (int N, vector<vector<int> > edges, vector<char> S, int Q, vector<int> queries) {
   
    vector<string> sv(N);
    vector<int> vis(N,0);
    vector<vector<int>> adj(N,vector<int>());

    for(auto it : edges)
    {
        adj[--it[0]].push_back(--it[1]);
    }

    f(N)
    {
        srt(adj[i]);
    }

    vector <int> ret;
    vi par(N,-1);
    dfs_p(par,0,-1,vis,adj);

    dfs(sv,adj,S,0,par);

    d(sv);

    for(auto it : queries)
    {
        if(isP(sv[--it]))
        {
            ret.push_back(1);
        }
        else
        {
            ret.push_back(0);
        }
    }

    return ret;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int> > edges(N-1, vector<int>(2));
    for (int i_edges = 0; i_edges < N-1; i_edges++)
    {
    	for(int j_edges = 0; j_edges < 2; j_edges++)
    	{
    		cin >> edges[i_edges][j_edges];
    	}
    }
    vector<char> S(N);
    for(int i_S = 0; i_S < N; i_S++)
    {
    	cin >> S[i_S];
    }
    int Q;
    cin >> Q;
    vector<int> queries(Q);
    for(int i_queries = 0; i_queries < Q; i_queries++)
    {
    	cin >> queries[i_queries];
    }

    vector<int> out_;
    out_ = Solve(N, edges, S, Q, queries);
    cout << out_[0]<< endl;
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout  << out_[i_out_] << endl;
    }
}
