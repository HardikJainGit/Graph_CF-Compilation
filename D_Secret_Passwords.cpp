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
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(n) {int x; cin>>x; a.pb(x);}
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

int32_t main() {
    yoyo

    in(n);
    vector <string> v;
    DSU dsu(n);

    f(n)
    {
        string s;
        cin>>s;
        v.pb(s);
    }

    unordered_map<char, int> m;

    f(n)
    {
        for (auto c : v[i]) 
        {
            if (m.find(c) != m.end()) 
            {
                dsu.Merge(i, m[c]);
            }
            m[c] = dsu.p[i];
        }
    }

    int cc = 0;
    vi vis(n,0);

    f(n)
    {
        int p = dsu.Find(i);
        if(!vis[p])
        {
            cc += 1;
            vis[p] = 1;
        }
    }

    pr(cc);
    
}