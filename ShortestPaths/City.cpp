#include"City.h"
#include<queue>
   //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����
bool*visited; //�����ж϶����Ƿ��Ѿ������·�����У�����˵�Ƿ����ҵ����·��
int*dist;
//�洢���ǵ��ýڵ��·����
int* roadCount;
//�洢��������Ԯ�ӵ�·��
 int* maxTeamSum;
 int*parent;
priority_queue<int,vector<int>,cmp> q; //���ȶ���stlʵ��

void SaveCity::dijstra(Atr*atr,int n,int src,int des)
    {
        //��̬���ٿռ�
        parent=new int[n];
        visited=new bool[n];
        dist=new int[n];
        roadCount=new int[n];
        maxTeamSum=new int[n];
        //��ʼ��
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;//ÿ�����㶼û�и��ڵ�
            visited[i]=false;//ÿ���ڵ㶼û�з��ʹ�
            dist[i]=INF;//ÿ�����붼�Ǻܴ��ֵ
            roadCount[i]=1;
            maxTeamSum[i]=0;
        }
        maxTeamSum[src]=atr[src].teamCount;
        dist[src]=0;
        q.push(src);
        while(!q.empty())
        {
            //����һ���ڵ�,���ȶ���ÿ�ζ�������Сdist�Ľڵ�
            int top=q.top();
            //cout<<"*******************"<<top<<endl;
            q.pop();
            if(visited[top])
            {
                continue;
            }
         //�ɳڲ���//�������������ڵĶ��㣬�����ɳڲ�����
         //���¹�����룬ѹ����С�
         City* city=atr[top].link;
         while(city!=NULL)
         {
            int cityNum=city->cityNumber;
         if((!visited[cityNum] )&& dist[cityNum] >=dist[top]+city->cost)
            {
                if(dist[cityNum] >dist[top]+city->cost)
               {
                   dist[cityNum] = dist[top]+city->cost;

                    parent[cityNum] = top;
                    maxTeamSum[cityNum]=maxTeamSum[top]+atr[cityNum].teamCount;
                    q.push(cityNum);
               }
               else
               {
                   if(maxTeamSum[top]>maxTeamSum[parent[cityNum]])
                   {
                         parent[cityNum] = top;
                        maxTeamSum[cityNum]=maxTeamSum[top]+atr[cityNum].teamCount;
                   }
                     parent[cityNum] = top;
                   roadCount[cityNum]++;
               }
            }
            city = city->next;
         }

           visited[top]=true;
        }
    //������

    cout<<roadCount[des]<<" "<<maxTeamSum[des];
        return;

    }
