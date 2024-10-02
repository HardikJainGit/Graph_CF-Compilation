#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define pyes cout << "YES\n"; 
#define pno cout << "NO\n";
#define int long long
#define vi vector <int>
#define vvi vector<vector<int>>
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
#define pr(x) cout<<x<<endl;

struct DSU
{
    int n;
    vi p;
    DSU(int _n)
    {
        n = _n;
        p.assign(n + 1,0);
        f(i,1,n)
        p[i] = i;
    }
    int ultpar(int i)
    {
        if (p[i] == i)
        return i;
        return p[i] = ultpar(p[i]);
    }
    void dsu_union(int u,int v)
    {
        u = ultpar(u),v = ultpar(v);
        if(u==v) return;
        p[v] = u; //dsu_union regardless of small->big
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<pair<int,int>> redundant,new_edges; //new_edges stores the edges between pairs of nodes in different cc's
    DSU val(n);
    f(i,0,n-1){
        int u,v;
        cin>>u>>v;
        if (val.ultpar(u) == val.ultpar(v)){
            redundant.pb({u,v}); //redundant edges we don't need to add
        }
        else{
            debug(u);
            debug(v);
            val.dsu_union(u,v);
        }
    }  

    for (int u = 1;u<=n;u++){ //u=1 would also work as everyone is connected to 1
    
        for (int v = u+1;v<=n;v++){
            if (val.ultpar(u) == val.ultpar(v)) continue;

            //we know that u<-->v is an edge which should be added
            //because u and v are part of different cc's
            
            new_edges.pb({u,v});
            val.dsu_union(u,v); //merge these two by introducing edge u-v
        }
    }

    debug(new_edges);
 
    pr(new_edges.size());
    //pr(redundant.size());

    f(i,0,new_edges.size())
    cout<<redundant[i].ff<<" "<<redundant[i].ss<<" "<<new_edges[i].ff<<" "<<new_edges[i].ss<<endl; 
    //first output redundant then newly added
}