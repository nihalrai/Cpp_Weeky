#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        long long inf = 1 << 29;
        long long ans = 0;
        long long inf = 1 << 29;
        std::vector<std::vector<int>> weights(26, std::vector<int>(26));
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (i == j)
                {
                    weights[i][i] = 0;
                }
                else
                {
                    weights[i][j] = inf;
                }
            }
        }
        for (int i = 0; i < original.size(); ++i)
        {
            weights[original[i] - 'a'][changed[i] - 'a'] = std::min(cost[i], weights[original[i] - 'a'][changed[i] - 'a']);
        }
        for (int k = 0; k < 26; ++k)
        {
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    weights[i][j] = std::min(weights[i][j], weights[i][k] + weights[k][j]);
                }
            }
        }

        for (int i = 0; i < source.size(); ++i)
        {
            if (source[i] == target[i])
            {
                continue;
            }
            else if (weights[source[i] - 'a'][target[i] - 'a'] >= inf)
            {
                ans = -1;
                break;
            }
            else
            {
                ans += weights[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution = Solution();
    string source = "abcd";
    string target = "acbe";
    std::vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    std::vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    std::vector<int> cost = {2, 5, 5, 1, 2, 20};

    std::cout << solution.minimumCost(source, target, original, changed, cost);

    return 0;
}