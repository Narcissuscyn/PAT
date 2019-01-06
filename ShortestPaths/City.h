#ifndef CITY_H
#define CITY_H
#include <iostream>
using namespace std;
const int MAXN=500;
const int INF=0xfffff;

struct City
{
public:

    int cityNumber;
    int cost;
    City*next;
};
struct Atr
{
public:
    int cityIndex;
    int teamCount;
    City* link;
};
class SaveCity
{
    public:
    void dijstra(Atr*atr,int n,int src,int des);
    int maxTeams();
};

struct cmp{
    bool operator ()(int &a,int &b){
        return a>b;//最小值优先
    }
};
#endif // CITY_H
