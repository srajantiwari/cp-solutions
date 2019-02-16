#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define repb(i,a,b)         for(ll i=a;i>=b;i--)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define tr(c,it)            for(auto const & it : c)
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
#define HT                  1000005
ll MOD=pow(10,9)+7;
ll INF=1e18;
const int N=200001;
ll segt[4*N];

void build(int v,int i,int j)
{
    if(i==j)
        segt[v]=1;
    else
    {
        int mid=(i+j)/2;
        build(2*v,i,mid);
        build(2*v+1,mid+1,j);
        segt[v]=segt[2*v]+segt[2*v+1];
    }
}

ll solve(int v,int l,int r,int i,int j)
{
    if(i>r || j<l || i>j)
        return 0;
    else if(l<=i && j<=r)
        return segt[v];
    int mid=(i+j)/2;
    ll p1=solve(2*v,l,r,i,mid);
    ll p2=solve(2*v+1,l,r,mid+1,j);
    return p1+p2;
}

void update(int v,int pos,int val,int i,int j)
{
    if(i==j)
        segt[v]=val;
    else
    {
        int mid=(i+j)/2;
        if(pos<=mid)
            update(2*v,pos,val,i,mid);
        else
            update(2*v+1,pos,val,mid+1,j);
        segt[v]=segt[2*v]+segt[2*v+1];
    }
}

int main()
{
    ll n;cin>>n;
    ll a[n+1];
    vector <int> v[n+1];
    rep(i,1,n+1)
    {
        cin>>a[i];
        a[i]=min(n,a[i]);
        v[a[i]].pb(i);
    }

    ll ans=0;

    build(1,1,n);
    rep(i,1,n+1)
    {
        ans+=solve(1,i+1,a[i],1,n);
        tr(v[i],it)
        {
            update(1,it,0,1,n);
        }
    }
    cout<<ans<<endl;
}
