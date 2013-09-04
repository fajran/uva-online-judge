#!/usr/bin/env python

import sys
n = int(sys.argv[1])

print 1
print n
for i in range(n):
    print 'n%d n%d' % (i, i+1)

