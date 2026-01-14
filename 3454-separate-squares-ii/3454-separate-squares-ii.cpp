class Solution {
public:
    struct Event {
        long long y;
        long long x1, x2;
        int type; // +1 = add, -1 = remove
    };

    struct SegTree {
        int n;
        vector<long long> coverLen;
        vector<int> coverCnt;
        vector<long long> xs;

        SegTree(const vector<long long>& coords) {
            xs = coords;
            n = xs.size() - 1;
            coverLen.assign(4 * n, 0);
            coverCnt.assign(4 * n, 0);
        }

        void pushUp(int node, int l, int r) {
            if (coverCnt[node] > 0) {
                coverLen[node] = xs[r] - xs[l];
            } else if (l + 1 == r) {
                coverLen[node] = 0;
            } else {
                coverLen[node] = coverLen[node * 2] + coverLen[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql)
                return;
            if (ql <= l && r <= qr) {
                coverCnt[node] += val;
                pushUp(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
            pushUp(node, l, r);
        }

        long long totalCovered() { return coverLen[1]; }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<long long> xs;

        // Build events
        for (auto& s : squares) {
            long long x = s[0];
            long long y = s[1];
            long long l = s[2];

            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});

            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](long long x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a.y < b.y; });

        SegTree st(xs);

        // First pass: compute total union area
        double totalArea = 0.0;
        for (int i = 0; i + 1 < events.size(); i++) {
            int l = getX(events[i].x1);
            int r = getX(events[i].x2);
            st.update(1, 0, st.n, l, r, events[i].type);

            double dy = events[i + 1].y - events[i].y;
            totalArea += st.totalCovered() * dy;
        }

        double target = totalArea / 2.0;

        // Second pass: find split y
        st = SegTree(xs);
        double currArea = 0.0;

        for (int i = 0; i + 1 < events.size(); i++) {
            int l = getX(events[i].x1);
            int r = getX(events[i].x2);
            st.update(1, 0, st.n, l, r, events[i].type);

            double dy = events[i + 1].y - events[i].y;
            double sliceArea = st.totalCovered() * dy;

            if (currArea + sliceArea >= target) {
                double remaining = target - currArea;
                return events[i].y + remaining / st.totalCovered();
            }

            currArea += sliceArea;
        }

        // Should not reach here
        return events.back().y;
    }
};