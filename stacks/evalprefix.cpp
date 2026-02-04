#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int operation(char op, int a, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
    return 0;
}

int evalpf(string inf){
    stack<int> st;

    for(int i = inf.length() - 1; i >= 0; i--){
        if(isdigit(inf[i])){
            st.push(inf[i] - '0'); 
        }
        else{
            if(st.size() < 2){
                cout << "Invalid prefix expression!\n";
                return 0;
            }
            int a = st.top(); st.pop(); 
            int b = st.top(); st.pop();
            int result = operation(inf[i], a, b);
            st.push(result);
        }
    }

    if(st.size() != 1){
        cout << "Invalid prefix expression!\n";
        return 0;
    }

    return st.top();
}

int main()
{
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    int result = evalpf(prefix);

    cout << "The evaluation result is: " << result << endl;

    return 0;
}
