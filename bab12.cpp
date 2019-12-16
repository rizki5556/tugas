#include<iostream>
#include<stack>
#include<conio.h>
using namespace std;

class simpul
{
	public:
		int idata;
		double ddata;
		simpul* panakkiri;
		simpul* panakkanan;
		
		simpul(): idata(0), ddata(0.0), panakkiri(NULL), panakkanan(NULL)
		{}
		~simpul()
		{
			cout<<"X-"<<idata<<" ";
		}
		void tampilsimpul()
		{
			cout<<"{"<<idata<<","<<ddata<<"}";
		}
};

class pohon
{
	private:
		simpul* pakar;
	public:
		pohon():pakar(NULL)
		{}
		simpul* cari(int kunci)
		{
			simpul* pskrg = pakar;
			while(pskrg->idata!=kunci)
			{
				if(kunci<pskrg->idata)
					pskrg = pskrg->panakkiri;
				else
					pskrg = pskrg->panakkanan;
				if(pskrg == NULL)
					return NULL;
			}
			return pskrg;
		}
		
		void sisip(int id,double dd)
		{
			simpul* simpulbaru = new simpul;
			simpulbaru->idata=id;
			simpulbaru->ddata=dd;
			
			if(pakar==NULL)
				pakar=simpulbaru;
			else
			{
				simpul* pskrg=pakar;
				simpul* pinduk;
				while(true)
				{
					pinduk=pskrg;
					if(id<pskrg->idata)
					{
						pskrg=pskrg->panakkiri;
						if(pskrg==NULL)
						{
							pinduk->panakkiri=simpulbaru;
							return;
						}
					}
					else
					{
						pskrg=pskrg->panakkanan;
						if(pskrg==NULL)
						{
							pinduk->panakkanan=simpulbaru;
							return;
						}
					}
				}
			}
		}
		
		void jelajah(int tipejelajah)
		{
			switch(tipejelajah)
			{
				case 1:	cout<<"\npenjelajahan preorder: ";
						preorder(pakar);
						break;
				case 2:	cout<<"\npenjelajahan inorder: ";
						inorder(pakar);
						break;
				case 3: cout<<"\npenjelajahan postorder: ";
						postorder(pakar);
						break;
			}
			cout<<endl;
		}
		
		void preorder(simpul* pakarlokal)
		{
			if(pakarlokal !=NULL)
				{
					cout<<pakarlokal->idata<<" ";
					preorder(pakarlokal->panakkiri);
					preorder(pakarlokal->panakkanan);
				}
		}
		
		void inorder(simpul* pakarlokal)
		{
			if(pakarlokal!=NULL)
			{
				inorder(pakarlokal->panakkiri);
				cout<<pakarlokal->idata<<" ";
				inorder(pakarlokal->panakkanan);
			}
		}
		
		void postorder(simpul* pakarlokal)
		{
			if(pakarlokal!=NULL)
			{
				postorder(pakarlokal->panakkiri);
				postorder(pakarlokal->panakkanan);
				cout<<pakarlokal->idata<<" ";
			}
		}
		
		void tampilpohon()
		{
			stack<simpul*>tumpukan;
			tumpukan.push(pakar);
			int jumspasi=32;
			bool apabariskosong=false;
			cout<<"..................................";
			cout<<endl;
			
			while(apabariskosong==false)
			{
				stack<simpul*>tumpukanlokal;
				apabariskosong=true;
				
				for(int j=0; j<jumspasi; j++)
					cout<<" ";
				
				while(tumpukan.empty()==false)
				{
					simpul* temp=tumpukan.top();
					tumpukan.pop();
					
					if(temp!=NULL)
					{
						cout<<temp->idata;
						tumpukanlokal.push(temp->panakkiri);
						tumpukanlokal.push(temp->panakkanan);
						
						if(temp->panakkiri!=NULL || temp->panakkanan!=NULL)
							apabariskosong=false;
					}
					
					else
					{
						cout<<"--";
						tumpukanlokal.push(NULL);
						tumpukanlokal.push(NULL);
					}
					
					for(int j=0; j<jumspasi; j++)
						cout<<" ";
						
					while(tumpukan.empty()==false)
					{
						simpul* temp= tumpukan.top();
						tumpukan.pop();
						
						if(temp != NULL)
						{
							cout<< temp->idata;
							tumpukanlokal.push(temp->panakkiri);
							tumpukanlokal.push(temp->panakkanan);
							
							if(temp->panakkiri!=NULL || temp->panakkanan!=NULL)
								apabariskosong=false;
						}
						
						else
						{
							cout<<"--";
							tumpukanlokal.push(NULL);
							tumpukanlokal.push(NULL);
						}
						
						for(int j=0; j<jumspasi*2-2; j++)
							cout<<" ";
					}
				}
				cout<<endl;
				jumspasi/=2;
				
				while(tumpukanlokal.empty()==false)
				{
					tumpukan.push(tumpukanlokal.top());
					tumpukanlokal.pop();
				}
			}
			cout<<"...........................";
			cout<<endl;
		}
		
		void hapus()
		{
			hapusrekursif(pakar);
		}
		
		void hapusrekursif(simpul* pakarlokal)
		{
			if(pakarlokal!=NULL)
			{
				hapusrekursif(pakarlokal->panakkiri);
				hapusrekursif(pakarlokal->panakkanan);
				
				delete pakarlokal;
			}
		}
};

int main()
{
	int nilai;
	char pilihan = NULL;
	simpul* ditemukan;
	
	pohon pohon;
	
	pohon.sisip(50, 5.0);
	pohon.sisip(25, 2.5);
	pohon.sisip(75, 7.5);
	pohon.sisip(12, 1.2);
	pohon.sisip(37, 3.7);
	pohon.sisip(43, 4.3);
	pohon.sisip(30, 3.0);
	pohon.sisip(33, 3.3);
	pohon.sisip(87, 8.7);
	pohon.sisip(93, 9.3);
	pohon.sisip(97, 9.7);
	
	while(pilihan!='k')
	{
		cout<<"masukan huruf pertama dari ";
		cout<<"tampil, sisip, cari jelajah, atau keluar: ";
		cin>>pilihan;
		
		switch(pilihan)
		{
			case 't': pohon.tampilpohon();
					  break;
			case 's': cout<<"masukan nilai yang akan disisipkan: ";
					  cin>>nilai;
					  pohon.sisip(nilai, nilai+0.9);
					  break;
			case 'c': cout<<"masukan nilai yang akan dicari: ";
					  cin>>nilai;
					  ditemukan = pohon.cari(nilai);
					  
					  if(ditemukan!=NULL)
					  {
					  	cout<<"ditemukan : ";
					  	ditemukan->tampilsimpul();
					  	cout<<endl;
					  }
					  else
					  	cout<<"tidak ditemukan."<<nilai<<endl;
					  break;
			case 'j': cout<<"masukan tipe jelajah(1 = preorder,"<<"2 = inorder, 3 = postorder): ";
					  cin>>nilai;
					  pohon.jelajah(nilai);
					  break;
			case 'k': pohon.hapus();
					  cout<<endl;
					  break;
			default : cout<<"entri tak-valid\n"; 
		}
	}
	
	getch();
	return 0;
}
