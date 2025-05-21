class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // lb graph lec 7

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        unordered_set<string>m(wordList.begin(),wordList.end());
        m.erase(beginWord);

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            string frontString=front.first;
            int frontDist=front.second;

            if(frontString==endWord) {
                return frontDist;
            }
            else{
                for(int i=0;i<frontString.size();i++){
                    char originalChar=frontString[i];
                    for(char ch='a';ch<='z';ch++){
                    frontString[i]=ch;

                    if(m.find(frontString) !=m.end()){
                         q.push({frontString,frontDist+1});
                         m.erase(frontString);
                    }
                    }
                    frontString[i]=originalChar;
                }
            }

        }
        return 0;
    }
};