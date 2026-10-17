#include <iostream>
using namespace std;
int* SieveofErastosthenes(int n)
{
    //Dynamic memory allocation to the isPrime array
    bool* isPrime=new bool[n+1];
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=n;i++)
    {
        isPrime[i]=true;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i])
        {
            for(int p=i*i;p<=n;p=p+i)
            {
                isPrime[p]=false;
            }
        }
    }
    //Allocate exaclty n+1 elemenrs for the results array
    //Initialize all the elements as zero.
    int* res=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        res[i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        if(i>=2 && isPrime[i])
        {
           res[i]=i;
        }
        else
        {
            res[i]=0;
        }
    }
    delete[] isPrime; //Free the temporary boolean array memory
    return res;
}
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int *res=SieveofErastosthenes(n);
    cout<<"Prime numbers upto "<< n <<" are:";
    for(int i=0;i<n;i++)
    {
        if(res[i]!=0)
            cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
