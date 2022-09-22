//https://www.hackerearth.com/problem/algorithm/teachers-dilemma-3-00955296/


///Path Compresion at Find Function


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



//  O(logn) Complexcity

ll int parent[maxx];

ll int find(ll int a) 
{
    if(parent[a]<0)return a;
    return parent[a]=find(parent[a]);
}

void unioon (ll int a, ll int b) 
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        parent[a]+=parent[b];
        parent[a]%=hp;
        parent[b]=a;
    }
}




void Boom()
{
    //Let's Move
    
    ll int n,m;
    cin>>n>>m;

    for(ll int i=0;i<=n;i++)parent[i]=-1;

    for(ll int i=0;i<m;i++)
    {
        ll int x,y;
        cin>>x>>y;
        unioon(x,y);
    }
    
    ll int ans=1;
    for(ll int i=1;i<=n;i++)
    {
        if(parent[i]<0)
        {
            //cerr<<parent[i]<<sp;
            ans*=(parent[i]*(-1))%hp;
            ans%=hp;
        }
    }

    cout<<ans<<dl;

      




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
