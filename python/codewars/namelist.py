namelist =[{'name': 'Bart'},{'name': 'Lisa'},
           {'name': 'Maggie'},{'name': 'Homer'},{'name': 'Marge'}]

str = ''
lst = [item['name'] for item in namelist]

if len(lst) <= 2:
    str = ' '.join(lst).replace(' ', ' & ')
else:
    str = ' '.join(lst[:len(lst) - 2]).replace(' ', ', ') + ', ' + ' '.join(lst[len(lst) - 2:]).replace(' ', ' & ')
print(str)
