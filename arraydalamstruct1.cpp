/*contoh program sederhana array di dalam struct*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
//#define maks 3		: membuat penginputan menjadi maksimal 3
using namespace std;
 
struct TMhs
{
char NIM[9];
char Nama[21];
int NilaiUTS,NilaiUAS,NilaiQuis;
float NilaiAkhir;
char index;
};

main ()
{
  int i, n; //variabel n digunakan untuk memasukan jumlah yang kita inginkan
  cout << "Masukan jumlah mahasiswa : ";
  cin >> n;

TMhs mhs[n];
//int i; dipindahkan ke atas agar variabel n terbaca
for(i=0;i<n;i++){

cout << "Pengisian Data Mahasiswa Ke-"<<i+1<< endl;

cout << "NIM : "; cin >> mhs[i].NIM;

cout << "NAMA : "; cin >> mhs[i].Nama;

cout <<"Nilai Quiz : ";cin >> mhs[i].NilaiQuis;

cout <<"Nilai UTS : ";cin >> mhs[i].NilaiUTS;

cout <<"Nilai UAS : ";cin >> mhs[i].NilaiUAS;

mhs[i].NilaiAkhir=0.2*mhs[i].NilaiQuis+0.3*mhs[i].NilaiUTS+0.5*mhs[i].NilaiUAS;

if
(mhs[i].NilaiAkhir>=80) {mhs[i].index ='A';}
else if(mhs[i].NilaiAkhir>=60) {mhs[i].index ='B';}
else if(mhs[i].NilaiAkhir>=40) {mhs[i].index ='C';}
else if(mhs[i].NilaiAkhir>=20) {mhs[i].index ='D';}
else//(mhs[i].NilaiAkhir>=0) 
{mhs[i].index ='E';}
}

cout <<"Data yang telah dimasukkan adalah : \n";
cout <<"------------------ \n";
cout <<"| NIM | NAMA | QUIS | UTS | UAS | NILAIAKHIR | INDEX | \n";
cout <<"------------------ \n";
for(i=0;i<n;i++)
{
	cout<<"\n|"<<mhs[i].NIM << "\t|"<<mhs[i].Nama<<"\t|"<<mhs[i].NilaiQuis<<"\t|"<<mhs[i].NilaiUTS<<"\t|"<<mhs[i].NilaiUAS<<"\t|"<<mhs[i].NilaiAkhir<<"\t|"<<mhs[i].index;
//cout<< mhs[i].NIM << endl;
//cout<< mhs[i].Nama << endl;
//cout<< mhs[i].NilaiQuis << endl;
//cout<< mhs[i].NilaiUTS<< endl; 
//cout<< mhs[i].NilaiUAS<< endl; 
//cout<< mhs[i].NilaiAkhir<< endl; 
//cout<< mhs[i].index<< endl; //<< endl;

}
//<< endl;
cout<<"\n|------------------ |\n";
getch();
return 0;
}
