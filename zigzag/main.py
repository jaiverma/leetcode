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

def main():
    s = 'PAYPALISHIRING'
    r = 4
    n = len(s)
    c = f(n, r)
    a = [[' ' for _ in range(c)] for x in range(r)]

    i = 0
    j = 0
    x = 0
    while j < c and x < n:
        if (j % (r - 1)) == 0:
            i = 0
            while i < r and x < n:
                a[i][j] = s[x]
                i += 1
                x += 1
            i -= 1
        else:
            i -= 1
            a[i][j] = s[x]
            x += 1
        j += 1
    for i in range(r):
        for j in range(c):
            sys.stdout.write(a[i][j])
        sys.stdout.write('\n')

main()
