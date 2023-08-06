#include<iostream>
using namespace std;
class node{
    public:
    int v;
     node *left,*right;

};
node *root=nullptr;
void add_node_to_tree(int v){
    node *cur;
    node *newnode;
    int flag=0;
    newnode=new node;
    //建立節點內容
    newnode->v=v;
    newnode->left=nullptr;
    newnode->right=nullptr;
    //如果是空的，便將新的節點設定為新節點
    if(root=nullptr){
        root=newnode;
    }
    else {
        cur=root;
        while(!flag){
            if(v<cur->v){
                //在左子樹
                if(cur->left==NULL){
                    
                }
            }
        }
    }

}
int main(){




    return 0;
}