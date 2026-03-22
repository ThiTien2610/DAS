#include<cstring>
#include<vector>
#include<string>
#include<iostream>
std::string LongestPalindrome(const char*s)
{
    if (s == nullptr) return "";
    int n=strlen(s);
    if (n == 0) return "";

    std::vector<char> row(n,0);
    std::vector<std::vector<char>> F(n, row); //->O(n^2)

    int MaxStart =0;
    int MaxLength =1;

    for (int i=0; i<n; ++i) F[i][i]=1;//->O(n)

    for (int L =2;L<=n;++L)
    {
        for (int i=0;i+L-1<n;++i)
        {
            int j=i+L-1;//->O(n^2)
            
            if (s[i]==s[j])
            {
                if (L == 2) F[i][j]=1;
                else if (F[i+1][j-1]) F[i][j]=1;
            }

            if(F[i][j]&& L> MaxLength)
            {
                MaxLength=L;
                MaxStart=i;
            }

        }
    }

    std::string str =s;
    return str.substr(MaxStart, MaxLength);//->O(MaxLength)<=O(n)
}
int main()
{
    std::string input;
    std::cin>> input;
    std::cout<< LongestPalindrome(input.c_str())<< "\n";
}

//-> Time complexity: O(n^2)
//-> Space complexity: O(n^2) (table F has size 2*2 )
