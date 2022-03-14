#include<stdio.h>
#include<stdlib.h>


void preorder();
void inorder();
void postorder();
void max();
void min();

struct tree{
int data;
struct tree *left;
struct tree *right;
}*root,*p,*q;


void main(){
int n,i,data;
printf("enter the no of nodes\n");
scanf("%d",&n);
for(i=0;i<n;i++){
	p=(struct tree *)malloc(sizeof(struct tree));
	printf("\nenter the node:\n");
	scanf("%d",&data);
	p->data=data;
	p->left=0;
	p->right=0;
	if(i==0){
	root=p;
	}
	else{
		q=root;
		if(p->data>q->data){
			if(q->right==0){
				q->right=p;
				}
			else{
				q=q->right;
			}
		}
		else{
			if(q->left==0){
				q->left=p;
			}
			else{
				q=q->left;
			}
		}

	}

}

int c;
while(1){

	printf("\nBINARY SEARCH TREE\n");
	printf("1.preorder\n2.inorder\n3.postorder\n4.max\n5.min\n6.exit\nenter your choice\n");
	scanf("%d",&c);
	switch(c){
		case 1:preorder(root);break;
		case 2:inorder(root);break;
		case 3:postorder(root);break;
		case 4:max(root);break;
		case 5:min(root);break;
		case 6:exit(0);break;
		default:printf("invalid choice\n");
	}

	}
}



void preorder(struct tree *node){
	if(node!=0){
		printf("%d\t",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(struct tree *node){
	if(node!=0){
		inorder(node->left);
		printf("%d\t",node->data);
		inorder(node->right);
	}
}

void postorder(struct tree *node){
	if(node!=0){
		postorder(node->left);
		postorder(node->right);
		printf("%d\t",node->data);
	}
}


void max(struct tree *node){

	while(node->right!=0){
		node=node->right;
	}
printf("max:=%d",node->data);
}


void min(struct tree *node){

	while(node->left!=0){
		node=node->left;
	}
printf("min:=%d\t",node->data);
}
