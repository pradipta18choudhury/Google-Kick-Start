#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, m, i, j, ans, k, c;
    string a;
    
    cin>>t;
    
    for(j=1; j<=t; j++)
    {
        cin>>n>>k;
        cin>>a;
        c=0;
        for(i=0; i<=(n/2-1); i++)
        {
            if(a[i]!=a[n-i-1])
            {
                c++;
            }
        }
        ans=abs(k-c);
        cout<<"Case #"<<j<<": "<<ans<<"\n";
    }
}
