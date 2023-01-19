#include <iostream>
#include <iomanip>
using namespace std;
void merge(int A[], int mid, int low, int high);
void mergeSort(int A[], int low, int high);

int main()
{
    int i = 0,n,arr[100];
    cout<<"Enter the number of employees:";
    cin>>n;
    cout<<endl;
    cout<<"Enter the salary of "<<n<<" employees"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<"The array before sorting,"<<endl;
     for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    cout<<endl<<"Top 5 performers are,"<<endl;
    int count=0;
     for(i=n-1;i>=0;i--)
    {
        if(count==5)
        {
            break;
        }
        cout<<arr[i]<<" ";
        count++;
    }
    return 0;
}
void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
