#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define repb(i,a,b)         for(ll i=a;i>=b;i--)
#define f(n)                for (ll i=0;i<n;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define tr(c,it)            for(const auto & it : c)
#define xlr8                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
ll MOD=pow(10,9)+7;
ll INF=1e18+10;

// using bitset for storing elements as indices in bitset
// using set Time-Outs

const int N=100000;
bitset <5001> seg1[4*N],seg2[4*N];
int a[N];
int b[N];

void build(int v,int i,int j)
{
    if(i==j)
    {
        seg1[v].set(a[i]);
        seg2[v].set(b[i]);
    }
    else
    {
        int mid=(i+j)/2;
        build(2*v,i,mid);
        build(2*v+1,mid+1,j);
        seg1[v]=seg1[2*v]|seg1[2*v+1];
        seg2[v]=seg2[2*v]|seg2[2*v+1];
    }
}

bitset<5001> query1(int v,int l,int r,int i,int j)
{
    bitset <5001> res;
    if(j<l || i>r || i>j)
        return 0;
    if(l<=i && j<=r)
        return seg1[v];
    else
    {
        int mid=(i+j)/2;
        bitset<5001> p1=query1(2*v,l,r,i,mid);
        bitset<5001> p2=query1(2*v+1,l,r,mid+1,j);
        res=p1|p2;                                  // sets the bits which are set in both the bitsets of left and right child
        return res;
    }
}

bitset<5001> query2(int v,int l,int r,int i,int j)
{
    bitset<5001> res;
    if(j<l || i>r || i>j)
        return 0;
    if(l<=i && j<=r)
        return seg2[v];
    else
    {
        int mid=(i+j)/2;
        bitset<5001> p1=query2(2*v,l,r,i,mid);
        bitset<5001> p2=query2(2*v+1,l,r,mid+1,j);
        res=p1|p2;                                    // sets the bits which are set in left and right child
        return res;
    }
}

int main()
{
    xlr8;
    int n;cin>>n;
    rep(i,0,n)
    cin>>a[i];
    rep(i,0,n)
    cin>>b[i];

    build(1,0,n-1);

    int q;cin>>q;
    while(q--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        bitset<5001> p1=query1(1,l1-1,r1-1,0,n-1);
        bitset<5001> p2=query2(1,l2-1,r2-1,0,n-1);
        bitset<5001> res=p1|p2;
        cout<<res.count()<<"\n";                        // returns the count in bitset which is the answer
    }
}
