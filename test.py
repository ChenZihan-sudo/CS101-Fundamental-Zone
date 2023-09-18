alist = range(1, 10)
print(alist)

aIter = iter('hello')
print(next(aIter))
print(next(aIter))
print(next(aIter))
print(next(aIter))
print(next(aIter))

aIter = iter([0, 1, 2, 3, 4, 5])

print(tuple([1, 2, 3]))
print(list(range(1, 5)))

alist = list(range(1, 11))
print(alist)
print([x*2 for x in range(1,11)])