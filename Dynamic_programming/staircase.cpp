StairCase Problem
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5


||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
long long staircase(int n, long long int* arr)
{
    if(n < 0)
        return 0;
    if(n == 0 || n == 1)
       return 1;
    if( n == 2)
        return n;
    if(n==3)
        return 4;
    
    if(arr[n] != -1)
        return arr[n];
    long long ans = 0;
    ans += staircase(n-1,arr)%mod;
    if(n >= 2)
        ans += staircase(n-2,arr)%mod; 
    if(n >= 3)
        ans += staircase(n-3,arr)%mod;
    
    arr[n] = ans;
    
    return (arr[n])%mod;
}

*/

long long staircase(int n)
{
    if(n < 0)
        return 0;
    if(n==0 || n==1)
        return 1;
    if(n==2)
        return 2;
    long long* arr = new long long[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i=3; i<=n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-3])%mod;
    }
    long long ans = arr[n] % mod;
    delete [] arr;
    return ans;
}
int main()
{
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        long long ans = staircase(n);
        cout<<ans%mod<<endl;
    }
    return 0;
}
