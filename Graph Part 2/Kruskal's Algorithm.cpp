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

// O(ElogV)

ll int parent[maxx];
ll int size[maxx];
bool ok;
ll int find(ll int a)
{
    if(parent[a]==a)return a;
    return parent[a]=find(parent[a]);
}

void unioon (ll int a, ll int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
    else ok=true;
}


bool comp(vi x, vi y)
{
    if(x[2]<y[2]) return true;
    return false;
}





void Boom()
{
    //Let's Move

    ll int n,m;
    cin>>n>>m;

    for(ll int i=0;i<=maxx;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    vector<vi>edges;

    for(ll int i=0;i<m;i++)
    {
        ll int x,y,z;
        cin>>x>>y>>z;
        edges.pb({x,y,z});
    }

    sort(all(edges),comp);
    
    // for(auto x:edges)
    // {
    //     cerr<<x[0]<<sp<<x[1]<<dl;
    // }

    ll int cost=0;

    for(auto i:edges)
    {
        ll int x=i[0];
        ll int y=i[1];
        ll int z=i[2];

        ll int p=find(x);
        ll int q=find(y);

        if(p==q)continue;
        else
        {
            cout<<x<<sp<<y<<dl;
            cost+=z;
            unioon(x,y);
        }
    }



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


//Input: 
// 8 9
// 1 2 5
// 2 3 6
// 4 3 2
// 1 4 9
// 3 5 5
// 5 6 10
// 6 7 7
// 7 8 1
// 8 5 1
