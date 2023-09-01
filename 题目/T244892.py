t = int(input())
while t != 0:
    a, b, c = [int(i) for i in input().split()]
    if a * b == c:
        print("YES")
    else:
        print("NO")
    t -= 1