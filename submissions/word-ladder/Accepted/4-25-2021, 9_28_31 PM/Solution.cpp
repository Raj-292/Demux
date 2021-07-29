// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        
        // Initialize with the beginWord
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        // Start a level-order traversal.
        while(!q.empty()) {
            pair<string, int> t = q.front();
            q.pop();
            
            if (t.first == endWord) {
                return t.second;
            }
            
            // Go through the neighbours, mark them visited and push them in the queue.
            string word = t.first;
            int dist = t.second;
            for (int i = 0; i < word.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    word[i] = (j + 'a');
                    
                    if (dict.find(word) != dict.end() && visited.find(word) == visited.end()) {
                        visited.insert(word);
                        q.push({word, dist+1});
                    }
                    
                    word[i] = (t.first)[i];
                }
            }
        }
        
        return 0;
    }
};