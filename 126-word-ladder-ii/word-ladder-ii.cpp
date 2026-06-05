class Solution {
public:
    void dfs(vector<vector<string>>& ans,
             unordered_map<string, vector<string>>& map,
             vector<string>& constructor, string& beginWord, string currWord) {
        if (currWord == beginWord) {
            vector<string> temp = constructor;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string i : map[currWord]) {
            constructor.push_back(i);
            dfs(ans, map, constructor, beginWord, i);
            constructor.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> dict;
        for (int i = 0; i < wordList.size(); i++) {
            dict.insert(wordList[i]);
        }

        unordered_map<string, vector<string>> map;
        queue<string> q;
        int count = 1;
        q.push(beginWord);
        dict.erase(beginWord);
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            count++;
            unordered_set<string> visitedThisLayer;
            for (int i = 0; i < size; i++) {
                string node = q.front();
                q.pop();

                for (int j = 0; j < node.size(); j++) {
                    string parent = node;

                    for (char c = 'a'; c <= 'z'; c++) {
                        node[j] = c;

                        if (node == endWord) {
                            found = true;
                        }

                        if (dict.find(node) != dict.end()) {
                            if (visitedThisLayer.find(node) ==
                                visitedThisLayer.end()) {
                                q.push(node);
                                visitedThisLayer.insert(node);
                            }

                            map[node].push_back(parent);
                        }
                    }

                    node = parent;
                }
            }
                    for (string word : visitedThisLayer) {
                        dict.erase(word);
                    }
        }

        for (auto [i, j] : map) {
            cout << i << ": ";
            for (auto k : j) {
                cout << k << " ";
            }
            cout << endl;
        }
        vector<vector<string>> ans;
        if (found) {
            vector<string> constructor;
            constructor.push_back(endWord);
            dfs(ans, map, constructor, beginWord, endWord);
        }
        return ans;
    }
};