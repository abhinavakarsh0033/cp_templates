int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u,v);
        int a = u, b = v;
    for(int i=0;i<19;i++)
        if((depth[u]-depth[v]) & (1<<i))
            u = par[u][i];
    if(u == v) {
        cout<<depth[a]-depth[b]<<'\n';
        continue;
    }
    for(int i=18;i>=0;i--)
        if(par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    u = par[u][0];
    return u;
}

void dfs(vector<vector<int>> &tree, vector<vector<int>> &par, vector<int> &depth, int u) {
    for(int i=1;i<19;i++)
        par[u][i] = par[par[u][i-1]][i-1];
    for(auto v: tree[u]) {
        if(!depth[v]) {
            depth[v] = depth[u] + 1;
            par[v][0] = u;
            dfs(tree,par,depth,v);
        }
    }
    return;
}