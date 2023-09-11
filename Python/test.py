# Defines a list, from 1 to 10
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Slice from 2 to 5
sliced_numbers = numbers[2:5]

# Get person keys from  2 to end
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
