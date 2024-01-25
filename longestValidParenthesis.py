class Solution:
    def longestValidParentheses(self, s: str) -> int:
        count = 0
        index = [-1]
        stack = []
        for i in range(len(s)):
            if s[i] == '(':
                stack.append('(')
                index.append(i)
            else:
                if len(stack) != 0:
                    if stack[len(stack) - 1] == '(':
                        stack.pop()
                        index.pop()
                        count = max(count, i - index[len(index) - 1])
                else:
                    index.append(i)
        return count