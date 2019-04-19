N = int(input())
M = int(input())

n = list(map(int, input().split()))
m = list(map(int, input().split()))

d = {}
for j in m:
    for i in n:
        if j < i:
            break
        if j-i in d:
            d[j-i] += 1
        else:
            d[j-i] = 1

value = -1
key = 0
for i in sorted(d.keys()):
    if d[i] > value:
        value = d[i]
        key = i
print(key)