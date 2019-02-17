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

int dp[5001][5001][2]; // dp[start][end][colour of start index/end index]
int a[5001];

ll rec(int l,int r,int ch)
{
    if(l==r)
        return 0; when start == end then this is the starting index and you won't have to make any changes
        
    if(dp[l][r][ch]!=-1)
        return dp[l][r][ch];
        
    //when you take ending index colour then you have two options either you choose the end index/start index colour option from start to end-1
    dp[l][r][1]=min(rec(l,r-1,0)+(a[l]!=a[r]),rec(l,r-1,1)+(a[r-1]!=a[r]));
    
    //when you take start index colour then you have two options either you choose the end index/start index colour option from start+1 to end
    dp[l][r][0]=min(rec(l+1,r,0)+(a[l+1]!=a[l]),rec(l+1,r,1)+(a[r]!=a[l]));
    
    return dp[l][r][ch];
}

int main()
{
    ll n;cin>>n;
    rep(i,1,n+1)cin>>a[i];
    mem(dp,-1);
    rec(1,n,0);
    rec(1,n,1);
    cout<<min(rec(1,n,0),rec(1,n,1))<<endl;
}
