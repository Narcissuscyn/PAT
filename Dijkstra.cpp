#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int N,M;
int S;
int E;
const int MAXN=0x7fffffff;

int Map[1000][100];
int Val[1000][100];
int Abut[1000]={0};
int dist[1000];
bool flag[1000];
int prev[1000];

void init()
{
	scanf("%d %d\n",&N,&M);
	cin>>S;
	for (int i=1;i<=M;i++)
	{
		int a,b,c;
		scanf("%d %d %d\n",&a,&b,&c);
		Abut[a]++;
		Map[a][Abut[a]]=b;
		Val[a][Abut[a]]=c;
		
		
		Abut[b]++;
		Map[b][Abut[b]]=a;
		Val[b][Abut[b]]=c;
		
	}
	return;
}

void Dijkstra(int S)
{
	for (int i=1;i<=N;i++)
	{
		dist[i]=MAXN;
		flag[i]=false;
		prev[i]=0;
	}
	
	for (int i=1;i<=Abut[S];i++)
	{
		dist[Map[S][i]]=Val[S][i];
		prev[Map[S][i]]=S;
	}
	
	dist[S]=0;
	flag[S]=1;
	
	for (int i=2;i<=N;i++)
	{
		long long tmp=MAXN;
		int u=S;
		for(int j=1;j<=N;j++)
		{
			if( (!flag[j]) && dist[j]<tmp )
			{
				u=j;
				tmp=dist[j];
			}
		}
		flag[u]=1;
		
		for (int j=1;j<=Abut[u]; j++)
		{
			if ( (!flag[Map[u][j]]))
			{
				long long newdist=dist[u]+Val[u][j];
				if(newdist<dist[Map[u][j]])
				{
					dist[Map[u][j]]=newdist;
					prev[Map[u][j]]=u;
				}
			}
		}
	}
}

void print()
{
	int road[100]={0};
	int p=E;
	int n=1;
	
	while(p!=S)
	{
		road[n]=p;
		p=prev[road[n]];
		n++;
	}
	road[n]=S;

	for (int i=n;i>=2;i--)
		cout<<road[i]<<"->";
	cout<<E<<endl;
}

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	init();
	Dijkstra(S);
	
	cin>>E;
	
	for (int i=1;i<=N;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	cout<<dist[E]<<endl;
	print();
	return 0;
}
