import sys

seq=[]
best=[]
n=0

def LIS():
	for i in range(n):
		optimal=0
		for j in range(i-1, -1, -1):
			if seq[j] < seq[i] and best[j] > optimal:
				optimal=best[j]
			if j <= optimal: break
		best[i]=optimal+1
	return max(best)

allData = map( int, sys.stdin.read().split() )

n=allData[0]
seq=allData[1:]
best=[1]*n

print LIS()
