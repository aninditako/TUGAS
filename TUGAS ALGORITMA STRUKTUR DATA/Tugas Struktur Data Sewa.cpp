#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h> //system cls
using namespace std;


	char menu, pilih;
	string cari;
	int bdata,total;

struct dataPelanggan
{
  int no_urut, lama;
  string nama, kaset; 
}dp[100];


void menu1 ()
{
	system("cls");
	
	cout<<"Banyak Data : "; cin>>bdata;
	
	for(int i=0; i<bdata; i++)
	{
		cout<<"Nomor Urut Pelanggan\t: "; cin>>dp[i].no_urut;
		cout<<"Nama Pelanggan\t\t: "; cin.ignore(); getline(cin, dp[i].nama);
		cout<<"Kaset yang dipinjam\t: "; cin.ignore(); getline(cin, dp[i].kaset); //string
		cout<<"Lama Pinjam\t\t: "; cin>>dp[i].lama;
		cout<<endl;
	}
}

void menu2 ()
{	
	system("cls");
	
	string cari;
	int a;
	a=0;
	cout<<"Masukan Nama Kaset : "; cin.ignore(); getline(cin, cari);
	for(int i=0; i<bdata; i++)
	{
		if(cari==dp[i].kaset)
		{
			cout<<++a<<". "<<endl;
			cout<<"Nomor Urut\t: "<<dp[i].no_urut;
			cout<<"Nama Peminjam\t: "<<dp[i].nama;
			cout<<"Nama Kaset\t: "<<dp[i].kaset;
		}
		cout<<"aaaa";
	}
	if(a==0)
	{
		cout<<"\n----------Data tidak ditemukan----------\n\n";
	}
}

void menu3 ()
{
	cout<<"Masukan Nama Pelanggan : "; cin.ignore(); getline(cin, cari);
	for(int i=0; i<bdata; i++)
	{
		if(cari==dp[i].nama)
		{
			cout<<"Nomor Urut Pelanggan\t: "; cin>>dp[i].no_urut;
			cout<<"Nama Pelanggan\t\t: "; cin.ignore(); getline(cin, dp[i].nama);
			cout<<"Kaset yang dipinjam\t: "; cin.ignore(); getline(cin, dp[i].kaset); //string
			cout<<"Lama Pinjam\t\t: "; cin>>dp[i].lama;
			total=dp[i].lama*10000;
			cout<<"Total Bayar\t\t: Rp "<<total;
		}
	}	
}


main ()
{
	
	do
	{
		system("cls");
		
		cout<<"Data Sewa Kaset\n";
		cout<<"1. Input Nama Peminjam\n";
		cout<<"2. Cari Peminjam\n";
		cout<<"3. Pembayaran\n";
		cout<<"Pilih : "; cin>>pilih;
		
		switch (pilih)
			{
				case '1' :
					menu1();
				break;
				
				case '2' :
					menu2();
				break;
				
				case '3' :
					menu3();
				break;
			}
	cout<<endl<<"Kembali ke menu utama? (y/n) : "; cin>>menu;
	}
	while (menu=='y' || menu=='Y');
	return 0;
}





