/*======== PROGRAM LINKED LIST========
  =============== KUIS ===============
  ====================================*/
  
#include <iostream>
#include <malloc.h>
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;

struct data_Node
{
	char nama[20], status[20];
	typeinfo umur;
	char goldar[2];
};

struct typenode
{
	data_Node data;
	typeptr next; 
};

typeptr awal,akhir;
int pilih, pilih2, pilih3;
string hapus;
char kembali;
int banyak;
char nama[20], alamat[10], jarak[20];
typeinfo umur2;



int main()
{

	cout<<"Jasa Pengiriman Paket 3S"<<endl<<endl;
	cout<<"1. Admin"<<endl;
	cout<<"2. Kurir"<<endl;
	cout<<"Pilih : "; cin>>pilih;
	switch(pilih)
		{
			case 1 :
				cout<<"====== M E N U  A D M I N ======"<<endl;
				cout<<"1. Input Data Penerima Paket"<<endl;
				cout<<"2. Lihat Data"<<endl;
				cout<<"3. Keluar"<<endl;
				cout<<"Pilih : "; cin>>pilih2;
				switch(pilih2)
				{
					case 1 :
						cout<<"Masukkan Data Penerima"; cin>>banyak;
						for(int i=1; i<=banyak; i++)
						{
							cout<<"Penerima "<<i<<endl;
							cout<<"Nama Penerima : "; cin>>nama[i];
							cout<<"Alamat Penerima : "; cin>>alamat[i];
							cout<<"Jarak Dari Kantor : "; cin>>jarak[i];
						}
						
						break;
						
					case 2 :
						for(int i=1; i<=banyak; i++)
						{
							cout<<"Penerima "<<i<<endl;
							cout<<"Nama Penerima : "<<nama[i];
							cout<<"Alamat Penerima : "<<alamat[i];
							cout<<"Jarak Dari Kantor : "<<jarak[i];
						}
						break;	
				}
				break;	
			case 2 :
				cout<<"====== M E N U  A D M I N ======"<<endl;
				cout<<"1. Isi Bensin"<<endl;
				cout<<"2. Antarkan Paket"<<endl;
				cout<<"3. Lihat Paket"<<endl;
				cout<<"4. Keluar"<<endl;
				cout<<"Pilih : "; cin>>pilih3;
				switch(pilih3)
				{
					case 1 :
						cout<<"Masukkan Data Penerima"; cin>>banyak;
						for(int i=1; i<=banyak; i++)
						{
							cout<<"Penerima "<<i<<endl;
							cout<<"Nama Penerima : "; cin>>nama[i];
							cout<<"Alamat Penerima : "; cin>>alamat[i];
							cout<<"Jarak Dari Kantor : "; cin>>jarak[i];
						}
						
						break;
						
					case 2 :
						for(int i=1; i<=banyak; i++)
						{
							cout<<"Penerima "<<i<<endl;
							cout<<"Nama Penerima : "<<nama[i];
							cout<<"Alamat Penerima : "<<alamat[i];
							cout<<"Jarak Dari Kantor : "<<jarak[i];
						}
						break;	
				}
				break;
		}	
}
