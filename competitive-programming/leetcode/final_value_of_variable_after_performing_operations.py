# https://leetcode.com/problems/final-value-of-variable-after-performing-operations


class Solution:
    def finalValueAfterOperations(self, ops: List[str]) -> int:
        return sum([-1, 1][op[1] == "+"] for op in ops)
