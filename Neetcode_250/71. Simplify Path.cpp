class Solution {
public:
    string simplifyPath(string path) {
        const int n = path.length();
        vector<string> stk;
        string dir;
        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') continue;
            dir.clear();
            while (i < n && path[i] != '/') dir.push_back(path[i++]);
            if (dir == "..") {
                if (!stk.empty()) stk.pop_back();
            } 
            else if (dir != ".") stk.push_back(dir);
        }
        if (stk.empty()) return "/";
        string res;
        res.reserve(n);
        for (auto& d : stk) {
            res.push_back('/');
            res += d;
        }
        return res;
    }
};