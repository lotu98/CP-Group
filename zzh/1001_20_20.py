'''
	1001. A+B Format (20)
	时间限制
	400 ms
	内存限制
	65536 kB
	代码长度限制
	16000 B
	判题程序
	Standard
	作者
	CHEN, Yue
	Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
	
	Input
	
	Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.
	
	Output
	
	For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
	
	Sample Input
	-1000000 9
	Sample Output
	-999,991
'''

import sys

#print 'waiting for input'	
str_in = sys.stdin.readline().strip()
#the loop is for debugging
while str_in != '':
	#Get the sum	
	a, b = str_in.split(' ')
	num = int(a) + int(b)
	
	#preprint the '-' and get the string form of the number
	if num < 0:
		sys.stdout.write('-')
		nums = str(num)[1::]
	else:
		nums = str(num)
	
	#initialize the output
	str_out = ''
	#indicator of position
	i = len(nums) % 3 
	for dig in nums:
		#adding commas
		if i == 0:
			str_out += ','
			i = 3
		#adding digits
		str_out += dig
		i -= 1
		
	#output
	print str_out.strip(',')
	#test end here, the rest is for the loop
	str_in = sys.stdin.readline().strip()
		
