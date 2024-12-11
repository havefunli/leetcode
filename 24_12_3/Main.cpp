#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

//class Solution {
//public:
//    int romanToInt(const string& s) {
//        unordered_map<char, int> map;
//        map['I'] = 1;
//        map['V'] = 5;
//        map['X'] = 10;
//        map['L'] = 50;
//        map['C'] = 100;
//        map['D'] = 500;
//        map['M'] = 1000;
//
//        int ans = 0;
//        char prev = s[0];
//        for (auto c : s)
//        {
//            if (prev == 'I')
//            {
//                if (c == 'V' || c == 'X')
//                {
//                    ans -= map['I'];
//                    ans += (map[c] - map['I']);
//                    continue;
//                }
//            }
//            else if (prev == 'X')
//            {
//                if (c == 'L' || c == 'C')
//                {
//                    ans -= map['X'];
//                    ans += (map[c] - map['X']);
//                    continue;
//                }
//            }
//            else if (prev == 'C')
//            {
//                if (c == 'D' || c == 'M')
//                {
//                    ans -= map['C'];
//                    ans += (map[c] - map['C']);
//                    continue;
//                }
//            }
//            ans += map[c];
//        }
//
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    vector<pair<int, string>> map = {
//        {1000, "M"},
//        {900,  "CM"},
//        {500,  "D"},
//        {400,  "CD"},
//        {100,  "C"},
//        {90,   "XC"},
//        {50,   "L"},
//        {40,   "XL"},
//        {10,   "X"},
//        {9,    "IX"},
//        {5,    "V"},
//        {4,    "IV"},
//        {1,    "I"}
//    };
//
//        string intToRoman(int num) {
//        string ans;
//        for (int i = 0; i < map.size(); i++)
//        {
//            while (num >= map[i].first)
//            {
//                ans += map[i].second;
//                num -= map[i].first;
//            }
//            if (num == 0) { break; }
//        }
//
//        return ans;
//    }
//};


//class Solution {
//public:
//
//    string reverseWords(string s) {
//        stringstream ss(s);
//        stack<string> st;
//        string tmp;
//        while (ss >> tmp)
//        {
//            st.push(tmp);
//        }
//
//        s.clear();
//        while (!st.empty())
//        {
//            s += (st.top() + ' ');
//            st.pop();
//        }
//        s.erase(s.end() - 1);
//        return s;
//    }
//};


class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int num = (numRows - 1) * 2 == 0 ? 1 : (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = i; j < s.size(); j += num)
            {
                ans.push_back(s[j]);
            }
        }

        return ans;
    }
};


int main()
{
    string str = "PAYPALISHIRING";
    Solution().convert(str, 3);
    return 0;
}