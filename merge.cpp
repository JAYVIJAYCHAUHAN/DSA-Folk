#include <bits/stdc++.h>
using namespace std;
 void merge(vector<int> &a, int low, int high)
{
    vector<int> temp;
     
    int mid = (low+high)/2;
    int left = low;
    int right = mid + 1;
    
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
           
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            
            temp.push_back(a[right]);
             
            right++;
        }
    }
    // if left element is still
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high)
    {
        /* code */
        temp.push_back(a[right]);
        right++;
    }
    // tranfer the element to arr
    
     
    for (int i = low; i <= high; i++)
    {
     
        a[i] = temp[i - low];
    }
    
      
   
    
}

void mergeSort(vector<int> &a, int low, int high)
{
     
    if(low>=high){
        return;
    }
    if (low < high){
          int mid = (low + high) / 2;
      mergeSort(a, low, mid);
     mergeSort(a, mid + 1, high);
 
     merge(a, low, high);
    }
     
}
// int numOfInversion(vector<int> &a, int n)
// {
//     return mergeSort(a, 0, n - 1);
// }

int main()
{
     int n;
     cin>>n;
    vector<int> a(n);
     for(int i=0;i<n;i++){
         cin>>a[i];
     }
    mergeSort(a,0,n-1);
    for(int i=0;i<a.size();i++){
         cout << a[i] << endl;
    }
    return 0;
}
