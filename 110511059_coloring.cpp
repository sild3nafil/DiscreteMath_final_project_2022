#include<bits/stdc++.h>
 
using namespace std;
 
const int MAX = 101;
int n , e, max_color, q;
vector<vector<int> > graph;
vector<int> degree, color;
bool edge[MAX][MAX], with_zero;

FILE *input,*output;
 
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
	switch(q)
		{
			case 0:
				output = fopen("110511059_0.txt", "w");
				break;
			case 1:
				output = fopen("110511059_1.txt", "w");
				break;
			case 2:
				output = fopen("110511059_2.txt", "w");
				break;
			case 3:
				output = fopen("110511059_3.txt", "w");
				break;
			default:
				break;
		}
	
	
	fprintf(output, "%d\n", max_color);
	for(int i = 0; i < color.size(); ++i)
		if(color[i] > 0)
			fprintf(output, "%d-%d\n", i, color[i]);
			
	fclose(output);
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
void reset()
{
	n = 0, e = 0, max_color = 0;
	graph.clear();
	degree.clear();
	color.clear();
    memset(edge, 0, sizeof edge);
    with_zero = false;
    
}
 
int main()
{
    int u, v;
    
    for(q = 0; q < 4; ++q)
    {
    	reset();
    	
		switch(q)
		{
			case 0:
				input = fopen("gc_test_input/0.txt", "r");
				break;
			case 1:
				input = fopen("gc_test_input/1.txt", "r");
				break;
			case 2:
				input = fopen("gc_test_input/2.txt", "r");
				break;
			case 3:
				input = fopen("gc_test_input/3.txt", "r");
				break;
			default:
				break;
		}
		
	
		while(!feof(input) && fscanf(input,"%d %d", &u, &v) != EOF)
		{
			if(!u || !v)
				with_zero = true;
			
			edge[u][v] = edge[v][u] = 1;
				
			n = u > n ? u : n;
			n = v > n ? v : n;
			e++;
		}
		if(with_zero)
			n++;
		
		fclose(input);

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
		print();
	}
	
	return 0;
}
