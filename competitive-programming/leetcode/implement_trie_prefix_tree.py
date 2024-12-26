# https://leetcode.com/problems/implement-trie-prefix-tree


class Trie:
    def __init__(self):
        self.kids = {}  # char -> Trie
        self.is_end = False

    def walk(self, word: str) -> Optional["Trie"]:
        t = self
        for c in word:
            if c not in t.kids:
                return None
            t = t.kids[c]
        return t

    def insert(self, word: str) -> None:
        t = self
        for c in word:
            if c not in t.kids:
                t.kids[c] = Trie()
            t = t.kids[c]
        t.is_end = True

    def search(self, word: str) -> bool:
        t = self.walk(word)
        return t is not None and t.is_end

    def startsWith(self, prefix: str) -> bool:
        return self.walk(prefix) is not None


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
