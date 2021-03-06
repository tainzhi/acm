from math import sqrt
def IsPrime(number):
    if number == 1:
        return True
    for i in range(2, int(sqrt(number))+1):
        if number % i == 0:
            return False
    return True

def GetReverseValue(number):
    reverse = []
    len = 0
    while number != 0:
        reverse.append(int(number%10))
        number = int(number / 10)
        len += 1
    j = len-1
    for i in range(int(len/2)):
        if reverse[i] != reverse[j]:
            return False
        j -= 1
    return True

n = int(input())
while True:
    if IsPrime(n) and GetReverseValue(n):
        print(n)
        break
    n += 1


