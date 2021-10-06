#include<bits/stdc++.h>
using namespace std;

void lis(int* input, int n)
{
    if(n<=1)
        return n;
    
    
     int* output = new int[n];
    	output[0] = 1;
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
    
     int best = 0;
     for(int i=0; i<n; i++)
     {
         if(best < output[i])
             best = output[i];
     }
    delete [] output;
    return best;
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
       
        int ans = lis(input, n);
        cout<<ans<<endl;
        
        
        delete [] input;
    }
    return 0;
}
