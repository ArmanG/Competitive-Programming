summ = 0
x = 1
y = 2

while(y < 4000000):
  if y % 2 == 0:
    summ += b
  z = y
  y = x + y
  x = z

print(summ)
