class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                      vector<int>& vFences) {

        // Add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Store all possible horizontal gaps
        unordered_set<long long> hDiffs;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDiffs.insert((long long)hFences[j] - hFences[i]);
            }
        }

        long long maxSide = -1;

        // Check vertical gaps and find max common
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long diff = (long long)vFences[j] - vFences[i];
                if (hDiffs.count(diff)) {
                    maxSide = max(maxSide, diff);
                }
            }
        }

        if (maxSide == -1)
            return -1;

        long long area = (maxSide % MOD) * (maxSide % MOD) % MOD;
        return (int)area;
    }
};