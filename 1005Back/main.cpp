#include<iostream>
using namespace std;
#define MAXNUM 101
string names[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void printSum(int sum);
int main()
{
    char *N;
    N=new char[MAXNUM];
    int i=0;

    //gets()函数可以读取一行（包括/c/c++）
    gets(N);

    //将所有igit加起来
    int sum=0;
    while(N[i]!='\0')
    {
        sum+=N[i]-'0';
        i++;
    }
    printSum(sum);
    return 0;
}
void printSum(int sum)
{
      //输出每位数字;
    string name[4];
    int i=0;
    int temp=0;
    if(sum==0)
    {
        cout<<"zero";
        return;
    }
    while(sum!=0)
    {
       temp=sum%10;
       name[i]=names[temp];
       i++;
       sum=sum/10;
    }
    for(int j=i-1;j>0;j--)
    {
    cout<<name[j]<<" ";
    }
    cout<<name[0];
}
