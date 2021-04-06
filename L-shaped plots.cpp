/******
Problem
Given a grid of R rows and C columns each cell in the grid is either 0 or 1.

A segment is a nonempty sequence of consecutive cells such that all cells are in the same row or the same column. 
We define the length of a segment as number of cells in the sequence.

A segment is called "good" if all the cells in the segment contain only 1s.

An "L-shape" is defined as an unordered pair of segments, which has all the following properties:

Each of the segments must be a "good" segment.
The two segments must be perpendicular to each other.
The segments must share one cell that is an endpoint of both segments.
Segments must have length at least 2.
The length of the longer segment is twice the length of the shorter segment.
We need to count the number of L-shapes in the grid.

Below you can find two examples of correct L-shapes,

Examples of valid L-shapes.
and three examples of invalid L-shapes.

Examples of invalid L-shapes.
Note that in the shape on the left, two segments do not share a common endpoint. The next two shapes do not meet the last requirement, as in the middle shape both segments have the same length, and in the last shape the longer segment is longer than twice the length of the shorter one.

Input
The first line of the input contains the number of test cases, T. T test cases follow.

The first line of each testcase contains two integers R and C.

Then, R lines follow, each line with C integers representing the cells of the grid.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of L-shapes.

Limits
Time limit: 60 seconds.
Memory limit: 1 GB.
1≤T≤100.
Grid consists of 0s and 1s only.
Test Set 1
1≤R≤40.
1≤C≤40.
Test Set 2
1≤R≤1000 and 1≤C≤1000 for at most 5 test cases.
For the remaining cases, 1≤R≤40 and 1≤C≤40.
Sample
Sample Input
save_alt
content_copy
2
4 3
1 0 0
1 0 1
1 0 0
1 1 0
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0
Sample Output
save_alt
content_copy
Case #1: 1
Case #2: 9
In Sample Case #1, there is one L-shape.

The first one is formed by using cells: (1,1), (2,1), (3,1), (4,1), (4,2)
Visualization for the first sample case, showing one L-shape.
In Sample Case #2, there are nine L-shapes.

The first one is formed by using cells: (1,1), (2,1), (3,1), (4,1), (5,1), (6,1), (6,2), (6,3)
The second one is formed by using cells: (3,1), (4,1), (5,1), (6,1), (6,2)
The third one is formed by using cells: (6,1), (5,1), (4,1), (3,1), (3,2)
The fourth one is formed by using cells: (3,3), (4,3), (5,3), (6,3), (6,2)
The fifth one is formed by using cells: (6,3), (5,3), (4,3), (3,3), (3,2)
The sixth one is formed by using cells: (3,1), (3,2), (3,3), (3,4), (2,4)
The seventh one is formed by using cells: (3,4), (3,3), (3,2), (3,1), (2,1)
The eighth one is formed by using cells: (3,4), (3,3), (3,2), (3,1), (4,1)
The ninth one is formed by using cells: (6,3), (5,3), (4,3), (3,3), (3,4)
The first three L-shapes are shown on the picture below. Visualization for the second sample case, showing first three L-shapes.
*******/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, m, i, j, ans, r, c, p1, p2, z;
    
    cin>>t;
    
    for(z=1; z<=t; z++)
    {
        cin>>r>>c;
        ans=0;
        
        ll a[r][c], f[r][c], b[r][c], u[r][c], d[r][c];
        
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                cin>>a[i][j];
            }
        }
        
        for(i=0; i<r; i++)
        {
            if(a[i][0]==1)
            f[i][0]=1;
            else
            f[i][0]=0;
        }
        
        for(i=0; i<r; i++)
        {
            for(j=1; j<c; j++)
            {
                if(a[i][j]==1)
                {
                    f[i][j]=(f[i][j-1]+1);
                }else{
                    f[i][j]=0;
                }
            }
        }
        
        for(i=0; i<r; i++)
        {
            if(a[i][c-1]==1)
            {
                b[i][c-1]=1;
            }else{
                b[i][c-1]=0;
            }
        }
        
        for(i=0; i<r; i++)
        {
            for(j=c-2; j>=0; j--)
            {
                if(a[i][j]==1)
                {
                    b[i][j]=b[i][j+1]+1;
                }else{
                    b[i][j]=0;
                }
            }
        }
        
        for(i=0; i<c; i++)
        {
            if(a[0][i]==1)
            {
                d[0][i]=1;
            }else{
                d[0][i]=0;
            }
        }
        
        for(i=1; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(a[i][j]==1)
                {
                    d[i][j]=d[i-1][j]+1;
                }else{
                    d[i][j]=0;
                }
            }
        }
        
        for(i=0; i<c; i++)
        {
            if(a[r-1][i]==1)
            {
                u[r-1][i]=1;
            }else{
                u[r-1][i]=0;
            }
        }
        
        for(i=r-2; i>=0; i--)
        {
            for(j=0; j<c; j++)
            {
                if(a[i][j]==1)
                {
                    u[i][j]=(u[i+1][j]+1);
                }else{
                    u[i][j]=0;
                }
            }
        }
        
        
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                //cout<<f[i][j]<<" "<<b[i][j]<<" "<<u[i][j]<<" "<<d[i][j]<<"   ";
                p1=u[i][j];
                p2=b[i][j];
                
                if(p1>=2 && p2>=2)
                {
                if(p1>=p2)
                {
                    if(p1>=2*p2){
                        ans=ans+p2-1;
                    }else{
                        ans=ans+p1/2-1;
                    }
                    ans=ans+p2/2-1;
                }else{
                    if(p2>=2*p1){
                        ans=ans+p1-1;
                    }else{
                        ans=ans+p2/2-1;
                    }
                    ans=ans+p1/2-1;
                }
                }
                
                p1=u[i][j];
                p2=f[i][j];
                
                if(p1>=2 && p2>=2)
                {
                if(p1>=p2)
                {
                    if(p1>=2*p2){
                        ans=ans+p2-1;
                    }else{
                        ans=ans+p1/2-1;
                    }
                    ans=ans+p2/2-1;
                }else{
                    if(p2>=2*p1){
                        ans=ans+p1-1;
                    }else{
                        ans=ans+p2/2-1;
                    }
                    ans=ans+p1/2-1;
                }
                }
                
                p1=b[i][j];
                p2=d[i][j];
                
                if(p1>=2 && p2>=2)
                {
                if(p1>=p2)
                {
                    if(p1>=2*p2){
                        ans=ans+p2-1;
                    }else{
                        ans=ans+p1/2-1;
                    }
                    ans=ans+p2/2-1;
                }else{
                    if(p2>=2*p1){
                        ans=ans+p1-1;
                    }else{
                        ans=ans+p2/2-1;
                    }
                    ans=ans+p1/2-1;
                }
                }
                
                p1=f[i][j];
                p2=d[i][j];
                
                if(p1>=2 && p2>=2)
                {
                if(p1>=p2)
                {
                    if(p1>=2*p2){
                        ans=ans+p2-1;
                    }else{
                        ans=ans+p1/2-1;
                    }
                    ans=ans+p2/2-1;
                }else{
                    if(p2>=2*p1){
                        ans=ans+p1-1;
                    }else{
                        ans=ans+p2/2-1;
                    }
                    ans=ans+p1/2-1;
                }
                }
                //cout<<ans<<" ";
            }
            //cout<<"\n";
        }
        cout<<"Case #"<<z<<": "<<ans<<"\n";
    }
}
