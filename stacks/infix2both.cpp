//infix to prefix and postfix 
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

string reverse(string str, int len)
{
    string revString = "";
    for (int i = len - 1; i >= 0; i--)
    {
        revString += str[i];
    }
    return revString;
}

// Reverses string and swaps parentheses for postfix calculation
string reverseAndSwapParens(string str, int len)
{
    string revString = "";
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '(')
            revString += ')';
        else if (str[i] == ')')
            revString += '(';
        else
            revString += str[i];
    }
    return revString;
}

int prec(char c)
{
    if (c == '^' || c == '$' || c == '@')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string prefix(string s, int leng)
{
    stack<char> st;
    string res;
    for (int i = 0; i < leng; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i]; // checks if the current char is alphabet or not
        }
        else if (s[i] == '(')
        {
            st.push(s[i]); // if the current char is ( then pushes it in the stack
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(') // if the current char is ) then if the stack is not empty and top of the stack is not ( then the top of stack is added to the res and popped
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop(); // if it's still not empty then it pops
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i])) // check precedence of the operads
            {
                res += st.top(); // if precedence of top of stack is greater then current ch of string it adds the top of stack to the result and pops it and again runs while loop
                st.pop();
            }
            st.push(s[i]); // if top of stack is smaller than the precedence of current char then it is pushed into stack
        }
    }
    while (!st.empty())
    {
        res += st.top(); // if stack is not empty it adds the rest of the stack to the result and pops them
        st.pop();
    }
    return res;
}

int main()
{
    int x, len = 0, n = 0;
    string s, prf, pof;
    char ch = 'Y';

    while (ch == 'y' || ch == 'Y')
    {
        cout << "Enter a suffix:";
        cin >> s;
        while (s[n] != '\0')
        {
            len++;
            n++;
        }

        cout << "Enter \n 1.Prefix \n 2.Postfix\n";
        cin >> x;
        if (x == 1)
        {
            string rev_s = reverseAndSwapParens(s, len); // reverse input and swap parentheses
            string ans = prefix(rev_s, len);             // reuse prefix logic
            pof = reverse(ans, len);                     // reverse back to get postfix
            cout << "The prefix of " << s << " is: " << pof << endl;
            // string ans = prefix(s, len);
            // prf = ans;
            // cout << "The prefix of " << s << "is: " << prf<<endl;
        }
        else if (x == 2)
        {
            // string rev_s = reverseAndSwapParens(s, len); // reverse input and swap parentheses
            // string ans = prefix(rev_s, len);             // reuse prefix logic
            // pof = reverse(ans, len);                     // reverse back to get postfix
            // cout << "The postfix of " << s << " is: " << pof << endl;
            string ans = prefix(s, len);
            prf = ans;
            cout << "The postfix of " << s << "is: " << prf << endl;
        }
        else
        {
            cout << "Inavlid";
        }
        cout << "Do you want to check again (Y/N):";
        cin >> ch;
        cout << endl;
    }
    return 0;
}
