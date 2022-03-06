#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mData;
        for (const auto& v : nums) {
            if (mData.find(v) != mData.end()) {
                mData[v]++;
            }
            else {
                mData.emplace(v, 1);
            }
        }

        int degree = 1;
        for (const auto& v : mData) {
            degree = (degree < v.second) ? v.second : degree;
        }

        unordered_map<int, int> left, right;
        for (int i = 0; i < nums.size(); ++i) {
            if (left.count(nums[i]) == 0)
                left[nums[i]] = i;
            right[nums[i]] = i;
        }

        int res = nums.size();
        for (auto& kv : mData) {
            if (kv.second == degree) {
                res = min(res, right[kv.first] - left[kv.first] + 1);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{ 1,2,2,3,1,4,2 };
    Solution s;
    cout << s.findShortestSubArray(nums) << endl;
    return 0;
}