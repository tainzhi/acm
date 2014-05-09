while True:
    n = int(input())
    if n == 0:
        break
    wood = list(map(int, input().split()))
    count = 0
    flag = False
    for i in range(n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):
                if wood[i] + wood[j] > wood[k] and wood[i] + wood[k] > wood[j] and wood[j] + wood[k] > wood[i]:
                    count +=1
                    Flag = True
                elif (wood[i] + wood[j] < wood[k] or wood[i] + wood[k] < wood[j] or wood[j] + wood[k] < wood[i]) and flag == False: 
                    count +=1
    print(count)

