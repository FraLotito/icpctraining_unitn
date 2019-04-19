n = int(input())
l = list(map(int, input().split()))

l = list(sorted(l))
m = 1
imp = False
for i in range(len(l)):
    if l[i] > i + 1:
        imp = True
        break
    else:
        m = min(m, l[i] / (i+1))
if not imp:
    print(m)
else:
    print("impossible")