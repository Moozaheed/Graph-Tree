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
#define maxx 105
#define EPS 1e-9
using namespace std;
const double PI = acos(-1);
ll int hp = 1e9+7;


bool vis[maxx][maxx];
int dist[maxx][maxx];
int dirx[8] ={-2,-1,1,2,2,1,-1,-2};
int diry[8] ={1,2,2,1,-1,-2,-2,-1};

int ROW=35;
int COL=35;
int tarX,tarY;
bool isValid(int row, int col)
{
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return false;
    if (vis[row][col])
        return false;
    return true;
}

void bfs(int srcX, int srcY)
{
    queue<pair<int, int> > q;
    q.push(make_pair(srcX, srcY));
    dist[srcX][srcY]=0;
    vis[srcX][srcY]=1;
    
    //if(srcX==tarX && srcY==tarY)return;

    while (!q.empty()) 
    {
        pair<int, int> curr = q.front();
        q.pop();

        int row = curr.first;
        int col = curr.second;

       for (int i = 0; i < 8; i++)
        if(isValid(row+dirx[i],col+diry[i]))
        {
            int adjx = row + dirx[i];
            int adjy = col + diry[i];

            dist[adjx][adjy]=dist[row][col]+1;
            vis[adjx][adjy]=1;

            q.push({ adjx, adjy });
        }
    }
}

void Boom()
{
    //Let's Move

    bfs(1,1);

    cin>>tarX>>tarY;
    cout<<dist[tarX][tarY]<<dl;


}

int main()
{
    Boost;


    int t=1;      //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<" : ";
        Boom();
    }

    return 0;

}
