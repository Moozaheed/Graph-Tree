//subtree size

int subtree(int node)
{
    vis[node]=1;
    int curr_size=1;
    for(int child:adj[node])
    {
        if(vis[child]==0)
        {
            curr_size=curr_size+subtree(child)
        }
        subsize[node]=curr_size;
        return curr_size;
    }
}
