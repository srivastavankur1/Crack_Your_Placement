class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return backspace(s) == backspace(t);
    }

private:
    string backspace(string& s) {
        string stack;
        for (char c : s)
        if (c != '#')
            stack.push_back(c);
        else if (!stack.empty())
            stack.pop_back();
        return stack;
    }    
};