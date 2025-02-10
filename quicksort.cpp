#include <bits/stdc++.h>
using namespace std;
 
int partition(int arr[],int start,int end){

    int x = arr[0];
     int count_of_smaller_element = 0;
     for(int i=start+1;i<=end;i++){
         if(arr[i]<=x){
            count_of_smaller_element++;
         }
     }
     // making partition around first element 
     int temp;
      temp = arr[start];
      arr[start]  = arr[start+count_of_smaller_element];
      arr[start+count_of_smaller_element] = temp;
      int i = start;
       int j = end;
     while(i < start+count_of_smaller_element || j>start+count_of_smaller_element){
        if(arr[i] <= x) {
             i++; 
        }
        else if(arr[j]>x){
             j--;
        }
        else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j]= temp;
            i++;
            j--;
        }
       
     }
     return start+count_of_smaller_element;
}

void qs(int arr[],int start ,int end){
    if(start>=end){
        return;
    }
    int c = partition(arr,start,end);
      qs(arr,start,c-1);
       qs(arr,c+1,end);
   
}
int main()
{
    int n;

    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    qs(arr, 0, n - 1);

    // Printing the sorted data.
    cout << "\nSorted Data ";
    for (int i = 0; i < n; i++)
        cout << "->" << arr[i];

    return 0;
}
