#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,k;
        cin>>s>>k;
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second%2==1)
            {
                ans++;
            }
        }
          if(ans>1)
          {
            cout<<"NO"<<endl;
          } 
          else
          {
            cout<<"YES"<<endl;
          } 
    }
}