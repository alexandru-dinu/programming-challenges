# https://leetcode.com/problems/permutations

from collections import namedtuple

State = namedtuple("State", ["acc", "mask"])


def dfs(xs: List[int], state: State):
    if all(state.mask):
        yield state.acc[:]

    for i in range(len(xs)):
        if state.mask[i]:
            continue

        state.mask[i] = True
        state.acc.append(xs[i])

        yield from dfs(xs, state)

        state.mask[i] = False
        state.acc.pop()


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        init_state = State(acc=[], mask=[False] * len(nums))
        return list(dfs(nums, state=init_state))
