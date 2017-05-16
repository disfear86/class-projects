import string
def toJadenCase(str):
     return ' '.join([c[0].upper() + c[1:]
               for c in str.split(' ')])
        

str = "How can mirrors be real if our eyes aren't real"
print(toJadenCase(str))
