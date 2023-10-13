from random import *

while input() != "exit":
    n = 10
    m = randint(5, 8)
    print(n, m)
    
    for i in range(10):
        print(choice(["?", "0", "1"]), end = "")

