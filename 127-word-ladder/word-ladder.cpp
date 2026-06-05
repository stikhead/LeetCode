class Solution {
public:
    // bool differByOneLetter(string a, string b){
    //     int count = 0;
    //     int pointer_a = 0;
    //     int pointer_b = 0;
    //     for(int i=0; i<a.size(); i++){
    //         if(a[pointer_a]!=b[pointer_b]){
    //             count++;
    //         }
    //         pointer_a++;
    //         pointer_b++;
    //     }
    //     return count > 1 ? false : true;
    // }
    // void buildGraphAdjList(vector<vector<int>> &adjList, vector<string> &wordList, string &beginWord, string &endWord){
    //     for(int i=wordList.size()-1; i>=0; i--){
    //         if(differByOneLetter(beginWord, wordList[i])){
    //             adjList[0].push_back(i+1);
    //         }
    //     }

    //       for(int i=0; i<wordList.size(); i++){
    //         for(int j=0; j<wordList.size(); j++){
    //             if(i!=j && differByOneLetter(wordList[i], wordList[j])){
    //                 adjList[i+1].push_back(j+1);
    //             }
    //         }
    //     }
    // }

    // bool isSeq(string endWord, vector<string>& wordList){
    //     for(int i=0; i<wordList.size(); i++){
    //         if(endWord==wordList[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict;
        for(int i=0; i<wordList.size(); i++){
            dict.insert(wordList[i]);
        }

        if(dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int count = 1;

        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i=0; i<size; i++){
                string word = q.front();
                q.pop();

                for(int j=0; j<word.size(); j++){
                    char orgWord = word[j];
                    for(char c='a'; c<='z'; c++){
                        word[j] = c;

                        if(word==endWord) return count;

                        if(dict.find(word) != dict.end()){
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = orgWord;
                }

            }
        }

        return 0;

        // if(isSeq(endWord, wordList)) return 0;
        // vector<vector<int>> adjList(wordList.size()+1);
        // buildGraphAdjList(adjList, wordList, beginWord, endWord);
        // int count = 1;
        // vector<int> vis(wordList.size()+1, 0);
        // queue<int> q;
        // q.push(0);
        // vis[0] = 1;
        // while(!q.empty()){
        //     int size = q.size();
        //     count++;
        //     for(int j=0; j<size; j++){
        //         int node = q.front();
        //         q.pop();
        //         for(int i=0; i<adjList[node].size(); i++){
        //             if(vis[adjList[node][i]]==0){
        //                 if(wordList[adjList[node][i]-1]==endWord){
        //                     return count;
        //                 }   
        //                 vis[adjList[node][i]] = 1;
        //                 q.push(adjList[node][i]);
        //             }
        //         }
        //     }
        // }
        // return 0;

    }
};