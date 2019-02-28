#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
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

ll k[50+1][4];
ll dp[50+1][4];
int n;

ll fin(int l,int x,int y)
{
    ll m=INF,mi=-1;
    rep(i,1,n+1)
    {
        if(i!=x && i!=y && k[i][l]<m)
        {
            m=min(k[i][l],m);
            mi=i;
        }
    }
    return mi;
}

ll MIN(int x,int y,int z)
{
    int a1=fin(x,-1,-1);
    int b1=fin(y,a1,-1);
    int c1=fin(z,a1,b1);
    if(a1==-1 || b1==-1 || c1==-1)
        return INF;
    ll add=k[a1][x]+k[b1][y]+k[c1][z]-min(k[a1][1],min(k[a1][2],k[a1][3]))-min(k[b1][1],min(k[b1][2],k[b1][3]))-min(k[c1][1],min(k[c1][2],k[c1][3]));
    return add;
}

int main()
{

    // Approach to AC
    // Find the minimum path ---> min(dp[n][1],min(dp[n][2],dp[n][3]))
    // Then find the indices a1, b1, c1 such that a1!=b1!=c1 and they are also minimum for alphabet, numeral and symbol respectively
    // Here the order of finding a1, b1, c1 also need to be considered
    // Now add these costs and subtract the minimum cost for these indices from answer
    
    ll m;
    cin>>n>>m;
    rep(i,1,n+1)
    {
        k[i][1]=k[i][2]=k[i][3]=INF;
        dp[i][1]=dp[i][2]=dp[i][3]=INF;
    }
    rep(i,1,n+1)
    {
        string s;cin>>s;
        rep(j,0,m)
        {
            if(s[j]>='a' && s[j]<='z')
                k[i][1]=min(k[i][1],j);
            else if(s[j]>='0' && s[j]<='9')
                k[i][2]=min(k[i][2],j);
            else if(s[j]=='*' || s[j]=='#' || s[j]=='&')
                k[i][3]=min(k[i][3],j);
        }

        for(int j=m-1;j>=0;j--)
        {
            if(s[j]>='a' && s[j]<='z')
                k[i][1]=min(k[i][1],m-j);
            else if(s[j]>='0' && s[j]<='9')
                k[i][2]=min(k[i][2],m-j);
            else if(s[j]=='*' || s[j]=='&' || s[j]=='#')
                k[i][3]=min(k[i][3],m-j);
        }
    }

    rep(i,1,n+1)
    {
        dp[i][1]=k[i][1]+min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
        dp[i][2]=k[i][2]+min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
        dp[i][3]=k[i][3]+min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
    }

    ll add=min(MIN(1,2,3),MIN(1,3,2));
    add=min(MIN(2,3,1),min(add,MIN(2,1,3)));
    add=min(add,min(MIN(3,1,2),MIN(3,2,1)));
    ll ans=min(dp[n][1],min(dp[n][2],dp[n][3]))+add;
    cout<<ans<<endl;
}
