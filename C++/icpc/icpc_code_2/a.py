a=1
for i in range(0,100):
    a+=(0.50001)*pow(0.49999,i)*(i+1)
print(a)