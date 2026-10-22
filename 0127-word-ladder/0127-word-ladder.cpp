class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,0});// level is zero alright.
        unordered_map<string,int>mpp;
        mpp[beginWord]++;
        while(!q.empty()){
            string str = q.front().first;
            int level = q.front().second;
            q.pop();
            for(int i=0;i<wordList.size();i++){
                if(mpp.find(wordList[i])!=mpp.end()) continue;
                else{
                    int diff = inner_product(str.begin(), str.end(), wordList[i].begin(), 0,
                         plus<>(), not_equal_to<>());
                         if(diff==1){
                            if(wordList[i]==endWord) return (level+1)+1;
                            mpp[wordList[i]]++;// you have marked it.
                            q.push({wordList[i],level+1});

                         }
                }
            }
        }
        return 0;
    }
};