import math

def PS(num):
    if math.isqrt(num)**2 == num:
        return num
    else:
        return -1

number = int(input("Enter a number: "))

result = PS(number)
print(result)