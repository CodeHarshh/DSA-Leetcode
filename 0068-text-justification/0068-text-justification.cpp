class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> cuurentLine;
        int cuurentLineTotalChar = 0;
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];

            int currentNoOfSpaceNeeded = cuurentLine.size();

            if (cuurentLineTotalChar + currentNoOfSpaceNeeded +
                    currentWord.size() >
                maxWidth) {
                int extraSpace = maxWidth - cuurentLineTotalChar;

int spaceGoBetweenWords = extraSpace / max(1, (int)cuurentLine.size() - 1);
 int remainder = extraSpace % max(1, (int)cuurentLine.size() - 1);

                // we dont need space after last word
                for (int j = 0; j < cuurentLine.size() - 1; j++) {
                    for (int k = 0; k < spaceGoBetweenWords; k++) {
                        cuurentLine[j] = cuurentLine[j] + ' ';

                        if (remainder > 0) {
                            cuurentLine[j] = cuurentLine[j] + ' ';
                            remainder--;
                        }
                    }
                }
                if (cuurentLine.size() == 1) {
                    while (extraSpace--) {
                        cuurentLine[0] = cuurentLine[0] + ' ';
                    }
                }
                // final line
                string finalLine = "";
                for (string i : cuurentLine) {
                    finalLine = finalLine + i;
                }

                ans.push_back(finalLine);
                cuurentLine.clear();
                cuurentLineTotalChar = 0;
            }

            cuurentLine.push_back(currentWord);
            cuurentLineTotalChar += currentWord.size();
        }
        // Now we have to add last Line
        // add 1 space B|w them
        string finalLine = "";
        for (auto it : cuurentLine) {
            finalLine = finalLine + it + " ";
        }
        finalLine.pop_back();

        int leftspace = maxWidth - finalLine.size();
        while (leftspace--) {
            finalLine = finalLine + " ";
        }
        ans.push_back(finalLine);

        return ans;
    }
};