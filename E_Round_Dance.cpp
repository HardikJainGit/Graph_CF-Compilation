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
#define int long long
#define vi vector <int>
#define vvi vector<vector<int>>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_itement(v.begin(), v.end())
#define maxv(v) *max_itement(v.begin(), v.end())
#define aint(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool cycle;
void dfs(int Node,vector<bool>& visited, set<int> adj[],int par){

    visited[Node] = true;
    //int visCount = 0; //initialise

    for(auto it:adj[Node]){

        //debug(it);
        if(visited[it]){
            if(it!=par){
                cycle = true;
            }
            continue;
        }

        dfs(it,visited,adj,Node);
    }
 
    //debug(visCount);
    //if(visCount != 1 && visCount!=0){ //either it is linear or circular graph
        //cycle = true;
    //}
}

int32_t main() {
    yoyo
    int t;
    cin>>t;

    while (t--) {
    in (n);
        
    vi arr(n+1);
    f(i,1,n+1){
        cin>>arr[i];
    }     
 
    set<int> adj[n+1];
    f(i,1,n+1){
        adj[i].insert(arr[i]);
        adj[arr[i]].insert(i);
    }
 
    vector<bool> visited(n+1);
 
    int cc = 0; //connected components

    int cycleCount = 0;

    f(i,1,n+1){
        if(!visited[i]){
              
            cc++; //no of disconnected vertices being processed
            //pr(i);
            cycle = false;
            dfs(i,visited,adj,-1);
            if(cycle){
                //pr(i);
                cycleCount++;
            }
        }
    }
 
    cout<<cycleCount + (cc - cycleCount > 0 ? 1 : 0)<<" "; //minimum
    pr(cc); //maximum

    }
}

/* #include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> g(n);
    vector<set<int>> neighbours(n);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        g[i].insert(a[i]);
        g[a[i]].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        d[i] = g[i].size();
    }
    int bamboos = 0, cycles = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            vector<int> component = {i};
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        component.push_back(v);
                    }
                }
            }
            bool bamboo = false;

            for (int j: component) {
                if (d[j] == 1) {
                    bamboo = true; //means bamboo exists i.e reached at its end point
                    //break;
                }
            }

            if (bamboo) {
                bamboos++;
            } 
            else {
                cycles++;
            }
        }
    }
    cout << cycles + min(bamboos, 1) << ' ' << cycles + bamboos << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
} */