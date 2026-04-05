#include<iostream>
#include<vector>

int countWays(int s)
{
    std::vector dp(s+1,0);

    dp[0]=1;

    for( int i=1; i<=s; i++)
    {
        if (i -1 >=0)
        {
            dp[i]+= dp[i-1];
        }
        if (i -2>=0)
        {
            dp[i]+= dp[i-2];
        }
          if (i -3>=0)
        {
            dp[i]+= dp[i-3];
        }
    }
    return dp[s];
}
int main()
{
    int s;
    std::cout<<"Enter score: ";
    std::cin>>s;

    std::cout<<"Number of ways: "<< countWays(s)<<'\n';
    return 0;
}