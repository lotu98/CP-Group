n = input()
m = map(lambda x:int(x), raw_input().split(' '))

head, tail, peak = 0, 0, 0
peak_l = []	# peak list
temp = 0	# start num
flag = 0	# whether it's a none Positive case
for i in range(n):
	# Positive
	if m[i] > 0:
		head = m[i]
		peak = m[i]
		tail = m[i]
		temp = i+1
		flag = 1
		break
	# All Negative or zeros
	elif m[i] == 0:
		flag = 2
	# All Negative
	if i == n-1:
		if flag == 2:
			print 0, 0, 0
		else:
			print 0, m[0], m[-1]


if flag == 1:
	count = 0
	# simplify the list
	for i in range(temp,n):
		if m[i] == 0:
			continue
		elif peak * m[i] > 0:
			peak += m[i]
			tail = m[i]
		else:
			peak_l.append((head, tail, peak))
			peak = m[i]
			head = m[i]
			tail = m[i]
	if peak > 0:
		peak_l.append((head, tail, peak))
	length = len(peak_l)
	
	out = (0,0,0)
	
	# one by one search for minimun sublist
	for i in range(length)[0::2]:
		lp, rp = i, i	#pivor
		la, ra = 0, 0	#addition
		lm, rm = 0, 0	#maximun
		h, t, p = peak_l[i]
		while lp >0 and count < 100:
			# count += 1
			la = peak_l[lp-1][2] + peak_l[lp-2][2] + la
			lp -= 2
			if la > lm:
				lm = la
				h = peak_l[lp][0]
			if lp <= 0:
				count = 10000000
		while rp < length-1 and count < 100:
			# count += 1
			ra = peak_l[rp+1][2] + peak_l[rp+2][2] + ra
			rp += 2
			if ra > rm:
				rm = ra
				t = peak_l[rp][1]
			if rp >= length:
				count = 10000000
		p = lm + rm + p
		if p > out[0]:
			out = (p, h, t)	
	print ''.join(str(out)[1:-1:1].split(','))
