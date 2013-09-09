import random
import sys

del sys.argv[0]

while len(sys.argv) > 0:
    N, M = map(int, sys.argv[0:2])
    del sys.argv[0]
    del sys.argv[0]

    s = ''.join(map(str, [random.randint(0, 1) for x in range(N)]))
    print s

    print M
    for i in range(M):
        a = random.randint(0, N)
        b = random.randint(0, N)
        print a, b

