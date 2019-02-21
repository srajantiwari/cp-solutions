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

int main()
{
    ll sr,su;cin>>sr>>su;
    ll dr,du;cin>>dr>>du;
    ll n;cin>>n;

    char s[n];
    cin>>s;
    
    // prefix sums for right and up direction which store the coordinates of the ship as per the wind
    // consider the ship is intially at (0,0)
    // they store its position w.r.t (0,0) then change the coordinates as per the starting point
    // and you get the coordinates of the ship when the wind is moving at any ith day
    ll u[n+1],r[n+1]; 
    mem(u,0);mem(r,0);
    rep(i,0,n)
    {
        if(s[i]=='U')
            u[i+1]=u[i]+1;
        else if(s[i]=='D')
            u[i+1]=u[i]-1;
        else
            u[i+1]=u[i];

        if(s[i]=='R')
            r[i+1]=r[i]+1;
        else if(s[i]=='L')
            r[i+1]=r[i]-1;
        else
            r[i+1]=r[i];
    }

    ll lo=1,hi=INF;
    while(lo<hi)
    {
        ll mid=lo+(hi-lo)/2;             // suppose the "mid" is minimum number of moves you need --- answer to the question
        
        ll tim=mid/((long double)n);
        ll rem=mid % n;
        
        ll winr=r[n]*tim+r[rem];        // right moves you could have done remaining at stay at your initial position
        ll winu=u[n]*tim+u[rem];        // up moves you could have done remaining at stay at your position
        
        ll rmov=dr-sr;                  // right moves you need to do if there was no wind
        ll umov=du-su;                  // up moves you need to do if there was no wind
        
        ll nrmov=rmov-winr;             // number of right moves you actually need when the wind is moving as per the given string
        ll numov=umov-winu;             // number of up moves you actually need when the wind is moving as per the given string
        
        if((abs(nrmov)+abs(numov))>mid) 
            lo=mid+1;                   // unable to reach destination in moves = mid
        
        else
            hi=mid;                     // if we can reach the destination in moves = mid, maybe we can also reach destination in (lo+mid)/2
        
    }
    if(lo!=INF)
        cout<<lo<<endl;                // answer
    else
        cout<<-1<<endl;                // you need more than INF moves, you gotta be kidding me !!! (You can't reach your destination)
}
