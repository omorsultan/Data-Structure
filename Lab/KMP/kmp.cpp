#include<bits/stdc++.h>
using namespace std;
void calculateLps(char *pat,int M,int* lps)
{
  int len=0;
  lps[0]=0;
  int i=1;
  while(i<M)
  {
    if(pat[i]==pat[len])
    {
      len++;
      lps[i]=len;
      i++;
    }
    else
    {
      if(len!=0)len=lps[len-1];
      else
      {
        lps[i]=0;i++;
      }
    }
  }
}
void KMP(char* pat, char* txt)
{
  int M=strlen(pat);
  int N=strlen(txt);

  int lps[M];

  calculateLps(pat,M,lps);
  int i=0,j=0;
  while(i<N)
  {
    if(txt[i]==pat[j])
    {
      i++;j++;
    }
   
      if(j==M){
        cout<<"Found at index"<<i-j<<endl;
         j=lps[j-1];
      }
      else if(i<N&&txt[i]!=pat[j]){
       if(j!=0) j=lps[j-1];
        else i++;

    }

  }

}
int main()
{
  char pat[]="AB";
  char txt[]="ABABCABABABCABABABCD";
  KMP(pat,txt);
}