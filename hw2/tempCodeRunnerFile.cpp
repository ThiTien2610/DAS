#include<vector>
#include<iostream>
int findPeakElement(const std::vector<int>& nums)
{
    int n=nums.size();
    if (n==1) {return 0;}
    if (nums[0] > nums[1]) {return 0;}
    if (nums[n-1] > nums[n-2]) {return n-1;}

    int low=1, high =n-2;
    while(low<= high)
    {
        int mid =low+(high-low)/2;
        if (nums[mid]> nums[mid-1]&& nums[mid]> nums[mid+1])
        { return mid;}
        else if (nums[mid]> nums[mid-1])
        { low=mid+1;}
        else { high= mid-1;}
    }
    return -1;
}
int main()
{
    std::vector<int> nums ={1,2,3,1};
    int peakIndex= findPeakElement(nums);
    std::cout<< "Peak Index:"<< peakIndex<< '\n';
    return 0;
}