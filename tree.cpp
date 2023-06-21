#include<bits/stdc++.h>
using namespace std;   // tree with any number of children using graph techniques

void dfs1(vector<int> v[], int visited[], int node){
    if(visited[node]==0){
        visited[node]=1;
        cout<<node<<" ";
        for(int i=0 ; i<v[node].size() ; i++){
            dfs1(v, visited, v[node][i]);
        }
    }
}

void dfs_tree(vector<int> v[], int node, int parent, int depth[], int height[]){
    for(int child : v[node]){
        if(child==parent){
            continue;
        }
        depth[child]=depth[node]+1;
        dfs_tree(v, child, node, depth, height);
        height[node]=max(height[node], height[child]+1);

    }
}

int main(){
    int n, m;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>m;

    vector<int> v[n+1]; 
    vector<int> useless={-1, -1, -1};
    v[0]=useless;
    cout<<"Enter "<<m<<" lines of pairs between which an edge exist"<<endl;
    for(int i=1 ; i<=m ; i++){
        int v1, v2;
        cin>>v1;
        cin>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    int visited[n+1];
    visited[0]=-1;
    for(int i=1 ; i<=n ; i++){
        visited[i]=0;
    }
    for(int i=1 ; i<=n ; i++){
        if(visited[i]==0){
            dfs1(v, visited, i);
        }
    }
    int depth[n+1];
    int height[n+1];
    for(int i=0 ; i<n+1 ; i++){
        depth[i]=0;
        height[i]=0;
    }
    dfs_tree(v, 1, 0, depth, height);
    for(int i=1 ; i<=n ; i++){
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
    cout<<endl;
    return 0;
}