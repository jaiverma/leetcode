def rot90(m):
    r = len(m)
    c = len(m[0])
    for i in range(r - 1):
        for j in range(i + 1, c):
            t = m[i][j]
            m[i][j] = m[j][i]
            m[j][i] = t

    for i in range(r):
        m[i] = m[i][::-1]

if __name__ == '__main__':
    m = [[1,2,3],
         [4,5,6],
         [7,8,9]]

    for i in m:
        print(i)

    print('--------\n')
    rot90(m)

    for i in m:
        print(i)
