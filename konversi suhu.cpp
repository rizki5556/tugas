#include<iostream>
#include<conio.h>
using namespace std;

main()
{
   float c,f,r,k;
   int input;

   cout<<"Program Konversi Suhu\n";
   cout<<"============================\n";
   cout<<"[1] Celcius\n";
   cout<<"[2] Fahrenheit\n";
   cout<<"[3] Reamur\n";
   cout<<"[4] Kelvin\n";
   cout<<"Masukan Pilihan : ";
   cin>>input;
   cout<<"============================\n";

   if (input==1)
   {
      cout<<"[1] Celcius ke Fahrenheit\n";
      cout<<"[2] Celcius ke Reamur\n";
      cout<<"[3] Celcius ke Kelvin\n";
      cout<<"Masukan Pilihan : ";
      cin>>input;
      cout<<"============================\n";
      
      if (input==1)
      {
    	cout<<"Konversi Dari Celcius ke Fahrenheit\n";
        cout<<"============================\n";
        cout<<"Masukkan Suhu dalam satuan Celcius = ";cin>>c;
        f=(c*9/5)+32;
        cout<<"\nSuhu Dalam Fahrenheit = ";cout<<f;
      }
      else
      {
      	if (input==2)
      	{
      		cout<<"Konversi Dari Celcius ke Reamur\n";
        	cout<<"============================\n";
        	cout<<"Masukkan Suhu dalam satuan Celcius = ";cin>>c;
        	r=c*4/5;
        	cout<<"\nSuhu Dalam Reamur = ";cout<<r;
		}
		else
        {
      		if (input==3)
      		{
      			cout<<"Konversi Dari Celcius ke Kelvin\n";
        		cout<<"============================\n";
        		cout<<"Masukkan Suhu dalam satuan Celcius = ";cin>>c;
        		k=c+273.16;
        		cout<<"\nSuhu Dalam Kelvin = ";cout<<k;
			}
			else
      		{
          		cout<<"inputan salah";
      		}			
	    }
	  }
   }
   else
   {
    	if(input==2)
    	{
      	cout<<"[1] Fahrenheit ke Celcius\n";
      	cout<<"[2] Fahrenheit ke Reamur\n";
      	cout<<"[3] Fahrenheit ke Kelvin\n";
      	cout<<"Masukan Pilihan : ";
      	cin>>input;
      	cout<<"============================\n";
      
      		if (input==1)
      		{
    			cout<<"Konversi Dari Fahrenheit ke Celcius\n";
        		cout<<"============================\n";
        		cout<<"Masukkan Suhu dalam satuan Fahrenheit = ";cin>>f;
        		c=(f-32)*5/9;
        		cout<<"\nSuhu Dalam Celcius = ";cout<<c;
    		}
      		else
    		{
      			if (input==2)
      			{
      				cout<<"Konversi Dari Fahrenheit ke Reamur\n";
        			cout<<"============================\n";
        			cout<<"Masukkan Suhu dalam satuan Fahrenheit = ";cin>>f;
        			r=(f-32)*4/9;
        			cout<<"\nSuhu Dalam Reamur = ";cout<<r;
				}
				else
        		{
      				if (input==3)
      				{
      					cout<<"Konversi Dari Fahrenheit ke Kelvin\n";
        				cout<<"============================\n";
        				cout<<"Masukkan Suhu dalam satuan Fahrenheit = ";cin>>f;
        				k=(f-32)*5/9+273.16;
        				cout<<"\nSuhu Dalam Kelvin = ";cout<<k;
					}
					else
      				{
          				cout<<"inputan salah";
      				}			
	    		}
			}
   		}
   		else
   		{
   			if(input==3)
    		{
      			cout<<"[1] Reamur ke Celcius\n";
      			cout<<"[2] Reamur ke Fahrenheit\n";
      			cout<<"[3] Reamur ke Kelvin\n";
      			cout<<"Masukan Pilihan : ";
      			cin>>input;
      			cout<<"============================\n";
      
      			if (input==1)
      			{
    				cout<<"Konversi Dari Reamur ke Celcius\n";
        			cout<<"============================\n";
        			cout<<"Masukkan Suhu dalam satuan Reamur = ";cin>>r;
        			c=r*5/4;
        			cout<<"\nSuhu Dalam Celcius = ";cout<<c;
    			}
      			else
    			{
      				if (input==2)
      				{
      					cout<<"Konversi Dari Reamur ke Fahrenheit\n";
        				cout<<"============================\n";
        				cout<<"Masukkan Suhu dalam satuan Reamur = ";cin>>r;
        				f=(r*9/4) + 32;
        				cout<<"\nSuhu Dalam Fahrenheit = ";cout<<f;
					}
					else
        			{
      					if (input==3)
      					{
      						cout<<"Konversi Dari Reamur ke Kelvin\n";
        					cout<<"============================\n";
        					cout<<"Masukkan Suhu dalam satuan Reamur = ";cin>>r;
        					k=(r*5/4)+273.16;
        					cout<<"\nSuhu Dalam Kelvin = ";cout<<k;
						}
						else
      					{
          				cout<<"inputan salah";
      					}			
	    			}
				}
			}
			else
			{
				if(input==4)
    			{
      				cout<<"[1] Kelvin ke Celcius\n";
      				cout<<"[2] Kelvin ke Fahrenheit\n";
      				cout<<"[3] Kelvin ke Reamur\n";
      				cout<<"Masukan Pilihan : ";
      				cin>>input;
      				cout<<"============================\n";
      
      				if (input==1)
      				{
    					cout<<"Konversi Dari Kelvin ke Celcius\n";
        				cout<<"============================\n";
        				cout<<"Masukkan Suhu dalam satuan Kelvin = ";cin>>k;
        				c=k-273.16;
        				cout<<"\nSuhu Dalam Celcius = ";cout<<c;
    				}
      				else
    				{
      					if (input==2)
      					{
      						cout<<"Konversi Dari Kelvin ke Fahrenheit\n";
        					cout<<"============================\n";
        					cout<<"Masukkan Suhu dalam satuan Kelvin = ";cin>>k;
        					f=(k-273.16)*9/5+32;
        					cout<<"\nSuhu Dalam Fahrenheit = ";cout<<f;
						}
						else
        				{
      						if (input==3)
      						{
      							cout<<"Konversi Dari Kelvin ke Reamur\n";
        						cout<<"============================\n";
        						cout<<"Masukkan Suhu dalam satuan Kelvin = ";cin>>k;
        						r=(k-273.16)*4/5;
        						cout<<"\nSuhu Dalam Kelvin = ";cout<<r;
							}
							else
      						{
          					cout<<"inputan salah";
      						}			
	    				}
					}
				}	
			}
		}
   }
   getch();
}
