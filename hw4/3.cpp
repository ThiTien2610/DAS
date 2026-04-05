#include <vector>
#include <iostream>

class Solution
{
public:
    int rob(std::vector<int>& nums)
    {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];

        std::vector<int> dp(n);

        dp[0]= nums[0];
        dp[1]= std::max(nums[0], nums[1]);

        for(int i=2; i<n; i++)
        {
            dp[i]= std::max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
int main()
{
    int n;
    std::cout<<" Enter n houses: ";
    std::cin>> n;

    std::vector<int> nums(n);

    std::cout<<"Enter t[i] treasure: ";
    for(int i=0; i<n; i++)
    {
        std::cin>> nums[i];
    }

    Solution s;
    int result= s.rob(nums);

    std::cout<< " Maximum treasures: "<< result<<'\n';

    return 0;
}
