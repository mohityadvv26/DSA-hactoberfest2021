#include <iostream>
using namespace std;

#define count 10

class node
{
public:
    int data;
    node *left;
    node *right;
    // int height;
    node(int d)
    {
        data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int getheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return max(getheight(root->left), getheight(root->right)) + 1;
    }
}

int GetBalancedFator(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
        return getheight(root->left) - getheight(root->right);
}

node* rightrotate(node* y)
{
    node* x=y->left;
    node*T2=x->right;

    x->right = y;
    y->left = T2;

    return x;
    
}
node* leftrotate(node* x)
{
    node* y=x->right;
    node* T2=y->left;

    y->left=x;
    x->right=T2;

    return y;
}
node* insertnode(node* root,int val)
{
    if(root==NULL)
    {
        root=new node(val);
        
    }
    else if(val<root->data)
    {
        root->left= insertnode(root->left,val);
        // rootbalance(root);
    }
    else if(val>root->data)
    {
        root->right= insertnode(root->right,val);
        // root=balance(root);
    }

    int bf=GetBalancedFator(root);


    // Left Left Case
        if(bf>1 && val < root->left->data){
            return rightrotate(root);
        }
    // Right Right Case
        if(bf<-1 && val > root->right->data){
            return leftrotate(root);
        }
    // Left Right Case
    if(bf>1 && val > root->left->data){
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }
    // Right Left Case
    if(bf<-1 && val < root->right->data){
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }


    return root;
}

void print2D(node* root,int space)
{
    if(root==NULL)
    {return;}

    space+=count;

    print2D(root->right,space);

    cout << endl;
    for (int i = count; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
 
    // Process left child
    print2D(root->left, space);
}


int main()
{
    int c,val;
    node* root=NULL;

    while (1)
    {
        cout << "1.Insert Element into the tree: " << endl;
        cout<<"2.print 2D Tree: "<<endl;
        cout << "5.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
    

    switch (c)
    {
    case 1:
        cout<<"enter value to be inserted: ";
        cin>>val;
        root=insertnode(root,val);
        break;
    case 2:
        cout<<"--------------------------------";
        print2D(root,0);
        break;
    case 5:
        exit;

    
    default:
    cout<<"wrong choice";
        break;
    }
    
    }


    return 0;
}