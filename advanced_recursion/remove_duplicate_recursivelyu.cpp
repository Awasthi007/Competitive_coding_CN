Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
First line of input will contain T number of test cases
Next T line will contain the string S
Output Format :
For every test case print the answer in a separate line
Constraints :
1 <= T <= 10
1 <= |S| <= 10^4
where |S| represents the length of string
Sample Input 1 :
1
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
1
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
/*
Time complexity : O(N)
Space complexity : O(N)
where N is the length of string
Space complexity is O(N) because
of recursion stack
*/
#include <bits/stdc++.h>
using namespace std;
void removeDuplicate(char *str, int index, int newIndex)
{
if (str[index] == '\0')
{
str[newIndex] = str[index - 1];
str[newIndex + 1] = '\0';
return;
}
if (str[index] == str[index - 1])
{
removeDuplicate(str, index + 1, newIndex);
}
else
{
str[newIndex] = str[index - 1];
removeDuplicate(str, index + 1, newIndex + 1);
}
}
int main()
{
int t;
cin >> t;
while (t--)
{
char str[10000];
cin >> str;
removeDuplicate(str, 1, 0);
cout << str << endl;
}
}

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  #include<bits/stdc++.h>
using namespace std;

void helper(char input[])
{
    if(input[0] == '\0')
        return;
    if(input[0] == input[1])
    {
        for(int i=0; input[i] != '\0'; i++)
        {
            input[i] = input[i+1];
        }
        helper(input);
    }
    helper(input+1);
    

    
}

int main()
{
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        char s[10000];
        cin>>s;
        
        helper(s);
        for(int i=0; s[i] != '\0'; i++)
            cout<<s[i];
        
        cout<<endl;
    }
    
    return 0;
}
