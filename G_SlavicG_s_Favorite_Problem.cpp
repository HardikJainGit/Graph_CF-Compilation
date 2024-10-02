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

#define py cout << "YES\n";
#define pn cout << "NO\n";
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
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 1e7;
vector<pair<int, int>> g[N];
set<int> s;
//bool ok = true;
int n, a, b;

void dfs1(int u, int par, int x) {

    if(u == b) return; 

    //We do not need to insert distance between a and b in set as then it would be always
    //true as in dfs of b->a s.count will be true

    debug(u);
    debug(x);
    s.insert(x);

    for(auto e: g[u]) {
        int v = e.first, w = e.second;
        if(v == par) 
        continue; //it is a tree
        dfs1(v, u, x ^ w);
    }
}

bool dfs2(int u, int par, int x) {

    if(u != b && s.count(x)) 
    {
        debug(u);
        debug(x);
        return true;
    }

    for(auto e: g[u]) {
        int v = e.first, w = e.second;
        if(v == par) continue;
        
        debug(u);
        debug(v);
        
        //debug(t);
        if(dfs2(v, u, w ^ x)) 
        return true;
    } 
    return false;
}


int32_t main() {
    yoyo
    int t;
    cin>>t;

    while (t--) {

    s.clear();

    cin >> n >> a >> b; 
    --a, --b; //base 0

    f(i,0,n) 
    {
        g[i].clear();
    }

    f(i,0,n-1) {
        in(u);in(v);in(w);
        --u, --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    } 

    dfs1(a, -1, 0); //initially xor is 0
    debug(s);

    if(dfs2(b, -1, 0))
    { 
        py;
    }

    else 
    {
        pn;
    }

    }
}


/* 
1
5 1 5
1 2 3
2 3 4
1 4 3
4 5 4
Handling when a->c is same as a->b ie teleporting to a
*/