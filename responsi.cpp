#include<conio.h>
#include <iostream>
#include<stdlib.h>

using namespace std;

struct data{
char nim[200],nama[20];
char orkom[20],jarkom[20],so[20],basisdata[20],pbo[20],clientserver[20];};
 data batas[100];
 int nim1,angka;
int a,b,c,d;
char i,j,k,tmp,jumlah=0;

void inputdata()
{    cout<<"\nJumlah Data Yang Akan diinput : ";cin>>b;

   d=0;
   for(c=0;c<b;c++){
   d=d+1;
   cout<<"\nData ke-"<<d<<endl;
        
  
   cout<<"NIM\t: ";cin>>batas[a].nim;
   cout<<"Nama\t: ";cin>>batas[a].nama;
   cout<<"NILAI MATA KULIAH";
   cout<<"\n orkom\t: ";cin>>batas[a].orkom;
   cout<<"jarkom\t: ";cin>>batas[a].jarkom;
   cout<<"so\t: ";cin>>batas[a].so;
   cout<<"basis data\t: ";cin>>batas[a].basisdata;
   cout<<"pbo\t: ";cin>>batas[a].pbo;
   cout<<"client server\t: ";cin>>batas[a].clientserver;
   a++;}  }



void urutdata()
{
	 for( i=0;i<b;i++)
      {
          for(j=i+1;j<b;j++)
          {
               if(batas[i].orkom>batas[j].orkom)
             {
			 
                 tmp=i;
                 batas[i]=batas[j];
                 j=tmp;
         }
         }
      }
         cout<<"\n Nilai orkom setelah diurutkan  : "<<endl;
       for(i=0; i<b; i++)
       {
        {
        	cout<<"||\tNO\t||\tNIM\t||\tNama\t\t||\tOrkom\t||\tOrkom\t||\tJarkom\t||\tSO\t||\tBasis data\t||\t Client server\t||\n";
           cout<<batas[i].orkom,batas[i].jarkom ,batas[i].so,batas[i].basisdata ,batas[i].pbo ,batas[i].clientserver;
            }
       }
	

       }
   


void caridata()
{

cout<<"  Masukan nim Yang Dicari  = ";
cin>>nim1;
cout<<endl;  


i=0;
do{
if(d==nim1)
angka=d;
i++;}
while(i<b);
if(angka==nim1)
cout<<"  nim "<<nim1<<" Ditemukan";
else
cout<<"  nim "<<nim1<<" Tidak Ditemukan";
getch();	

}



int main()
{     int pilih;
 char w;
 
  awal:
  cout<<"\n================================ PILIHAN MENU =================================";
  cout<<"\n1. Masukkan data";
  cout<<"\n2. urut Data";
  cout<<"\n3. Cari Data";
  cout<<"\n4. Keluar";
  cout<<"\n\nMasukkan Pilihan : ";
  cin>>pilih;
  if(pilih==1)
   {inputdata();goto awal;system("cls");}
  if(pilih==2)
   {urutdata();goto awal;system("cls");}
  if(pilih==3)
   {caridata();goto awal;system("cls");}
 
  if(pilih==4)
   {
    cout<<"\n\n\n\n\n\n\n\n                     YAKIN KELUAR DARI PROGRAM??\n\n";
    cout<<"                         [Y]                         [N]                  \n"<<endl;
    cout<<"                                         ";cin>>w;
    if(w=='y'||w=='Y')
    {}
    if(w=='n'||w=='N')
           {goto awal;}}
  else
   {cout<<"Pilihan 1-4";getch();goto awal;}

}
