///https://assessment.hackerearth.com/challenges/college/codemania-20/algorithm/owl-fight/

///Maximum Parent


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


ll int par[maxx];

int finds(int a)
{
    if(par[a]<0)return a;
    return par[a]=finds(par[a]);
    
}

int unions(int a,int b)
{
    par[a]=min(par[a],par[b]);
    par[b]=a;
}

void Boom()
{
    int n,m,x,y,a,b,i,q;
    cin>>n>>m;

    for(i=1;i<=n;i++)par[i]=-i;

    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        a=finds(a);
        b=finds(b);
        if(a!=b)unions(a,b);
    }

    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        a=x,b=y;
        a=finds(a);
        b=finds(b);
        if(a==b)cout<<"TIE"<<dl;
        else{
            if(par[a]<par[b])
            {
                cout<<x<<dl;
            }
            else cout<<y<<dl;
        }
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
