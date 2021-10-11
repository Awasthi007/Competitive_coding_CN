Vanya and GCD

Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it. So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with length ≥1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 109+7
She finds this task really easy, and thinks that you can do it too. Can you?
Input Format:
First line will contain T(number of test case), each test consists of two line.
The first line contains a single integer N denoting size of array A. 
The next line contains N space separated integers denoting the elements of array A
Output Format:
Print the required answer Modulo 10^9+7 for each test case in new line
Constraints:
1 <= T <= 50
1 <= N <= 200
1 <= A[i] <= 100
Sample Input
1
3
1 2 3
Sample Output
5

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef unsigned long long int ll;
long long helper(int* arr, ll n, ll** dp)
{
	dp[0][arr[0]] = 1;
	ll sum = dp[0][1];
	for(int i=1; i<n; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(arr[j] < arr[i])
			{
				for(int g=1; g<=100; g++)
				{
					int ng = __gcd(arr[i], g);
					dp[i][ng] = (dp[i][ng] + dp[j][g])%mod;
				}
			}
		}
		dp[i][arr[i]]++;
		sum = (sum + dp[i][1])%mod;
	}
	return sum;
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
		int* arr = new int[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		ll** dp = new ll*[n];
		for(ll i=0; i<n; i++)
		{
			dp[i] = new ll[101];
			for(int j=0; j<=100; j++)
			dp[i][j] = 0;
		}
		long long ans = helper(arr, n, dp);
		cout<<ans<<endl;
	}

	return 0;
}
