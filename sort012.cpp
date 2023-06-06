#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   for(int l = -1, i = 0, r = n; i < r; i++)
   {
      if(arr[i] == 0)
         swap(arr[++l], arr[i]);
      else if(arr[i] == 2)
         swap(arr[--r], arr[i--]);
   }
}