#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
bool graph[MAX][MAX], with_zero = false;
int all[MAX][MAX], some[MAX][MAX], none[MAX][MAX];
int n = 0;
vector<vector<int> > clique;

inline bool compare(const vector<int> &u, const vector<int> &v)
{
	return (u.size() == v.size()) ? u < v : u.size() < v.size();
}
void sort_2d_vec()
{
	for(size_t i = 0; i < clique.size(); ++i)
		sort(clique[i].begin(), clique[i].end());
	sort(clique.begin(), clique.end(), compare);
}
void print()
{
	int index = 0;
    for(size_t i = 0; i < clique.size(); ++i)
    {
		if(index < clique[i].size())
    	{
    		index = clique[i].size();
    		printf("%d\n",index);
		}
		printf("{");
		for(size_t j = 0; j < clique[i].size(); ++j)
		{
    		printf("%d", clique[i][j]);
    		if(j < clique[i].size() - 1) 
				printf(","); 
    	}
    	printf("}\n");
	}
}
void max_cliq(int d, int an, int sn, int nn)
{
    int u = some[d][0]; 
    
    for(size_t i = 0; i < sn; ++i)
    {
        int v = some[d][i];
        
		if(graph[u][v]) 
			continue; 
			
        for(size_t j = 0; j < an; ++j)  
            all[d+1][j] = all[d][j];  
        all[d+1][an] = v;
        
        int nextsn, nextnn;
        nextsn = nextnn = 0;
        
        for(size_t j = 0; j < sn; ++j)  
			if(graph[v][some[d][j]])  
				some[d+1][nextsn++] = some[d][j];
        for(size_t j = 0; j < nn; ++j)  
			if(graph[v][none[d][j]])  
				none[d+1][nextnn++] = none[d][j];
		
		if(!nextsn && !nextnn)
			clique.push_back(vector<int>(all[d+1], all[d+1] + an + 1));
		
        max_cliq(d+1, an+1, nextsn, nextnn);
        some[d][i] = -1, none[d][nn++] = v;
    }
}
void execute()
{
    if(with_zero)
		n++;
	for(size_t i = 0; i < n; ++i) 
		some[1][i] = (with_zero == true) ? i : i+1;
		
	max_cliq(1, 0, n, 0);
	sort_2d_vec();
	print();
}

int main()
{
	int u, v;
 	
 	clique.clear();
 	memset(graph, 0, sizeof graph);
 
 	while(scanf("%d",&u) != EOF)
	{
    	scanf("%d",&v);
    	
		if(!u || !v)
			with_zero = true;
			
		graph[u][v] = graph[v][u] = 1;
				
		n = u > n ? u : n;
		n = v > n ? v : n;
	}
	
	execute();
	
    return 0;
}


