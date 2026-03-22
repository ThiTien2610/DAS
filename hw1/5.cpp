#include<iostream>
#include<vector>

std::vector<int> twoSum(const std::vector<int>&nums, int target)
{
    int n=(int)nums.size();
    for(int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if(nums[i]+nums[j] == target)
            {
                return {i,j};
            }
        }
    }
    return {};
}
// if = (n(n-1))/2 ~ O(n^2): Time complexity

int main()
{
    std::vector<int> nums= {2,7,11,15};
    int target=9;
    std::vector<int> result = twoSum(nums,target);
    if(!result.empty())
    {
        std::cout<<"Indices: " << result[0]<< result [1]<<"\n";
    }
    else
    {
        std::cout<<"No solution"<<"\n";

    }
    return 0;
}