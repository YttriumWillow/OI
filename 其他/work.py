

n = 4
P = 0

while True:
    s = input()
    if s == 'd': P += 1
    elif s == 'a': P -= 1
    else: print("                    !sb")
    
    lpos = (P % n + n) % n + 1
    rpos = (((lpos - 2) % n + n) % n + 1)
    
    print("pos:", lpos, "->", rpos)