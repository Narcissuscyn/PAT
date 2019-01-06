
#include "Tree.h"
bool TreeNode::isMyChild(string number)
{
    for(int i=0;i<this->childCount;i++)
    {
        if(number==childNum[i])
        {
            return true;
        }
    }
    return false;
}
/*
TreeNode::TreeNode(string myNum,int childCount,int level,int parent)
{
    this->myNum=myNum;
    this->childCount=childCount;
    this->level=level;
    //this->parent=parent;
    childNum=new string[childCount];
    for(int i=0;i<this->childCount;i++)
    {
        childNum[i]="";
    }
}*/
TreeNode::TreeNode()
{
    myNum="";
    childCount=0;
    level=0;
   // parent=0;
}
void TreeNode::setTreeNode(string myNum,int childCount,int level)
{
     this->myNum=myNum;
    this->childCount=childCount;
    this->level=level;
    //this->parent=parent;
    childNum=new string[childCount];
    for(int i=0;i<this->childCount;i++)
    {
        childNum[i]="+++++++++++++++++++";
    }
}
