def permute(s,l,r):
    if l==r:
        print("".join(s))
    else:
        for i in range(l,r+1):
            s[l],s[i]=s[i],[l]
            permute(s,l+1,r)
            s[l],s[i]=s[i],s[l]  