class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;

        for (string& op : operations) {
            if (op == "C") {
                if (!stack.empty())
                    stack.pop_back();
            } else if (op == "D") {
                if (!stack.empty())
                    stack.push_back(2 * stack.back());
            } else if (op == "+") {
                int n = stack.size();
                stack.push_back(stack[n - 1] + stack[n - 2]);
            } else {
                stack.push_back(stoi(op));
            }
        }

        return accumulate(stack.begin(), stack.end(), 0);
    }
};