#include <vector>
#include <string>
#include <unordered_map>

#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mapData;
        for (const auto& domain : cpdomains) {
            string delimiter{ " " };
            std::size_t found = domain.find(delimiter);
            if (found != string::npos) {
                int count = stoi(domain.substr(0, found));
                string str = domain.substr(found + 1);
                if (mapData.find(str) != mapData.end()) {
                    mapData[str] += count;
                }
                else {
                    mapData.emplace(str, count);
                }
                found = str.find(".");
                while (found != string::npos) {
                    str = str.substr(found + 1);
                    if (mapData.find(str) != mapData.end()) {
                        mapData[str] += count;
                    }
                    else {
                        mapData.emplace(str, count);
                    }
                    found = str.find(".");
                }
            }
        }
        vector<string> vReturn;
        for (const auto& v : mapData)
        {
            auto s = std::to_string(v.second) + " " + v.first;
            vReturn.emplace_back(s);
        }
        return vReturn;
    }
};

int main()
{
    vector<string> domains{ "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };

    Solution s;
    auto v = s.subdomainVisits(domains);

    for (const auto& i : v) {
        cout << i << endl;
    }

    return 0;
}