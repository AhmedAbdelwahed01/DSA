class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty())
            return s;

        vector<std::string> specials;

        int count = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                count++;
            else
                count--;

            if (count == 0) {
                string sp = s.substr(start + 1, i - start - 1);

                specials.push_back("1" + makeLargestSpecial(sp) + "0");
                start = i + 1;
            }
        }

        std::sort(specials.begin(), specials.end(),greater<string>());

        std::string ss = "";
        for (string& c : specials) {
            ss += c;
        }

        return ss;
    }
};