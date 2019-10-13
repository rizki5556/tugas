#include <iostream>
using namespace std;

int main()
{
    string nama;
    cout<<"Masukan suatu kata: ";
    cin>>nama;
    cout<<endl;
    cout<<"Keluaran yang diperlukan adalah :";
    cout<<endl;
    cout<<endl;
    int i=nama.length()-1;
    for (i;i>=0;i--){ 
        for(int a=0;a<=i;a++){ 
            cout<<nama[a]; 
        }
        cout<<endl;
    }
    return 0;
}
