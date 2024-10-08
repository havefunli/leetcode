//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        if (s.size() == 0) return;
//
//        int l = 0, r = s.size() - 1;
//        while (l < r)
//        {
//            swap(s[l], s[r]);
//            l++;
//            r--;
//        }
//    }
//};

//class Solution {
//public:
//    void reverse(string& s, int begin, int end)
//    {
//        while (begin < end)
//        {
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//    }
//
//    string reverseStr(string s, int k) {
//        int prev = 0;
//        int i = 0;
//        for (i; i < s.size(); i++)
//        {
//            if ((i + 1) % (2 * k) == 0)
//            {
//                reverse(s, i + 1 - 2 * k, i - k);
//                prev = i + 1;
//            }
//        }
//
//
//        if (i - prev < k)
//        {
//            reverse(s, prev, i - 1);
//        }
//        else if (i - prev >= k)
//        {
//            reverse(s, prev, prev + k - 1);
//        }
//
//        return s;
//    }
//};

//#include <iostream>
//#include <string>
//
//
//int main()
//{
//    std::string s;
//    std::string ans;
//    std::cin >> s;
//
//    for (auto ch : s)
//    {
//        if (ch >= '1' && ch <= '9')
//        {
//            ans += "number";
//        }
//        else
//        {
//            ans += ch;
//        }
//    }
//
//    std::cout << ans << std::endl;
//
//    return 0;
//}