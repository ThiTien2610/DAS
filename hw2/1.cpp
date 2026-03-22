#include<iostream>
#include<string>
#include<stack>
bool isValid(const std::string& s)
{
    std::stack<char> st;
    for(int i=0; i<(int)s.size();i++)
    {
        char c=s[i];
        
        if(c=='(')
        {
            st.push(')');
        }
        else if (c== '{')
        {
            st.push('}');
        }
        else if (c== '[')
        {
            st.push(']');
        }
        else
        {
            if(st.empty()|| st.top()!=c)
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    std::string s;
    std::cin >> s;

    if (isValid(s))
    {
        std::cout<< "Valid";
    }
    else
    {
        std::cout<< "Not Valid";
    }
    return 0;
}
