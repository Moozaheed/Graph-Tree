//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define pob pop_back
#define in insert
#define vi vector<ll int>
#define vs vector<string>
#define pii pair<ll int,ll int>
#define psi pair<string,ll int>
#define pis pair<ll int,string>
#define mii map<ll int,ll int>
#define mib map<ll int,bool>
#define msi map<string,ll int>
#define mis map<ll int,string>
#define S string
#define fi first
#define se second
#define sp ' '
#define dl "\n"
#define all(data) data.begin(),data.end()
#define b() begin()
#define e() end()
#define cY cout<<"YES\n"
#define cN cout<<"NO\n"
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define setp(n) setprecision(n)
#define mem(arr,val) memset(arr,val,sizeof(arr));
#define debug(x) cerr<<x<<dl;
#define here fprintf(stderr, "====I am Here====\n");
#define FOR(data) for(auto it=data.begin();it!=data.end();it++)
#define Boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define maxx 100005
#define EPS 1e-9
using namespace std;
const double PI = acos(-1);
ll int hp = 1e9+7;


vector<pair<ll int,ll int>>adj[maxx];
bool vis[maxx];
ll int dist[maxx];
ll int parent[maxx];
ll int cost;
ll int node,edge;

void primsMST(int source)
{
    for(int i=1;i<=node;i++)
    {
        dist[i]=hp;
    }
    set<pair<ll int,ll int>>s;

    dist[source]=0;
    s.insert({0,source});

    while(!s.empty())
    {
        auto x=*(s.b());
        s.erase(x);
        vis[x.se]=true;

        ll int u=x.se;
        ll int v=parent[x.se];
        ll int w=x.fi;

        cout<<u<<sp<<v<<sp<<w<<dl;
        cost+=w;

        for(auto it:adj[x.se])
        {
            if(vis[it.fi])continue;
            if(dist[it.fi]>it.se)
            {
                s.erase({dist[it.fi],it.fi});
                dist[it.fi]=it.se;
                s.insert({dist[it.fi],it.fi});
                parent[it.fi]=x.se;
            }
        }
    }
}



void Boom()
{
    //Let's Move


    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        int n1,n2,cost;
        cin>>n1>>n2>>cost;
        adj[n1].push_back({n2,cost});
        adj[n2].push_back({n1,cost});
    }
    

    primsMST(1);

    cout<<cost<<dl;





}

int main()
{

    Boost;

    int t=1;     // cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<" : ";
        Boom();
    }

    return 0;

}


// Input: 
// 4 5
// 0 1 10
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40