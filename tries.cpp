#include<iostream>
#include<string>
using namespace std;

class Node
{
    public:
         int count;
         Node *p[26];
    Node()
    {
        count=0;
    }
    void dumpNode()
     {
        for(int i=0;i<26;i++){
            cout<<"for "<<i<<" is "<<this->p[i]<<endl;
        }
    }
};

class Trie
{
    public:
          Node *start;
         Node *p1;
    Trie()
    {
        start=new Node;
        p1=start;
    }
    int getIndex(char chr)
    {
        return ((int)chr)-97;
    }    

    int insertWord(string str)
     {
        p1=start;
        cout<<"Creating Trie for word : "<< str<<endl;
        for(int i=0;i<str.length();i++)
        {
            int index=getIndex(str[i]);
            if(!p1->p[index]){
                 cout<<"creating Node for "<<str[i]<<endl;
                p1->p[index]=new Node;
            }
            p1=p1->p[index];
        }
        p1->count+=1;
         cout<<"increamented count to : "<< p1->count<<endl;
        return p1->count;
    }
    int displayTree()
    {
    }
    int searchTheTree(string str)
    {
         p1=start;
        cout<<"Search for word : "<<str<<endl;
        for(int i=0;i<str.length();i++)
                {
            int index=getIndex(str[i]);
            cout<<"Searching for : "<<str[i]<< " with index "<<index;
             if(p1->p[index]){
                p1=p1->p[index];
                cout<<" found\n";
            }
            else{
                cout<<" Not found\n";
                 return 0;
            }
        }
        return p1->count;
        
    }
    
};
int main()
{
    Trie *t1=new Trie;
    t1->insertWord("apple");
    t1->insertWord("apple");
     t1->insertWord("approve");
    cout<<"Apple was found :"t1->searchTheTree("apple")<<" times"<<endl;
    cout<<t1->searchTheTree("appre");
    cout<<endl;
}
