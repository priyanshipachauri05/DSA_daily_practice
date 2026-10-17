#include <iostream>
using namespace std;
void zeroAtEnd(int* arr,int n)
{
    int new_arr[n];
    int no_of_zero=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            no_of_zero+=1;
    }
    int i=0;
    int j=0;
    while(i<n)
    {
        if(arr[i]!=0)
        {
            new_arr[j]=arr[i];
            j++;
        }
        i++;
    }
    for(int i=n-no_of_zero;i<n;i++)
    {
        new_arr[i]=0;
    }
    cout<<"Array after function:";
    for(int i=0;i<n;i++)
    {
        cout<<new_arr[i]<<" ";
    }
}
/* Problem with this approach that given it uses O(n) time complexity.
It also uses O(n) space complexity. Now could we reduce the space complexity?
*/
/*Yes! By using Optimized in-Place Solution where time complexity will be O(n).
And space complexity will be O(1).*/
void zeroAtEnd_updates(int *arr,int n)
{
    int insertPos=0;
    //First move all the non-zero elements to the front of the array
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[insertPos]=arr[i];
            insertPos+=1;
        }
    }
    //Fill the remaining position with zeros.
    while(insertPos<n)
    {
        arr[insertPos]=0;
        insertPos++;
    }
    //Print the modified original array
    cout<<"Array after fucntion:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
/*Although the question says we have to maintain the relative
ordering of non zero elements, we could solve this question using
two pointers method but the relative ordering of non zero elements won't be
maintained.*/
void zeroAtEndUnstable(int* arr,int n)
{
    int left=0;
    int right=n-1;
    while(left<right)
    {
        //Find the first zero from the left
        while(left<right && arr[left]!=0)left++;
        //Find the first non-zero element from the right
        while(left<right && arr[right]==0)right--;
        if(left<right)
        {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
        cout<<endl<<"Array after function:";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}
/*
Two advanced C++ ways to solve this problem: the single pass stable
swap method and one line C++ standard template library approach.
*/
/*1.Instead of copying non zero elements first and then filling the
zeros later, you can ddo both in single loop using std::swap. This maintains
the relative order and only writes to the array when necssary.
*/
void zeroAtEndStableSinglePass(int* arr,int n)
{
    int insertPos=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            //Swap the current non-zero elements with the first available zero spot
            swap(arr[i],arr[insertPos]);
            insertPos++;
        }
    }
}
//Whenever revising just dry run this on array [5,6,0,9,4,0]
/*Approach 2.The One line C++ STL Approach.
if you are using modern C++ and want clean,production ready code, you
can use std::stable partition fromt the <algorithm> header. It
rearranges the element so that all elements that satisfy a condition
come before those that do not, while preserving their relative order.*/
#include <algorithm> //Required library for std::stable_partition
void zeroAtEndSTD(int* arr, int n)
{
    //Move non zero elements to the front and zeros to the back.
    stable_partition(arr,arr+n,[](int x){return x!=0});
}
/*How does it work??
The lambda function [](int x){return x!=0} tells the algorithm to prioritise
non zero elements. stable_partition automatically handles the shifting,,
grouping and ordering behind the scenes.*/
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array before function:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    zeroAtEndUnstable(arr,n);

    return 0;
}
