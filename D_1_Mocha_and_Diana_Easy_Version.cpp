#include <bits/stdc++.h>
using namespace std;

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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t=1;
    while (t--) {
    int n,m1,m2;
    cin>>n>>m1>>m2;
    DSU val1(n + 1),val2(n + 1);
    vvi a;
    while (m1--){
        int u,v;
        cin>>u>>v;
        val1.Merge(u,v); //merge nodes in forest 1
    }
    while (m2--){
        int u,v;
        cin>>u>>v; 
        val2.Merge(u,v); //merge nodes in forest 2
    }
    int ans = 0;
    for (int i = 1;i<=n;i++){
        for (int j =1;j<=n;j++){
            if (val1.Find(i) != val1.Find(j) && val2.Find(i) != val2.Find(j)){ //if <i,j> is in different cc for both forest make edge
                val1.Merge(i,j);
                val2.Merge(i,j);
                a.pb({i,j});
                ans++;
            }
        }
    }
    
    pr(ans);

    for (auto it:a)cout<<it[0]<<" "<<it[1]<<endl;
    }
}
