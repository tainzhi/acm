n, k = map(int, input().split())
tree = list(map(int, input().split()))
min_action = 1010
for i in range(1, 1001):
    count=0
    for j in range(0, n):
        if tree[j] != i + j * k:
            count+=1
    if min_action > count:
        min_action = count
        ans = i
print(min_action)
for i in range(0, n):
    if ans + i *k < tree[i]:
        print('- %s %s' % (i+1, tree[i] - ans - i*k))
    elif ans + i*k > tree[i]:
        print('+ %s %s' % (i+1, ans + i*k - tree[i]))





