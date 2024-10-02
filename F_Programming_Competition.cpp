#include<bits/stdc++.h>
using namespace std;
#define pyes cout << "YES\n";
#define pno cout << "NO\n";
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

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
 
    while (t--) {
    
        int n;
        cin>>n;
 
        vector<vector<int>> adj(n);
 
        f(i,1,n)
        {
            int p;
            cin>>p;
 
            adj[p-1].pb(i);
        }
 
        vector<int> subtree(n);
 
        function<void(int)> dfs = [&](int u)   
        {
            subtree[u]++; 
            //directed tree doesnt need vis or i!=p for termination
  
            for(auto v: adj[u])
            {
                dfs(v);
                subtree[u] += subtree[v]; //count total elements in subtree including root
            }
        };
 
        dfs(0);
 
        int pair_total = 0;
 
        function<void(int, int)> dfs2 = [&](int u, int x)
        {
            pair_total += (x > 0);
 
            if(x > 0)       
            --x; //consume for probable pairing
 
            int tot = 0;

            for(auto v: adj[u])
                tot += subtree[v]; //count total elements in subtree excluding root
                //cout<<tot<<" v ";
 
            for(auto v: adj[u]){
                //cout<<x-tot-subtree[v]<<" ";

                //tot-subtree[v] additional nodes than x availaible for pairing 
                dfs2(v, x+tot-subtree[v]); 
            }
        };
 
        dfs2(0, 0);
 
        cout<<floor(double(pair_total)/double(2))<<endl;
    }
}
