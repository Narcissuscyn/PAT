#include"City.h"
#include<queue>
   //每个顶点的父亲节点，可以用于还原最短路径树
bool*visited; //用于判断顶点是否已经在最短路径树中，或者说是否已找到最短路径
int*dist;
//存储的是到该节点的路径数
int* roadCount;
//存储的是最多救援队的路线
 int* maxTeamSum;
 int*parent;
priority_queue<int,vector<int>,cmp> q; //优先队列stl实现

void SaveCity::dijstra(Atr*atr,int n,int src,int des)
    {
        //动态开辟空间
        parent=new int[n];
        visited=new bool[n];
        dist=new int[n];
        roadCount=new int[n];
        maxTeamSum=new int[n];
        //初始化
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;//每个顶点都没有父节点
            visited[i]=false;//每个节点都没有访问过
            dist[i]=INF;//每个距离都是很大的值
            roadCount[i]=1;
            maxTeamSum[i]=0;
        }
        maxTeamSum[src]=atr[src].teamCount;
        dist[src]=0;
        q.push(src);
        while(!q.empty())
        {
            //弹出一个节点,优先队列每次都弹出最小dist的节点
            int top=q.top();
            //cout<<"*******************"<<top<<endl;
            q.pop();
            if(visited[top])
            {
                continue;
            }
         //松弛操作//找所有与他相邻的顶点，进行松弛操作，
         //更新估算距离，压入队列。
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
    //输出结果

    cout<<roadCount[des]<<" "<<maxTeamSum[des];
        return;

    }
