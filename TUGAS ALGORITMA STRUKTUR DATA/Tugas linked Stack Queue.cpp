#include <iostream>
#include <malloc.h>
#include <string.h>
#define true 1
#define false 0
using namespace std;

FILE *pf1 ,*pf2 ,*pf3, *logpf1;

typedef struct node *typeptr;

typedef struct data_pegawai{
	char nama[30];
	char jabatan[30];
	char nomorinduk[4];
}data_pegawai;
data_pegawai pegawai;

typedef struct log_pegawai{
	char nama[30];
	char jabatan[30];
	char nomorinduk[4];
}log_pegawai;
log_pegawai logpegawai;

struct node{
	data_pegawai info; 
	typeptr next;
};

struct log{
	log_pegawai info; 
	typeptr next;
};

int i;
typeptr awal,akhir;
void tambahPegawai();
void hapusPegawai(char* IH);
void cariPegawai(char* IC);
void tampilPegawai();
void sisipnode (data_pegawai IB);
int listkosong();
void bacamaju();
void bacamundur();
char namahapus[30];
char namacari[30];


struct parkir
{
	char mobil[20];
	char plat[10];
};
parkir park;
struct stack{
parkir info;
stack * next, * prev;
};
void buatStack();
void push(parkir IB);
void pop();
void cetakStack();
void popSembarang(char platcari[10]);

stack * awalStack;
stack * akhirStack;


struct antrian{
	char nama[20];
};
antrian antri;

struct queue{
antrian info;
queue * next, * prev;
};

queue * awalQueue;
queue * akhirQueue;

void enqueue(antrian IB);
void dequeue();
void cetakQueue();
void buatQueue();


int main(){
	char carimobil[10];
	int menu,menupegawai,menuparkir,menuantrian;
	cout<<"======= MENU UTAMA =======\n";
	cout<<"1. Data Pegawai\n";
	cout<<"2. Data Parkir\n";
	cout<<"3. Data Antrian Order\n";
	cout<<"4. Keluar\n";
	cout<<"Pilih Menu ";
	cin>>menu;
	switch(menu){
		case 1 :
	do{
	cout<<"======= MENU PEGAWAI =======\n";
	cout<<"1. Tambah data Pegawai\n";
	cout<<"2. Hapus data Pegawai\n";
	cout<<"3. Cari nama Pegawai\n";
	cout<<"4. Tampil data Pegawai\n";
	cout<<"5. Kembali ke Menu Utama\n";
	cout<<"6. Keluar\n";
	cout<<"Pilih menu ";
	cin>>menupegawai;
	
	if(menupegawai==1){
	tambahPegawai();
	}
	else if(menupegawai==2){
		cin.ignore();
	cout<<"HAPUS DATA"<<endl;
	cout<<"Nama Pegawai yang dihapus : ";cin.getline(namahapus,30);
	hapusPegawai(namahapus);	
	}
	else if(menupegawai==3){
		system ("cls");
		cin.ignore();
		cout<<"CARI DATA"<<endl;
		cout<<"Nama Pegawai yang dicari : ";cin.getline(namacari,30);
		cariPegawai(namacari);
	}
	else if(menupegawai==4){
	tampilPegawai();	
	}
	else if(menupegawai==5){
	main();	
	}
	}while(menupegawai!=6);
	break;
	case 2 :
	buatStack();
	parkir park;	
	do{
	cout<<"**MENU PARKIRAN**"<<endl;
	cout<<"1. Mobil Masuk"<<endl;
	cout<<"2. Mobil Keluar"<<endl;
	cout<<"3. Tampil Data"<<endl;
	cout<<"4. Keluar Sembarang"<<endl;
	cout<<"5. Kembali Ke Menu Utama\n";
	cout<<"6. Keluar"<<endl;
	cout<<"Pilih : ";cin>>menuparkir;
	
	system ("cls");
	if(menuparkir==1)
	{
			cin.ignore();
			cout<<"Mobil : ";
			cin.getline(park.mobil,20);
			cout<<"Plat : ";
			cin.getline(park.plat,10);
			push(park);
	}
	else if(menuparkir==2){
	pop();	
	}
	else if(menuparkir==3){
		cetakStack();
		}
	else if (menuparkir==4){
		cin.ignore();
        cout<<"Plat Mobil yang keluar : ";
        cin.getline(carimobil,sizeof(carimobil));
        popSembarang(carimobil);	
	}
	else if (menuparkir==5){
		main();	
	}
	}while(menuparkir!=6);
	break;
	case 3 :
	buatQueue();
	antrian antri;	
	do{
	cout<<"**MENU ANTRIAN**\n";
	cout<<"1. Customer Antri\n";
	cout<<"2. Customer Dilayani\n";
	cout<<"3. Tampil Data Antrian\n";
	cout<<"4. Kembali Ke Menu Utama\n";
	cout<<"5. Exit"<<endl;
	cout<<"Pilih : ";cin>>menuantrian;
	system("cls");
	if(menuantrian==1)
	{
			cin.ignore();
			cout<<"Nama Customer : ";
			cin.getline(antri.nama,20);
			enqueue(antri);
	}
	else if(menuantrian==2){
	dequeue();	
	}
	else if(menuantrian==3){
		cetakQueue();
		}
	else if(menuantrian==4){
		main();
		}
    }while(menuantrian!=5);
	}
}


void tambahPegawai(){
	int jml;
	system ("cls");
	cout<<"Jumlah Data : ";cin>>jml;
	pf1 = fopen( "linked.txt" , "ab+" );
		for(i=0;i<jml;i++)
		{
			cin.ignore();
			cout<<"Data ke- "<<i+1<<endl;
			cout<<"\tNama Pegawai : ";
			cin.getline(pegawai.nama,30);
			cout<<"\tJabatan Pegawai : ";
			cin.getline(pegawai.jabatan,30);
			cout<<"\tNomor Pegawai : ";
			cin>>pegawai.nomorinduk;
			sisipnode(pegawai);
			fflush(stdin);
			fwrite(&pegawai, sizeof (pegawai), 1, pf1);
		}
		fclose (pf1);
		cout<<"Data sudah diinput";
		cout<<endl;
}

void sisipnode (data_pegawai IB){
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
void logPegawai(){
	int jml;
	system ("cls");
	logpf1 = fopen( "loglinked.txt" , "ab+" );
		for(i=0;i<jml;i++)
		{
			cin.ignore();
			cout<<"Data ke- "<<i+1<<endl;
			cout<<"\tNama Pegawai : ";
			cin.getline(pegawai.nama,30);
			cout<<"\tJabatan Pegawai : ";
			cin.getline(pegawai.jabatan,30);
			cout<<"\tNomor Pegawai : ";
			cin>>pegawai.nomorinduk;
			sisipnode(pegawai);
			fflush(stdin);
			fwrite(&pegawai, sizeof (pegawai), 1, pf1);
		}
		fclose (pf1);
		cout<<"Data sudah diinput";
		cout<<endl;
}

void sisiplog(data_pegawai IB){
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
int listkosong(){
	if (awal==NULL)
		return (true);
	else
		return (false);
}

void hapusPegawai(char* IH){
	typeptr hapus,bantu;
	if(listkosong()){
		cout<<"List Masih Kosong"<<endl;
	}
	else if(strcmp(awal->info.nama,IH)==0){
		hapus=awal;
		awal=hapus->next;
		
		free(hapus);
		cout<<"Data dihapus"<<endl;
	}
	else{
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
			
		}
		else{
		cout<<"Data tidak ditemukan"<<endl;
		}
	}
}

void cariPegawai(char* IC){
	typeptr bantu;
	bantu=awal;
	system ("cls");
	while(bantu->next!=akhir->next && strcmp(bantu->info.nama,IC))
		bantu=bantu->next;
		if (strstr(bantu->info.nama,namacari)){
			cout<<"Data Ditemukan"<<endl;
			cout<<"\tNama Pegawai : "<<bantu->info.nama<<endl;
			cout<<"\tJabatan Pegawai : "<<bantu->info.jabatan<<endl;
			cout<<"\tNomor Pegawai : "<<bantu->info.nomorinduk<<endl;
		}
	else{
		cout<<"Data Tidak Ditemukan"<<endl;
	}
}

void tampilPegawai(){
		int pilih;
		system ("cls");
		cout<<"TAMPIL DATA"<<endl;
		cout<<"1. Ascending"<<endl;
		cout<<"2. Descending"<<endl;
		cout<<"Pilih: ";
		cin>>pilih;
		if(pilih==1)
		{
			bacamaju();
		}
		if(pilih==2)
		{
			bacamundur();
			bacamaju();
			bacamundur();
		}
}

void bacamaju(){
	typeptr bantu;
	int i=0;
	bantu=awal;
	system ("cls");
	while (bantu!=NULL){
	cout<<"Data ke- "<<i+1<<endl;
	cout<<"\tnama Pegawai : "<<bantu->info.nama<<endl;
	cout<<"\tJabatan Pegawai : "<<bantu->info.jabatan<<endl;
	cout<<"\tNomor Induk : "<<bantu->info.nomorinduk<<endl;
	bantu=bantu->next;
	i++;
	}
}

void bacamundur(){
	typeptr depan, bantu;
	depan=awal;
	awal=akhir;
	do{
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

void buatStack(){
	stack * newStack;
	newStack=NULL;
	awalStack = newStack;
	akhirStack=newStack;
}

bool stackKosong(){
	if(awalStack==NULL) return true;
	else return false;
}

void push(parkir IB){
	stack * NS;
    NS = (stack*)malloc(sizeof(stack));
    NS -> info = IB;
    NS-> next = NULL;
    NS -> prev = NULL;
    if(stackKosong()){
    awalStack = NS;
    akhirStack = NS;
    }
    else{
        akhirStack-> next = NS;
        NS-> prev = akhirStack;
        akhirStack = NS;
    }
}

void cetakStack(){
stack * bantu;
    bantu = akhirStack;
    while(bantu!=NULL){
        cout<<"Mobil : "<<bantu->info.mobil<<endl;
        cout<<"Plat : "<<bantu->info.plat<<endl;
        bantu= bantu->prev;
    }
}

void pop(){
	stack * bantu, * hapus;
	
	if(stackKosong()){
	cout<<"stack kosong\n";
	}
	else{
	hapus=akhirStack;
	bantu=awalStack;
	
	while(bantu->next!=akhirStack){
	bantu=bantu->next;	
	}
	
	akhirStack=bantu;
	free(hapus);
	akhirStack->next=NULL;
	}	
}

void popSembarang(char platcari[10]){
	stack * hapus,* bantu,* bantu2;
    bantu = awalStack;
    if(strcmp(platcari,awalStack->info.plat)==0){
        awalStack = bantu->next;
        cout<<endl<<"Mobil keluar Sembarang : "<<endl;
        cout<<"Mobil :"<<bantu->info.mobil<<endl;
        cout<<"Plat : "<<bantu->info.plat<<endl;
        free(bantu);
        awalStack->prev=NULL;
        }
    else if(strcmp(platcari,akhirStack->info.plat)==0){
        while(bantu -> next != akhirStack){
            bantu = bantu->next;
        }
        hapus = bantu->next;
        cout<<endl<<"Mobil Yang keluar :"<<endl; 
        cout<<"Mobil :"<<hapus->info.mobil<<endl;
        cout<<"Plat : "<<hapus->info.plat<<endl;
        akhirStack =  bantu;
        free(hapus);
        bantu->next = NULL;
    }
    else{
        while(bantu -> next != akhirStack && strcmp(platcari,bantu->info.plat)!=0){
            bantu = bantu->next;
        }
        if(strcmp(platcari,bantu->info.plat)==0){
            hapus = bantu;
            cout<<endl<<"Mobil Yang keluar : "<<endl;
            cout<<"Mobil :"<<hapus->info.mobil<<endl;
            cout<<"Plat : "<<hapus->info.mobil<<endl;
            bantu = hapus->prev;
            bantu2 = hapus->next;
            bantu->next = bantu2;
            bantu2 -> prev = bantu;
            free(hapus);
        }
        else{
            cout<<"\nData Tidak Ditemukan\n";
        }
    }

}

void buatQueue(){
	queue * newQueue;
	newQueue = NULL;
	awalQueue = newQueue;
	akhirQueue=newQueue;
}

bool queueKosong(){
	if(awalQueue==NULL) 
	return(1);
	else 
	return (0);
}

void enqueue(antrian IB){
	queue * NQ;
    NQ = (queue *)malloc(sizeof(queue));
    NQ -> info = IB;
    NQ-> next = NULL;
    NQ -> prev = NULL;
    if(queueKosong()){
    awalQueue = NQ;
    akhirQueue = NQ;
    }
    else{
        akhirQueue-> next = NQ;
        NQ-> prev = akhirQueue;
        akhirQueue = NQ;
    }
}

void cetakQueue(){
queue * bantu;
    bantu = awalQueue;
    while(bantu!=NULL){
        cout<<"Nama : "<<bantu->info.nama<<endl;
        bantu= bantu->next;
    }
}

void dequeue(){
	queue * bantu, * hapus;
	
	if(queueKosong()){
	cout<<"queue kosong\n";
	}
	else{
	hapus=awalQueue;
	bantu=akhirQueue;
	
	while(bantu->prev!=awalQueue){
	bantu=bantu->prev;	
	}
	
	awalQueue=bantu;
	free(hapus);
	awalQueue->prev=NULL;
	}	
}

