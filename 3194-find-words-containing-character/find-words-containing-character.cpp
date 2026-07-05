class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
         std::vector<int> result;
        
        for (int i = 0; i < words.size(); ++i) {
            // Using std::any_of and a lambda expression
            if (std::any_of(words[i].begin(), words[i].end(), [x](char c) { return c == x; })) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};