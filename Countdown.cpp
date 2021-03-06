/********
____________________________________________________________ GOOGLE KICK START ROUND-C 2020 _______________________________________________________________________________

Problem
Avery has an array of N positive integers. The i-th integer of the array is Ai.

A contiguous subarray is an m-countdown if it is of length m and contains the integers m, m-1, m-2, ..., 2, 1 in that order. For example, [3, 2, 1] is a 3-countdown.

Can you help Avery count the number of K-countdowns in her array?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the
integers N and K. The second line contains N integers. The i-th integer is Ai.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of K-countdowns in her array.

Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1 ≤ T ≤ 100.
2 ≤ K ≤ N.
1 ≤ Ai ≤ 2 × 105, for all i.
Test Set 1
2 ≤ N ≤ 1000.
Test Set 2
2 ≤ N ≤ 2 × 105 for at most 10 test cases.
For the remaining cases, 2 ≤ N ≤ 1000.
Sample
Sample Input
save_alt
content_copy
3
12 3
1 2 3 7 9 3 2 1 8 3 2 1
4 2
101 100 99 98
9 6
100 7 6 5 4 3 2 1 100
Sample Output
save_alt
content_copy
Case #1: 2
Case #2: 0
Case #3: 1
In sample case #1, there are two 3-countdowns as highlighted below.

1 2 3 7 9 3 2 1 8 3 2 1
1 2 3 7 9 3 2 1 8 3 2 1
In sample case #2, there are no 2-countdowns.

In sample case #3, there is one 6-countdown as highlighted below.

100 7 6 5 4 3 2 1 100
*******/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        ll ans=0,len;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]==k)
            {
                len=1;
                while(arr[i+1]+1==arr[i] && arr[i]>=2)
                {
                    len++;
                    i++;
                }
                if(len==k)
                ans++;
            }
        }
        cout<<"Case #"<<i+1<<":"<<" "<<ans<<endl;
    }
    return 0;
}
