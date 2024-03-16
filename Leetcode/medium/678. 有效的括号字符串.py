"""
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
一个空字符串也被视为有效字符串。
"""


class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left = []
        star = []
        for i, ch in enumerate(s):
            if ch == "(":
                left.append(i)
            elif ch == "*":
                star.append(i)
            else:
                if len(left):
                    left.pop()
                elif len(star):
                    star.pop()
                else:
                    return False
        if len(star) < len(left):
            return False
        while len(star) and len(left):
            starIndex = star.pop()
            leftIndex = left.pop()
            if starIndex < leftIndex:
                return False

        return True
