class Solution {
public:
    void backtrackWordBreak(const std::string& s,
                            const std::unordered_set<std::string>& wordSet,
                            std::vector<std::string>& results,
                            const std::string& currentSentence = "") {
        std::string word;

        // try every possible prefix of string `s`
        for (size_t i = 0; i < s.length(); ++i) {
            word += s[i];

            // check if this prefix is a valid dictionary word
            if (wordSet.find(word) != wordSet.end()) {
                // construct a new sentence
                std::string sentence = currentSentence.empty()
                    ? word
                    : currentSentence + " " + word;

                // if we've reached the end of string `s`, store the sentence
                if (i == s.length() - 1) {
                    results.push_back(sentence);
                } 
                // otherwise, continue exploring the rest of the string
                else {
                    backtrackWordBreak(s.substr(i + 1), wordSet, results, sentence);
                }
            }
        }
    }

    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        // convert vector to unordered_set for O(1) lookups
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        
        std::vector<std::string> results;
        backtrackWordBreak(s, wordSet, results);
        return results;
    }
};