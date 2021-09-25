Inversion Count
Send Feedback
For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Input format :
The first line of input contains an integer 'N', denoting the size of the array.

The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
Output format :
Print a single line containing a single integer that denotes the total count of inversions in the input array.
Note:
You are not required to print anything, it has been already taken care of. Just implement the given function.  
Constraints :
1 <= N <= 10^5 
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the array element at 'ith' index.

Time Limit: 1 sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
                                                   
                                                   
                                                   
                                                   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                                                   
                                                   
                                                   
                                                   
 long long helper(long long *arr, int si, int mid, int ei)
{
    int n1 = mid - si + 1;
    int n2 = ei - mid;
    
    int count = 0;
    
    long long f[n1];
    long long s[n2];
    
    for(int i=0; i<n1; i++)
    {
        f[i] = arr[si+i];
    }
    for(int i=0; i<n2; i++)
    {
        s[i] = arr[mid+i+1];
    }
    
    int i=0,j=0,k=si;
    while(i < n1 && j< n2)
    {
        if(f[i] <= s[j])
        {
            arr[k] = f[i];
            k++;i++;
        }
        else
        {
            arr[k] = s[j];
            count += n1-i;
            j++;k++;
            
        }
    }
    while(i < n1)
    {
        arr[k] = f[i];
        i++;k++;
    }
    while(j < n2)
    {
        arr[k] = s[j];
        j++;k++;
    }
    
    return count;
}


long long merge(long long *arr, int si, int ei,long long count)
{
    if(si >= ei)
    {
        return count;
    }
    
    int mid = si + (ei-si)/2;
    
    long long a = merge(arr,si,mid,count);
    long long b = merge(arr, mid+1, ei, count);
    
    long long c = helper(arr, si, mid, ei);
    
    return a+b+c;
    
}


long long getInversions(long long *arr, int n)
{
    // Write your code here.
    
    return merge(arr,0,n-1,0);
}


