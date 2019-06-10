#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define repb(i,a,b)         for(ll i=a;i>=b;i--)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define tr(c,it)            for(auto const &it : c)
#define xlr8                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
ll MOD=pow(10,9)+7;//998244353
ll INF=1e18+10;

const int N=10005;
vector <pair<ll,ll>> adj[N];
bool vis[N];
ll d[N];
ll n,m;

void dijkstra(int s)
{
    d[s]=0;

    rep(i,1,n+1)
    {
        int v=-1;
        rep(j,1,n+1)
        {
            if(!vis[j] && (v==-1 || d[j]<d[v]))
                v=j;
        }

        if(d[v]==INF)
            break;

        vis[v]=1;

        for(auto edge : adj[v])
        {
            int to=edge.F;
            int len=edge.S;

            if(d[to]>(d[v]+len))
            {
                d[to]=d[v]+len;
                //p[to]=v;
            }
        }
    }
}

int main()
{
    xlr8;

    int t;cin>>t;
    while(t--)
    {
        rep(i,1,N)
        d[i]=INF;
        cin>>n>>m;
        rep(i,0,m)
        {
            int a,b,c;cin>>a>>b>>c;
            adj[a].pb(mp(b,c));
        }
        int a,b;cin>>a>>b;

        dijkstra(a);
        d[b]!=INF ? cout<<d[b]<<endl : cout<<"NO\n";
        mem(vis,0);
        //mem(p,0);
        rep(i,0,n+1)
        adj[i].clear();

    }
}
