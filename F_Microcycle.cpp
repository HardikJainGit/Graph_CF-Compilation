#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "ff.h"
#else
#define debug(...)
#endif

#define py cout << "YES\n";
#define pn cout << "NO\n";
#define int long long
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
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


struct DSU
{
    int n;
    vi p;
    DSU(int N)
    {
        n = N;
        p.assign(n + 1,-1);
        for (int i = 0;i<=n;i++)p[i] = i;
    }
    int Find(int i)
    {
        if (p[i] == i)return i;
        return p[i] = Find(p[i]);
    }
    void Merge(int a,int b)
    {
        a = Find(a),b = Find(b);
        p[b] = a;
    }
};


vvi adj;
vector<bool> visited;
 
vector<int> route;
 
bool dfs(int current_node, int end)
{
    if(visited[current_node])
    {
        return false;
    }
 
    if (current_node == end)
    {
        route.push_back(current_node);
        return true;
    }

    visited[current_node] = true;
    int flag = 0;
    
    for (auto it : adj[current_node])
    {
        if (dfs(it, end))
        {
            route.push_back(current_node);
            flag = 1;
        }
    }
    if (flag) return true;
    return false;   
}
 
int_fast32_t main()
{
    yoyo
    in(t);
    while(t--){

    in(n);
    in(m);

    priority_queue<pair<int, pair<int, int>>> pq;

    f(i,0,m)
    {
        int l, r, w;
        cin >> l >> r >> w;
        l--;
        r--;
        pq.push({w, {l, r}});
    }
 
    vector<pair<int, pi>> v;
    DSU dsu(n);
    adj.resize(n);
    visited.resize(n);

    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        if (dsu.Find(x.ss.ff)!=dsu.Find(x.ss.ss))
        {
            dsu.Merge(x.ss.ff, x.ss.ss);
            adj[x.ss.ff].push_back(x.ss.ss);
            adj[x.ss.ss].push_back(x.ss.ff);
        }

        else
        {
            v.push_back(x);
        }
    }

    srt(v);

    //Since we are popping out of a pq the edges terminating the cycle will be the 
    //least weighted in that cycle

    int start = v[0].ss.ff;
    int end = v[0].ss.ss;

    dfs(start, end);

    cout << v[0].ff << ' ' << route.size() << endl;

    for (auto x : route)
    {
        cout << x+1 << ' ';
    }

    cout << endl;
    adj.clear();
    visited.clear();
    route.clear();

}
}