# 3
# 5 1
# 1 1 1 1 1 
# 5 2
# 1 3 1 1 3 
# 3 4 
# 1000 1000 1000   

# 5 1

i = 0
health = 1
maxPill = 0
count = 0
a = [1 ,1 ,1, 1, 1 ]
while i < 5:
    i+=1
    maxPill = max(maxPill,a[i])
    health-=1
    if health == 0:
        health+=maxPill
        count+=1