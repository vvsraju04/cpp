#include<iostream>
using namespace std;
class Node
{
        public:
                int data;
                Node *left;
                Node *right;
};
class BST
{
        public:
                Node *start;
        BST(){
                start=new Node;
        }
        int constructBST(int *intPoint)
        {
                Node *nodePoint=start;
                Node *prevNodePoint=start;
                start->data=intPoint[0];
                for( int i=1;intPoint[i];i++)
                {
                        nodePoint=start;
                        while(!nodePoint)
                        {
                                if(intPoint[i]>(nodePoint->data))
                                {
                                        cout<<"right"<<endl;
                                        nodePoint=nodePoint->right;
                                        prevNodePoint=nodePoint;
                                }
                                if(intPoint[i]<(nodePoint->data))
                                {
                                        cout<<"left"<<endl;
                                        nodePoint=nodePoint->left;
                                        prevNodePoint=nodePoint;
                                }
                        }
                        if(intPoint[i]>(prevNodePoint->data))
                        {
                                cout<<"Creating Right Node for "<<intPoint[i]<<endl;
                                prevNodePoint->right=new Node;
                                prevNodePoint->right->data=intPoint[i];
                        }
                        if(intPoint[i]<(prevNodePoint->data))
                        {
                                cout<<"Creating Left Node for "<<intPoint[i]<<endl;
                                prevNodePoint->left=new Node;
                                prevNodePoint->left->data=intPoint[i];
                        }
                }
                return 1;
        }
        int findLCA(int a, int b)
        {
                return 1;
        }
};
int main()
{
        BST *bst=new BST;
        int a[]={34,76,23,12,88,335,73,456,29,25,32};
        bst->constructBST(a);
        bst->findLCA(12,32);
}
