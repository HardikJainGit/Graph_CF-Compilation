/* #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define inf 1e9
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define all(arr) arr.begin(),arr.end()
#define pyes cout << "YES\n";
#define pno cout << "NO\n";
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

const int N = 1e5 + 228;

vector<int> G[N];

void dfs(int v, int par, int h, vector<int> &d) { //get distance from v
    d[v] = h;
    for (int i : G[v]) {
        if (i != par) {
            dfs(i, v, h + 1, d);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    vector<int> d1(n), d2(n);
    dfs(0, -1, 0, d1);
    //debug(d1);

    int a = max_element(all(d1)) - d1.begin(); //index of the max element
    dfs(a, -1, 0, d1); //get dist from max dist element from 1 i.e one end of diameter

    int b = max_element(all(d1)) - d1.begin();
    dfs(b, -1, 0, d2); //get dist from one end of diameter

    for (int i = 0; i < n; ++i) {
        d2[i] = max(d2[i], d1[i]); //get max dist from either of the two ends
    }

    sort(all(d2)); //dist are sorted

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (ans < n && d2[ans] < i) {
            //debug(ans);
            ans++; //inc no of cc's
        }
       if(ans!=n) cout << (ans + 1) << ' ';
       else cout << n << ' ';
    }
    cout << '\n';
} */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define inf 1e9
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define all(arr) arr.begin(),arr.end()
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

pair<ll,ll> dfs(ll curr,vector<ll> adj[],ll par){

    bool leaf = true;

    pair<ll,ll> ans = {-1,-1};  
    for(auto el:adj[curr]){
        if(el==par){
            continue;
        }
        leaf = false;
        auto ret = dfs(el,adj,curr); 
        //debug(ans); debug(ret);
        if(ret.first > ans.first){ //return bigger value of the 2 subtrees
            ans = ret;
        }

    }

    if(leaf){
        return {0,curr};
    }
    //debug(ans);

    return {ans.first+1,ans.second}; //returns max depth from 1 and the leaf node at max depth
}

void dfsPath(ll curr,vector<ll> adj[],map<ll,ll>& dist,ll par,ll len){
    bool isLeaf = true;

    for(auto el:adj[curr]){
        if(el==par){
            continue;
        }
        isLeaf = false;
    }

    if(isLeaf){
        dist[curr] = max(dist[curr],len);
        return;
    }

    for(auto el:adj[curr]){
        if(el==par){
            continue;
        }
        dfsPath(el,adj,dist,curr,len+1);
    }
}

void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> adj[n+1];

    ll edges = n-1;

    for(ll i=0;i<edges;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }     

    auto oneEnd = dfs(1,adj,-1);
    ll e1 = oneEnd.second; //one end

    auto secondEnd = dfs(e1,adj,-1);

    ll mxPath=secondEnd.first;

    ll e2 = secondEnd.second; //diameter another end
    //similar logic as F Max Min distance Problem

    map<ll,ll> maxFromDia; //node , dist

    //get max dist of leaves which could be either from e1 or from e2
    dfsPath(e1,adj,maxFromDia,-1,0);
    dfsPath(e2,adj,maxFromDia,-1,0);

    map<ll,vector<ll>> dist;
    for(auto el:maxFromDia){
        dist[el.second].pb(el.first); //get all nodes for a particular distance
    }

    // ll mxPath = -1;
    // for(auto el:dist){
    //     mxPath = max(mxPath,el.first);
    // }

    vector<ll> ans(n+1,1);
    for(ll i=mxPath+1;i<=n;i++){
        ans[i] = n; //no of connected components
    }

    ans[mxPath] = (n - dist[mxPath].size() + 1);
    //debug(dist[mxPath]);

    //BFS//
    queue<ll> q;

    vector<bool> visited(n+1);

    for(auto el:dist[mxPath]){
        q.push(el); //multi source bfs
        visited[el] = true;
    }

    //dist.erase(mxPath);

    ll current_dist = mxPath-1;

    debug(q);

    while(current_dist>=1 && !q.empty()){
        vector<ll> oldElem;
        while(!q.empty()){
            auto elem = q.front();
            q.pop();
            oldElem.pb(elem);
        }
        debug(oldElem);

        //Count new members who will join the connected group (x-1) 

        ll newMem = 0;

        for(auto el:oldElem){
            for(auto neigh:adj[el]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                    //debug(neigh);
                    newMem++;
                }
            }
        }

        debug(q);

        //unvisited leaves
        //debug(current_dist);
        for(auto el:dist[current_dist]){ //push leaves at dist=current_dist
            if(!visited[el]){
                q.push(el);
                debug(dist[current_dist]);
                visited[el] = true;
                newMem++;
            }
        }

        //dist.erase(current_dist);        
        ans[current_dist] = ans[current_dist+1] - newMem; //cc reduced by newMem
        current_dist--;
    }

    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {

    ll tt = 1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}