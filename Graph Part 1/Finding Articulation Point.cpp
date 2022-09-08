

//Theory From Abudl Bari
//Code From CP Algorithm


int in[maxx],low[maxx];
bool color[maxx];
int timer=0;

void dfs(int node, int p = -1) 
{


    color[node] = true;
    in[node] = low[node] = timer++;
    int children=0;
    for (int child : adj[node]) 
    {
        if (child == p) continue;

        if (color[child]) 
        {
            low[node] = min(low[node], in[child]);
        } 
        else 
        {
            dfs(child, node);

            low[node] = min(low[node], low[child]);

            if (low[child] >= in[node] && p!=-1)
            {
                //node is an Articulation Point
                cout<<node<<endl;
            }

            ++children;
        }
    }
    if(p == -1 && children > 1)
    {
        //node is an Articulation Point
        cout<<node<<endl;
    }
}


//For Main Function
// memset(low,-1)
// memset(in,-1)
// dfs(1);