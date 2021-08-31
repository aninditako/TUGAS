#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int x, y, z, i, j, banyak[10], harga[10],kategori, total, total1=0, total2=0, bayar, bayar2, disk; 
string user, pass, user1, pass1, menu[20], no; 
char log, log2, ulang2, ulang, kode[5], nama[20];
//cin.ignore();

void login();
void menurestoran();
void makan();
void minum();
void membayar();
void diskon();
void tanpadiskon();

int main()
{
	login();
	do
	{	
		menurestoran();
		cout<<"\nIngin Memesan Lagi? (y/n) : "; cin>>z;
	}	
	while(z=='y' || z=='Y');
	
	membayar();
		
	cout<<endl;
	cout<<"|======================================|"<<endl;
	cout<<"|\tTerima Kasih Sudah Memesan\t|"<<endl;
	cout<<"|\t    Semoga Memuaskan    \t"<<endl;
	cout<<"|======================================|"<<endl;
}

void login()
{

	cout<<"||========================================||"<<endl;
	cout<<"||---------------DAFTAR AKUN--------------||"<<endl;
	cout<<"||========================================||"<<endl;
	cout << "Username\t: "; cin>>user;
	cout << "Password\t: "; cin>>pass;
	cout << "\nIngin Login ? (y/n) : "; cin>>log;
	cout <<endl << endl;
	if (log=='y' || log=='Y')
	{	
		do
		{
		cout<<"||-----------------LOGIN----------------||"<<endl;
		cout<<"Username\t: "; cin>>user1;
		cout<<"Password\t: "; cin>>pass1;
		if (user1==user && pass1==pass)
		{
			cout<<"\nSelamat, Login Anda Berhasil\n";
			//l='n';
		}
		else
		{
			cout<<"LOGIN GAGAL " <<endl;
			cout<<"Ingin Login Kembali? (y/n) : "; cin>>log2;
		}
		}
		while (log2=='Y' || log2=='y');
	
	}
	else
	{
		cout << "TERIMA KASIH" <<endl;
		exit(0);
	}
}

void menurestoran()
{
	//do
	//{	
		cout<<"|*********************************|"<<endl;
		cout<<"|\t\t\tRESTORANKU\t\t\t|"<<endl;
		cout<<"|*********************************|"<<endl;
		cout<<"Nomor Pesanan\t: ";cin>>no;
		cout<<"Nama Pemesanan\t: ";cin>>nama;

		do 
		{
			cout<<"||==================================================||"<<endl;
			cout<<"||    KATEGORI    |          MENU      |    HARGA   ||"<<endl;
			cout<<"||==================================================||"<<endl;
			cout<<"||    |           | AG | Ayam Goreng   | Rp 16.000  ||"<<endl;
			cout<<"|| 1  |  Makanan  | AB | Ayam Bakar    | Rp 18.000  ||"<<endl;
			cout<<"||    |           | LG | Lele Goreng   | Rp 13.000  ||"<<endl;
			cout<<"||----------------| LB | Lele Bakar    | Rp 14.000  ||"<<endl;
			cout<<"|| 2  |  Minuman  | EJ | Es Jeruk      | Rp 3.000   ||"<<endl;
			cout<<"||    |           | ET | Es Teh        | Rp 3.000   ||"<<endl;
			cout<<"||==================================================||"<<endl;
			
			cout<<"Masukan Kategori Menu :"; cin>>kategori;
			cout<<endl;
			
			switch(kategori)
			{
				case 1 :
				{
					cout<<"Masukan Banyak Makanan : "; cin>>x;
					
					for(i=1; i<=x; i++)
					{
						makan();
						total1=total1+harga[i];
					}
					cout<<"\nTotal harga makanan :"<<total1;
				}
				break;
				
				case 2 :
				{
					cout<<"Masukan Banyak Minuman : "; cin>>y;
					
					for(j=1; j<=y; j++)
					{
						minum();
						total2=total2+harga[j];
					}
					cout<<"\nTotal harga minuman :"<<total2;
				}
				break;
				
				default : cout<<"Input Yang Anda Masukkan Salah"<<endl;
			}
				cout<<"\nIngin Kembali Ke Menu Utama? (y/n) : "; cin>>ulang;
				cout<<endl;
		}	
		while(ulang=='y' || ulang=='Y');
}
void makan()
{
	cout<<"\nMasukkan Menu Makanan ke-"<<i<<"\t: ";
						getline(cin,menu[i]);
						cout<<"Masukkan banyak makanan\t\t: "; cin>>banyak[i];
						cin.ignore();
						
						if (menu[i]=="AG" ||menu[i]=="ag")
						{
							harga[i]=16000*banyak[i];
							cout<<"Harga ="<<harga[i];
						}
						else if (menu[i]=="AB" || menu[i]=="ab")
						{
							harga[i]=18000*banyak[i];
							cout<<"Harga ="<<harga[i];
						}
						else if (menu[i]=="LG" || menu[i]=="lg")
						{
							harga[i]=13000*banyak[i];
							cout<<"Harga ="<<harga[i];
						}
						else if (menu[i]=="LB" || menu[i]=="lb")
						{
							harga[i]=14000*banyak[i];
							cout<<"Harga ="<<harga[i];
						}
						else
						{
							cout<<"Maaf, Menu Tidak Tersedia";
						}
}
void minum()
{
	cout<<"\nMasukkan Menu Minuman ke-"<<j<<"\t: "; //cin>>menu[j];
						//cin.getline(menu[j],sizeof(menu[j]));
						getline(cin,menu[j]);
						cout<<"Masukkan banyak minuman\t\t: "; cin>>banyak[j];
						cin.ignore();
						if (menu[j]=="EJ" || menu[j]=="ej")
						{
							harga[j]=3000*banyak[j];
							cout<<"Harga ="<<harga[j];
						}
						else if (menu[j]=="ET" ||menu[j]=="et")
						{
							harga[j]=3000*banyak[j];
							cout<<"Harga ="<<harga[j];
						}
						else
						{
							cout<<"Maaf, Menu Tidak Tersedia";
						}
}
void membayar()
{
	
		total=total1+total2;
		cout<<"Total yang harus dibayarkan : "<<total;
		cout<<"\nPunya kode diskon? (y/n)"; cin>>ulang2;
		
		if(ulang2=='Y' || ulang2=='y')
		{
			diskon();
		}
		else
		{
			tanpadiskon();
		}
			
			
}
void diskon()
{
	cout<<"\nMasukan Kode Diskon :"; cin>>kode;
			if(kode=="enaknyo")
			{
				disk=0.1*total;
				cout<<"Diskon : "<<disk;
				cout<<"\nTotal yang harus dibayarkan : "<<total-disk;
				cout<<"\nMasukkan jumlah pembayaran\t: Rp "; cin>>bayar;
				
				if(bayar<total)
				{
					cout<<"Silahkan Tambahkan\t\t: Rp "<<total-bayar<<endl;
					cout<<"Pembayaran Tambahan\t\t: Rp "; cin>>bayar2;
				}
				if (bayar2>=total-bayar)
				{
					cout<<"Kembalian\t                : Rp "<<bayar2-(total-bayar)<<endl;
				}
				else if (bayar>=total)
				{
					cout<<"Kembalian\t                : Rp "<<bayar-total;
				}
			}
				
			else
			{
				cout<<"maaf kode yang anda masukan salah\n";
			}
}
void tanpadiskon()
{
	cout<<"\nMasukkan jumlah pembayaran\t: Rp "; cin>>bayar;
					
				if(bayar<total)
				{
					cout<<"Silahkan Tambahkan\t\t: Rp "<<total-bayar<<endl;
					cout<<"Pembayaran Tambahan\t\t: Rp "; cin>>bayar2;
				}
				if (bayar2>=total-bayar)
				{
					cout<<"Kembalian\t                : Rp "<<bayar2-(total-bayar)<<endl;
				}
				else if (bayar>=total)
				{
					cout<<"Kembalian\t                : Rp "<<bayar-total;
				}
}
