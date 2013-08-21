import sys

n = int(sys.argv[1])

print n
for i in range(1,n+1):
    print i,
    for j in range(1, n+1):
        if j != i:
            print j,
    print

