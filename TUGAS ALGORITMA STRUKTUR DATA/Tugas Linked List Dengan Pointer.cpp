/*======== PROGRAM LINKED LIST========
  ========== DENGAN POINTER ==========
  ============== Nomor 8 =============
  ====================================*/
  
#include <iostream>
#include <malloc.h>

using namespace std;

//deklarasi struct untuk membuat linked list
	typedef int typeinfo; //typedef=tipedatanya
	typedef struct typenode *typeptr; //typeptr = pointer
	struct typenode{
		typeinfo info;
		typeptr next;
	}; typeptr awal,akhir;

//deklarasi/pemanggilan void
	void buatlistbaru(); //Mendefinisikan kondisi awal linked list, masih dalam keadaan kosong
	void sisipnode(typeinfo IB); //menyiapkan sebuah fungsi sisipnode(menyisipkan node) dengan parameter IB yang bertipe typeinfo pada linked list
	void hapusnode(typeinfo IH); //menyiapkan sebuah fungsi hapus node dengan parameter IH yang bertipe typeinfo pada linked list
	void bacamaju(); //mencetak dari depan
	void bacamundur(); //mencetak dari belakang
	void bacadari(int ID);
	int listkosong();

//deklarasi global
	int pilih, pilih2, banyak, nilaisisip, nilaihapus, infodari;
	char ulang;

int main()
{
	do{
		//system("cls");
		
		cout<<"\n\nMenu\n";
		cout<<" 1. Sisip Node\n";
		cout<<" 2. Baca Node\n";
		cout<<" 3. Hapus Node\n";
		cout<<" 4. Keluar\n"; //program stop
		cout<<"Pilih : "; cin>>pilih;
		
		switch(pilih)
		{
			case 1 :
				cout<<endl;
				cout<<"\t------------SISIP NODE------------"<<endl;
				cout<<"\n\tJumlah Info yang akan disisipkan : "; cin>>banyak; //Menentukan berapa banyak angka yang akan disisipkan kedalam (berapa) Node
				for(int i=0; i<banyak; i++)
				{
					cout<<"\t  Info ke-"<<i+1<<" : "; cin>>nilaisisip;
					sisipnode(nilaisisip); //menyisipan angka menuju void sisipnode dengan perulangan sebanyak angka yang akan disisipkan
				}
				break;
			
			case 2 :
				cout<<endl;
				cout<<"\t------------BACA NODE------------"<<endl;
				cout<<"\tMenu Baca\n";
				cout<<"\t 1. Baca Maju\n";
				cout<<"\t 2. Baca Mundur\n";
				cout<<"\t 3. Baca dari\n";
				cout<<"\tPilih : "; cin>>pilih2;
				switch(pilih2)
				{
					case 1 :
						cout<<endl;
						cout<<"\t======= BACA MAJU ======="<<endl;
						cout<<"\tHasil dari baca maju : "<<endl;
						cout<<"\t"; bacamaju();
						cout<<endl;
						break;
						
					case 2 :
						cout<<endl;
						cout<<"\t======= BACA MUNDUR ======="<<endl;
						cout<<"\tHasil dari baca mundur : "<<endl;
						cout<<"\t"; bacamundur();
						cout<<endl;
						break;
					
					case 3 :
						cout<<endl;
						cout<<"\t======= BACA DARI ======="<<endl;
						cout<<"\tBaca mulai dari info ke: "; cin>>infodari;
						cout<<endl;
						cout<<"\tHasil dari baca dari info ke-"<<infodari<<" : "<<endl;
						cout<<"\t"; bacadari(infodari);
						cout<<endl;
						break;	
				}
				break;	
				
			case 3 : 
				cout<<endl;
				cout<<"\t------------HAPUS NODE------------"<<endl;
				cout<<"\n\tInfo yang dapat dihapus :\n";
				cout<<"\t"; bacamaju();
				cout<<"\n\tPilih info yang akan dihapus : "; cin>>nilaihapus; //input angka pada node yang akan dihapus
				hapusnode(nilaihapus); //penghapusan angka yang telah diinputkan pada perintah sebelumnya
				cout<<"\n\tInfo setelah proses penghapusan : ";
				cout<<"\t"; bacamaju();
				break;

			default:
				break;
		}cout<<"\n   Ingin kembali ke menu (y/n) ? "; cin>>ulang;
	}while(ulang=='Y' || ulang=='y');
}


void buatlistbaru(){ 
	 typeptr list;
	 
	 list=NULL;
	 awal=list; // awal=null
	 akhir=list; //akhir=null
}

int listkosong(){ 
	if(awal==NULL)
		return(true);
	else
		return(false); 
}

void sisipnode(typeinfo IB){ 
	typeptr NB, bantu;
	 
	NB=(typenode *) malloc(sizeof(typenode)); 
	 
	NB->info=IB;
	NB->next=NULL; 
	 
	if (listkosong()) 
	{
	 	awal=NB;
		akhir=NB; 
	}
	
	else if (IB <= awal->info) //Sisip di depan
	{
		NB->next=awal;
		awal=NB; 
	}
	else
	{
		bantu=awal;
		while (bantu->next!=NULL && IB > bantu->next->info)
			bantu=bantu->next;
			NB->next=bantu->next; //Sisip di tengah atau di belakang
			bantu->next=NB;
		if (IB>akhir->info)
			akhir=NB;
	}
}

void hapusnode(typeinfo IH){
	typeptr hapus, bantu;
	
	if (listkosong())
		cout << "List masih kosong";
	else if (awal->info==IH)
	{
		hapus=awal; //Hapus di awal
		awal=hapus->next;
		free(hapus); 
	}
	else
	{ 
		bantu=awal;
		while (bantu->next->next!=NULL && IH!=bantu->next->info)
			bantu=bantu->next;
			if (IH==bantu->next->info)
			{	 
				hapus=bantu->next;
				if (hapus==akhir) //Hapus di akhir
	 			{ 
					akhir=bantu;
					akhir->next=NULL; 
				}
				else
					bantu->next=hapus->next; //Hapus di tengah
					free(hapus);
			}
			else
				cout << "Node tidak ditemukan!\n"; 
	}
} 



void bacamaju() //mencetak dari depan
{
	typeptr bantu;
	
	bantu=awal;
	while (bantu!=NULL)
	{
		cout<<" "<<bantu->info;
		cout<<" ";
		bantu=bantu->next;
	}
}
	
void bacamundur()
{
	typeptr depan,bantu;
	
	depan=awal;
	awal=akhir;
	do
	{
		bantu=depan;
		
		while (bantu->next!=akhir)
			bantu=bantu->next;
			akhir->next=bantu;
			akhir=bantu;
	}
	while (akhir!=depan);
		akhir->next=NULL;
		bantu=awal;
	while (bantu!=NULL)
	{
		cout<<" "<<bantu->info;
		cout<<" ";
		bantu=bantu->next;
	}

	depan=awal;
	awal=akhir;
	do {
		bantu=depan;
		while (bantu->next!=akhir)
		bantu=bantu->next;
		akhir->next=bantu;
		akhir=bantu;
	}while (akhir!=depan);
	
	akhir->next=NULL;
	bantu=awal;
}

void bacadari(int ID) //mencetak dari angka yang dipilih
{
	typeptr bantu;
	
	bantu=awal;
	while (bantu->info!=ID) //cek apakah sama dengan nilai yang dipilih
	{
		bantu=bantu->next;
	}
	while (bantu!=NULL) //mencetak dari nilai yang dipilih
	{
		cout<<" "<<bantu->info;
		cout<<" ";	
		bantu=bantu->next;
	}
	bantu=awal;
	while (bantu!=NULL && bantu->info!=ID) //mencetak dari awal
	{
		cout<<" "<<bantu->info;
		cout<<" ";	
		bantu=bantu->next;
	}
}
