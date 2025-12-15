class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> prens = {
            {'}', '{'}, {')', '('}, {']', '['}};
        std::stack<char> pStack;

        for (char c : s) {

            if (!prens.contains(c)) {
                pStack.push(c);
            } else {
                char top = pStack.empty() ? '#': pStack.top();
                 pStack.pop();
                 if(top!=prens[c])
                 return false;
            }
        }

        return pStack.empty();
    }
};