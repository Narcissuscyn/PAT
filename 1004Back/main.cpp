#include "Tree.h"
int main()
{
    int sumNodes=0;
    int nonLeafNodes=0;
    cin>>sumNodes>>nonLeafNodes;

     if(nonLeafNodes==0)
     {
         cout<<"1";
         return 0;
     }


    string myNum;
    int childCount;
    TreeNode* nodes;
    nodes=new TreeNode[nonLeafNodes]();

    //������ڵ�
    cin>>myNum>>childCount;
  //  cout<<"*****************"<<childCount<<endl;
    nodes[0].setTreeNode(myNum,childCount,0);
    for(int i=0;i<childCount;i++)
    {
        cin>>nodes[0].childNum[i];
     //   cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%:"<<nodes[0].childNum[i]<<endl;
    }
    if(nonLeafNodes==1)
    {
        cout<<"0 "<<nodes[0].childCount;
    }
    else
    {

    //��ȥ���ڵ�
    int child=1;
    //�������г����ڵ�ķ�Ҷ�����
    while(child<nonLeafNodes)
    {
    cin>>myNum>>childCount;

    //Ѱ�Ҳ���
    int n=child-1;
    int level;
    while(n>=0)
    {
        if(nodes[n].isMyChild(myNum))
        {
            level=nodes[n].level+1;
    nodes[n].childCount--;
            break;
        }
        n--;
    }
  //cout<<"n:__________________________"<<n<<endl;
    //�����µĽڵ�
    nodes[child].setTreeNode(myNum,childCount,level);

    for(int i=0;i<childCount;i++)
    {
        cin>>nodes[child].childNum[i];
    }

    child++;
    }


    //������
     cout<<"0 ";
    int temp=0;
    int lastLevel=0;

   // cout<<"************��Ҷ�������"<<nonLeafNodes<<endl;
    for(int i=0;i<nonLeafNodes;i++)
    {
        if(lastLevel==nodes[i].level)
        {
           //cout<<nodes[i].childCount<<"***************************************"<<endl;
            temp+=nodes[i].childCount;
        }
        else
        {
            cout<<temp<<" ";
            //cout<<nodes[i].childCount<<"else***************************************"<<endl;
           // cout<<temp<<" +++++++=";
            temp=0;
            temp+=nodes[i].childCount;
        }
        lastLevel=nodes[i].level;

    }
    cout<<temp<<endl;

    }
   /* //������ݣ���鹹��������Ƿ��д���
   for(int i=0;i<nonLeafNodes;i++)
    {
        cout<<"MyNum:"<<nodes[i].myNum<<" childCount:"<<nodes[i].childCount<<" level:"<<nodes[i].level<<endl;
        cout<<"childNum:";
        for(int j=0;j<nodes[i].childCount;j++)
        {
            cout<<"-----"<<nodes[i].childNum[j];
        }
        cout<<endl<<endl;
    }
*/
    return 0;
}
