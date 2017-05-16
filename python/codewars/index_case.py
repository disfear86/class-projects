def to_weird_sting(string):
    lst = [c for c in string]
    i = 0

    for item in enumerate(lst):
        if item[0] % 2 == 0:
            lst[i] = item[1].upper()
        else:
            lst[i] = item[1].lower()
        i += 1
        
    return ''.join(lst)
                       


print(to_weird_sting('This is a test'))
