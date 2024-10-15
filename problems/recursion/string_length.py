def string_len(s):
    if s=='':
        return 0
    return 1+string_len(s[1:])
print(string_len("habib"))