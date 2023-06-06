#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    while(top < bottom && left < right)
    {
        int temp = mat[top][left];
        for(int c = left + 1; c <= right; c++)
            swap(temp, mat[top][c]);
        top++;
        for(int r = top; r <= bottom; r++)
            swap(temp, mat[r][right]);
        right--;
        for(int c = right; c >= left; c--)
            swap(temp, mat[bottom][c]);
        bottom--;
        for(int r = bottom; r >= top; r--)
            swap(temp, mat[r][left]);
        left++;
        swap(temp, mat[left - 1][top - 1]);
    }
}