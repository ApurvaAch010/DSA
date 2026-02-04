#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int operation(char op,int a,int b){
    switch(op){
        case '+':return b+a; break;
        case '-':return b-a; break;
        case '*':return b*a; break;
        case '/':return b/a; break;
    }
    return 0;

}


int evalpf(string inf){
    stack<int> st;
    

    for(int i=0;i<inf.length();i++){
        if(isdigit(inf[i])){
            st.push(inf[i]-'0');
        }
        else{
           int felm=st.top();
           st.pop();
           int selm=st.top();
           st.pop();
           int result=operation(inf[i],felm,selm);
           st.push(result);
        }
    }
    return st.top();

}

int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evalpf(postfix);

    cout << "The evaluation result is: " << result << endl;

    return 0;
}
