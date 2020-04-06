# 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
#
# 示例:
#
# Trie trie = new Trie();
#
# trie.insert("apple");
# trie.search("apple");   // 返回 true
# trie.search("app");     // 返回 false
# trie.startsWith("app"); // 返回 true
# trie.insert("app");
# trie.search("app");     // 返回 true
# 说明:
#
# 你可以假设所有的输入都是由小写字母 a-z 构成的。
# 保证所有输入均为非空字符串。


class Trie:

    def __init__(self):
        self.val = ''
        self.left = None
        self.right = None
        """
        Initialize your data structure here.
        """


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if self.val=='':
            self.val = word
        else:
            cur = self
            while cur.val!='':
                if word<cur.val:
                    if cur.left == None:
                        cur.left = Trie()
                        cur.left.val = word
                        break
                    else:
                        cur = cur.left
                if word>=cur.val:
                    if cur.right==None:
                        cur.right = Trie()
                        cur.right.val = word
                        break
                    else:
                        cur = cur.right





    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if self.val == word:
            return True
        elif word<self.val:
            if self.left==None:
                return False
            return self.left.search(word)
        else:
            if self.right==None:
                return False
            return self.right.search(word)


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if self.val[:len(prefix)] == prefix:
            return True
        elif prefix<self.val:
            if self.left==None:
                return False
            return self.left.startsWith(prefix)
        else:
            if self.right==None:
                return False
            return self.right.startsWith(prefix)



# Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert('word')
obj.insert('apple')
print(obj.search('word'))
print(obj.startsWith('ap'))
print(obj.search('apple'))