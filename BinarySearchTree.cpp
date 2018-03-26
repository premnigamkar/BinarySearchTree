# binarysearchtree

#include<iostream>
using namespace std;
//Node for Tree
class node{
     public:
     node *parent;
     node *left;
     node *right;
     int data;
    node(){
     parent=left=right=NULL;
     data=0;
    }
};

// Binary tree
class Btree{
     public:
     node *root;       
   
    Btree()
    {
    root=NULL;
    }

// function insert elements
 void insert(int x){
   node *temp=new node;
   temp->data=x;
   temp->parent=temp->left=temp->right=NULL;
   
   if(root==NULL)
   { root=temp;
   }
   else{ node *cur; 
         cur=root;
        while(1){
            if(x<cur->data){
              
               if(cur->left==NULL){
                  temp->parent=cur;
                  cur->left=temp;
               break;
               }              
              else{cur=cur->left;}
            }
           else { 
                    if(cur->right==NULL)
                       {
                       temp->parent=cur;
                       cur->right=temp;
                     break;}
                   else{cur=cur->right;}
                  }
                          
        }
     }
 }

// function to Display elements

 void display(node *temp){
     
      if(temp==NULL)
         return;
      display(temp->left);
      cout<<"\t"<<temp->data;
      display(temp->right);                
}

};     


int main(){
 Btree b;
 cout<<"\nMENU";
 cout<<"\n1.INSERT";
 cout<<"\n2.DISPLAY";
 cout<<"\n3.EXIT";
 
int ch,x;
do{
  cout<<"Enter your choice (1-3): "<<endl;
  cin>>ch;
  switch(ch){
  case 1:cout<<"Enter the element to be added :"<<endl;
         cin>>x;
         b.insert(x);break;
  case 2:b.display(b.root);break;
  deafult:cout<<"wrong choice "<<endl;
  break;
  }
}while(ch!=3);
return 0;
}

