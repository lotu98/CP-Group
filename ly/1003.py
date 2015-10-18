import numpy as np
import copy
#function to get the shortest ways and  max teams
def waysAndTeams(dis, n, start, end, team):
	# dis :distance array 
	# n: number of nodes
	# start: start node
	# end : end node
	D = np.array([dis[start,i] for i in range(n)]) # dis of shortest ways
	D[start] = 0
	cur_route = (D!=99999999) 	# num of current shortest ways
	cur_route = [int(x) for x in cur_route]
	cur_team = copy.deepcopy(team) 	# max num of team in the shortest 
	start_team = [team[start]]*n
	start_team[start] = 0
	cur_team = np.array(cur_team)+np.array(start_team)*np.array(cur_route)
	set_done = set([]) 	
	set_undo = set([i for i in range(n)])
	set_done.add(start)
	set_undo.remove(start)
	routeList = [[start]]	#possible shortest way (including start,excluding end)
	while(len(set_undo)!=0):
		mini = min(D[i] for i in set_undo)
		for i in set_undo:
			if (D[i]==mini):
				flag = i
				break
		if(flag == end): 
			break
		set_done.add(flag)
		set_undo.remove(flag)
		for i in set_undo:
			if(D[i]>D[flag]+dis[i,flag]):
				cur_route[i] = cur_route[flag]
				D[i] = D[flag]+dis[i,flag]
				cur_team[i] = cur_team[flag] +team[i]
			elif(D[i]==D[flag]+dis[i,flag]):
				cur_route[i] = cur_route[i] + 1
				if (cur_team[i] < cur_team[flag] + team[i]):
					cur_team[i] = cur_team[flag] + team[i]
	return cur_route,cur_team


first_line = raw_input()
statList = first_line.split(' ')
num_city = int(statList[0])
num_road = int(statList[1])
start = int(statList[2])
end = int(statList[3])
second_line = raw_input()
teamList = second_line.split(" ")
team = [int(i) for i in teamList]
#initial distance matrix
inf = 99999999
dis = [[inf]*num_city for i in range(num_city)]
dis = np.array(dis)

k = 0
while(k<num_road):
	M_line = raw_input()
	road = M_line.split(' ')
	i_road = [int(x) for x in road]
	dis[i_road[0],i_road[1]] = i_road[2]
	dis[i_road[1],i_road[0]] = i_road[2]
	k = k+1
ways, teams = waysAndTeams(dis,num_city,start,end,team)
print ways[end], teams[end]
