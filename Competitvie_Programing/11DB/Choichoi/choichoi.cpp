#include <bits/stdc++.h>
using namespace std;
string s[] = {"010","8","82","71","93","20","02","100","47"};
bool compare(string i1, string i2)
{
    int i = 0;
    while (i!=i1.length() || i!=i2.length())
    {
        if(i1[i] > i2[i]){
            return true;
        }
        if(i1[i] < i2[i]){
            return false;
        }
        ++i;
    }
    return (i1.length()<i2.length());
}
int main(){
    sort(s,s+sizeof(s),compare);
    for(int i=0;i<sizeof(s);++i){
        cout<<s[i]<<" ";
    }
    return 0;
}