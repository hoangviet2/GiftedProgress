//
//  bai11.cpp
//  Test
//
//  Created by Hoang Viet on 18/10/2021.
//

// CPP program to convert infix to prefix
#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream Inp;
ofstream Oup;
string s;
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            char_stack.push('(');
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        }
        else
        {
            if (isOperator(char_stack.top()))
            {
                if(infix[i] == '^')
                {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                else
                {
                    while (getPriority(infix[i]) < getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                    
                }
                char_stack.push(infix[i]);
            }
        }
    }
    return output;
}

string infixToPrefix(string infix){
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
void Input(){
    getline(Inp,s);
    return;
}
int main(){
    Inp.open("bai11.inp");
    Oup.open("bai11.out");
    Input();
    Oup<<infixToPrefix(s) << std::endl;
    Inp.close();
    Oup.close();
    return 0;
}
