#include <vector>
#include<iostream>
class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        std::vector<int> fib ={1,1};
        while (fib.back() + fib[fib.size()-2]<=k)
        {
            fib.push_back(fib.back() + fib[fib.size()-2]);
        }
    

        int ans=0;
        for(int i=fib.size()-1; i>=0; i--)
        {
            if(fib[i]<=k)
            {
                k-=fib[i];
                ans ++;
            }
            if (k==0) break;
        }

    return ans;
    }
};

int main()
{
    Solution sol;

    int k;
    std::cout<< "Enter k: ";
    std::cin>> k;

    int result =sol.findMinFibonacciNumbers(k);
    std::cout<< "Minimum Fibonacci numbers: "<< result<<'\n';
    return 0;
}