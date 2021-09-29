Replace Character Recursively
Send Feedback
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
The first line of input will contain an integer T, which will denote the value of number of test cases. In the following lines, T test cases will be written.
The first line of each test case will contain a string S. 
The following line of each test case will contain two space separated characters, c1 and c2, respectively.
Output Format :
For each test case, the first and only line of output contains the updated string S.
Constraints :
 1 <= T <= 100
 1 <= Length of String S <= 100
Sample Input :
1
abacd
a x
Sample Output :
xbxcd




||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


/*
Time complexity : O(N)
Space complexity : O(N)
where N is the length of string
Space complexity is O(N) because
of recursion stack
*/
#include <bits/stdc++.h>
using namespace std;
void replaceCharacter(string &str, int n, int index, char c1, char c2)
{
if (index == n)
{
return;
}
if (str[index] == c1)
{
str[index] = c2;
}
replaceCharacter(str, n, index + 1, c1, c2);
}
int main()
{
int t;
cin >> t;
while (t--)
{
string str;
cin >> str;
int n = str.size();
char c1, c2;
cin >> c1 >> c2;
replaceCharacter(str, n, 0, c1, c2);
cout << str << endl;
}
}

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  #include<bits/stdc++.h>
using namespace std;

void helper(char s[], char p, char q)
{
    if(s[0] == '\0')
        return;
    if(s[0] == p)
    {
    	s[0] = q;
       
    }
    //string small = s.substr(1);
    helper(s+1, p, q);
}

int main()
{
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        char s[1000000];
        cin>>s;
        
        char p,q;
        cin>>p>>q;
        
        helper(s, p, q);
        cout<<s<<endl;
    }
    
    return 0;
}
