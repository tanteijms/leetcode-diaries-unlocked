class Solution
{
public:
    string decodeString(string s)
    {
        // 递归来做。分情况进行讨论

        // 若 s 是空串，直接返回空，不拼接
        if (s.empty())
        {
            return s;
        }

        // 不为空，可以向下递归。
        // 首先考虑，若为字母，那当前的就直接拼接到答案里即可，然后后面的部分可以直接递归得到后面的答案
        // 我们只看第一个字符，后面的都用递归去求解
        if (isalpha(s[0]))
        {
            return s[0] + decodeString(s.substr(1));
            // 直接保留第 0 号，后面的用递归去看，直接截子串
        }

        // 另一种情况，首符是数字，那就需要循环[]里面的内容这个数字这么多次，再后面的，就直接递归进行处理。
        // 那么需要精准定位到[]的位置。[ 显然可以直接 find
        // 找到第一个，但是]，由于可能存在嵌套，无法进行直接定位。需要通过左右括号的数量来进行匹配
        // 另外注意当前首符是数字，但是此数字可能不是个位数，因此不是简单的第二个字符一定就是[，需要注意
        int i = s.find('['); // 用 find 去找，不一定就是第二个字符
        // 需要统计左右括号的数量精准找到对应的 ]
        int balance = 1; // 左括号数量 - 右括号数量
        for (int j = i + 1;; j++)
        {
            // 找到 ]
            // 之后，把[]之间的重复k次，然后后面的交给递归去处理。因此一定有
            // return，不用写 for 循环终止条件
            if (s[j] == '[')
            {
                balance++;
            }
            else if (s[j] == ']')
            {
                balance--;
                if (balance == 0)
                {
                    int k = stoi(s.substr(0, i));
                    string t = decodeString(s.substr(i + 1, j - i - 1)); // 这里是从 i+1，也就是[的下一个开始，然后长度为 j-i-1。
                    // 这样考虑：如果是 ij 之间，那就是 j-i+1，但是 ij 都是[]，所以再-2 即可
                    // 这之间可能也有嵌套的[]，所以需要递归处理，拿到自己这一层[]之间的串的结果，也是递归得到的
                    string result;
                    while (k--)
                    {
                        result += t;
                    }
                    return result +
                           decodeString(s.substr(j + 1)); // j是]的位置}
                }
            }
        }
    }
};