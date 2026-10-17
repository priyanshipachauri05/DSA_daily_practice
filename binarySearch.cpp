#include <iostream>
using namespace std;
int BinarySearch(int* arr,int n,int k)
{
    int left=0;
    int right=n;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]>k)
            right=mid-1;
        else
            left=mid+1;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the key to be searched:";
    cin>>k;
    int res;
    res=BinarySearch(arr,n,k);
    if(res!=-1)
        cout<<"Element "<<k<<" found at "<<res<<" index.";
    else
        cout<<"Element not present.";
    delete arr;
    return 0;
}
