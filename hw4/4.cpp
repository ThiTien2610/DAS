#include<iostream>

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        int i=0, j=0;
        while(i<s.size() && j<t.size())
        {
            if (s[i]==t[j])
            {
                i++;
            }
            j++;
        }
        return i ==s.size();
    }
};
int main()
{
    std::string s,t;
    std::cout<<"Enter string s: ";
    std::cin>> s;
     std::cout<<"Enter string t: ";
    std::cin>> t;

    Solution sol;
    if(sol.isSubsequence(s,t))
    {
        std::cout<<"true";
    }
    else
    {
        std::cout<<"false";
    }
    return 0;
}