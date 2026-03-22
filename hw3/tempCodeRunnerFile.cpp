#include <iostream>
#include <vector>
#include <algorithm>

bool compareEnvelopes(const std::vector<int>& a, const std::vector<int>& b)
{
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int maxEnvelopes(std::vector<std::vector<int>>& envelopes)
{
    if (envelopes.empty())
    {
        return 0;
    }

    std::sort(envelopes.begin(), envelopes.end(), compareEnvelopes);

    std::vector<int> seq;
    seq.push_back(envelopes[0][1]);

    for (int i = 1; i < (int)envelopes.size(); i++)
    {
        int h = envelopes[i][1];

        if (seq.back() < h)
        {
            seq.push_back(h);
        }
        else
        {
            int ind = std::lower_bound(seq.begin(), seq.end(), h) - seq.begin();
            seq[ind] = h;
        }
    }

    return (int)seq.size();
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> envelopes(n, std::vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        std::cin >> envelopes[i][0] >> envelopes[i][1];
    }

    std::cout << maxEnvelopes(envelopes);

    return 0;
}