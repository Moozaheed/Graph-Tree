//cycle detection

bool cycledet(int node ,int par)
{
    vis[node]=1;
    for(int child:adj[node])
    {
        if(vis[child]==0)
        {
            if(cycledet(child,node)==true)return true;
        }
        else 
        if(child!=par)return true;
    }
    return false;
}


///Cycle detection for directed graph


bool st[maxx];
bool cycledet(int node,int par)
{
    st[node]=1;
    vis[node]=1;
    for(int child:adj[node])
    {
        if(vis[child]==0)
        {
            if(cycledet(child,node)==true)return true;
        }
        if(st[child])return true;
    }
    st[node]=0;
    return false;

}