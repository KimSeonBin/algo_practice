#http://code0xff.tistory.com/76
class Node(object):
    def __init__(self, key, data=None):
        self.key = key # 단어 글자를 담는데 이용
        self.data = data #flag. 마지막 여부 체크
        self.children = {}
class Trie(object):
    def __init__(self):
        self.head = Node(None)
    def insert(self, s):
        curr_node = self.head

        for c in s:
            if c not in curr_node.children:
                curr_node.children[c] = Node(c)
            curr_node = curr_node.children[c]
        curr_node.data = s

    def search(self, s):
        curr_node = self.head
        for c in s:
            if c not in curr_node.children:
                return False
            else:
                curr_node = curr_node.children[c]
        if curr_node.data is not None:
            return True
    # def starts_with(self, prefix):
    #     aaaa
    def cons(self, s):
        curr_node = self.head
        for c in s:
            curr_node = curr_node.children[c]
        if len(curr_node.children) != 0:
            return False
        else:
            return True

    def cons_insert(self, s):
        curr_node = self.head
        for c in s:
            if c not in curr_node.children:
                curr_node.children[c] = Node(c)
            curr_node = curr_node.children[c]
            if curr_node.data != None:
                return False
        if curr_node.data == None and len(curr_node.children) == 0:
            curr_node.data = s
            return True
        else:
            return False

t = int(input())
for iter in range(0, t):
    n = int(input())
    trie = Trie()
    sen = []
    check = True

    for i in range(0, n):
        sen.append(input())

    for i in range(0, n):
        # check = trie.cons_insert(sen[i])
        curr_node = trie.head
        for c in sen[i]:
            if c not in curr_node.children:
                curr_node.children[c] = Node(c)
            curr_node = curr_node.children[c]
            if curr_node.data is not None:
                check = False
                break
        curr_node.data = sen[i]
        if len(curr_node.children) != 0:
            check = False

        if check == False:
            print('NO')
            break
    if check:
        print('YES')
