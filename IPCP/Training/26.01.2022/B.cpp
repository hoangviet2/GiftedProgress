//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string s;
int res, st[30];
int top;

int main() {
    cin>>s>>res;
    int ans1 = s[0] - '0';
    for (int i = 2; i <= s.length()-1; i += 2) {
        if (s[i - 1] == '+') {
            ans1 += s[i] - '0';
        } else {
            ans1 *= s[i] - '0';
        }
    }
    st[++top] = s[0] - '0';
    for (int i = 2; i <= s.length()-1; i += 2) {
        if (s[i - 1] == '*') {
            st[top] *= s[i] - '0';
        } else {
            st[++top] = s[i] - '0';
        }
    }
    int ans2 = 0;
    for (int i = 1; i <= top; i++) ans2 += st[i];
    if (ans1 == res && ans2 == res){
        cout<<"U";
    }else if (ans1 == res) {
        cout<<"L";
    }else if (ans2 == res) {
        cout<<"M";
    }else {
        cout<<"I";
    }
    return 0;
}