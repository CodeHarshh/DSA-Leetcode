class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mini;
        for (int i = 0; i < timePoints.size(); i++) {
            int hours =
                (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
            // or hours=stoi(timePoints[i].substr(0,2)); 
            // It will return substring of length 2 starting from 0
            int minutes =
                (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
            // or minutes=stoi(timePoints[i].substr(3,2));
            //  It will also return sunstring of length 2 starting from 3
        
            int rizz = hours * 60 + minutes;
            mini.push_back(rizz);
        }
        sort(mini.begin(), mini.end());
        int maxminimun = INT_MAX;
        for (int i = 1; i < mini.size(); i++) {
            int minimum = mini[i] - mini[i - 1];
            maxminimun = min(maxminimun, minimum);
        }
//         Normal difference: 1439 - 1 = 1438 minutes ❌ (wrong)
//         Circular difference: 1440 + 1 - 1439 = 2 minutes ✅ (correct)
        int circular = 1440 + mini[0] - mini.back();
        return min(maxminimun, circular);
        return maxminimun;
    }
};