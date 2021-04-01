import heapq

f = open('huffman.txt', 'r')
line = f.readline()
#print(line)
line = f.read().splitlines()

all = []
weight = []
tt = 0
for l in line:
    new = []
    tt += int(l)
    new.append(int(l))
    all.append(list(new))
    new.append(0)
    weight.append(new)

print(tt)

heapq.heapify(all)

while len(all) > 1:
    min1 = heapq.heappop(all)
    if len(all) is 0:
        break
    min2 = heapq.heappop(all)
    if len(all) is 0:
        print("salut")
    to_add = []
    to_add.append(min1[0] + min2[0])
    heapq.heappush(all, to_add)
    for nb in weight:
        if nb[0] == int(min1[0]):
            nb[0] = min1[0] + min2[0]
            nb[1] += 1
            #print "Found it!", nb, len(all)

print(all)
min1 = heapq.heappop(all)
for nb in weight:
        if nb[0] == int(min1[0]):
            print "Found it!", nb, len(all)
# search = min1
# for nb in weight:
#     if nb[0]  search:
        
#         nb[0] = min1 + min2
#         nb[1] += 1
#         print "Found it!", nb
#         break


