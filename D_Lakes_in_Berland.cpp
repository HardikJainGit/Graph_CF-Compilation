#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v; //to store coordinates of . for a particular lake

int dfs2(int i,int j,int n,int m,vector<vector<char>>& grid){ //get size of lake
    if(i==n || j==m || i<0 || j<0 || grid[i][j]=='*'){
        return 0;
    }
    grid[i][j] = '*';
    v.push_back({i,j});

    int sz = 1 + 
            dfs2(i+1,j,n,m,grid) + 
            dfs2(i-1,j,n,m,grid) + 
            dfs2(i,j+1,n,m,grid) + 
            dfs2(i,j-1,n,m,grid);

    return sz;
}

void dfs(int i,int j,int n,int m,vector<vector<char>>& grid){
    if(i==n || j==m || i<0 || j<0 || grid[i][j]=='*'){
        return;
    }
    grid[i][j] = '*';

    dfs(i+1,j,n,m,grid);
    dfs(i-1,j,n,m,grid);
    dfs(i,j+1,n,m,grid);
    dfs(i,j-1,n,m,grid);
}

void solve(int tc){
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<char>> grid(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }       

    auto finalGrid = grid;

    //Lets resolve borders -> make border . to *
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || j==0 || i==n-1 || j==m-1) && (grid[i][j]=='.')){
                dfs(i,j,n,m,grid);
            }
        }
    }


    vector<pair<int,vector<pair<int,int>>>> data; //(lake sz , vector of coordinates)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                v.clear();
                int sz = dfs2(i,j,n,m,grid);
                data.push_back(make_pair(sz,v));
            }
        }
    }

    sort(data.begin(),data.end()); //cause we need decreasing sz of lakes

    int currLakes = data.size();

    int cnt = currLakes;

    int changes = 0;

    for(auto el:data){
        if(cnt==k){
            break;
        }
        changes += el.second.size();
        for(auto coord:el.second){
            finalGrid[coord.first][coord.second] = '*';
        }
        cnt--;
    }

    cout<<changes<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<finalGrid[i][j];
        }
        cout<<endl;
    }
}

int main() {

    int tt = 1;
    for(int i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}