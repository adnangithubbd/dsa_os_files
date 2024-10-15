def pali(s):
    if len(s)<=1:
        return True
    if s[0]!=s[-1]:
        return False
    return pali(s[1:-1])

print(pali("radar"))