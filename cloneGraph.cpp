#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode* dfs(graphNode *node, unordered_map<graphNode*, graphNode*> &vis)
{
	graphNode *copy = new graphNode(node -> data);
	vis[node] = copy;
	for(graphNode *adj : node -> neighbours)
	{
		if(vis.find(adj) != vis.end()){
			copy -> neighbours.push_back(vis[adj]);
			continue;
		}
		copy -> neighbours.push_back(dfs(adj, vis));
	}
	return copy;
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	unordered_map<graphNode*, graphNode*> vis;
	return dfs(node, vis);
}