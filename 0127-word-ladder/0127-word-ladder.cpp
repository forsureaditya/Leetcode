class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);// as it is visited.
        
        while(!q.empty()){
            string str = q.front().first;
            int level = q.front().second;
            q.pop();
            if(str==endWord) return level;
            for(int i=0;i<str.size();i++){
                string original = str;
                vector<string>collection;
                for(char ch = 'a';ch<='z';ch++){
                    str[i]=ch;
                    if(st.find(str)!=st.end()){
                        q.push({str,level+1});
                        collection.push_back(str);
                    }

                }
                str = original; // cuz ek time par ek hi change karna hai 
            for(auto it: collection){
                st.erase(it);
            }
            }
        }
        return 0;

    }
};