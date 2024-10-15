def rev(sen):
    if len(sen)==0:
        return sen
    else:
        return rev(sen[1:])+sen[0]

res=rev("jackma")
print(res)
