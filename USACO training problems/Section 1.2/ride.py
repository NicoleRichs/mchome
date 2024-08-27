""""
ID: ethanhp1
LANG: PYTHON3
TASK: ride
"""
fin = open("ride.in",'r')
fout = open("ride.out",'w')
l1 = fin.readline()
l2 = fin.readline()
s1 = 1
s2 = 1
for each in (l1):
  if(ord(each)>64 and ord(each)<91):
    s1*=ord(each)-64
for each in (l2):
  if(ord(each)>64 and ord(each)<91):
    s2*=ord(each)-64
print(s1,s2)
if(s1%47 == s2%47):
  fout.write("GO\n")
else:
  fout.write("STAY\n")
fout.close()
#successfully passed all USACO tests 9/9/2021 13:20!