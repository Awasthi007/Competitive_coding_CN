Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Note: Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
1 <= W <= 1000
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  #include<bits/stdc++.h>
using namespace std;

int knapsnack(int* weights, int* values, int n, int w, int** dp)
{
    if(n==0 || w==0)
        return 0;
    
    if(dp[n][w] != -1)
        return dp[n][w];
    
    int ans;
     if(w >= weights[n-1])
     {
         int a = knapsnack(weights, values, n-1, w-weights[n-1], dp) + values[n-1];
         int b = knapsnack(weights, values, n-1, w, dp);
         
         ans = max(a,b);
         
     }
    else
    {
        ans = knapsnack(weights, values, n-1, w,dp);
    }
    dp[n][w] = ans;
    
    return ans;
}







int main(){
    
    // write your code here
    int n;
    cin>>n;
    
    int* weights = new int[n];
    int* values = new int[n];
    
    for(int i=0; i<n; i++)
    {
        cin>>weights[i];
    }
     for(int i=0; i<n; i++)
    {
        cin>>values[i];
    }
    int w;
    cin>>w;
    
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i] = new int[w+1];
        for(int j=0; j<=w; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    int ans = knapsnack(weights, values, n, w, dp);
    cout<<ans;
    
    
    
    return 0;
}
