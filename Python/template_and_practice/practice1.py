# Defines a list, from 1 to 10
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Slice from 2 to 5
sliced_numbers = numbers[2:5]

# Get person keys from 2 to end
person = {"A": 25, "B": 30, "C": 100, "D": 40}
sliced_person = list(person.keys())[2:]

# Print result
print(sliced_numbers, sliced_person)

# Slice a dict
def slice_dict(the_dict, start, end):
    res = {}
    for i in list(the_dict.keys())[start:end]:
        res[i] = the_dict[i]
    return res

sliced_dict = slice_dict(person, 0, 1)
print(sliced_dict)


# Use iterator
alist = range(1, 10)
alist_iter = iter(alist)
print(next(alist_iter))

aiter = iter('hello')
print(next(aiter))


print(tuple([1, 2, 3]))
print(list(range(1, 5)))

alist = list(range(1, 11))
print(alist)
print([x * 2 for x in range(1, 11)])


# Create a list with numbers from 1 to 10
alist = list(range(1, 11))
print(alist)

# Create a list with numbers from 1 to 10 that double of itself
blist = [x*2 for x in range(1, 11)]
print(blist)