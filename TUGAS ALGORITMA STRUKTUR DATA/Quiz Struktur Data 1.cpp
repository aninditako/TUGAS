/*======== PROGRAM LINKED LIST========
  =============== KUIS ===============
  Nama   : Anindita Khusnul Oktavia
  NIM    : 124190019
  Kelas  : Prak. Struktur Data C 
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
int pilih;
string hapus;
char kembali;
int banyak;
char nama2[20], goldar2[2];
typeinfo umur2;

void buatlistbaru();
void sisipnode(data_Node dt);
void bacamaju();
void hapusnode(typeinfo nimH);
void cetaklist();
void cetakterbalik();
int listkosong();

int main()
{

	cout<<"Unit Pelayanan Transfusi Darah"<<endl<<endl;
	cout<<"-------------------------------------------";
	buatlistbaru();
	typenode tmp;
	
	while (pilih !=5)
	{
		system("cls");
		cout<<"Daftar Menu : "<<endl;
		cout<<"1. Input Data Pendonor"<<endl;
		cout<<"2. Lihat Data Pendonor"<<endl;
		cout<<"3. Cek Kandidat Pendonor"<<endl;
		cout<<"4. Hapus Data Pendonor"<<endl;
		cout<<"5. Keluar"<<endl;
		cout<<"-------------------------------------------";
		cout<<"\nMasukkan Pilihan  :  "; cin>>pilih;
		
		switch(pilih)
		{
			case 1 :
			
				
				
				cout<<"Input Data Pendonor"<<endl;
				cout<<"Banyak Data Yang Diinput : "; cin>>banyak;
				for(int i=0; i<banyak; i++)
				{
					cout<<"\tData ke- "<<i+1<<endl;
					cout<<"\t    Nama Pendonor     : "; cin>>tmp.data.nama;
					cout<<"\t    Umur              : "; cin>>tmp.data.umur;
					cout<<"\t    Golongan Darah    : "; cin>>tmp.data.goldar;
					if(tmp.data.umur>=17 && tmp.data.umur<=60)
					{                
						cout<<"\t    Status            : "<<"Bisa Donor"<<endl;
					}
					else 
					{
						cout<<"\t    Status            : "<<"Tidak Bisa Donor"<<endl;
					}
					cout<<endl;
					sisipnode(tmp.data);
				}
				cin.ignore();
				cin.get();
				break;
				
			case 2 :
				cout<<"Lihat Data"<<endl;
				cout<<"Data berdasar urutan : "<<endl;
				bacamaju();
				break;	
				
			case 3 :
				cout<<"\t    Nama Penerima Donor : "; cin>>nama2;
				cout<<"\t    Umur                : "; cin>>umur2;
				cout<<"\t    Golongan Darah      : "; cin>>goldar2;
				cout<<"\tKandidat Pendonor"<<endl;
				//cekdata();
				break;	
				
			case 4 :
				int b;
				cout << "Data Pendonor :\n";
				bacamaju();
				cout<<"\nHapus Data Pendonor : "; cin>>b;
				hapusnode(b);
				break;
				
			default :
				break;
			}
		}
}

void buatlistbaru()
{
	typeptr list;
	 
	list=NULL;
	awal=list; // awal=null
	akhir=list; //akhir=null
}

int listkosong()
{
	if(awal==NULL)
		return(true);
	else
		return(false); 
}

void sisipnode(data_Node dt)
{
	typeptr NB,bantu;
	
		NB=(typenode *) malloc(sizeof(typenode));
		
		NB->data=dt;
		NB->next=NULL;
		
		if (listkosong())
	 	{
		 	awal=NB;
			akhir=NB; 
		}
	 	else if (dt.nama<= awal->data.nama)  // Sisip di depan
		{
			NB->next=awal;
			awal=NB; 
		}
		else
		{
			bantu=awal;
			while (bantu->next!=NULL && dt.nama > bantu->next->data.nama)
	 			bantu=bantu->next;
				NB->next=bantu->next; // Sisip di tengah atau di belakang
				bantu->next=NB;
				if (dt.nama>akhir->data.nama)
					akhir=NB;
		}
}

void bacamaju()
{
	typeptr bantu;
	bantu=awal;
	
	while (bantu!=NULL)
	{
		for(int i=1; i<=banyak; i++)
		{
			if(bantu->data.umur>=17 && bantu->data.umur<=60)
			{
				//int i=1;
				cout<<"\n\tPendonor ke- "<<i<<endl;
				cout<<"\n\t    Nama Pendonor     : "<<bantu->data.nama;
				cout<<"\n\t    Umur              : "<<bantu->data.umur;
				cout<<"\n\t    Golongan Darah    : "<<bantu->data.goldar;
				bantu=bantu->next;
				i++;
			}
		}
		
	}

}

void cekdata()
{
	/*typeptr bantu;
	bantu=awal;
	
	while (bantu!=NULL)
	{
		if(bantu->goldar2=O || bantu->goldar2=o)
		{
			if(bantu->data.umur>=17 && bantu->data.umur<=60)
			{
				int i=1;
				cout<<"\tPendonor ke- "<<i<<endl;
				cout<<"\n\t    Nama Pendonor     : "<<bantu->data.nama;
				cout<<"\n\t    Umur              : "<<bantu->data.umur;
				cout<<"\n\t    Golongan Darah    : "<<bantu->data.goldar;
				bantu=bantu->next;
				i++;
			}
		}
		
		if(bantu->goldar2=A || bantu->goldar2=a)
		{
			if(bantu->data.umur>=17 && bantu->data.umur<=60 && (bantu->data.goldar=A || bantu->data.goldar=AB))
			{
				int i=1;
				cout<<"\tPendonor ke- "<<i<<endl;
				cout<<"\n\t    Nama Pendonor     : "<<bantu->data.nama;
				cout<<"\n\t    Umur              : "<<bantu->data.umur;
				cout<<"\n\t    Golongan Darah    : "<<bantu->data.goldar;
				bantu=bantu->next;
				i++;
			}
		}
		
		if(bantu->goldar2=B || bantu->goldar2=b)
		{
			if(bantu->data.umur>=17 && bantu->data.umur<=60 && (bantu->data.goldar=B || bantu->data.goldar=AB))
			{
				int i=1;
				cout<<"\tPendonor ke- "<<i<<endl;
				cout<<"\n\t    Nama Pendonor     : "<<bantu->data.nama;
				cout<<"\n\t    Umur              : "<<bantu->data.umur;
				cout<<"\n\t    Golongan Darah    : "<<bantu->data.goldar;
				bantu=bantu->next;
				i++;
			}
		}
		
		if(bantu->goldar2=AB || bantu->goldar2=ab)
		{
			if(bantu->data.umur>=17 && bantu->data.umur<=60 && (bantu->data.goldar=AB || bantu->data.goldar=ab))
			{
				int i=1;
				cout<<"\tPendonor ke- "<<i<<endl;
				cout<<"\n\t    Nama Pendonor     : "<<bantu->data.nama;
				cout<<"\n\t    Umur              : "<<bantu->data.umur;
				cout<<"\n\t    Golongan Darah    : "<<bantu->data.goldar;
				bantu=bantu->next;
				i++;
			}
		}
		
	}*/
	
}
void hapusnode(typeinfo nimH)
{
	/*typeptr hapus, bantu;
	if (listkosong())
		cout << "List masih kosong";
	else if (awal->data.nama==nimH){ 
		hapus=awal; // Hapus di awal
		awal=hapus->next;
		free(hapus); 
		cout <<"Data berhasil terhapus";
	}
	else{ 
		bantu=awal;
		while (bantu->next->next!=NULL && nimH!=bantu->next->data.nama){
			bantu=bantu->next;}
		if (nimH==bantu->next->data.nama){
				hapus=bantu->next;
			if (hapus==akhir){ // Hapus di akhir
				akhir=bantu;
				akhir->next=NULL; 
				cout <<"Data berhasil terhapus";
			}
			else{
				bantu->next=hapus->next; // Hapus di tengah
				free(hapus);
				cout <<"Data berhasil terhapus";
			}
		}
		else if(nimH!=bantu->next->data.ama)
		cout << "Data tidak ditemukan!\n";
	}*/
}

