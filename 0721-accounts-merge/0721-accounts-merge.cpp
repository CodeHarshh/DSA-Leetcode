class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = findParent(parent[x], parent); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = findParent(x, parent);
        int rootY = findParent(y, parent);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToID; // Map email -> unique ID
        unordered_map<int, string> idToName;  // Map ID -> Name
        int n = 0;

        vector<int> parent(10001);
        vector<int> rank(10001, 0);
        for (int i = 0; i < parent.size(); i++) parent[i] = i;

        // Step 1: Map emails to unique IDs and record names
        for (const auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (!emailToID.count(email)) {
                    emailToID[email] = n++;
                }
                idToName[emailToID[email]] = name;
                if (i > 1) {
                    unionSets(emailToID[account[i - 1]], emailToID[email], parent, rank);
                }
            }
        }

        // Step 2: Group emails by their root parent
        unordered_map<int, vector<string>> groups;
        for (const auto& [email, id] : emailToID) {
            int rootID = findParent(id, parent);
            groups[rootID].push_back(email);
        }

        // Step 3: Prepare the result
        vector<vector<string>> result;
        for (const auto& [id, emails] : groups) {
            vector<string> mergedAccount;
            mergedAccount.push_back(idToName[id]); // Add name
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            sort(mergedAccount.begin() + 1, mergedAccount.end()); // Sort emails
            result.push_back(mergedAccount);
        }

        return result;
    }
};
