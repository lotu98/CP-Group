import sys
import Queue 
#todo   24/30
node_dict = dict()	#key for node_id and value for [num of sons,id of sons]

#To fill node_dict
def reader():
	text = sys.stdin.readline().strip().split(' ')
	node_dict[text[0]] = text[1::]

#Count the num of lines to read
m, n = sys.stdin.readline().strip().split(' ')[0:2:]
#Do the filling
for i in range(int(m)-int(n)):
	reader()

#Queue q to store the node series
q = Queue.Queue()
count_not_dad = {}
FLAG = 0
q.put(FLAG)
q.put('01')
level = -1

while not q.empty():
	node_id = q.get()
	if node_id == FLAG:
		if q.empty():
			continue
		else:
			level += 1
			count_not_dad[level] = 0
			q.put(FLAG)
			continue
	node = node_dict.get(node_id)
	if node == None:
		count_not_dad[level] += 1
	else:
		for son in node[1::]:
			q.put(son)
result = sorted(count_not_dad.iteritems(), key = lambda x:int(x[0]))
output = ''
for i in result:
	output += str(i[1])+' '
sys.stdout.write(output.strip())
