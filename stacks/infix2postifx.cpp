// infix to postfix only
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int prec(char ch)
{
    if (ch == '^' || ch == '$' || ch == '@')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
};

string infix2postfix(string s)
{
    // reverse(s.begin(),s.end());
    // for(int i=0;i<s.length();i++){
    //     if(s[i]==')')s[i]='(';
    //     else if(s[i]=='(')s[i]=')';
    // }
    string res = "";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            while (!st.empty() &&
                   ((prec(st.top()) > prec(s[i])) ||
                    (prec(st.top()) == prec(s[i]) && s[i] != '^' && s[i] != '$' && s[i] != '@')))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);

        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    // reverse(res.begin(),res.end());
    return res;
};

int main()
{
    string infix;
    cout << "Enter a infix:";
    cin >> infix;
    string postfix = infix2postfix(infix);
    cout << "The postfix of " << infix << " is " << postfix << endl;
    return 0;
}