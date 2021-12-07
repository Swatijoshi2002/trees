#include<stdio.h>
#include<stdlib.h>
struct b_tree{
    struct b_tree* left;
    int data;
    struct b_tree * right;
};
struct b_tree * insert(struct b_tree* root,int info)
{
        if(root==NULL)
        {
          struct b_tree * temp=(struct b_tree*)malloc(sizeof(struct b_tree));
        temp->left=NULL;
        temp->right=NULL;
        temp->data=info;
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
            root=root->right;
            free(temp);
            return root;
        }
         else if(root->left!=NULL && root->right==NULL)
        {
            struct b_tree* temp=root->left;
            root=root->left;
            free(temp);
            temp=NULL;
            return root;
        }
        
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
     print(root);\
     printf("enter data to delete\n");
     int key;
     scanf("%d",&key);
    root= delete(root,key);
    print(root);
    }
}
