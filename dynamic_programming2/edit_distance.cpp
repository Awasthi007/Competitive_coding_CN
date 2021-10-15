Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
First line of input will contain T (number of test cases), each test case consists of two lines.
Line 1 : String s
Line 2 : String t
Output Format :
For each test case print the Edit Distance value in new line.
Constraints:
1 <= T <= 100
1<= m,n <= 100
Sample Input 1 :
1
abc
dc
Sample Output 1 :
2
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  #include<bits/stdc++.h>
using namespace std;

/*
int edit(char* s1, char* s2, int m, int n,int** dp)
{
    if(m==0)
        return n;
    else if(n==0)
        return m;
    
    if(dp[m][n] != -1)
        return dp[m][n];
    int ans;
    if(s1[0] == s2[0])
    {
        ans = edit(s1+1, s2+1, m-1, n-1, dp);
    }
    
    else
    {
        int a = 1 + edit(s1+1, s2, m-1, n, dp);
        int b = 1 + edit(s1+1, s2+1, m-1, n-1, dp);
        int c = 1 + edit(s1, s2+1, m, n-1, dp);
        
        ans = min(a, min(b,c));
        
    }
    dp[m][n] = ans;
    return ans;
}
*/

int edit2(char* s1, char* s2, int m, int n, int** dp)
{
    for(int i=0; i<=n; i++)
    {
        dp[0][i]  = i;
    }
    for(int i=0; i<=m; i++)
    {
        dp[i][0] = i;
    }
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[m-i] == s2[n-j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
    }
    
    return dp[m][n];
}



int main()
{
    
    int t;
    cin>>t;
    
    while(t--)
    {
        char* s1 = new char[101];
        char* s2 = new char[101];
        
        cin>>s1;
        cin>>s2;
        
        int m = strlen(s1);
        int n = strlen(s2);
        
        
        int** dp = new int*[m+1];
        for(int i=0; i<=m; i++)
        {
            dp[i] = new int[n+1];
            for(int j=0; j<=n; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        
        int ans = edit2(s1, s2, m ,n, dp);
        cout<<ans<<endl;
    }
    return 0;
}
