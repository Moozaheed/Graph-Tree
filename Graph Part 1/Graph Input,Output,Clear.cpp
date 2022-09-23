//total array

vector<ll int>adj[maxx];
bool vis[maxx];
//int level[maxx];


//grp input

ll int node,edge;
cin>>node>>edge;
for(ll int i=0;i<edge;i++)
{
    ll int n1,n2; 
    cin>>n1>>n2;
    adj[n1].push_back(n2);
    adj[n2].push_back(n1); 
}
 
//grp output

for(int i=0;i<node;i++)
{
    cout<<"Adjacent list of : "<<i<<"->";
    for(auto j:adj[i])
    {
        cout<<j<<" ";
    }
    cout<<endl;
}


//grp clear

for(int i=0;i<node;i++)
{
    adj[i].clear();
    vis[i]=0;
    //level[i]=0;
}


//grp input with cost

vector<pair<ll int,ll int>>adj[maxx];

ll int node,edge;
cin>>node>>edge;
for(ll int i=0;i<edge;i++)
{
    ll int n1,n2,cost; 
    cin>>n1>>n2>>cost;
    adj[n1].push_back({n2,cost});
    adj[n2].push_back({n1,cost}); 
}


//grp output with cost


for(int i=0;i<node;i++)
{
    for(auto x:adj[i])
    {
        cout<<i<<sp<<x.fi<<" weight "<<x.se<<dl;
    }
    cout<<endl;
}
