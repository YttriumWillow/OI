# print("fzy qwq~")

ipl = [int(i) for i in input().split()]
s = a = b = ""
for i in range(10):
    s += (ipl[9 - i] * str(9 - i))
for i in range(len(s)):
    if i % 4 in (0, 3):
        a += s[i]
    else:
        b += s[i]
print(a)
print(b)