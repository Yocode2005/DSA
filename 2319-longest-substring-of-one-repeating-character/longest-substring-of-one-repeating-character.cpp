class Solution {
public:
    struct Node {
        int len;
        int pref, suff, best;
        char lc, rc;
    };

    vector<Node> seg;
    string s;

    Node merge(Node &L, Node &R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;
        res.len = L.len + R.len;
        res.lc = L.lc;
        res.rc = R.rc;

        res.pref = L.pref;
        if (L.pref == L.len && L.rc == R.lc)
            res.pref += R.pref;

        res.suff = R.suff;
        if (R.suff == R.len && L.rc == R.lc)
            res.suff += L.suff;

        res.best = max(L.best, R.best);
        if (L.rc == R.lc)
            res.best = max(res.best, L.suff + R.pref);

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2, l, mid, pos, c);
        else
            update(idx * 2 + 1, mid + 1, r, pos, c);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    vector<int> longestRepeating(string S, string queryCharacters, vector<int>& queryIndices) {
        s = S;
        int n = s.size();
        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, pos, c);
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};