 
f = open("temp.txt", 'r')
lines = f.readlines()
f.close()
data = []
for line in lines:
    temp_data = line.split()
    for m in temp_data: data += [int(m)]

#for i in range(0, 2048):
#    print(data[(i * 8):(i * 8 + 8)])

g = open("temp2.txt", 'w')
for i in range(0, 2048):
    s = "\t"
    for j in range(8 * i, 8 * i + 7):
        s += str(data[j])
        s += ", "
    s += str(data[8 * i + 7])
    s += ",\n"
    g.write(s)

g.close()


