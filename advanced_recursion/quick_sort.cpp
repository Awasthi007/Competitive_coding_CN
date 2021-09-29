Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
First line will contain T number of test case and each tet case will consist of two lines.
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
for every test case print rray elements in increasing order (separated by space) in a new line.
Constraints :
1 <= T <= 10
1 <= n <= 10^5
0 <= arr[i] <= 10^9
Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
1
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
  
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  
  #include<bits/stdc++.h>
using namespace std;

int partition(long long arr[], int si, int ei)
{
    long long x = arr[si];
    int count=0;
    for(int i=si+1; i<=ei; i++)
    {
        if(arr[i] < x)
            count++;
    }
    swap(arr[si],arr[si+count]);
    
    int i=si,j=ei;
    while(i < (si+count) && j > (si+count))
    {
        if(arr[i] < x)
            i++;
        else if(arr[j] >= x)
            j--;
        else
        {
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    
    return si+count;
}



void helper(long long arr[], int si, int ei)
{
    if(si >= ei)
        return;
    
    int c = partition(arr,si,ei);
    helper(arr,si,c-1);
    helper(arr,c+1,ei);
    
    return;
}



void qs(long long arr[], int n)
{
    if(n==0 || n==1)
        return;
    
    helper(arr, 0, n-1);
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
    
    	long long arr[n];
    	for(int i=0; i<n; i++)
   	 	{
        	cin>>arr[i];
    	}
    
    	qs(arr, n);
    	for(int i=0; i<n; i++)
    	{
        	cout<<arr[i]<<" ";
    	}
        cout<<endl;
    }
    return 0;
}
