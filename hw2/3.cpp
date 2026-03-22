#include<vector>
#include<iostream>
int missingNumber( const std::vector<int>& nums)
{
    int allXOR=0;
    int n=nums.size();

    for(int i=0; i<=n; ++i)
    {
        allXOR= allXOR ^i;
    }
    for(int i=0; i<n; ++i)
    {
        allXOR= allXOR ^nums[i];
    }
    return allXOR;
}

int main()
{
    std::vector<int> nums ={0, 4, 5, 3, 2};
    std::cout<< missingNumber(nums)<<'\n';
    return 0;
}