//dfs

void dfs(int v)
{
    vis[v]=1;
    //cout<<v<< "->";
    for(auto child:adj[v])
    {
        if(!vis[child]) dfs(child);
    }
}