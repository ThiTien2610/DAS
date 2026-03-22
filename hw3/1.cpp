#include <iostream>
#include <vector>
#include<algorithm>

std::vector<std::vector<int>> MergeIntervals(std::vector<std::vector<int>>& arr)
{
    int n= arr.size();
    sort(arr.begin(), arr.end());

    std::vector<std::vector<int>> ans;

    for (int i=0; i<n; i++)
    {
        if(ans.empty() || arr[i][0] > ans.back()[1] )
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1]= std::max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    std::cin>>n;

    std::vector<std::vector<int>> arr(n, std::vector<int>(2));

    for (int i=0; i<n; i++)
    {
        std::cin>> arr[i][0]>>arr[i][1];
    }

    std::vector<std::vector<int>> result= MergeIntervals(arr);

    for(int i=0; i < result.size(); i++)
    {
        std::cout<< "[" <<result[i][0]<< "," << result[i][1] << ")";

    }
    return 0;
}

