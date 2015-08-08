import sys

weight, iq=[], []
best=[-1] * 1000
prev=[-5] * 1000
n=0

def getbest( k ):
	if best[k] != -1: return best[k]

	optimal=0
	for i in range(n):
		if weight[i] < weight[k] and iq[i] > iq[k]:
			if getbest(i) > optimal:
				optimal=getbest(i)
				prev[k]=i

	best[k]=optimal+1
	return best[k]

allData = map( int, sys.stdin.read().split() )
for i in range(0, len(allData), 2):
	weight.append(allData[i])
	iq.append(allData[i+1])
	print weight[i/2], iq[i/2]
n=len(weight)

bestsize=0
bestindex=-1
for i in range(n):
	if getbest(i)>=bestsize:
		bestsize=getbest(i)
		bestindex=i

	print i, getbest(i), prev[i], '-->', weight[i], iq[i]

end=bestindex
indexes=[]

while end != -5:
	indexes.append(end)
	print end, '-->', prev[end]
	end=prev[end]

ans=[ x+1 for x in indexes[::-1] ]
print bestsize
print ans


