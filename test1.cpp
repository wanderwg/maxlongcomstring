//最长公共子序列
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int ret=0;
        int len1=s1.size()+1;
        int len2=s2.size()+1;
        int str[len1][len2];
        for(int i=0;i<len2;++i)
            str[0][i]=0;
        for(int i=1;i<len1;++i)
            str[i][0]=0;
        for(int i=1;i<len1;++i)
        {
            for(int j=1;j<len2;++j)
            {
                if(s1[i-1]==s2[j-1])
                    str[i][j]=str[i-1][j-1]+1;
                else
                    str[i][j]=max(str[i-1][j],str[i][j-1]);
            }
        }
        ret=str[len1-1][len2-1];
        cout<<ret<<endl;
    }
    return 0;
}