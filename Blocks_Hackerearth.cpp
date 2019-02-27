#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define repb(i,a,b)         for(ll i=a;i>=b;i--)
#define f(n)                for (ll i=0;i<n;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define tr(c,it)            for(((c).begin())it=(c).begin();it!=(c).end();it++)
#define xlr8                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
ll MOD=pow(10,9)+7;
ll INF=1e18+10;

const int N=200005;
ll segt[4*N];
ll lazy[4*N];
ll a[N];

void build(int v,int i,int j)
{
    if(i==j)
        segt[v]=a[i];
    else
    {
        int mid=(i+j)/2;
        build(2*v,i,mid);
        build(2*v+1,mid+1,j);
        segt[v]=max(segt[2*v],segt[2*v+1]);
    }
}

void updateRange(int v,int l,int r,int i,int j,int val)
{
    if(j<l || i>r || i>j)
        return;
    if(lazy[v]!=0)
    {
        segt[v]=lazy[v];
        if(i!=j)
        {
            lazy[2*v]=lazy[v];
            lazy[2*v+1]=lazy[v];
        }
        lazy[v]=0;
    }

    if(l<=i && j<=r)
    {
        segt[v]=val;
        if(i!=j)
        {
            lazy[2*v]=val;
            lazy[2*v+1]=val;
        }
    }
    else
    {
        int mid=(i+j)/2;
        updateRange(2*v,l,r,i,mid,val);
        updateRange(2*v+1,l,r,mid+1,j,val);
        segt[v]=max(segt[2*v],segt[2*v+1]);
    }
}

ll query(int v,int l,int r,int i,int j)
{
    if(j<l || i>r || i>j)
        return -INF;

    if(lazy[v]!=0)
    {
        segt[v]=lazy[v];
        if(i!=j)
        {
            lazy[2*v]=lazy[v];
            lazy[2*v+1]=lazy[v];
        }
    }

    if(l<=i && j<=r)
        return segt[v];
    int mid=(i+j)/2;
    ll p1=query(2*v,l,r,i,mid);
    ll p2=query(2*v+1,l,r,mid+1,j);
    return max(p1,p2);
}

int main()
{
    int n;cin>>n;
    rep(i,0,n)
    {
        int l,h,p,c,x;
        cin>>l>>h>>p>>c>>x;
        if(c==0)
        {
            // we have two options either the whole segment will be placed higher than the highest peak in segement
            // or at same height
            ll h1=query(1,x+p-1,x+p-1,1,N);
            ll h2=query(1,x,x+l-1,1,N);
            if(h1+h>=h2)                            // when all are placed at height = height of highest peak in segment
                updateRange(1,x,x+l-1,1,N,h1+h+1);
            else                                    // when segment was allocated a height higher than highest peak because it was supported by some other segment
                updateRange(1,x,x+l-1,1,N,h2+1);
        }
        else
        {
            // here we have single option segment will be placed at same height except the highest peak
            ll h1=query(1,x,x+l-1,1,N);
            updateRange(1,x,x+l-1,1,N,h1+1);
            updateRange(1,x+p-1,x+p-1,1,N,h1+h+1);
        }
    }
    
    // answer will be the highest peak after placing the segments
    cout<<query(1,1,N,1,N)<<endl;
}
