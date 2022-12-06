#include <iostream>
using namespace std;
int main()
{
  int n,i;
  // Dynamic memory allocation
  int *arr = new(nothrow) int[n];

  // Enter size of array
  cout<<"Enter size of array: ";
  cin>>n;

  // Enter array elements
  cout<<"Enter array: "<<endl;
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  
  // display array
  cout<<"Display array: "<<endl;
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  // Free the memory using delete operator
  delete [] arr;
  
  return 0;
}