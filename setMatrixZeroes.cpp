#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	// Write your code here.
	bool row = false, col = false;
	int n = mat.size(), m = mat[0].size();
	if(mat[0][0] == 0)
		row = col = true;
	for(int c = 0; c < m; c++)
	{
		if(mat[0][c] == 0){
			row = true;
			break;
		}
	}
	for(int r = 0; r < n; r++)
	{
		if(mat[r][0] == 0){
			col = true;
			break;
		}
	}
	for(int r = 1; r < n; r++)
	{
		for(int c = 1; c < m; c++)
		{
			if(mat[r][c] == 0)
				mat[r][0] = mat[0][c] = 0; 
		}
	}
	for(int r = 1; r < n; r++)
	{
		if(mat[r][0] == 0)
		{
			for(int c = 0; c < m; c++)
				mat[r][c] = 0;
		}
	}
	for(int c = 1; c < m; c++)
	{
		if(mat[0][c] == 0)
		{
			for(int r = 0; r < n; r++)
				mat[r][c] = 0;
		}
	}
	if(row)
	{
		for(int c = 0; c < m; c++)
			mat[0][c] = 0;
	}
	if(col)
	{
		for(int r = 0; r < n; r++)
			mat[r][0] = 0;
	}
}