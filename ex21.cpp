

       #include "pzhelp"
#include <iostream>

using namespace std;
    struct node{
     int info;
     node *left,*right;
    };

class bstree{
public:
    bstree();
    int height();
    void insert(node *t,int x);
    int search(int x);
    int min();
    int max();
    void preorder();
    void inorder();
    void postorder();
    node *root;

 int heightA(node *t) {
  if (t == nullptr) return 0;
    int a,b;
    a=heightA(t->left),
    b=heightA(t->right);
    if(a>=b)return (1+a);
    return (1+b);
     }
};bstree::bstree(){
 root=nullptr;
}

int bstree::height(){
 return heightA(root);
}

void bstree::insert(node *t,int x){
    if (t == nullptr) {
      node *q=new node;
      q->info=x;
      q->left=q->right=nullptr;
      t=q;
    }
    if ((t->info) >x)
      insert(t->left,x);
    else if ((t->info) <x)
      insert(t->right,x);
}
int bstree::search (int x){
 node *p=root;
 int i=1;
 while(p!=nullptr){
  if(x<(p->info)){
   p=p->left;
   i++;
  }
  else if(x>(p->info)){
   p=p->right;
   i++;
  }
  else
    return i;
 }
 return 0;
}


int bstree::min(){
 node *p=root;
 while((p->left)!=nullptr){
  p=p->left;
 }
 return (p->info);
}

int bstree::max(){
 node *p=root;
 while((p->right)!=nullptr){
  p=p->right;
 }
 return (p->info);
}
void bstree::inorder(){
 node*p=root;
 if(p!=nullptr){
  bstree trleft, trright;
  trleft.root=p->left;
  trright.root=p->right;
  WRITE(p->info);
  WRITE(" ");
  trleft.inorder();
  WRITELN(p->info);
  trright.inorder();
 }
}

void bstree::preorder(){
 node*p=root;
 if(p!=nullptr){
  bstree trleft, trright;
  trleft.root=p->left;
  trright.root=p->right;
  WRITE(p->info);
  WRITE(" ");
  trleft.preorder();
  trright.preorder();
 }
}

void bstree::postorder(){
 node*p=root;
 if(p!=nullptr){
  bstree trleft, trright;
  trleft.root=p->left;
  trright.root=p->right;
  WRITE(p->info);
  WRITE(" ");
  trleft.postorder();
  trright.postorder();
  WRITELN(p->info);
 }
}
int array[100];

int main(){
bstree bstree1;
int N,M,X;
scanf("%d",&N); WRITELN("N=",N);
for(int i=0;i<N;i++){
 scanf("%d",&X); WRITELN("X=",X);
 bstree1.insert(bstree1.root,X);
 }

WRITELN("PREORDER=");
bstree1.preorder();
scanf("%d",&M); WRITELN("M=",M);
for(int i=0;i<M;i++){
 scanf("%d",&X);  WRITELN("X=",X);
 array[i]=bstree1.search(X); WRITELN("search(X)=",bstree1.search(X));
}
WRITELN(bstree1.height());

WRITELN(bstree1.min(),bstree1.max());

for(int i=0; i<M; i++){
 WRITE(array[i]);
 WRITE(" ");
}

WRITELN();

bstree1.inorder();
WRITELN("end");

bstree1.preorder();
WRITELN("end");

bstree1.postorder();
WRITELN("end");
}
               


