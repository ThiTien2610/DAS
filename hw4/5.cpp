#include<vector>
#include <iostream>
#include<algorithm>
class Solution
{
public:
    bool canReachEnd(std::vector<std::vector<int>>& grid)
    {
        int m= grid.size();
        int n= grid[0].size();

        std::vector<std::vector<int>> best(m, std::vector<int>(n, -1));

        int startPower= 100;
        startPower += grid[0][0];
        if(startPower >100)
        {
            startPower= 100;
        }
        if(startPower <0)
        {
            return false;
        }

        best[0][0] = startPower;

        for(int c=0; c<n-1; c++)
        {
            for (int r=0; r<m;r++)
            {
                if (best[r][c]==-1)
                { continue;}
                // ->
                int power = best[r][c];

                int nr =r;
                int nc=c+1;
                int newPower= power;

                newPower +=grid[nr][nc];
                if(newPower>100)
                {
                    newPower=100;
                }
                if (newPower >=0)
                {
                    best[nr][nc]= std::max(best[nr][nc], newPower);
                }
                // go up and turn right
                if( r-1>=0 && power>=3)
                {
                    int nr=r-1;
                    int nc=c+1;

                    int newPower =power +3;
                    if(newPower>100)
                    {
                        newPower=100;
                    }
                    newPower +=grid[nr][nc];
                    if(newPower>100)
                    {
                        newPower=100;
                    }
                    if (newPower >=0)
                    {
                        best[nr][nc]= std::max(best[nr][nc], newPower);
                    }
                }
                    // go down and turn right
                if( r+1 <m && power>=3)
                {
                    int nr=r+1;
                    int nc=c+1;

                    int newPower =power +3;
                    if(newPower>100)
                    {
                        newPower=100;
                    }
                    newPower +=grid[nr][nc];
                    if(newPower>100)
                    {
                        newPower=100;
                    }
                    if (newPower >=0)
                    {
                        best[nr][nc]= std::max(best[nr][nc], newPower);
                    }

                }

            }
        }

        for (int r=0; r<m; r++)
        {
            if(best[r][n-1]>=0)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int m,n;
    std::cout<<" Enter m rows and n columns: ";
    std::cin>>m>>n;

    std::vector<std::vector<int>> grid(m, std::vector<int>(n));

    std::cout<< "Enter grid: \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin >>grid[i][j];
        }
    }

    Solution sol;
    if (sol.canReachEnd(grid))
    {
        std::cout<<"true"<<'\n';
    }
    else
    {
        std::cout<<"false"<<'\n';
    }
    return 0;
}