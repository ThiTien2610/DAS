#include <vector>
#include <algorithm>
#include <climits>
#include<iostream>

class Solution
{
public:
    int calculateMinimum(std::vector<std::vector<int>> & dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, INT_MAX));

        dp[m][n-1]=1;
        dp[m-1][n]=1;

        for (int i=m-1; i>=0; --i)
        {
            for( int j=n-1; j>=0; --j)
            {
                dp[i][j] = std::min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
                if( dp[i][j]<1)
                {
                    dp[i][j]=1;
                }
            }
        }
        return dp[0][0];


    }
};

int main()
{
    int m,n;
    std::cin>>m>>n;

    std::vector<std::vector<int>> dungeon(m, std::vector<int>(n));

    for (int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            std::cin>> dungeon[i][j];
        }
    
    }

    Solution sol;
    std::cout<< sol.calculateMinimum(dungeon)<<'\n';

    return 0;
}
