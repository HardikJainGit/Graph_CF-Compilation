//Multi-State Dijkstra AKA Graph Modelling -> https://codeforces.com/blog/entry/45897

#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A> void __print(const A &x);
template <typename A, typename B> void __print(const pair<A, B> &p);
template <typename... A> void __print(const tuple<A...> &t);
template <typename T> void __print(stack<T> s);
template <typename T> void __print(queue<T> q);
template <typename T, typename... U> void __print(priority_queue<T, U...> q);
template <typename A> void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B> void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A> void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T> void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T> void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T)) cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif

#define pyes cout << "YES\n";
#define pno cout << "NO\n";
#define vi vector <int>
#define vvi vector<vector<int>>
#define pb push_back
#define ff first
#define ss second
#define int long long
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
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve() {
    
    
    
}

int32_t main() {
    yoyo
    int t = 1;
    cin >> t;
    
   while(t--){
    int n, m;
    cin >> n >> m;
    
    vector<pair<int,int>> adj[n];
    f(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    inpv(s,n);
    
    vvi dist(n, vector<int>(n, 1e17));
    vvi vis(n, vector<int>(n, 0));
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
    
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    
    while (!pq.empty()) {
        int city = pq.top()[1];
        int bike = pq.top()[2];
        pq.pop();
        
        if (city == n - 1) {
            cout << dist[city][bike] << endl;
            break;
        }
        
        if (vis[city][bike]) continue;
        vis[city][bike] = 1;

        for (auto it : adj[city]) {
            int nbr = it.first;
            int wt = it.second;
            
            int newBike = bike;
            if (s[nbr] < s[bike]) newBike = nbr;
            
            if (dist[nbr][newBike] < dist[city][bike] + wt * s[bike]) continue;
            
            dist[nbr][newBike] = dist[city][bike] + wt * s[bike];
            pq.push({dist[nbr][newBike], nbr, newBike});
        }
    }
    
    }
    
    return 0;
}