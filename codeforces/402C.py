t = int(input())
while t > 0:
    t -= 1
    n, p = map(int, input().split())
    count = 0
    for i in range(1, n):
        for j in range(i+1, n+1):
            count += 1
            if count <= 2*n + p:
                print("%s %s" % (i, j))
            else:
                break
