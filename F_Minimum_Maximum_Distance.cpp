#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector < int > bfs(int start, vector < vector < int > > &tree) {
    queue < int > q;
    q.push(start);
    vector < int > dist(tree.size()+1,-1);
    dist[start] = 0;
    while(!q.empty()) {
        int parent = q.front();
        q.pop();
        for(auto i : tree[parent]) {
            if(dist[i]==-1) {
                 dist[i] = dist[parent] + 1;
                 q.push(i);
            }
        }
    }
    return dist;
}

int main()
{   

    int t;
    cin>>t;
    while(t--) {
        int n,k,u,v;
        cin>>n>>k;
        vector < int > marked(k),dist;
        vector < vector < int > > tree(n+1, vector < int > (0));
        for(int i = 0 ; i < k ; i++) {
            cin>>marked[i];
        }
        for(int i = 0 ; i < n-1 ; i++) {
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        if(k == 1) {
            cout<<0<<endl;
            continue;
        }
        dist = bfs(marked[0],tree);
        int first_farthest_marked = -1,maxi = 0;
        for(int i = 0 ; i < marked.size(); i++) {
           
            if(dist[marked[i]] > maxi) {
                maxi = dist[marked[i]];
                first_farthest_marked = marked[i];
            }
        }
        
        dist = bfs(first_farthest_marked,tree);
        maxi = 0;
        for(int i = 0 ; i < marked.size(); i++) {
            if(dist[marked[i]] > maxi) {
                maxi = dist[marked[i]];
            }            
        }
        cout<<ceil(double(maxi)/double(2))<<endl;
    }
    return 0;     
 }

 /* #include<bits/stdc++.h>
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

vector<vector<int>> g;

void dfs( int node,int p,vector<int> &d) {
    
    //component.push_back(node);
    //visited[node] = 1; 
    if(p!=-1){
        d[node]=d[p]+1;
    }

    for(auto i : g[node]) {
        if(i!=p) {
            dfs(i,node,d);  recursive call stk
        } 
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int k;
        int n;

		cin>>n>>k;
		g.assign(n, vector<int>(0));
		vector<int> marked(k);
		for(int &e: marked) cin >> e, --e; //marked vertices' indexes and convert to base 0

		for(int i=1;i<n;i++){ //n-1 edges
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v); //converting to base 0 indexing
			g[v].push_back(u);
		}
		if(k==1){
			cout<<0<<"\n";
			continue;
		}

        //First dfs 
        vector<int> d1(n,0);

        dfs(marked[0], -1, d1);
		int mx = marked[0];
		for(int e: marked){
		    if(d1[e] > d1[mx]) mx = e;
		}
		vector<int> d2(n,0);
		dfs(mx, -1, d2);
		mx = marked[0];
		for(int e: marked){
		    if(d2[e] > d2[mx]) mx = e;
		}
		cout << ceil(double(d2[mx])/double(2)) << endl;
	}
	return 0;
} */