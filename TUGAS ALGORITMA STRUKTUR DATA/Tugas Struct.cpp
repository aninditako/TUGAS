#include <iostream>
using namespace std;

int main() 
{
	char menu;
	int pilih, bdata, total;
	string cari; 

	struct dataPelanggan
	{
	  int lama;
	  string no_urut, nama, kaset; 
	}dp[100];
	
	do
	{
		system("cls");
		
		cout<<"============================================\n";
		cout<<"\t\tData Sewa Kaset\n";
		cout<<"============================================\n\n";
		cout<<"\t1. Input Nama Peminjam\n";
		cout<<"\t2. Cari Peminjam\n";
		cout<<"\t3. Pembayaran\n\n";
		cout<<"Pilih : "; cin>>pilih;
		cout<<endl<<endl;
		cin.ignore();
		
		switch(pilih) 
		{
			case 1:
				int bdata;
				cout<<"   Banyak Data : "; cin>>bdata;
	
				for(int i=0; i<bdata; i++)
				{
					cout<<"\n\tNomor Urut Pelanggan\t: "; cin>>dp[i].no_urut;
					cout<<"\tNama Pelanggan\t\t: "; cin.ignore(); getline(cin, dp[i].nama);
					cout<<"\tKaset yang dipinjam\t: "; cin.ignore(); getline(cin, dp[i].kaset);
					cout<<"\tLama Pinjam\t\t: "; cin>>dp[i].lama;
				}
				break;
				
			case 2:
				cout<<"   Masukan Nama Kaset : "; cin.ignore(); getline(cin, cari);
				for(int i=0; i<bdata; i++)
				{
					if(cari==dp[i].kaset)
					{
						cout<<"\tNomor Urut\t: "<<dp[i].no_urut<<endl;
						cout<<"\tNama Peminjam\t: "<<dp[i].nama<<endl;
						cout<<"\tNama Kaset\t: "<<dp[i].kaset<<endl;
					}
				}

				break;
				
			case 3:
				cout<<"   Masukan Nama Pelanggan : "; getline(cin, cari);
				for(int i=0; i<bdata; i++)
				{
					if(cari==dp[i].nama)
					{
						cout<<"\tNomor Urut Pelanggan\t: "<<dp[i].no_urut<<endl;
						cout<<"\tNama Pelanggan\t\t: "<<dp[i].nama<<endl;
						cout<<"\tKaset yang dipinjam\t: "<<dp[i].kaset<<endl; 
						cout<<"\tLama Pinjam\t\t: "<<dp[i].lama<<endl;
						total=dp[i].lama*10000;
						cout<<"\tTotal Bayar\t\t: Rp "<<total<<endl;
					}
				}	
				break;
				
		}
		cout<<endl<<"Kembali ke menu utama? (y/n) : "; cin>>menu;
	}
	while (menu=='y' || menu=='Y');
	return 0;
}
