# 给定两个字符串 s 和 t，判断它们是否是同构的。
#
# 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
#
# 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
#
# 示例 1:
#
# 输入: s = "egg", t = "add"
# 输出: true
# 示例 2:
#
# 输入: s = "foo", t = "bar"
# 输出: false
# 示例 3:
#
# 输入: s = "paper", t = "title"
# 输出: true
# 说明:
# 你可以假设 s 和 t 具有相同的长度。
#
#
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/isomorphic-strings
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution:
    # def isIsomorphic(self, s: str, t: str) -> bool: #method 1
    #     def trans(s):
    #         out = ''
    #         dic = {}
    #         j = 1
    #         for i in s:
    #             if i not in dic.keys():
    #                 dic[i] = str(j)
    #                 out = out + str(j)
    #                 j += 1
    #             else:
    #                 out = out + dic[i]
    #         return out
    #
    #
    #     return trans(s) == trans(t)

    def isIsomorphic(self, s: str, t: str) -> bool: #method 2
        if len(s)!=len(t): return False
        dic1 = {}
        dic2 = {}
        j=1
        for i in range(len(s)):
            if s[i] not in dic1.keys() and t[i] not in dic2.keys():
                dic1[s[i]] = j
                dic2[t[i]] = j
                j+=1
            elif s[i] in dic1.keys() and t[i] in dic2.keys():
                if dic1[s[i]] != dic2[t[i]]:
                    return False
            else:
                return False
        return True


A = Solution()
print(A.isIsomorphic('paper', 'title'))
