
//Finding  Brideges

int in[maxx],low[maxx];
bool vis[maxx];
int timer=0;
void dfs (int node,int par) //dfs(1,-1)
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    for(int child : adj[node])
    {
        if(child==par)continue;
        if(vis[child]==1)
        {
            //edge node - child is a back edge
            low[node]=min(low[node],in[child]);
        }
        else
        {
            // edge node -child forward edge
            dfs(child,node);
            if(low[child]>in[node])
                cout<<node<<sp<<child<<" is  a Brideges"<<endl;

            low[node]=min(low[node],in[child]);
        }
    }
}



