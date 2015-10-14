import sys
#read and format inputs
text_1 = sys.stdin.readline().strip()
text_2 = sys.stdin.readline().strip()
#initial dict
formula = dict()

def reasoner(text):
	#filter out the exp and coe
	a = text.split(' ')[1::2]
	b = text.split(' ')[2::2]
	#parsing
	for i in range(len(a)):
		a[i] = int(a[i])
		b[i] = float(b[i])	
	#counting
	for i in range(len(a)):
		if formula.get(a[i]) == None:
			formula[a[i]] = 0.0
		formula[a[i]] += b[i]
	pass
#do the counting
reasoner(text_1)
reasoner(text_2)
#initial output
output = ''
terms_count = 0
#sort and output
for i in sorted(formula.items(), key = lambda a: a[0], reverse = True):
	#filter out the zero terms
	if i[1] != 0:
		output += (' ' + str(i[0]) + ' ' + str(round(i[1],1)))
		terms_count += 1
	#print 'xxxxxxxxxxxxxxxxxxxxxx'
	#print i
	#print 'xxxxxxxxxxxxxxxxxxxxxxxxxxxx'
print str(terms_count) + output
