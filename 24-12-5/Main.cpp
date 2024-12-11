#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    bool IsSubString(const int* s_map, const int* t_map)
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            if (s_map[c] < t_map[c]) { return false; }
        }
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (s_map[c] < t_map[c]) { return false; }
        }

        return true;
    }

    string minWindow(string s, string t) {
        if (t.size() > s.size()) { return ""; }

        int s_map[128];
        int t_map[128];
        for (int i = 0; i < t.size(); i++) { t_map[t[i]]++; }

        string ans;
        int l = 0, flag = 1;
        for (int i = 0; i < s.size(); i++)
        {
            s_map[s[i]]++;
            while (IsSubString(s_map, t_map))
            {
                if (flag)
                {
                    ans = s.substr(l, i - l + 1);
                    flag = 0;
                }
                if (ans.size() > i - l + 1) { ans = s.substr(l, i - l + 1); }
                s_map[s[l]]--;
                l++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution().minWindow("ABC", "B");
    return 0;
}