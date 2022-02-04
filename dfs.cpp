#include <bits/stdc++.h>

bool hasAPath(vector<vector<int>> edges, int source, int destination, int n){
    
    vector<vector<int>> adjList(n);

    for(vector<int> edge:edges){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    
    stack<int> s;
    s.push(source);
    vector<int> vis(n,0);

    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(node == destination) return true;

        if(vis[node] == 1) continue;

        vis[node] = 1;

        for(int neighbour: adjList[node]){
            s.push(neighbour);
        }
    }
    return false;
}


int main() {
    int n,m,s,d,a;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(2,0));
    cout<<"[";
    for (int i=0; i<m; i++) {
        cout<<"[";        
        cin>>a;
        edges[i][0] = a;
        cin>>a;
        edges[i][1] = a;
        cout<<edges[i][0]<<","<<edges[i][1]<<"]";
    }
    cout<<"]\n";
    cin>>s>>d;
    cout<<n<<" "<<s<<" "<<d<<" ";
    if (hasAPath(edges,s,d,n))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}