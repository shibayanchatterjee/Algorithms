import os
import sys
os.system('clear')

class Node(object):
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev
    def getdata(self):
        return self.data
    def getnext(self):
        return self.next
    def getprev(self):
        return self.prev
    def setdata(self, newdata):
        self.data = newdata
        return
    def setnext(self, newnext):
        self.next = newnext
        return
    def setprev(self, newprev):
        self.prev = newprev
        return

class Doubly_linked_list(object):
    def __init__(self):
        self.head = None

    def insert(self, val):
        tmp = Node(val)
        tmp.setnext(self.head)
        if self.head is not None:
            self.head.setprev(tmp)
        self.head = tmp
        self.display(self.head)
        return
    def display(self, headptr):
        tmp, line = headptr, ''
        while tmp is not None:
            line = line +str(tmp.getdata())+ '<->'
            tmp = tmp.getnext()
        line = line + 'NULL'
        print line
        return
    def dll_append(self, val):
        headptr = self.head
        tmp = Node(val)
        while headptr is not None:
            if headptr.getnext() is None:
                headptr.setnext(tmp)
                tmp.setprev(headptr)
                break
            headptr = headptr.getnext()
        self.display(self.head)
        return
    def insert_after(self, key, val):
        headptr = self.head
        tmp = Node(val)
        while headptr is not None:
            if headptr.getdata() == key:
                tmp.setnext(headptr.getnext())
                tmp.setprev(headptr)
                headptr.getnext().setprev(tmp)
                headptr.setnext(tmp)
                break
            headptr = headptr.getnext()
        self.display(self.head)
        return
    def delete_node(self, val):
        headptr = self.head
        if headptr.getdata() == val:
            tmp = self.head
            self.head.getnext().setprev(None)
            self.head = self.head.getnext()
            del tmp
        else:
            while headptr is not None:
                if headptr.getnext().getdata() == val:
                    tmp = headptr.getnext()
                    headptr.getnext().getnext().setprev(headptr)
                    headptr.setnext(headptr.getnext().getnext())
                    del tmp
                    break
                headptr = headptr.getnext()
        self.display(self.head)
        return

d = Doubly_linked_list()

keys = [12, 21, 23, 25, 36, 43, 48, 55, 60, 63]
k = None
for k in keys:
    d.insert(k)

print 'Appending 10: '
d.dll_append(10)

print 'Adding 40, after 48: '
d.insert_after(48, 40)

print 'Delete 63: '
d.delete_node(63)

print 'Delete 23: '
d.delete_node(23)