#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> used(26, 0);
        for(int i=0; i<s.size(); ++i){
            if(s[i] != t[i]){
                int curr = t[i] - s[i] % 26;
                if(curr < 0 or curr >= 26){   //  this check is needed to avoid negative index or overflow index, sanitizers warn it as error.
                    curr = curr % 26;
                }
                int value = 26*used[curr] + curr;
                if(value > k){
                    return false;
                }
                used[curr]++;
            }
        }        
        return true;
    }
};

int main()
{
    Solution solution = Solution();
    string s = "atmtxzjkz";
    string t = "tvbtjhvjd";
    int k = 35;
    std::cout << solution.canConvertString(s, t, k);

    return 0;
}