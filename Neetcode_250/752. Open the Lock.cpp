class Solution {
public:

    void fillNeighbours(queue<string> &que, string &curr, unordered_set<string> &st) {
        for (int i = 0; i < 4; i++) {
            char ch = curr[i];

            char dec = (ch == '0') ? '9' : ch - 1;
            char inc = (ch == '9') ? '0' : ch + 1;

            // Try decrement
            curr[i] = dec;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                que.push(curr);
            }

            // Try increment
            curr[i] = inc;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                que.push(curr);
            }

            // Restore
            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string> st(begin(deadends), end(deadends));

        if (st.count(start)) return -1; // if starting position is dead

        queue<string> que;
        que.push(start);
        st.insert(start);

        int level = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                string curr = que.front();
                que.pop();

                if (curr == target)
                    return level;

                fillNeighbours(que, curr, st);
            }

            level++;
        }

        return -1; // if target not reachable
    }
};