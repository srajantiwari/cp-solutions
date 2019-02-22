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
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
#define N                   100005
ll MOD=pow(10,9)+7;
ll INF=1ll<<60;

int main()
{
    int n;cin>>n;
    char arr[n+1];
    cin>>arr;
    ll cost[n+1];
    rep(i,1,n+1)
    cin>>cost[i];

    ll dp[n+1][4];mem(dp,0);
    // dp[i][j] : minimum ambiguity until ith element such the prefix ubtil j of string "hard"
    // dp[i][2] : minimum ambiguity in the given string until the ith index when only "ha" is taken into consideration
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            dp[i][j] = dp[i-1][j];

            if(arr[i-1] == 'h') 
            {
                dp[i][0] = dp[i-1][0] + cost[i]; // remove all 'h' before ith index
            }
            else if(arr[i-1] == 'a'){
                dp[i][1] = min(dp[i-1][0], dp[i-1][1] + cost[i]); // either remove this 'a' and add cost to the previous cost of dealing with 'a's or remove 'h' before ith index
            }
            else if(arr[i-1] == 'r'){
                dp[i][2] = min(dp[i-1][1],dp[i-1][2] + cost[i]); // either add the cost of removal of this 'r' with cost of dealing with the previous 'r's or remove the 'a's
            }
            else if(arr[i-1] == 'd'){
                dp[i][3] = min(dp[i-1][2],dp[i-1][3] + cost[i]); // either add cost for removal of 'd' or cost of removing 'r's
            }
        }
    }
    cout<<dp[n][3]<<endl;
}
