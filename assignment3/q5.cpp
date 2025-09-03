#include <iostream>
#include <stack>
#include <cctype> 
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> st;

    for(char ch : postfix) {
        if(isdigit(ch)) {
            st.push(ch - '0');  
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch(ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a Postfix expression (single-digit numbers): ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}
