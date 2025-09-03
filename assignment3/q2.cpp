#include <iostream>
#include <stack>  
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;   

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string r = "";
    while (!s.empty()) {
        r += s.top();
        s.pop();
    }

    cout << "Reversed string: " << r << endl;

    return 0;
}
