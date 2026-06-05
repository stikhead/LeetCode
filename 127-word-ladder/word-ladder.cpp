class Solution {
public:
    bool differByOneLetter(string a, string b){
        int count = 0;
        int pointer_a = 0;
        int pointer_b = 0;
        for(int i=0; i<a.size(); i++){
            if(a[pointer_a]!=b[pointer_b]){
                count++;
            }
            pointer_a++;
            pointer_b++;
        }
        return count > 1 ? false : true;
    }
    void buildGraphAdjList(vector<vector<int>> &adjList, vector<string> &wordList, string &beginWord, string &endWord){
        for(int i=0; i<wordList.size(); i++){
            if(differByOneLetter(beginWord, wordList[i])){
                adjList[0].push_back(i+1);
            }
        }

          for(int i=0; i<wordList.size(); i++){
            for(int j=0; j<wordList.size(); j++){
                if(i!=j && differByOneLetter(wordList[i], wordList[j])){
                    adjList[i+1].push_back(j+1);
                }
            }
        }
    }

    bool isSeq(string endWord, vector<string>& wordList){
        for(int i=0; i<wordList.size(); i++){
            if(endWord==wordList[i]){
                return false;
            }
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(isSeq(endWord, wordList)) return 0;
        vector<vector<int>> adjList(wordList.size()+1);
        buildGraphAdjList(adjList, wordList, beginWord, endWord);

        for(int i=0; i<adjList.size(); i++){
            for(int j=0; j<adjList[i].size(); j++){
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl;
        }
        int count = 1;
        vector<int> vis(wordList.size()+1, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int j=0; j<size; j++){
                int node = q.front();
                q.pop();
                for(int i=0; i<adjList[node].size(); i++){
                    if(vis[adjList[node][i]]==0){
                        if(wordList[adjList[node][i]-1]==endWord){
                            return count;
                        }   
                        vis[adjList[node][i]] = 1;
                        q.push(adjList[node][i]);
                        cout<<wordList[adjList[node][i]-1]<<" ";
                    }
                }
            }
        }
        return 0;

    }
};