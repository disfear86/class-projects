def maskify(cc):
    lst = list(cc)
    for item in enumerate(lst):
        if item[0] < (len(lst) - 4):
            lst[item[0]] = '#'
    return ''.join(lst)
    
str = "4556364607935616"
print(maskify(str))
