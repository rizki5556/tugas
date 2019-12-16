#include <iostream>
#include <conio.h>
using namespace std;

class simpul
{
	public:
		double dData;
		simpul* pBrktnya;
		simpul* pSblmnya;
	
	public:
		simpul(double dd):
		dData(dd), pBrktnya(NULL), pSblmnya(NULL)
		{}
		void tampilSenarai()
		{
			cout<<dData<<"";
		};
};

class senaraiberantaiganda
{
	private:
		simpul* pPertama;
		simpul* pAkhir;
	
	public:
		senaraiberantaiganda():
			pPertama(NULL), pAkhir(NULL){}
			~senaraiberantaiganda()
			{
				simpul* pSkrg = pPertama;
				while(pSkrg != NULL)
				{
					simpul* pLama = pSkrg;
					pSkrg = pSkrg->pBrktnya;
					delete pLama;
				}
			}
			
			bool apaKososng(){return pPertama==NULL;}
			
			void sisipPertama(double dd)
			
			{
				simpul* pSimpulBaru = new simpul(dd);
				if(apaKosong())
					pAkhir = pSimpulBaru;
				else
					pPertama->pSblmnya = pSimpulBaru;
					pSimpulBaru->pBrktnya = pPertama;
					pPertama = pSimpulBaru;
			}
			
			void sisipAkhir(double dd)
			
			{
				simpul* pSimpulBaru = new simpul(dd);
				if(apaKosong())
					pPertama = pSimpulBaru;
				else
				{
					pAkhir->pBrktnya = pSimpulBaru;
					pSimpulBaru->pSblmnya =pAkhir;
				}
				pAkhir = pSimpulBaru;
			}
			
			void hapusPertama()
			{
				simpul* pTemp = pPertama;
				if(pPertama->pBrktnya == NULL)
					pAkhir = NULL;
				else
					pPertama->pBrktnya->pSblmnya = NULL;
					pPertama = pPertama->pBrktnya;
				delete pTemp;
			}
			
			void hapusAkhir()
			{
				simpul* pTemp = pAkhir;
				if(pPertama->pBrktnya==NULL)
					pPertama=NULL;
				else
					pAkhir=pAkhir->pSblmnya;
					delete pTemp;
			}
			
			bool sisipSetelah(double kunci, double dd)
			{
				simpul* pSkrg = pPertama;
				while(pSkrg->dData != kunci)
				{
					pSkrg = pSkrg->pBrktnya;
					if(pSkrg==NULL)
						return false;
				}
					simpul* pSimpulBaru = new Simpul(dd);
					if(pSkrg==pAkhir)
					{
						pSimpulBaru->pBrktnya=NULL;
						pAkhir=pSimpulBaru;
					}
					else
					{
						pSimpulBaru->pBrktnya=pSkrg->pBrktnya;
						pSkrg->pBrktnya->pSblmnya=pSimpulBaru;
					}
				pSimpulBaru->pSblmnya=pSkrg;
				pSkrg->pBrktnya=pSimpulBaru;
				return true;
			}
			
			bool hapusKunci(double kunci)
			{
				simpul* pSkrg=pPertama;
				while(pSkrg->dData != kunci)
				{
					pSkrg = pSkrg->pBrktnya;
					if(pSkrg == NULL)
						return false;
				}
				
				if(pSkrg==pPertama)
					pPertama=pSkrg->pBrktnya;
				else
					pSkrg->pSblmnya->pBrktnya=pSkrg->pBrktnya;
				if(pSkrg==pAkhir)
					pAkhir=pSkrg->pSblmnya;
				else
					pSkrg->pBrktnya->pSblmnya=pSkrg->pSblmnya;
				delete pSkrg;
				return true;
			}
			
			void tampilMaju()
			{
				cout<<"Senarai (Pertama-->akhir): ";
				simpul* pSkrg=pPertama;
				while(pSkrg != NULL)
				{
					pSkrg->tampilSenarai();
					pSkrg=pSkrg->pBrktnya;
				}
				cout<<endl;
			}
			
			void tampilMundur()
			{
				cout<<"senarai (akhir-->pertama):";
				simpul* pSkrg=pAkhir;
				while(pSkrg!=NULL)
				{
					pSkrg->tampilSenarai();
					pskrg=pSkrg->pSblmnya;
				}
				cout<<endl;
			}
};

int main()
{
	SenaraiBerantaiGanda senarai;
		senarai.sisipPertama(22);
		senarai.sisipPertama(44);
		senarai.sisipPertama(66);
		
		senarai.sisipAkhir(11);
		senarai.sisipAkhir(33);
		senarai.sisipAkhir(55);
		
		senarai.tampilMaju();
		senarai.tampilMundur();
		
		cout<<"Menghapus simpul pertama, simpul akhir, dan 11"<<endl;
		senarai.hapusPertama();
		senarai.hapusAkhir();
		
		senarai.tampulMaju();
		
		cout<<"menyisipkan 77 setelah simpul 22, dan 88 setelah 33"<< endl;
		senarai.sisipSetelah(22,77);
		senarai.sisipSetelah(33, 88);
		senarai.tampilMaju();
		
		getch();
		return();
}
