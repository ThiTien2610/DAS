#include<iostream>
#include<string>
int LengthOfLastWord (const std::string& s)
{
    int count=0;

    for (int i=(int)s.size()-1; i>=0; --i)
    {
        if (s[i]!=' ')
        {
            ++count;
        }
        else
        {
            if (count >0) return count;
        }
    }
    return count;
}
int main()
{
    std::string s= " fly me to the moon ";
    int result= LengthOfLastWord(s);
    std::cout <<"Length of last word: "<< result <<'\n';
    return 0;
}