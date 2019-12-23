def zigzag(s, r):
    if (r == 1):
        return s
    sz = [0 for _ in range(r)]
    step = 1
    rno = 0
    for i in range(len(s)):
        sz[rno] += 1
        rno += step
        if (rno == 0) or (rno == r - 1):
            step = -step

    step = 1
    rno = 0
    cnos = [0 for _ in range(r)]
    a = [None for _ in range(len(s))]
    for i in range(len(s)):
        if rno == 0:
            a[cnos[rno]] = s[i]
        else:
            a[sum(sz[:rno]) + cnos[rno]] = s[i]
        cnos[rno] += 1
        rno += step
        if (rno == 0) or (rno == r - 1):
            step = -step

    return ''.join(a)


if __name__ == '__main__':
    s = 'AB'
    r = 1
    print(zigzag(s, r))
