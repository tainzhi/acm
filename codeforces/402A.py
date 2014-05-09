#input return a string, input().split() get the string, and int() convert a string to an integer
k, a, b, v = map(int, input().split())
outcome = 0
while a > 0:
    outcome += 1
    kn = min(k, b+1)
    a -= kn * v
    b = max(0, b - kn + 1)
#python3, print is a function
print(outcome)


