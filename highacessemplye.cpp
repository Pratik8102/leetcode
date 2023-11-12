#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& time) 
    {
        int n = time.size();
        vector<string> ans;
        unordered_map<string, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            string word = time[i][0];
            int acctime = stoi(time[i][1]);
            mp[word].push_back(acctime);
        }

        for (auto& query : mp)
        {
            vector<int> t = query.second;
            sort(t.begin(), t.end());

            if (t.size() >= 3)
            {
                for (int i = 0; i < t.size(); i++)
                {
                    bool flag = false;
                    int cnt = 1;
                    int d = t[i];

                    for (int j = i + 1; j < t.size(); j++)
                    {
                        if (t[j] - d <= 99)
                        {
                            cnt++;
                            if (cnt >= 3) { flag = true; break; }
                        }
                        else
                        {
                            d = t[j];
                            cnt = 1;
                        }
                    }

                    if (flag == true)
                    {
                        ans.push_back(query.first);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    // Example usage
       vector<vector<string>> time = {{"d", "0002"}, {"c", "0808"}, {"c", "0829"}, {"e", "0215"},
                                   {"d", "1508"}, {"d", "1444"}, {"d", "1410"}, {"c", "0809"}};

    Solution solution;
    vector<string> result = solution.findHighAccessEmployees(time);

    // Displaying the result
    cout << "Employees with high access: ";
    for (const auto& emp : result) {
        cout << emp << " ";
    }
    cout << endl;

    return 0;
}
