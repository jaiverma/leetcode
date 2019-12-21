import sys
from pprint import pprint

def f(n, r):
    c = 0
    while n > 0:
        c += 1
        n -= r
        if n > 0:
            c += r - 2
            n -= r - 2
    return c

def idx(i, j, c):
    return (c + 1) * i + j

def main():
    s = 'PAYPALISHIRING'
    r = 3
    n = len(s)
    c = f(n, r)
    a = [' ' for _ in range((c + 1) * r)]
    for i in range(r):
        a[idx(i, c, c)] = '\n'

    i = 0
    j = 0
    x = 0
    while j < c and x < n:
        if (j % (r - 1)) == 0:
            i = 0
            while i < r and x < n:
                a[idx(i, j, c)] = s[x]
                i += 1
                x += 1
            i -= 1
        else:
            i -= 1
            a[idx(i, j, c)] = s[x]
            x += 1
        j += 1
    for i in range(r):
        for j in range(c + 1):
            sys.stdout.write(a[idx(i, j, c)])
    pprint(a)

main()
