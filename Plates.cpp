#include <bits/stdc++.h>
using namespace std;
const int N = 51;
const int K = 30*51;
int dp[N][K];
int n,k,p;
int arr[N][31];
int prefix[N][31];

int plates(int index,int taken)
{
    if(taken==p)
    return 0;
    if(index>n || taken>p)
    return INT_MIN;
    if(dp[index][taken]!=-1)
    return dp[index][taken];
    
    int ans=INT_MIN;
    for(int i=0;i<=k;i++)
    {
        ans=max(ans,prefix[index][i]+plates(index+1,taken+i));
    }
    return dp[index][taken]=ans;
}
int main()
{
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        //int n,k,p;
        cin>>n>>k>>p;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                cin>>arr[i][j];
                prefix[i][j]=prefix[i][j-1]+arr[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=plates(1,0);
        cout<<"Case #"<<i<<":"<<" "<<ans<<endl;
    }
    return 0;
}

/*******
Problem
Dr. Patel has N stacks of plates. Each stack contains K plates. Each plate has a positive beauty value, 
describing how beautiful it looks.

Dr. Patel would like to take exactly P plates to use for dinner tonight. If he would like to take a plate in a stack, 
he must also take all of the plates above it in that stack as well.

Help Dr. Patel pick the P plates that would maximize the total sum of beauty values.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line 
containing the three integers N, K and P. Then, N lines follow. The i-th line contains K integers, describing the beauty values of each stack of plates from top to bottom.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is 
the maximum total sum of beauty values that Dr. Patel could pick.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ K ≤ 30.
1 ≤ P ≤ N * K.
The beauty values are between 1 and 100, inclusive.

Test set 1
1 ≤ N ≤ 3.
Test set 2
1 ≤ N ≤ 50.
Sample

Input
 	
Output
 
2
2 4 5
10 10 100 30
80 50 10 50
3 2 3
80 80
15 50
20 10

  
Case #1: 250
Case #2: 180

  
In Sample Case #1, Dr. Patel needs to pick P = 5 plates:

He can pick the top 3 plates from the first stack (10 + 10 + 100 = 120).
He can pick the top 2 plates from the second stack (80 + 50 = 130) .
In total, the sum of beauty values is 250.
In Sample Case #2, Dr. Patel needs to pick P = 3 plates:

He can pick the top 2 plates from the first stack (80 + 80 = 160).
He can pick no plates from the second stack.
He can pick the top plate from the third stack (20).
In total, the sum of beauty values is 180.
Note: Unlike previous editions, in Kick Start 2020, all test sets are visible verdict test sets, meaning you receive instant feedback upon submission.

*********/
