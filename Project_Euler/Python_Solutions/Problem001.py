def mult_3_and_5(n):
    summ = 0
    for i in range(1, n):
        if i % 3 == 0 or i % 5 == 0:
            summ += i
    return summ

print(mult_3_and_5(10))
