#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void RemoveExtraSpace(string& s)
    {
        int slow = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (slow != 0)
                {
                    s[slow] = ' ';
                    slow++;
                }
                while (i < s.size() && s[i] != ' ')
                {
                    s[slow] = s[i];
                    slow++;
                    i++;
                }
            }
        }
        s.resize(slow);
    }

    void Reverse(string& s, int start, int end)
    {
        int l = start, r = end;
        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

    string reverseWords(string s)
    {
        if (s.size() == 0) return s;

        RemoveExtraSpace(s);
        Reverse(s, 0, s.size() - 1);

        for (int i = 0; i < s.size(); )
        {
            auto pos = s.find(' ', i);
            if (pos == string::npos)
            {
                Reverse(s, i, s.size() - 1);
                break;
            }
            else
            {
                Reverse(s, i, pos - 1);
                i = pos + 1;
            }
        }
        return s;
    }
};