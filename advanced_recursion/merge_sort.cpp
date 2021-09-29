Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
First line of input will contain T number of test cases
First line of every input will contain a single integer N size of the input array.
second line of each input will contain N space-separated integers.
Output format :
For every test case print, array elements in increasing order (separated by space) in a separate line.
Constraints :
1 <= T <= 10
1 <= n <= 10^5
Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
1
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
  
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  #include<bits/stdc++.h>
using namespace std;

void merge_sorted(int arr[], int start, int mid, int end)
{
    int n1 = mid-start+1;
    int n2 = end - mid;
    
    int a[n1];
    int b[n2];
    
    for(int i=0; i<n1; i++)
    {
        a[i] = arr[start+i];
    }
    for(int i=0; i<n2; i++)
    {
        b[i] = arr[mid+1+i];
    }
    
    
    int k=start,i=0,j=0;
    
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            i++;k++;
        }
        else
        {
            arr[k] = b[j];
            j++;k++;
        }
    }
    while(i < n1)
    {
        arr[k] = a[i];
        i++;k++;
    }
    while(j < n2)
    {
        arr[k] = b[j];
        j++;k++;
    }
    
    return;
}



void helper(int arr[], int start, int end)
{
    if(start >= end)
        return;
    
        int mid = start + (end-start)/2;
        
        helper(arr, start,mid);
        helper(arr, mid+1, end);
        
        merge_sorted(arr, start, mid, end);
    
    	return;
}


void merge(int arr[], int n)
{
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
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        
        merge(arr,n);
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  
  
