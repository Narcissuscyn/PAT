#include <iostream>
using namespace std;


int  main(){
	void getET();
	getET();
	getchar();
}


class Point//存放一个点的坐标
{
public: 
	int x;
	int y;
	bool isExtremum;//标志是否为极小值点
};


class PointET//一个“吊桶”
{
public:
	int Ymax;
	int Xmin;
	float m;
	PointET* next;
};

class PointAtr//链接吊桶的数组
{
public:
	int x;
	PointET* link;
	PointAtr(){
		x = 0;
	}
};



void getET(){

	
	cout << "请输入顶点数目：" << endl;
	int n;
	cin >> n;

	bool* edge = new bool[n];
	Point* myPoint = new Point[n];
	int max=0;
	int min = 10000;

	//输入点并存储在数组中
	for (int i = 0; i < n; i++)
	{
		edge[i] = false;
		cin >> myPoint[i].x >> myPoint[i].y;
		if (myPoint[i].y>max)
		{
			max = myPoint[i].y;
		}
		if (myPoint[i].y<min)
		{
			min = myPoint[i].y;
		}
		myPoint[i].isExtremum = false;
	}

	//遍历数组，并判断每个点是否为极小值点
	for (int i = 0; i < n;i++)
	{
		if (i==0)//当i==0时，它和第n个点有连接
		{
			if (((myPoint[i].x<myPoint[i + 1].x) && (myPoint[i].y<myPoint[i + 1].y))&&((myPoint[n-1].x<myPoint[i].x)&&(myPoint[n-1].y>myPoint[i].y)))
			{
				myPoint[i].isExtremum = true;
			}
		}
		else if (i==n-1)//当i=n-1时，它和第一个点有连接
		{
			if (((myPoint[i].x < myPoint[0].x) && (myPoint[i].y < myPoint[0].y)) && ((myPoint[i-1].x<myPoint[i].x) && (myPoint[i-1].y>myPoint[i].y)))
		{
				myPoint[i].isExtremum = true;
		}
		}
		else {
			if (((myPoint[i].x > myPoint[i + 1].x) && (myPoint[i].y < myPoint[i + 1].y)) && ((myPoint[i - 1].x > myPoint[i].x) && (myPoint[i - 1].y > myPoint[i].y)))
			{
				myPoint[i].isExtremum = true;
			}
		}

	}


	//构造ET

	PointAtr *pointAtr = new PointAtr[max - min + 1];
	int m = 0;
	for (int i = min; i <max+1; i++)
	{
		pointAtr[m].x = i;
		pointAtr[m].link = NULL;
		m++;
	}

	
		int i = min;
		for (; i < max+1;i++)
		{
		for (int j = 0; j < n;j++)
		{
			
				if (i == myPoint[j].y)
				{
					if (!edge[j])
					{
						if (myPoint[j].isExtremum)
						{
							cout << myPoint[j].y;
							PointET*pET1 = new PointET();
							PointET*pET2 = new PointET();

							if (j == 0)
							{
								edge[0] = true;
								edge[n - 1] = true;
								float m1 = (float)(myPoint[0].x - myPoint[n - 1].x) / (float)(myPoint[0].y - myPoint[n - 1].y);
								pET1->Ymax = myPoint[n - 1].y;
								pET1->Xmin = myPoint[0].x;
								pET1->m = m1;

							}
							else
							{
								edge[j] = true;
								edge[j - 1] = true;
								float m1 = (float)(myPoint[j].x - myPoint[j - 1].x) / (float)(myPoint[j].y - myPoint[j - 1].y);
								pET1->m = m1;
								pET1->Ymax = myPoint[j].y;
								pET1->Xmin = myPoint[j - 1].x;

							}
							pointAtr[i-min].link = pET1;
							float m2 = (float)(myPoint[j].x - myPoint[(j + 1) % n].x) / (float)(myPoint[j].y - myPoint[(j + 1) % n].y);
							pET2->m = m2;

							pET2->Ymax = myPoint[(j + 1) % n].y;
							pET2->Xmin = myPoint[j].x;
							pET1->next = pET2;
						}
						else//如果不是极小值点，而且未加入ET中
						{
							PointET*pET = new PointET();
								edge[j ] = true;
							if (myPoint[j].y < myPoint[(j + 1) % n].y)
							{
								pET->Ymax = myPoint[(j + 1) % n].y;
								pET->Xmin = myPoint[j].x;
							}
							else
							{

								pET->Ymax = myPoint[j].y ;
								pET->Xmin = myPoint[(j + 1) % n].x;
							}
							if (myPoint[(j + 1) % n].x != myPoint[j].x)
							{
								float m = (float)(myPoint[(j + 1) % n].y - myPoint[j].y) / (float)(myPoint[(j + 1) % n].x - myPoint[j].x);
								pET->m = m;
							}
							pointAtr[i-min+1].link = pET;
						
						}
					}
				}
			}

	}
	cout << "输出ET表" << endl;
	//打印ET表
	for (int i = 0; i < max - min + 1;i++)
	{
		PointET * temp = pointAtr[i].link;
		cout << pointAtr[i].x << ":";
		while (temp!=NULL)
		{
			cout << temp->Ymax << "-" << temp->Xmin << "-" << temp->m<<"->";
			temp = temp->next;
		}
		cout << endl;
	}
	getchar();
}