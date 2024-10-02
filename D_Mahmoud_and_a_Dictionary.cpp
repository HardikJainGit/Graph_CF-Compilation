#include <bits/stdc++.h>
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
struct DSU
{
    int n;
    vi p;
    DSU(int _n)
    {
        n = _n;
        p.assign(2 * n,0);
        for (int i = 0;i<=2 * n - 1;i++)p[i] = i;//0 to n - 1 
        // and n to 2n - 1
            //0 to n - 1 represents the friend leaders
            //and n to 2n - 1 represents the enemy leaders
    }
    int Find(int i)
    {
        if (p[i] == i)return p[i];
        return p[i] = Find(p[i]);
    }
    bool areFriends(int u,int v)
    {
        return Find(u) == Find(v);//Find(u) gives the friend leader of u
        //and Find(v) gives the enemy leader of v
    }
    bool areEnemies(int u,int v)
    {
        return Find(u) == Find(n + v) || Find(u + n) == Find(v);
        //Find(u + n) gives the enemy leader of u
        //because the enemy leader of 0 is n, 1 is n + 1,2 is n + 2,
        //... n - 1 is n - 1 + n
    }
    void MergeFriends(int u,int v)
    {
        int fu = Find(u),fv = Find(v),eu = Find(u + n),ev = Find(v + n);
        p[fv] = fu;
        p[ev] = eu;
    }
    void MergeEnemies(int u,int v)
    {
        int fu = Find(u),fv = Find(v),eu = Find(u + n),ev = Find(v + n);
        p[fv] = eu;
        p[ev] = fu;
    }
};
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    DSU val(n);
    map<string,int>pos;//pos[S] = i means that the element
    //at position i in the array of strings is S
    for (int i = 0;i<n;i++){string s;cin>>s;pos[s] = i;}

    while (m--){
        int t;
        string a,b;
        cin>>t>>a>>b;
        int u = pos[a],v = pos[b];
        if (t == 1){
            if (!val.areEnemies(u,v)){
                val.MergeFriends(u,v);
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else{
            if (!val.areFriends(u,v)){
                val.MergeEnemies(u,v);
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    while (q--){
        string a,b;
        cin>>a>>b;
        int u = pos[a],v = pos[b];
        if (val.areFriends(u,v))cout<<1<<endl;
        else if (val.areEnemies(u,v))cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}