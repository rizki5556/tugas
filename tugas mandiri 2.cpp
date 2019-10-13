#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int array[100], i, n;
  float rerata, total=0 ,sd;
  cout << "===========================================================" << endl;
  cout << "Program Menghitung Nilai Rata-rata dan Daviasi dengan Array" << endl;
  cout << "===========================================================" << endl;
  cout << "Masukkan banyaknya elemen array: ";
  cin >> n;
  for(i=0; i<n; i++){
    cout << "Nilai Ke-" << i+1 << " : ";
    cin >> array[i];
    total = total + array[i];
  }
  rerata = total/n;
  sd = sqrt(rerata/n-1);
  cout << "Hasil nilai total adalah : " << total << endl;
  cout << "Hasil rata-rata adalah : " << rerata << endl;
  cout << "Standar daviasi : " << sd << endl;
  return 0;

}
