#include<vector>
#include<iostream>
int findLeftBound( const std::vector<int>& nums, int target)
{
    int low=0, high=nums.size();
    while(low<high)
    {
        int mid =low +(high-low)/2;
        if (nums[mid]< target)
        {
            low=mid+1;
        }
        else {high=mid;}
    }
    return low;
}

int findRightBoundExcluded( const std::vector<int>& nums, int target)
{
    int low=0, high=nums.size();
    while(low<high)
    {
        int mid =low +(high-low)/2;
        if (nums[mid]<=target)
        {
            low=mid+1;
        }
        else {high=mid;}
    }
    return low;
}

std::pair<int,int> searchRange(const std::vector<int>& nums, int target)
{
    int left = findLeftBound(nums,target);
    int right= findRightBoundExcluded(nums,target);
    if (left ==nums.size() || nums[left]!= target)
    {
        return {-1, -1};
    }
    return{left,right};
}

int main()
{
    std::vector<int> nums ={ 5, 7, 7, 8, 8, 10};
    int target =8;

    std::pair<int, int> result =searchRange(nums, target);
    std::cout<< "[" << result.first << ","<< result.second<< ")"<<'\n';
}