Largest Bitonic Subsequence
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
First line will contain T (number of test case), each test is consists of two lines. 
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence for each test case in a newline.
Input Constraints:
1 <= T <= 10
1<= N <= 5000
Sample Input 1:
1
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
1
2
1 5
Sample Output 2:
2
Sample Input 3:
1
2
5 1
Sample Output 3:
2
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  #include<bits/stdc++.h>
using namespace std;

void lis(int* input, int n, int* output)
{
    if(n<=1)
        return ;
    
    
    
    for(int i=1; i<n; i++)
    {
        output[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(input[j] >= input[i])
                continue;
            int possible = output[j]+1;
            if(output[i] < possible)
                output[i] = possible;
        }
    }
    
    // int best = 0;
    // for(int i=0; i<n; i++)
    // {
    //     if(best < output[i])
    //         best = output[i];
    // }
    //delete [] output;
    //return best;
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
        
        int* input = new int[n];
        for(int i=0; i<n; i++)
        {
            cin>>input[i];
        }
        int* output1 = new int[n];
    	output1[0] = 1;
        lis(input, n,output1);
        
        int* output2 = new int[n];
        output2[0] = 1;
        int i=0,j=n-1;
        while(i<j)
        {
            swap(input[i],input[j]);
            i++;j--;
        }
        lis(input, n, output2);
        
        int* ans = new int[n];
        for(int k=0; k<n; k++)
        {
            ans[k] = output1[k] + output2[n-k-1] - 1;
        }
        
        int best = 0;
    	for(int k=0; k<n; k++)
    	{
         	if(best < ans[k])
             	best = ans[k];
 		}
        
        cout<<best<<endl;
        
        delete [] ans;
        delete [] output1;
        delete [] output2;
        delete [] input;
    }
    return 0;
}
  
  
  
  
  
  
