#include <vector>
#include <algorithm>
#include <iostream>

bool canJump(const std::vector<int>& nums)
{
    int n= nums.size();
    int farthest=0;

    for (int i=0; i<n; i++)
    {
        if (i> farthest)
        {
            return false;
        }

        farthest = std::max(farthest, i + nums[i]);
    }

    return true;

}
int main()
{
    int n;
    std::cin>>n;

    std::vector<int> nums(n);
    for (int i=0; i<n; i++)
    {
        std::cin>> nums[i];
    }
    if (canJump(nums))
    { 
        std::cout<< "true";
    }
    else
    {
        std::cout<< "false";
    }
    return 0;
}
