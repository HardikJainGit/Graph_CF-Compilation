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


typedef long long ll;

#define forn(i, n) for (int i = 0; i < int(n); i++)

map<int, vector<int>> m;
vector<bool> vis;

// int dfs(int v) {
//     vis[v] = true;
//     for (auto now : m[v]) {
//         if (!vis[now]) {
//             //debug(now);
//             //debug(dfs(now));
//             return dfs(now) + 1;
//         }
//     }
//     return 1;
// }
int sz=0;

void dfs(int v,int &sz)
{
    vis[v]=1;
    sz++;
    for(auto it : m[v])
    {
        if(vis[it]) continue;
        dfs(it,sz);
    }
}

void solve() {

    int n, x, y;
    cin >> n;

    m.clear();
    vis.clear();
    sz=0;
    vis.resize(n + 1, false);

    bool f = false;

    forn(i, n) {
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
        if (x == y || m[x].size() > 2 || m[y].size() > 2) f = true;
    }

    if (f) { //indeg > 2
        cout << "NO\n";
        return;
    }

    forn(i, n) { 
        if (!vis[i + 1]) {
            dfs(i+1,sz);
            if (sz % 2) { //odd cycles
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        solve();
    }
}