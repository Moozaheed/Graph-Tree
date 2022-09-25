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
#define maxx 10000
#define LOG 14
#define EPS 1e-9
using namespace std;
const double PI = acos(-1);
ll int hp = 1e9+7;


//https://www.spoj.com/problems/LCASQ/
//Solution in O(n)

vector<int>adj[maxx];
int LCA[maxx][LOG];
int depth[maxx];
void dfs(int a)
{
    for(auto b:adj[a])
    {
        depth[b]=depth[a]+1;
        LCA[b][0]=a;
        for(int j=1;j<LOG;j++)
        {
            LCA[b][j]=LCA[LCA[b][j-1]][j-1];
        }
        dfs(b);
    }
}

int get_lca(int a,int b)
{
    if(depth[a]<depth[b])swap(a,b);

    while(depth[a]>depth[b])
    {
        a=LCA[a][0];
    }

    while(a!=b)
    {
        a=LCA[a][0];
        b=LCA[b][0];
    }

    return a;
}


void Boom()
{
    //Let's Move

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int cnt;
        cin>>cnt;
        for(int j=0;j<cnt;j++)
        {
            int c;
            cin>>c;
            adj[i].pb(c);
        }
    }

    dfs(0);

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<get_lca(a,b)<<dl;
    }







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

