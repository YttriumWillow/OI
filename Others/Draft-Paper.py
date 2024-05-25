S = "A person in need is a person indeed!"
c1 = "person"
c2 = "friend"

l = 0; r = 0; res = ""
i = len(c1) - 1

while i < len(S):
    ch = S[i - len(c1) + 1 : i + 1]
    # print(i, "[" + str(i - len(c1) + 1) + "," + str(i + 1) + "):", ch)
    if ch == c1:
        # print("Changed")
        res += S[l : i - len(c1) + 1] + c2
        l = i + 1
    i += 1

res += S[l:]

print(res)