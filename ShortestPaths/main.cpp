#include"City.h"
#include<string.h>
#include<fstream>
int main()
{
    //����ͼ�ı�����洢���ݽṹ

    Atr* atr;
    int n,m,src,des;

    ifstream infile;
    infile.open("data.txt",ios::in);
    //    cin>>n>>m>>src>>des;
    infile>>n>>m>>src>>des;
    atr=new Atr[n];
    for(int i=0;i<n;i++)
    {
        atr[i].cityIndex=i;
       // cin>>atr[i].teamCount;
       infile>>atr[i].teamCount;
        atr[i].link=NULL;
    }
    for(int i=0;i<m;i++)
    {

        int temp=-1;
        //cin>>temp;
        infile>>temp;
        City*city=new City();

        //cin>>city->cityNumber;
        infile>>city->cityNumber;
        //cin>>city->cost;
        infile>>city->cost;
        city->next=NULL;

        if(atr[temp].link==NULL)
        {
        atr[temp].cityIndex=temp;

        atr[temp].link=city;
        }
        else
        {
         City* city1= atr[temp].link;
         while(city1->next!=NULL)
         {
             city1=city1->next;
         }
        city1->next=city;
        }
    }

/*
    //���������ڽ�����:
    for(int i=0;i<n;i++)
    {
         City*city1=NULL;
        if(atr[i].link!=NULL)
        {

            city1=atr[i].link;
            while(city1!=NULL)
            {
            cout<<"res:"<<i<<endl;
            cout<<"cityNumber:"<<city1->cityNumber<<endl;
            cout<<"cost:"<<city1->cost<<endl;
            cout<<"-------------------------------------------"<<endl;
            city1=city1->next;
            }
        }
        else
        {
            cout<<"û��ֵ��"<<endl;
        }
    }

*/

        //�����·��
    SaveCity* saveCity=new SaveCity;
    saveCity->dijstra(atr,n,src,des);
    delete[] atr;
    delete saveCity;
    infile.close();
    return 0;
}
