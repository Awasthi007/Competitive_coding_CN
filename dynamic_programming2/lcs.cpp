LCS - Problem
Send Feedback
Given two strings S1 and S2 with lengths M and N respectively, find the length of the longest common subsequence.
A subsequence of a string S whose length is K, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K. For example, subsequences of string "abc" are -- ""(empty string), a, b, c, ab, bc, ac, abc.
Input Format :
First line will contain T(number of test case), each test case will consist of two lines.
Line 1: String S1
Line 2: String s2
Output Format :
Length of the longest common subsequence for each test case in a newline.
Constraints :
1 <= T <= 100
1 <= M <= 100
1 <= N <= 100

Time Limit: 1 sec
Sample Input 1:
1
adebc
dcadb
Sample Output 1:
3
Explanation of Sample Input 1:
"a", "d", "b", "c", "ad", "ab", "db", "dc" and "adb" are present as a subsequence in both the strings in which "adb" has the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
Sample Input 2:
1
abcd
acbdef
Sample Output 2:
3
Explanation of Sample Input 2:
"a", "b", "c", "d", "ab", "ac", "ad", "bd", "cd", "abd" and "acd" are present as a subsequence in both the strings S1 and S2 in which "abd" and "acd" are of the maximum length.
  There are no other common subsequence of length greater than 3 and hence the answer.
  
  
  
  
  
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  
  #include<bits/stdc++.h>
using namespace std;

int lcs(char* s1, char* s2, int m, int n, int** dp)
{
    if(m == 0 || n == 0)
        return 0;
    
    if(dp[m][n] != -1)
        return dp[m][n];
    
    int ans;
    if(s1[0] == s2[0])
    {
        ans = 1 + lcs(s1+1,s2+1,m-1,n-1,dp);
    }
    else
    {
        int op1 = lcs(s1+1, s2, m-1, n, dp);
        int op2 = lcs(s1, s2+1, m, n-1, dp);
        ans = max(op1, op2);
    }
    dp[m][n] = ans;
    return ans;
}



int main()
{
    
    // write your code here
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
        
        int ans = lcs(s1, s2, m, n, dp);
        cout<<ans<<endl;
    }
    return 0;
}
