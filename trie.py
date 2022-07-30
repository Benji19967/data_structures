from typing import Dict, Set


class TrieNode:
    def __init__(self, is_word: bool = False) -> None:
        self.is_word = is_word
        self.neighbors: Dict[str, TrieNode] = {}  # keys are characters


class Trie:

    def __init__(self) -> None:
        self._root = TrieNode()
        self._words: Set[str] = set()


    def add_word(self, word: str) -> None:
        """
        Time: O(w)
        """
        self._words.add(word)
        node = self._root
        for c in word:
            if c not in node.neighbors:
                node.neighbors[c] = TrieNode()
            node = node.neighbors[c]
        node.is_word = True


    def find_word(self, word: str) -> bool:
        """
        Check whether full word is present or not.

        Time: O(1)
        """
        return word in self._words

    def find_prefix(self, prefix: str) -> bool:
        """
        Check whether prefix is present or not.

        Time: O(w)
        """
        if prefix in self._words:
            return True
        node = self._root
        for c in prefix:
            if c not in node.neighbors:
                return False
            node = node.neighbors[c]
        return True


if __name__ == "__main__":        

    t = Trie()

    t.add_word("hello")

    assert t.find_word("hello") == True
    assert t.find_word("hell") == False

    assert t.find_prefix("hello") == True
    assert t.find_prefix("hell") == True
    assert t.find_prefix("ello") == False

    print("Success")