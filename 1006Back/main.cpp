#include<iostream>
using namespace  std;
bool timeCmp(string s1,string s2);
int main()
{
    int M=0;
    string* ID;
    string* inTime;
    string* OutTime;
    cin>>M;
    ID=new string[M];
    inTime=new string[M];
    OutTime=new string[M];

    for(int i=0;i<M;i++)
    {
        cin>>ID[i]>>inTime[i]>>OutTime[i];
      //   cout<<ID[i]<<inTime[i]<<OutTime[i]<<endl;
    }
    int inTimeMin=0,outTimeMax=0;
    string strMin=inTime[0],strMax=OutTime[0];
    for(int i=1;i<M;i++)
    {
        //比较两个时间：

        if(timeCmp(strMin,inTime[i]))
        {
            strMin=inTime[i];
            inTimeMin=i;
        }
        if(!timeCmp(strMax,OutTime[i]))
        {
            strMax=OutTime[i];
             outTimeMax=i;
        }

    }
    //输出结果
cout<<ID[inTimeMin]<<" "<<ID[outTimeMax];
    return 0;
}

bool timeCmp(string s1,string s2)
{
    int length=s1.length();
    int i=0;
    while(length>0)
    {
        if(s1[i]!=s2[i])
        {
            if(s1[i]>s2[i])
            {
            return true;
            }
            else
            {
                return false;
            }

        }
        else
        {
             i++;
        length--;
        }

    }
    return false;
}
