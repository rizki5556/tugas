#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class BinaryTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
   
    public:
        BinaryTree()
        {
           root = NULL;
        }
      
        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node*);
        void print_preorder();
        void preorder(tree_node*);
        void print_postorder();
        void postorder(tree_node*);
        void insert(int);
        void remove(int);
        void count(tree_node*);
};

void BinaryTree::insert(int d)
{
	tree_node* t = new tree_node;
	tree_node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	if(isEmpty())root = t;
	else
	{
		tree_node* curr;
		curr = root;

		while(curr!=NULL)
		{
			parent = curr;
			if(t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if(t->data < parent->data)
			parent->left = t;
		else
		parent->right = t;
	}
}

void BinaryTree::inorder(tree_node* p)
	{
		if(p!=NULL)
		{
			if(p->left)
			inorder(p->left);
			cout<<" "<<p->data<<" ";
			if(p->right)
			inorder(p->right);
		}
		else
		return;
	}

void BinaryTree::postorder(tree_node* p)
    {
        if(p!=NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout<<" "<<p->data<<" ";
        }
              
        else
            return;
    }

void BinaryTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";   
        if(p->left)
            preorder(p->left);
        if(p->right)
            preorder(p->right);
    }

    else
        return;
}

void BinaryTree::print_inorder()
	{
		inorder(root);
	}

void BinaryTree::print_preorder()
{
    preorder(root);
}

void BinaryTree::print_postorder()
{
	postorder(root);
}

void BinaryTree::remove(int d)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
   
    tree_node* curr;
    tree_node* parent;
    curr = root;
   
    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
         {
        cout<<" Data not found! "<<endl;
        return;
    }
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }
         if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
                  delete curr;
                  return;
    }

    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else
        {


            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
        curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
           curr->right = tmp->right;
               delete tmp;
           }

        }
         return;
    }

}

void BinaryTree::count(tree_node* p,)
	{
		if(p==NULL)return 0;
		return count(p->left) + count(p->right) + 1;
	}

void BinaryTree::height(tree_node* p)
	{
		if(p==NULL)return 0;
		int u = height(p->left),v = height(p->right);
		if(u > v)
		return u+1;
		else
		return v+1;
	}

void BinaryTree::cari_terbesar(tree_node* p)
	{
		if(p==NULL)
		return;
		else
		if(p->right==NULL)
		{
			cout<<" "<<p->data<<" ";
			return;
		}
		else
		{
			cari_terbesar(p->right);
			return;
		}
	}

int main()
	{
		
		root=NULL;
		int ch, tmp, tmp1;

		while(1)
		{
			system("cls");
			cout<<endl;
			cout<<"Menu Utama Operasi Pohon Biner"<<endl;
			cout<<"--------------------"<<endl;
			cout<<"1. Insert/Tambah Data"<<endl;
			cout<<"2. Kunjungan In-Order"<<endl;
			cout<<"3. Kunjungan Pre-Order"<<endl;
			cout<<"4. Kunjungan Post-Order"<<endl;
			cout<<"5. Hapus Data"<<endl;
			cout<<"6. Menghitung Jumlah Node"<<endl;
			cout<<"7. Menghitung Tinggi Pohon"<<endl;
			cout<<"8. Mencari Data Terkecil"<<endl;
			cout<<"9. Mencari Data Terbesar"<<endl;
			cout<<"0. Exit"<<endl;
			cout<<"Pilihan Anda : ";
			cin>>ch;
			cout<<endl;
			switch(ch)
			{
				case 1 :
					cout<<"Masukan Data : ";
					cin>>tmp;
					insert(tmp);
				break;
				case 2 :
					cout<<endl;
					cout<<"Kunjungan In-Order"<<endl;
					cout<<"---------------"<<endl;
					print_inorder();
					getch();
				break;
				case 3 :
					cout<<endl;
					cout<<"Kunjungan Pre-Order"<<endl;
					cout<<"---------------"<<endl;
					print_preorder();
					getch();
				break;
				case 4 :
					cout<<endl;
					cout<<"Kunjungan Post-Order"<<endl;
					cout<<"---------------"<<endl;
					print_postorder();
					getch();
				break;
				case 5 :
					cout<<endl;
                    cout<<" Masukkan data yang dihapus : ";
                    cin>>tmp1;
                    remove(tmp1);
                    getch();
                break;
				case 6 :
					cout<<endl;
					cout<<"Menghitung Jumlah Node"<<endl;
					cout<<"------------------"<<endl;
					cout<<"Jumlah Node = "<<count(root);
					getch();
				break;
				case 7 :
					cout<<endl;
					cout<<"Menghitung Tinggi Pohon"<<endl;
					cout<<"------------------"<<endl;
					cout<<"Tinggi Pohon = "<<height(root);
					getch();
				break;
				case 9 :
					cout<<endl;
					cout<<"Mecari Data Terbesar"<<endl;
					cout<<"------------------"<<endl;
					cout<<"Data Terbesar Adalah = "<<endl;
					cari_terbesar(root);
					getch();
				break;
				case 0 :
					return 0;
				break;
				default: cout<<"Pilihan yang Anda Masukkan salah!"<<endl;
				getch();
				break;
			}
		}
	}
