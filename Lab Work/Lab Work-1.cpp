/*
      Git Title 
Case with 3 sorting Algorithm
    * Insertion Sort
    * Merge Sort
    * Quick Sort
    
*/
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define Saif ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
void insertion_sort(int arr[], int s)
{
    int pos,temp;
    for(int i=1; i<s; i++)
    {
        temp=arr[i];
        pos=i;
        while(pos>0 && arr[pos-1]>temp)
        {
            arr[pos]=arr[pos-1];
            pos--;
        }
        arr[pos]=temp;
    }
}

void Merge(int left[],int ln, int right[],int rn, int arr[])
{
    int i,j,k;
    i=j=k=0;

    while(i<ln && j<rn)
    {
        if(left[i]<=right[j])
        {
            arr[k]= left[i];
            i++;
        }
        else
        {
            arr[k]= right[j];
            j++;
        }
        k++;
    }
     while(i<ln){
        arr[k]= left[i];
        k++;
        i++;
    }
    while(j<rn){
        arr[k]= right[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[], int s)
{
    int mid;
    if(s<2) return;

    mid = s/2;
    int left[mid], right[s-mid];

    for(int i=0; i<=mid-1; i++)
        left[i] = arr[i];

    for(int i=mid; i<=s-1; i++)
        right[i-mid] = arr[i];

    merge_sort(left, mid);
    merge_sort(right, s-mid);
    Merge(left,mid, right,s-mid, arr);

}

void swap(int *a, int *b)
{
    int t= *a;
    *a = *b;
    *b = t;
}

int Partition(int arr[],int l,int h)
{
    int pivot= arr[l];
    int i=l, j=h;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=h)
                 i++;
        while(arr[j]>pivot)
                  j--;
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[j],&arr[l]);

    return j;
}
void quick_sort(int arr[], int l, int h)
{
    int q;
    if(l<h)
    {
        q = Partition(arr,l, h);
         quick_sort(arr,l,q-1);
         quick_sort(arr,q+1,h);
    }
}

int main()
{
    // Saif;

    int n,s;
    cout<<"Enter Array Size: ";
    cin>>s;
    int arr[s];
    cout<<"Array Values: ";
    for(int i=0; i<s; i++) cin>>arr[i];
    do
    {
        cout<<"Press 1: Insertion Sort"<<endl;
        cout<<"Press 2: Merge Sort"<<endl;
        cout<<"Press 3: Quick Sort"<<endl;
        cout<<"Press 4: Exit"<<endl;
        cout<<endl;
        cout<<"Choose your option:";
        cin>>n;

        switch(n)
        {
        case 1:
            insertion_sort(arr,s);
            cout<<"According to Insertion Sort, sorted data is: ";
            for(int  i=0; i<s; i++) cout<<arr[i]<<" ";
            cout<<endl;
            break;
        case 2:
            merge_sort(arr,s);
            cout<<"According to Merge Sort, sorted data is: ";
            for(int  i=0; i<s; i++) cout<<arr[i]<<" ";
            cout<<endl;
            break;
        case 3:
            quick_sort(arr,0,s-1);
            cout<<"According to Qick Sort, sorted data is: ";
            for(int i=0; i<s; i++) cout<<arr[i]<<" ";
            cout<<endl;
            break;
        case 4: 
           cout<<"Program terminated."<<endl;
           break;
        }

    }
    while(n!=4);
    return 0;
}
