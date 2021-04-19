#include <bits/stdc++.h>
using namespace std;


  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
   int n;
    cin >> n;
    
   int a[n];
    f(i,n)cin >> a[i];
    
   vi dif(n-1);
    
   for(int i=1;i<n;i++) dif[i - 1] = a[i] - a[i-1];
   
   vi suf(n-1);
   vi pref(n-1);
    
   pref[0] = 1;
    
   for(int i=1;i<n-1;i++) 
       if(dif[i] == dif[i-1]) pref[i] = pref[i-1] + 1;
       else pref[i] = 1;
    
   suf[n-2] = 1;
    
   for(int i=n-3;i>=0;i--)
       if(dif[i] == dif[i+1]) suf[i] = suf[i+1] + 1;
       else suf[i] = 1;
       
   int res = *max_element(all(pref));
 
   for(int i=0;i<n;i++)
   {
       if(i == 0)
       {
           if(n > 2)
           {
                res = max(res , suf[1] + 1);
           }
       }
       else if(i == n-1)
       {
           if(n > 2)
           {
               res = max(res , pref[n-3] + 1);
           }
       }
       else
       {
           //case 1 : try to fit with the left
           if(i >= 2) 
           {
               res = max(res , pref[i - 2] + 1);
           }
           
           //case 2 : try to fit with the right
           if(i < n-2)
           {
               res = max(res , suf[i+1] + 1);
           }
           
           //case 3 : try to fit with left and right
           int dif = (a[i + 1] - a[i - 1]);
           
           if(dif % 2 == 0)
           {
               int rs = 2;
               
               if(i >= 2 && a[i-1] - a[i-2] == (dif / 2)) rs += pref[i - 2];
               if(i < n-2 && a[i+2] - a[i+1] == (dif / 2)) rs += suf[i + 1];
               
               res = max(res,rs);
           }
       }
   }
    
   cout << res + 1 << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    for(int i=1;i<=t;i++)
    {
    cout <<"Case #" << i <<": ";    
    solve();
    }
}
/******
Problem
In Kick Start 2020 Round E (you do not need to know anything about the previous problem to solve this one) Sarasvati
learned about arithmetic arrays. An arithmetic array is an array that contains at least two integers and the differences 
between consecutive integers are equal. For example, [9,10], [3,3,3], and [9,7,5,3] are arithmetic arrays, while [1,3,3,7], [2,1,2], and [1,2,4] are not.

Sarasvati again has an array of N non-negative integers. The i-th integer of the array is Ai. She can replace at most one element 
in the array with any (possibly negative) integer she wants.

For an array A, Sarasvati defines a subarray as any contiguous part of A. Please help Sarasvati determine the length of the longest 
possible arithmetic subarray she can create by replacing at most one element in the original array.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the
integer N. The second line contains N integers. The i-th integer is Ai.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the length of the longest arithmetic subarray.

Limits
Time limit: 30 seconds.
Memory limit: 1 GB.
1≤T≤100
0≤Ai≤109.
Test Set 1
2≤N≤2000.
Test Set 2
2≤N≤3×105 for at most 10 test cases.
For the remaining cases, 2≤N≤2000.
Sample
Sample Input
save_alt
content_copy
3
4
9 7 5 3
9
5 5 4 5 5 5 4 5 6
4
8 5 2 0
Sample Output
save_alt
content_copy
Case #1: 4
Case #2: 6
Case #3: 4
In Sample Case #1, the whole array is an arithmetic array, thus the longest arithmetic subarray is the whole array.

In Sample Case #2, if Sarasvati changes the number at third position to 5, the array will become [5,5,5,5,5,5,4,5,6]. The subarray from 
first position to sixth position is the longest arithmetic subarray.

In Sample Case #3, Sarasvati can change the number at the last position to −1, to get [8,5,2,−1]. This resulting array is arithmetic.
******/
