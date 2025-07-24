class Solution {
public:
    // https://youtu.be/SmTow5Ht4iU?si=kxSfcc6Gv1c9Ykzs

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0, totalGas = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
        }
        for (int i = 0; i < cost.size(); i++) {
            totalCost += cost[i];
        }

        if (totalGas < totalCost)
            return -1;

        int st = 0, currGas = 0;

        for (int i = 0; i < gas.size(); i++) {

            currGas = currGas + gas[i] - cost[i];

            if (currGas < 0) {
                st = i + 1;
                currGas = 0;
            }
        }

        return st;
    }
};