//submitted by omor_sultan
#include<bits/stdc++.h>
using namespace std;

string solve(string s1,string s2,int i,int j,string s)
{
  string sh="";
 if(i==0||j==0)return s;
 else if(s[i]==s[j]){
  sh+=s[i];return sh;
 }
 else {
  
 }
}
signed main()
{
    string s1,s2,s="";
    cin>>s1>>s2;
    cout<<solve(s1,s2,s1.length(),s2.length(),s);
}
