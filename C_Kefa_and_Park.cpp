#include<bits/stdc++.h>
using namespace std;
#define pyes cout << "YES\n";
#define pno cout << "NO\n";
#define int long long
#define vi vector <int>
#define pb push_back
#define F first
#define S second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}

const int NUM = 3e5 + 7;
vector<long long> a[NUM];
long long c[NUM],safe,i,n,m;
 
void go(int v,int pr,int k){

	if(k>m)return; //> consecutive m cats

	int chk=1;

	for (auto i : a[v])

    if(i!=pr){
        chk=0;
        go(i,v,k*c[i]+c[i]); //if c[i] is 1 we need previous k also along with the itself c[i] which is taken eitherways
    }

	safe+=chk; //adding leaf nodes while returning from them with k<=m
}
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	f(i,0,n){
        cin>>c[i];
    }

    f(i, 0, n-1) { 
        int u, v;
        cin >> u >> v;
        --u, --v;
        a[u].push_back(v); 
        a[v].push_back(u);
    }

	go(0,-1,c[0]);
	cout<<safe<<endl;
}


/* #include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int n = 1e5 + 5,m;
vvi adj(n);
vi a(n);
int ans = 0;
void dfs(int u,int p,int numC,int maxC)
{
    if (a[u])numC++;
    else numC = 0;
    maxC = max(maxC,numC);//now we know for each node the max # of 
    //consecutive cats in the path from 1 to that node
    int numChild = 0;
    for (int v:adj[u]){
        if (v != p){
            dfs(v,u,numC,maxC);
            numChild++;
        }
    }
    if (numChild == 0 && maxC <= m)ans++;
}
int main()
{
    setIO();
    cin>>n>>m;
    for (int i = 1;i<=n;i++)cin>>a[i];
    for (int i = 1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1,0,0);
    cout<<ans;
    return 0;
} */