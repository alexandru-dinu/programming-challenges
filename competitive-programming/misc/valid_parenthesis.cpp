#include <stack>
#include <string>

using namespace std;

bool isOpen(char c)
{
    return (c == '(') || (c == '[') || (c == '{');
}

bool matches(char a, char b)
{
    bool b1 = (a == '{') && (b == '}');
    bool b2 = (a == '[') && (b == ']');
    bool b3 = (a == '(') && (b == ')');

    return b1 || b2 || b3;
}

bool isValid(string s)
{
    std::stack<char> st;

    for (const char c : s) {
        if (isOpen(c))
            st.push(c);
        else if (!st.empty() && matches(st.top(), c))
            st.pop();
        else
            return false;
    }

    return st.empty();
}