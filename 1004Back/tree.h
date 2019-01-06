#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<string>
using namespace std;
#define MAX_CHILD 100
class TreeNode
{
public:
    string myNum;
    int childCount;
    int level;
    string*childNum;
   //int parent;

    bool isMyChild(string childNum);
    void setTreeNode(string myNum,int childCount,int level);
    TreeNode();
   //TreeNode(string myNum,int childCount,int level,int parent);
};
#endif // TREE_H
