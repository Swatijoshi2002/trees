#include<stdio.h>
#include<stdlib.h>
struct b_tree{
    struct b_tree* left;
    int data;
    struct b_tree * right;
    int thread;
};
struct b_tree * insert(struct b_tree* root,int info)
{
        if(root==NULL)
        {
          struct b_tree * temp=(struct b_tree*)malloc(sizeof(struct b_tree));
        temp->left=NULL;
        temp->right=NULL;
        temp->data=info;
        temp->thread=0;
            return temp;
        }
        else if(info <root->data)
        {
            root->left=insert(root->left,info);
        }
        else if(info>root->data)
        {
            root->right=insert(root->right,info);
        }
        
    return root;
}
void print(struct b_tree * root)
{
    if(root==NULL)
    {
        return;
    }
    print(root->left);
    printf("%d ",root->data);
     print(root->right);

}
struct b_tree* inordersuc(struct b_tree* root)
{
    if(root==NULL)
    return NULL;
    else if(root->left==NULL)
    return root;
    else return inordersuc(root->left);
}
struct b_tree* delete(struct b_tree* root,int key)
{
    if(root==NULL)
    return root;
    else if(key>root->data)
    {
        root->right=delete(root->right,key);
    }
    else if(key<root->data)
    {
        root->left=delete(root->left,key);
    }
    else{
        if(!(root->left) && !(root->right))
        return NULL;
        else if(root->left==NULL && root->right!=NULL)
        {
            struct b_tree* temp=root->right;
            free(root);
            return temp;
        }
         else if(root->left!=NULL && root->right==NULL)
        {
            struct b_tree* temp=root->left;
            free(root);
          return temp;
        }
        else{
           struct b_tree* temp=inordersuc(root->right);
           root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
        
    }
    return root;
}
struct b_tree* predecessor(struct b_tree* root)
{
    if(root==NULL)
    return NULL;
    if(root->right==NULL)
    return root;
    else return predecessor(root->right);
}
void thread(struct b_tree* root)
{
    if(root==NULL)
    return ;
     thread(root->left);
     struct b_tree* l=predecessor(root->left);
     if(l!=NULL)
     {
         l->right=root;
         l->thread=1;
     }
    return  thread(root->right);
}
struct b_tree* leftm(struct b_tree* root)
{
    if(root==NULL)
    return NULL;
    while(root->left!=NULL)
    root=root->left;
    return root;
}
void print_threaded(struct b_tree* root)
{
    struct b_tree* l=leftm(root);
    printf("\n");
    while(l!=NULL)
    {
        printf("%d ",l->data);
        if(l->thread==1)
        l=l->right;
        else l=leftm(l->right);
    }
}
int main()
{
    struct b_tree* root=NULL;
     struct b_tree * temp=(struct b_tree*)malloc(sizeof(struct b_tree));
    if(temp==NULL)
    {
        printf("no sufficient memory\n");
    }
    else{
        printf("enter value to insert\n");
        int data;
        scanf("%d",&data);
        temp->left=NULL;
        temp->right=NULL;
        temp->data=data;
        root=temp;
     while(1)
     {
         printf("enter 1 to insert and -1 to stop\n");
         int n;
         scanf("%d",&n);
             if(n==1)
             {
                 int num;
                 printf("enter data\n");
                 int info;
                 scanf("%d",&info);
                 root=insert(root,info);
             }
             else break;
          
     }
     root=temp;
     print(root);
    thread(root);
     print_threaded(root);
     /*printf("enter data to delete\n");
     int key;
     scanf("%d",&key);
    root= delete(root,key);
    print(root);*/
    }
}
