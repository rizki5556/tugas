#include <iostream>
#include <conio.h>

using namespace std;

main ()
{
    int data[]= {12,2,84,1,5,65,7,45,8,4,3,6,8,7,4,1,5,45,99,65,78,21,12,36,45,32,76,45,34,76,34,12,87,5,3,9,2,54,9,67,45};
    int nilai,index[40],j;
    j=0;
    cout<<"Data : ";
    for (int i=0;i<40;i++)
    {
        cout<<data[i]<<",";
    }
    cout<<endl;
    cout<<"\nmasukkan nilai yang dicari : ";
	cin>>nilai;
    for (int i=0;i<=40;i++)
    {
        if (data[i]==nilai)
        {
            index[j]=i;
            j++;
        }
    }
    
    if (j>0)
    {
        cout<<"Nilai yang dicari = "<<nilai<<" ada sejumlah = "<<j<< " buah"<<endl;
        cout<<"Nilai tersebut ada dalam indeks ke (indeks mulai dari 0) = "<<endl;
        for (int i=0;i<j;i++)
        {
            cout<<"indeks ke "<<index[i]<<endl;
        }
        cout<<endl;
    }
    else
    {cout<<"Nilai tidak ditemukan dalam array"<<endl;}
    
    
    getch();    
}
