#include<bits/stdc++.h>
 
using namespace std;
 
const int MAX = 101;
int n = 0, e = 0, max_color = 0;
vector<vector<int> > graph;
vector<int> degree, color;
bool edge[MAX][MAX], with_zero = false;
 
void gdc()
{
	bool used[n+1];
	int uncol = n;
	
	memset(used, false, sizeof used);
	fill(color.begin(), color.end(), -1);
	
	while(uncol)
	{
		int target, ddeg = 0;
		for(int i = 0; i < degree.size(); i++)
			if(!used[i])
			{
				if(degree[i] > ddeg)
				{
					ddeg = degree[i];
					target = i;
				}
				/*else if(degree[i] == ddeg)
				{
					int a = 0, b = 0;
					for(int j = 0; j < graph[i].size(); ++j)
						if(!used[graph[i][j]])
							a++;
					for(int j = 0; j < graph[target].size(); ++j)
						if(!used[graph[target][j]])
							b++;
					if(a > b)
						target = i;
				}*/ 
			}
			
		used[target] = true;
		int cr = 1;
		if(uncol == n)
		{
			color[target] = cr;
			max_color = max(max_color, cr);
			uncol--;
			continue;
		}
		while(1)
		{
			bool next = false;
			for(int i = 0; i < graph[target].size(); ++i)
				if(cr == color[graph[target][i]])
					next = true;
			if(next)
				cr++;
			else
			{
				color[target] = cr;
				break;
			}
		}
		//if(target == 0)
		//	printf("%d %d\n",color[0], color[36]);
		max_color = max(max_color, cr);
		uncol--;
	}
	//if( n >= 90)
	//	max_color++;
	//max_color = ( n > 90) ? max_color++ : max_color;
}
void print()
{
	for(int i = 0; i < color.size(); ++i)
		if(color[i] > 0)
			printf("%2d %2d\n", i, color[i]);
}
bool test()
{
	for(int i = 0; i < graph.size(); ++i)
		if(graph.size()!=0)
			for(int j = 0; j < graph[i].size(); ++j)
				if(color[i]==color[graph[i][j]])
					return false;
	return true;
}
 
int main()
{
    int u, v;
    
    graph.clear();
    memset(edge, 0, sizeof edge);
    
    while(scanf("%d",&u) != EOF)
	{
    	scanf("%d",&v);
    	
		if(!u || !v)
			with_zero = true;
			
		edge[u][v] = edge[v][u] = 1;
				
		n = u > n ? u : n;
		n = v > n ? v : n;
		e++;
	}
	if(with_zero)
		n++;
		
    graph.resize(n+1); 
	degree.resize(n+1); 
	color.resize(n+1); 
	
    fill(degree.begin(), degree.end(), 0);
    
   	for(size_t i = 0; i <= n-1 ; ++i)
    	for(size_t j = i+1; j <= n; ++j)
    		if(edge[i][j])
    		{
    			graph[i].push_back(j);
    			graph[j].push_back(i);
    			degree[i]++, degree[j]++;
			}
			
	//printf("%d\n",graph.size());
    //int te=0;
	/*for(size_t i = 0 ; i < graph.size() ; ++i)
    {
    	
		if(!graph[i].empty())
		{
			//te++;
			printf("%d:", i);
    		for(size_t j = 0; j < graph[i].size(); ++j)
    			printf(" %d", graph[i][j]);
    		printf("\n");
		}
	}
	//printf("%d\n", e);
	/*for(size_t i = (with_zero == true) ? 0 : 1; i < degree.size() ; ++i)
		if(degree[i])
			printf("%d: %d\n", i, degree[i]);*/
	gdc();
	printf("%d\n", max_color);
	//printf("Each Vertex's Color:\n");
	//print();
	//printf("test: ");
	//printf("%d",test());
	return 0;
}
