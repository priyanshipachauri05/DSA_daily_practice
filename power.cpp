#include <iostream>
using namespace std;
int power(int x,int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x,y-1);
}
//This approach successfully calculates the yth power of a number x. But it takes O(n) time complexity.
//The idea to optimize this approach could be to Divide and Conquer.
/*We can write x^y as (x^y/2)*(x^y/2) and keep dividing y until it becomes 1.
But y could be either odd or even. If it is even then we could just write (x^y)=(x^(y/2))*(x^(y/2))
but if y is odd then we'll have to do (x^y)=x*(x^y/2)*(x^y/2).*/
int powerDC(int x,int y)
{
    if(y==0)
        return 1;
    int temp=powerDC(x,y/2);  //Calculate powerDC(x,y/2) and store it.
    if(y%2==0)
        return temp*temp;       //If y is even then ultimately power will be (x^y)=(x^(y/2))*(x^(y/2)
    else
        return x*temp*temp;     //If y is odd then ans will be (x^y)=x*(x^y/2)*(x^y/2)
}
/*One alert: Do save the function call in temp to avoid multiple times calling the fucntion.*/
int main()
{
    int x,y;
    cout<<"Enter the values of x and y:";
    cin>>x>>y;
    int res=0;
    res=powerDC(x,y);
    cout<<"x raised to the power y = "<<res;
    return 0;
}
