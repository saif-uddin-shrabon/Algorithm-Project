#include<bits/stdc++.h>
using namespace std;

void INSERTIONSORT(int arr[], int s) {
   int temp, pos;
   for(int i = 1; i<s; ++i) {
      temp = arr[i];
      pos = i;
      while(pos > 0 && arr[pos-1]>temp) {
         arr[pos] = arr[pos-1];
         pos--;
      }
      arr[pos] = temp;
   }
}



void merge(int L[], int R[], int A[])
 {
   int i, j, k, nL, nR;
   i = j = k = 0;

   while(i<nL && j<nR) {
      if(L[i] <= R[j]) {
         A[k] = L[i];
         i++;
      }
      else{
         A[k] = R[j];
         j++;
      }
      k++;
   }
   while(i<nL) {
      A[k] = L[i];
      i++;
      k++;
   }
   while(j<nR) {
      A[k] = R[j];
      j++;
      k++;
}
 }

void MERGESORT(int A[], int n) {
   int i, mid;
   if(n / 2){
     return;
   }
   mid = (n / 2);
   int left[mid];
   int right[n-mid];

   for(i=0; i<=mid-1; i++){
    left[i-mid] = A[i];
   }
   for(i=mid; i<=n-1; i++){
    right[i-mid] = A[i];
   }
      MERGESORT(left, mid);
      MERGESORT(right, n-mid);
      merge(left, right, A);
   }






int PARTITION(int A[], int left, int right)
 {
   int pivot, i, j;
   pivot = A [left];
   i = left;
   j = right;
   while (i<j)
   {
       while(A[i]<=pivot && i<=right)
       {
           i=i+1;
       }
       while(A[j]>pivot)
       {
           j=j-1;
       }
       if(i < j)
       {
           swap(A[j], A[j]);
       }
   }
   swap(A[j], A[left]);
   return j;
}

void QUICKSORT(int A[],int left, int right) {
    if(left<right)
    {
        int q = PARTITION(A, left, right);
        QUICKSORT(A, left, q-1);
        QUICKSORT(A, q+1, right);
    }
}


int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;
    int a[n];
    cout<<"Array Values: ";
    for(int i=0; i<n; i++) cin>>a[i];

    do
    {
       cout<<"Press 1: Insertion Sort"<<endl;
        cout<<"Press 2: Merge Sort"<<endl;
        cout<<"Press 3: Quick Sort"<<endl;
        cout<<"Press 4: Exit"<<endl;
        cout<<endl;
        cout<<"Choose your option:";
        cin>>n;

        if (n==1)
        {
          INSERTIONSORT(a,n);
          cout<<"According to Insertion Sort, sorted data is:"<<endl;
        }
        else if(n==2)
        {
          MERGESORT(a,n);
          cout<<"According to Merge Sort, sorted data is:"<<endl;
        }
         else if(n==3)
        {
          QUICKSORT(a,n);
          cout<<"According to Quick Sort, sorted data is:"<<endl;
        }
         else if(n==4)
        {
             cout<<"Program terminated."<<endl;
        }
    } while (n!=4);

    return 0;
}