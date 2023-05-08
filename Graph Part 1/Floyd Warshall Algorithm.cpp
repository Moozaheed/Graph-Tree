///https://atcoder.jp/contests/abc073/tasks/abc073_d


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
#define maxx 250
#define EPS 1e-9
using namespace std;
const double PI = acos(-1);
ll int hp = 1e9+7;
const int INF = 1000000;

int r[maxx], p[maxx], dist[maxx][maxx];

int main()
{
    int n,m,k;
	cin >> n >> m >> k;
	for(int i=0; i<k; i++)
    {
		cin >> r[i];
		r[i]--;
	}

	for(int i=0; i<n; i++)
    {
		for(int j=0; j<n; j++)
        {
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for(int i=0; i<m; i++)
    {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		dist[a][b] = dist[b][a] = c;
	}

	for(int k=0; k<n; k++)
    {
		for(int i=0; i<n; i++)
        {
			for(int j=0; j<n; j++)
            {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

//  for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (dist[i][j] == INF)
//                 cerr << "INF"
//                      << " ";
//             else
//                 cerr << dist[i][j] << "   ";
//         }
//         cerr << endl;
//     }



	int ans = INF;
	for(int i=0; i<k; i++){
		p[i] = i;
	}
	do{
		int c = 0;
		for(int i=1; i<k; i++){
			c += dist[r[p[i-1]]][r[p[i]]];
		}
		ans = min(ans, c);
        // for(int i=0;i<k;i++)cerr<<p[i]<<sp;
        // cerr<<dl;
        // cerr<<c<<dl;
	}while(next_permutation(p, p+k));
	cout << ans << endl;
}
