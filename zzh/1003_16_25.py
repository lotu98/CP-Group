import sys

def initialize_distance_matrix(n_city, n_road):
	inf = 0
	m_dist = [['N' for col in range(n_city)] for row in range(n_city)]
	#Read input
	for i in range(n_road):
		m, n, d = map(lambda x : int(x), sys.stdin.readline().strip().split(' '))
		m_dist[m][n] = d
		m_dist[n][m] = d
		if d > inf:
			inf = d
	inf += 2
	#Fill matrix
	for m in range(n_city):
		for n in range(m):
			if m_dist[m][n] == 'N':
				m_dist[m][n] = inf
				m_dist[n][m] = inf
		m_dist[m][m] = inf
	
	return m_dist, inf

def update_shortest_distance(l_shortest_distance, m_dist, l_newly_added_cities, target_city, pre_cities):
	s = l_shortest_distance
	n = l_newly_added_cities
	t = target_city
	d = m_dist
	p = pre_cities
	for i in n:
		if  s[i] + d[i][t] < s[t]:
			s[t] = s[i] + d[i][t]
			p[t] = [i]
		elif s[i] + d[i][t] == s[t]:
			p[t].append(i)
	return s[t]

def update_round(inf, n_city, done, l_shortest_distance, m_dist, l_newly_added_cities, pre_cities):
	short = inf - 1
	temp = []
	for city in set(range(n_city)) - done:
		distance_to_city = update_shortest_distance(l_shortest_distance, m_dist, l_newly_added_cities, city, pre_cities)
		if distance_to_city < short:
			short = distance_to_city
			temp = [city]
		elif distance_to_city == short:
			temp.append(city)
	done.update(temp)
	return temp
			
def outer(pre_cities, n_team, ori, des):
	path = 0
	teams = 0
	if des == ori:
		path = 1
		teams = 0
	else:
		for i in pre_cities[des]:
			temp = outer(pre_cities, n_team, ori, i)
			path += temp[0]
			if temp[1] > teams: teams = temp[1]
	return path, teams + n_team[des]
			

if __name__ == '__main__':
	
	n_city, n_road, ori, des = map(lambda x : int(x), sys.stdin.readline().strip().split(' '))
	n_team = map(lambda x : int(x), sys.stdin.readline().strip().split(' '))
	m_dist, inf = initialize_distance_matrix(n_city, n_road)
	#for row in m_dist:
		#print row
	done = set()
	done.add(ori)
 	l_shortest_distance = [inf for col in range(n_city)]
	l_shortest_distance[ori] = 0
	l_newly_added_cities = [ori]
	pre_cities = [[] for col in range(n_city)]
	for i in range(n_city - 1):
		l_newly_added_cities = update_round(inf, n_city, done, l_shortest_distance, m_dist, l_newly_added_cities, pre_cities)
		if des in done: break
	o = outer(pre_cities, n_team, ori, des)
	sys.stdout.write(str(o[0]).strip() + ' ' + str(o[1]).strip())
