import clipboard

while True:
    try: s = input()
    except: break
    l = ["$\\def\\U{\\underset} \\def\\T{\\texttt}"]
    for i in range(len(s)):
        l.append("\\U{" + str(i+1) + "}{\\T{" + s[i] + "}}")
    l.append("$")
    # print(l)
    res = "".join(l)
    print(res)
    clipboard.copy(res)
    