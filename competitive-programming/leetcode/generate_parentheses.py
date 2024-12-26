# https://leetcode.com/problems/generate-parentheses


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def bt(so_far: List[str], rem: int, balance: int):
            if rem == 0 and balance == 0:
                res.append("".join(so_far))
                return

            if abs(balance) > rem:
                return

            last = so_far[-1]

            if last == "(":
                if balance > 0:
                    bt(so_far + [")"], rem - 1, balance - 1)

                bt(so_far + ["("], rem - 1, balance + 1)

            if last == ")":
                bt(so_far + ["("], rem - 1, balance + 1)

                if balance > 0:
                    bt(so_far + [")"], rem - 1, balance - 1)

        bt(so_far=["("], rem=2 * n - 1, balance=1)

        return res
