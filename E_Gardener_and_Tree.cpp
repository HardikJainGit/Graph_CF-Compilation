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
#define vvi vector<vi>
#define vp vector<pair<int,int>>
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

int32_t main() {
    yoyo
    int t;
    cin>>t;

    while (t--) {
        int n, k;
		cin >> n >> k;

		vvi g(n, vi(0));
		vi rem(n, 0);
		vi layer(n, 0);

		f(i,0,n-1)
		{
			in(x);in(y);
			x--;
			y--;
			g[x].push_back(y);
			g[y].push_back(x);
			rem[x]++;
			rem[y]++;
		}

		queue<int> q;

		f(i,0,n)
			if (rem[i] == 1)
			{
				q.push(i);
				layer[i] = 1;
			}

        vi vis(n,0);

        //Multi Source BFS kind of burning tree
		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int v : g[u])
			{
                if(vis[v]) continue;

				if (rem[v] != 1)
				{
					rem[v]--;
					if (rem[v] == 1) //get nodes a leaf level above current sources
					{
						layer[v] = layer[u] + 1;
                        //debug(v+1);
                        vis[v]=1;
						q.push(v);
					}
				}
			}
		}

		int ans = 0;
		f(i,0,n) 
			if (layer[i] > k) //survivors
				ans++;

		cout << ans << '\n';
	}

    }


/*   ll a, b;
    cin >> a >> b;
 
    vll graph[a + 1];
    vll degree(a + 1, 0);
 
    rep(i, a - 1)
    {
        ll c, d;
        cin >> c >> d;
        graph[c].push_back(d);
        graph[d].push_back(c);
        degree[c]++;
        degree[d]++;
    }
 
    queue<pair<ll, ll>> q;
 
    for (int i = 1; i <= a; i++)
    {
        if (degree[i] < 2)
            q.push({i, 1});
    }
 
    ll ans = a;
 
    while (q.size())
    {
        pair<ll, ll> cur = q.front();
        q.pop();
 
        if (cur.second > b)
        {
            break;
        }
 
        ans--;
        for (auto z : graph[cur.first])
        {
            degree[z]--;
            if (degree[z] == 1)
                q.push({z, cur.second + 1});
        }
    }
 
    cout << ans << endl; */