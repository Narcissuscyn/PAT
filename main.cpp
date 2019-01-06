#include<iostream>
#include<string>
using namespace std;
void strlwr1(char*str)
{
    cout<<strlen(str)<<"----"<<endl;
    int i=0;
    for(;i<strlen(str);i++)
    {
       if(str[i]>=65&&str[i]<=90)
        {
            //str[i]+=32;
            str[i]=(char)(str[i]+32);
            cout<<str[i];
        }

    }
}
int main()
{
    char*s="+3ADDSDS2";
    strlwr1(s);
    return 0;
}
