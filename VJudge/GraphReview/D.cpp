#include<iostream>
#include<cstring>
using namespace std;
char a[101000],b[101000];
int main()
{
    while(cin>>a)
    {
        int len=strlen(a),i,j;
        for(i=0;i<len;i++)
        {
            if(a[i]=='['||a[i]==']')
            b[i]='\0';
            else b[i]=a[i];
        }
        b[len]='\0';
        for(j=len-1;j>=0;j--)
        {
            if(a[j]=='[')
            cout<<b+j+1;
        }
        if(!(a[0]=='['||a[0]==']'))
        cout<<b;
        for(j=0;j<len;j++)
        {
            if(a[j]==']')
            cout<<b+j+1;
        }
        cout<<endl;
    }
    return 0;
}