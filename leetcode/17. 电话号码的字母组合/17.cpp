class Solution
{
    unordered_map<int, vector<char>> digit;

    vector<char> path;
    vector<string> ans;
    int n;
    string di;

    void dfs(int i)
    {
        if (i == n)
        {
            string s(path.begin(), path.end()); // 长度都是一样的，不会错乱
            ans.emplace_back(s);
            return;
        }

        vector<char> temp = digit[di[i] - '0']; // 每次从哈希表里取对应字母的时候
        // 对传入的i做了处理，因此dfs的时候传入int i即可
        for (char c : temp)
        {
            path.emplace_back(c);
            dfs(i + 1);
            path.pop_back();
        }
    }

public:
    Solution()
    {
        digit[2] = {'a', 'b', 'c'};
        digit[3] = {'d', 'e', 'f'};
        digit[4] = {'g', 'h', 'i'};
        digit[5] = {'j', 'k', 'l'};
        digit[6] = {'m', 'n', 'o'};
        digit[7] = {'p', 'q', 'r', 's'};
        digit[8] = {'t', 'u', 'v'};
        digit[9] = {'w', 'x', 'y', 'z'};
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        n = digits.size();
        di = digits;
        dfs(0);
        return ans;
    }
};