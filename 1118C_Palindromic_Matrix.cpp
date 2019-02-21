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

int fr[1001];               // stores the frequency of the numbers (a[i])
int ans[21][21];            // answer to the question
int n;                      // numbers to be taken as input


// (i,j) is index v is value to be inserted

int call4(int i,int j,int v) // fills the answer matrix in 4 directions
{
    ans[i][j]=v;                    // $ . . . $
    ans[n-i-1][j]=v;                // . . . . .
    ans[n-1-i][n-1-j]=v;            // . . . . . 
    ans[i][n-1-j]=v;                // $ . . . $
    fr[v]-=4;                       // $ sign here denotes how the call4 function fills the answer matrix
}


// (i,j) is index , c is for choice when 0 represents horizontal filling when 1 represents vertical filling
// v is for value

int call2(int i,int j,int c,int v) 
{
    if(c==0) // $ represents the v to be filled 
    {
        ans[i][j]=v;               // . . . 
        ans[i][n-1-j]=v;           // $ . $
        fr[v]-=2;                  // . . .
    }
    
    else
    {
        ans[i][j]=v;              // . $ .
        ans[n-1-i][j]=v;          // . . .
        fr[v]-=2;                 // . $ .
    }
    
}

int main()
{
    cin>>n;
    int a[n*n];
    rep(i,0,n*n)
    {
        cin>>a[i];
        fr[a[i]]++;
    }


    if(n%2==0) // if the size of matrix is even then it won't have any odd frequency numbers and we'll only require call4
    {
        int cant=0;
        rep(i,0,1001)
        {
            if(fr[i]%4!=0)
                cant=1;
        }
        if(cant)
            cout<<"NO\n";
        else
        {
            int a=0,b=0;
            rep(i,0,1001)
            {
                if(fr[i]!=0)
                {
                    while(fr[i]!=0)
                    {
                        call4(a,b,i);
                        b++;
                        if(b==n/2)
                            a++,b=0;
                    }
                }
            }
            cout<<"YES\n";
            rep(i,0,n)
            {
                rep(j,0,n)
                cout<<ans[i][j]<<" ";
                cout<<endl;
            }
        }
    }
    
    else
    {
        int c1=0,cant=0;
        rep(i,0,1001)
        {
            if(fr[i]&1)
                c1++;
        }
        if(c1!=1)
        cant=1;
        if(cant)
            cout<<"NO\n";
        else
        {
            int a4=0,b4=0,a20=n/2,b20=0,a21=0,b21=n/2,full=0;
            rep(i,0,1001)
            {
                if(fr[i]!=0)
                {
                    while(fr[i]!=0)
                    {
                        if(fr[i]>=4 && full!=1)
                        {
                            call4(a4,b4,i);
                            b4++;
                            if(b4==n/2)
                                a4++,b4=0;
                            if(a4==n/2)
                                full=1;
                        }
                        else if(fr[i]>=2)
                        {
                            if(b20<n/2)
                            {
                                call2(a20,b20,0,i);
                                b20++;
                            }
                            else if(a21<n/2)
                            {
                                call2(a21,b21,1,i);
                                a21++;
                            }
                            else
                            {
                                cant=1;
                                break;
                            }
                        }
                        else
                        {
                            if(ans[n/2][n/2]!=0)
                            {
                                cant=1;
                                break;
                            }
                            else
                            {
                                ans[n/2][n/2]=i;
                                fr[i]-=1;
                            }
                        }
                    }
                }
            }
            if(cant==0)
            {
                cout<<"YES\n";
                rep(i,0,n)
                {
                    rep(j,0,n)
                    cout<<ans[i][j]<<" ";
                    cout<<endl;
                }
            }
            else
                cout<<"NO\n";
        }
    }
}
