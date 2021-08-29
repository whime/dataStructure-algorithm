"""
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
"""


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s)%2!=0:
            return False
        stack=[]
        for ch in s:
            if ch in ["(","{","["]:
                stack.append(ch)
            else:
                if len(stack)==0:
                    return False
                if ch==")" and stack[-1]=="(":
                    stack.pop()
                elif ch=="]" and stack[-1]=="[":
                    stack.pop()
                elif ch=="}" and stack[-1]=="{":
                    stack.pop()
                else:
                    return False
        if len(stack)!=0:
            return False
        else:
            return True