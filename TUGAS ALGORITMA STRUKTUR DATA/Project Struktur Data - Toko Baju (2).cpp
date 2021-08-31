#include <iostream>
#include <malloc.h>
#include <string.h>
#define true 1
#define false 0
using namespace std;

//FILE
FILE *pf1 ,*pf2 ,*pf3, *logpf1;

//Deklarasi Struct
typedef struct node *typeptr;

//===========================================Deklarasi Pegawai
char namahapus[30];
char namacari[30];
int i;
typeptr awal,akhir;

typedef struct data_pegawai{
	char nama[30];
	char jabatan[30];
	char nomorinduk[4];
}data_pegawai;
data_pegawai pegawai;

void menu1();
void tambahPegawai();
void hapusPegawai(char* IH);
void cariPegawai(char* IC);
void tampilPegawai();
void sisipnode (data_pegawai IB);
int listkosong();
void bacamaju();
void bacamundur();

//===========================================Deklarasi Barang
//char caripakaian[10];
//int carijum;

struct barang
{
	char pakaian[20],kodep[10],caripakaian[10];
	int carijum;
	int jum, tot;
};
barang toko;

struct stack{
	barang info;
	stack * next, * prev;
};

stack * awalStack;
stack * akhirStack;

void menu2();
void menuStack();
void buatStack();
void inputStack();
void push(barang IB);
void cetakStack();
void popPilih(char kodepcari[10], int jumcari);

//===========================================Deklarasi Antrian
int jum,jml, banyak, banyakP, x=0, tot;

typedef int typeinfo;  

struct dataPakaian
{
	char kodeO[10], cus[20];
	int jumlah;

};

void menu3();
void buatqueue();
int queuekosong();
void enqueue(dataPakaian dp);
void inputPakaian(); 
void cetakqueue();
void inputAntrian();
void cetakAntrian();
void dequeue();
void layani();

struct node{
	data_pegawai info;
	dataPakaian data;
	typeptr next;
};

node pengiriman;
typeptr depan, belakang;

int pilih;
int menu,menupegawai,menubarang,menuantrian;

//======================================================================== M A I N ==============================================================================

int main()
{
	
	cout<<endl;
	cout<<"|----------------------------------------------------|\n";
	cout<<"|          M E N U   U T A M A   U N I G L O         |\n";
	cout<<"|----------------------------------------------------|\n";
	cout<<"|  1. Data Pegawai Uniglo                            |\n";
	cout<<"|  2. Data Barang                                    |\n";
	cout<<"|  3. Data Antrian Order                             |\n";
	cout<<"|  0. Exit                                           |\n";
	cout<<"|----------------------------------------------------|\n";
	cout<<"Pilih Menu : "; cin>>menu;
	
	switch(menu)
	{
		case 1 :
			
				menu1();
		break;
		
		case 2 :
			menu2();
		break;
		
		case 3 :
			menu3();
		break;
				
		case 4:
			exit(0);		
		break;
				
		default:
			cout<<"Pilihan yang anda masukan SALAH";		
	}
}


//===================================================================== P E G A W A I ===========================================================================
//Jika Data Pegawai Masih Kosong maka ketika dicari program akan selesai

// MENU PEGAWAI
void menu1()
{
			do
			{
				cout<<endl;	
				cout<<"   +==============================================+   \n";
				cout<<"   |                  MENU PEGAWAI                |   \n";
				cout<<"   |==============================================|   \n";
				cout<<"   |   1. Tambah Data Pegawai                     |   \n";
				cout<<"   |   2. Hapus Data Pegawai                      |   \n";
				cout<<"   |   3. Cari Nama Pegawai                       |   \n";
				cout<<"   |   4. Tampil Data Pegawai                     |   \n";
				cout<<"   |   5. Kembali ke Menu Utama                   |   \n";
				cout<<"   |   0. Exit                                    |   \n"; 
				cout<<"   |==============================================+   \n";
				cout<<"      Pilih menu : "; cin>>menupegawai; 	
                switch(menupegawai)
				{
					case 1:
						 tambahPegawai();
					break;
					
					case 2:
						cin.ignore();
						cout<<"       +-------------------------------------+"<<endl;
						cout<<"       |           HAPUS DATA PEGAWAI        |\n";
						cout<<"       +-------------------------------------+"<<endl;
						bacamaju(); //agar sebelum dihapus muncul data pegawai terlebih dahulu
						cout<<"\n          Nama Pegawai yang ingin dihapus : ";
						cin.getline(namahapus,30);
						hapusPegawai(namahapus);
					break;
					
					case 3:
						//system ("cls");
						cin.ignore();
						cout<<"       +-------------------------------------+"<<endl;
						cout<<"       |            CARI DATA PEGAWAI        |\n";
						cout<<"       +-------------------------------------+"<<endl;
						cout<<"          Nama Pegawai yang dicari : "; cin.getline(namacari,30);
						cariPegawai(namacari);
					break;
					
					case 4:
						tampilPegawai();				
					break;
					case 5:
						main();
					break;
					
					case 0:
						exit(0);
					break;
					
					default:
						cout<<"       *** Pilihan yang anda masukan SALAH ***";
					break;	
				}                                                                                         				
			}while(menupegawai!=0);
}

//menu1 tambahPegawai
void tambahPegawai()
{
	int jml;
	
//	system ("cls");
	cout<<"       +-------------------------------------+"<<endl;
	cout<<"       |           INPUT DATA PEGAWAI        |"<<endl;
	cout<<"       +-------------------------------------+"<<endl;
	cout<<"        Jumlah Pegawai yang akan diinput : "; cin>>jml;

	pf1 = fopen( "linked.txt" , "ab+" );
	
		for(i=0;i<jml;i++)
		{
			cin.ignore();
			cout<<"     Data Pegawai ke "<<i+1<<endl;
			cout<<"\tNama Pegawai      : "; cin.getline(pegawai.nama,30);
			cout<<"\tJabatan Pegawai   : "; cin.getline(pegawai.jabatan,30);
			cout<<"\tNomor Pegawai     : "; cin>>pegawai.nomorinduk;
			sisipnode(pegawai);
			
			fflush(stdin);
			fwrite(&pegawai, sizeof (pegawai), 1, pf1);
		}
	fclose (pf1);
	cout<<"\n\t\t*** Data sudah diinput ***\n";
}

void sisipnode (data_pegawai IB)
{
	typeptr NB,bantu;
	NB = (node *)malloc(sizeof(node));
	NB->info = IB;
	NB->next=NULL;
	
	if(listkosong()){
		awal=NB;
		akhir=NB;
	}
	else if (strcmp(IB.nomorinduk,awal->info.nomorinduk)<0){
		NB->next=awal;
		awal=NB;
	}
	else {
		bantu=awal;
		while (bantu->next!=NULL && strcmp(IB.nomorinduk,bantu->next->info.nomorinduk)>0){
			bantu=bantu->next;
	}
			
		NB->next=bantu->next;
		bantu->next=NB;
		if (strcmp(IB.nomorinduk,akhir->info.nomorinduk)>0){
			akhir=NB;
		}
	}
}

int listkosong()
{
	if (awal==NULL)
		return (true);
	else
		return (false);
}

//menu2 hapuspegawai
void hapusPegawai(char* IH)
{
	typeptr hapus,bantu;
	if(listkosong())
	{
		cout<<"\n\t\t*** List masih kosong ***\n"<<endl;
	}
	else if(strcmp(awal->info.nama,IH)==0)
	{
		hapus=awal;
		awal=hapus->next;
		
		free(hapus);
		cout<<"\n\t\t*** Data sudah terhapus ***\n"<<endl;
	}
	else
	{
		bantu=awal;
		while(bantu->next->next!=NULL && strcmp(IH, bantu->next->info.nama))
			bantu=bantu->next;
		if (strcmp(IH,bantu->next->info.nama)==0){
			hapus=bantu->next;
			if(hapus==akhir){
				akhir=bantu;
				akhir->next=NULL;
			}
			else
				bantu->next=hapus->next;
			free(hapus);
			cout<<"\n\t\t*** Data sudah terhapus ***\n"<<endl;
			
		}
		else{
		cout<<"\n\t\t*** Data tidak ditemukan ***\n"<<endl;
		}
	}
}

//menu3 cariPegawai
void cariPegawai(char* IC)
{
	typeptr bantu;
	bantu=awal;
//	system ("cls");
		while(bantu->next!=akhir->next && strcmp(bantu->info.nama,IC))
		bantu=bantu->next;
		if (strstr(bantu->info.nama,namacari))
		{
			cout<<"\n\t\t*** Data Ditemukan ***\n"<<endl;
			cout<<"\t Nama Pegawai      : "<<bantu->info.nama<<endl;
			cout<<"\t Jabatan Pegawai   : "<<bantu->info.jabatan<<endl;
			cout<<"\t Nomor Pegawai     : "<<bantu->info.nomorinduk<<endl;
		}
		else
		{
			cout<<"\n\t\t*** Data Tidak Ditemukan ***\n"<<endl;
		}
}

//menu4 tampilPegawai
void tampilPegawai()
{
	int pilih;
	//system ("cls");
		cout<<"       +-------------------------------------+"<<endl;
		cout<<"       |          TAMPIL DATA PEGAWAI        |"<<endl;
		cout<<"       +-------------------------------------+"<<endl;
		cout<<"       |  1. Ascending                       |"<<endl;
		cout<<"       |  2. Descending                      |"<<endl;
		cout<<"       +-------------------------------------+"<<endl;
		cout<<"         Pilih  : "; cin>>pilih; 
		if(pilih==1)
		{
			cout<<"\n\n-------- Tampil Data Pegawai Secara Ascending --------\n"<<endl;
			bacamaju();
		}
		if(pilih==2)
		{
			cout<<"\n\n------- Tampil Data Pegawai Secara Descending  -------\n"<<endl;
			bacamundur();
			bacamaju();
			bacamundur();
		}
}

void bacamaju()
{
	typeptr bantu;
	int i=0;
	bantu=awal;
//	system ("cls");
	while (bantu!=NULL)
	{
		cout<<"     Pegawai ke "<<i+1<<endl;
		cout<<"\t Nama Pegawai       : "<<bantu->info.nama<<endl;
		cout<<"\t Jabatan Pegawai    : "<<bantu->info.jabatan<<endl;
		cout<<"\t Nomor Pegawai      : "<<bantu->info.nomorinduk<<endl;
		bantu=bantu->next;
		i++;
	}
}

void bacamundur()
{
	typeptr depan, bantu;
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
	while(akhir!=depan);
	akhir->next=NULL;
	bantu=awal;
}

//====================================================================== B A R A N G =======================================================================
//hapus barang masih per jenis pakaian, harusnya bebas jenis apa dan banyaknya berapa DIKIT LAGI
//ketika kembali ke menu utama, data detail barang tidak bisa ditampilkan

void menu2()
{
	buatStack();
	barang toko;	
			do
			{
				cout<<endl;	
				cout<<"   +==============================================+   \n";
				cout<<"   |                   MENU BARANG                |   \n";
				cout<<"   |==============================================|   \n";
				cout<<"   |   1. Barang Masuk                            |   \n";
				cout<<"   |   2. Tampil Data Barang                      |   \n"; //ketika kembali ke menu utama, hanya tampil banyak stock saja
				cout<<"   |   3. Pilih Barang keluar                     |   \n";
				cout<<"   |   4. Kembali ke Menu Utama                   |   \n";
				cout<<"   |   0. Exit                                    |   \n";
				cout<<"   |==============================================+   \n";
				cout<<"      Pilih menu : "; cin>>menubarang;
				//system ("cls"); //belum
				switch(menubarang)
				{
					case 1:
						cin.ignore();
	//					menuStack();
						cout<<"       +-------------------------------------+"<<endl;
						cout<<"       |       INPUT DATA BARANG MASUK       |"<<endl;
						cout<<"       +-------------------------------------+"<<endl;
						inputStack();
					break;
					
					case 2:
						cout<<"       +-------------------------------------+"<<endl;
						cout<<"       |              STOCK BARANG           |\n";
						cout<<"       +-------------------------------------+"<<endl;
						cetakStack();
					break;
					
					case 3:
						//system ("cls");
						cin.ignore();
						cout<<"       +-------------------------------------+"<<endl;
						cout<<"       |    Barang Yang Ingin Dikeluarkan    |\n";
						cout<<"       +-------------------------------------+"<<endl;
						cin.ignore();
						cout<<"\t Kode Pakaian    : ";
				        cin.getline(toko.caripakaian,sizeof(toko.caripakaian));
				        cout<<"\t Banyak Pakaian  : "; cin>>toko.carijum;
				       // cin.getline(carijum,sizeof(carijum));
				        popPilih(toko.caripakaian, toko.carijum);
					break;
					
					case 4:
						main();
					break;
					
					case 0:
						exit(0);
					break;
					
					default:
						cout<<"       *** Pilihan yang anda masukan SALAH ***";
					break;	
				}                                                                                         				
			}while(menubarang!=0);	
}               

void buatStack()
{
	stack * newStack;
	newStack=NULL;
	awalStack = newStack;
	akhirStack=newStack;
}

bool stackKosong()
{
	if(awalStack==NULL) return true;
	else return false;
}

void push(barang IB)
{
	stack * NS;
    NS = (stack*)malloc(sizeof(stack));
    NS -> info = IB;
    NS-> next = NULL;
    NS -> prev = NULL;
    if(stackKosong())
	{
	    awalStack = NS;
	    akhirStack = NS;
    }
    else
	{
        akhirStack-> next = NS;
        NS-> prev = akhirStack;
        akhirStack = NS;
    }
}

//menu1 inputBarang
void inputStack() {
	int byk;

	cout<<"         Banyak Jenis Pakaian : "; cin>>byk;
	pf2 = fopen( "barang.txt" , "ab+" );

		for(int j=0; j<byk; j++)
		{
			cout<<endl;
			cout<<"     Pakaian ke-"<<j+1<<endl;
			cout<<"\t Kode Pakaian    : "; cin>>toko.kodep;
			cout<<"\t Jenis Pakaian   : ";  cin>>toko.pakaian;
			cout<<"\t Banyak Pakaian  : ";  cin>>toko.jum;
			push(toko);	
			tot=tot+toko.jum; 
			fflush(stdin);
			fwrite(&toko, sizeof (toko), 2, pf2);
			cin.ignore();	
		}
		fclose (pf2);
		cout<<endl;
		cout<<"\n\t\t*** Data Barang sudah diinput ***\n";
}

//menu2 tampilBarang
void cetakStack()
{
	stack * bantu;
    bantu = akhirStack;
    while(bantu!=NULL)
	{
        cout<<"\t Kode Pakaian    : "<<bantu->info.kodep<<endl;
		cout<<"\t Jenis Pakaian   : "<<bantu->info.pakaian<<endl;
        cout<<"\t Banyak Pakaian  : "<<bantu->info.jum<<endl; 
        bantu= bantu->prev;
        cout<<endl; 
        
    }
  
	cout<<"     Total Stock Pakaian : "<<tot;
}

//menu3 pilih barang keluar
void popPilih(char kodepcari[10], int jumcari)
{
	stack * hapus,* bantu,* bantu2;
    bantu = awalStack;
    hapus=akhirStack;

    if(strcmp(kodepcari,awalStack->info.kodep)==0){
        awalStack = bantu->next; //diawal
        cout<<"\n    Pakaian Yang Dikeluarkan : "<<endl;
        cout<<"\t Kode Pakaian    : "<<bantu->info.caripakaian<<endl;
		cout<<"\t Jenis Pakaian   : "<<bantu->info.pakaian<<endl;
        cout<<"\t Banyak Pakaian  : "<<bantu->info.jum<<endl;
        tot=tot-bantu->info.carijum;
		free(bantu);
        awalStack->prev=NULL;
        
        //tot=tot-bantu->info.carijum;
        }
        
	else if(strcmp(kodepcari,akhirStack->info.kodep)==0){
    	while(bantu -> next != akhirStack){
            bantu = bantu->next;
        }
        bantu = bantu -> next;
		hapus = bantu;
        cout<<"\n    Pakaian Yang Dikeluarkan :  "<<endl;
        cout<<"\t Kode Pakaian   : "<<bantu->info.caripakaian<<endl;
		cout<<"\t Jenis Pakaian  : "<<bantu->info.pakaian<<endl;
        cout<<"\t Banyak Pakaian : "<<bantu->info.carijum<<endl;
        jum=jum-bantu->info.carijum;
  		tot=tot-bantu->info.carijum;
		akhirStack = bantu;
        free(hapus);
        akhirStack->next = NULL;
        jum=jum-bantu->info.carijum;
  		tot=tot-bantu->info.carijum;
    }
    
    else{
        while(bantu -> next != akhirStack && strcmp(kodepcari,bantu->info.kodep)!=0){
            bantu = bantu->next;
        }
        if(strcmp(kodepcari,bantu->info.kodep)==0){
            hapus = bantu;
            cout<<"\n    Pakaian Yang Dikeluarkan :  "<<endl;
            cout<<"\t Kode Pakaian   : "<<bantu->info.caripakaian<<endl;
			cout<<"\t Jenis Pakaian  : "<<bantu->info.pakaian<<endl;
        	cout<<"\t Banyak Pakaian : "<<bantu->info.carijum<<endl;
        	tot=tot-bantu->info.carijum;
            bantu = hapus->prev;
            bantu2 = hapus->next;
            bantu->next = bantu2;
            bantu2 -> prev = bantu;
            free(hapus);
          //tot=tot-bantu->info.carijum;
        }
        else{
            cout<<"\n\t\t*** Data Tidak Ditemukan ***\n";
        }
    }
}

///===================================================================== C U S T O M E R =========================================================================
//tiap customer harusnya bisa beli lebih dari 1 pakaian
//melayani customer 1 per satu sesuai kapasitas atau masuk ke queue semua dahulu??
//
void menu3()
{
			do
			{
				cout<<endl;	
				cout<<"   +==============================================+   \n";
				cout<<"   |                  MENU ANTRIAN                |   \n";
				cout<<"   |==============================================|   \n";
				cout<<"   |   1. Input Data Customer                     |   \n";
				cout<<"   |   2. Tampil Data Customer                    |   \n"; 
				cout<<"   |   3. Layani Customer                         |   \n";
				cout<<"   |   4. Kembali ke Menu Utama                   |   \n";
				cout<<"   |   0. Exit                                    |   \n";
				cout<<"   |==============================================+   \n";
				cout<<"      Pilih menu : "; cin>>menuantrian;
				//system ("cls"); 
				switch(menuantrian)
				{
					case 1:
						inputAntrian();
					break;
					
					case 2:
						cetakAntrian();
					break;
					
					case 3:
						layani();
					break;
					
					case 4:
						main();
					break;
					
					case 0:
						exit(0);
					break;
					
					default:
						cout<<"       *** Pilihan yang anda masukan SALAH ***";
					break;	
				}                                                                                         				
			}while(menuantrian!=0);	
}

//membuat queue
void buatqueue() 
{ 	depan=(node *) malloc(sizeof(node));
 	depan=NULL;
	belakang=depan;
}

//mengecek apakah queue kosong atau tidak
int queuekosong() 
{ 	if(depan==NULL)
		return(true);
	else
		return(false);
}

//memasukkan data ke queue
void enqueue(dataPakaian dp)
{ 	
	typeptr NB;
	NB=(node *) malloc(sizeof(node));
	NB->data=dp;
	if (depan==NULL)
		depan=NB;
	else
		belakang->next=NB;
	belakang=NB;
	belakang->next=NULL;
	
}

//menu1 input data antrian
void inputAntrian()
{
	cout<<"       +-------------------------------------+"<<endl;
	cout<<"       |          INPUT DATA CUSTOMER        |"<<endl;
	cout<<"       +-------------------------------------+"<<endl;
	cout<<"         Banyak Antrian : "; cin>>banyak;

		for(int j=0; j<banyak; j++)
		{
			cout<<endl;
			cout<<"\tAntrian ke-"<<j+1<<endl;
			cout<<"\t   Nama Customer  : "; cin>>pengiriman.data.cus; 
			cout<<"\t   Kode Pakaian   : "; cin>>pengiriman.data.kodeO; 
			cout<<"\t   Jumlah Order   : "; cin>>pengiriman.data.jumlah;
			cin.ignore();
									
			if(pengiriman.data.jumlah>x)
			{
				enqueue(pengiriman.data);
				x=pengiriman.data.jumlah;
				jum++;
			}
		}
		cout<<endl;
		cout<<"\n\t\t*** Data Antrian sudah diinput ***\n";
		menu3();
}

//menampilkan data pada queue
void cetakAntrian()
{
	int j=0;
	typeptr bantu;
	bantu=depan;
 	
	
	if (queuekosong())
 	{
 		cout<<"\n\t\t*** Data Masih Kosong! ***\n";
 	}
 	else
 	{	
 		cout<<"       +-------------------------------------+"<<endl;
		cout<<"       |         TAMPIL DATA CUSTOMER        |"<<endl;
		cout<<"       +-------------------------------------+"<<endl;
		do 
		{ 			
			cout<<"         Customer ke-"<<j+1<<endl;
			cout<<"\t   Nama Customer      : "<<bantu->data.cus<<endl;
			cout<<"\t   Kode Pakaian       : "<<bantu->data.kodeO<<endl;
			cout<<"\t   Jumlah Order       : "<<bantu->data.jumlah<<endl;
			bantu=bantu->next;	
			j++;					
		}
		while(bantu!=NULL);
	}
	cout<<endl;
	menu3();
}

//menghapus data ke-1 pada queue
void dequeue()
{
	typeptr hapus;
	if (queuekosong())
 	{
 		cout<<"\n\t\t*** Queue Masih Kosong! ***\n";
 	}
 	else
 	{	
		hapus=depan;
		depan=hapus->next;
		free(hapus); 
	}
}
//melayani customer sesuai antrian
void layani()
{
	typeptr bantu;
	bantu=depan;
	
	
		cout<<"       +-------------------------------------+"<<endl;
		cout<<"       |        Data Customer Dilayani       |"<<endl;
		cout<<"       +-------------------------------------+"<<endl;
		
		cout<<"\t   Nama Customer      : "<<bantu->data.cus<<endl;
		cout<<"\t   Kode Pakaian       : "<<bantu->data.kodeO<<endl;
		cout<<"\t   Jumlah Order       : "<<bantu->data.jumlah<<endl;
		--jum;
		tot=tot-bantu->data.jumlah;
		cout<<endl;
		
		cout<<"\t Tersisa "<<jum<<" customer yang belum dilayani";
		cout<<endl;
		dequeue();
		
		menu3();				
}

