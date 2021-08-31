/*==============================
  ===== PROGRAM LINKED LIST=====
  ======= DENGAN POINTER =======
  ==============================*/
  
#include <iostream>
#include <malloc.h> //mengembalikan pointer ke n byte ruang memori yang belum di inisialisasi
//define untuk deklarasi konstanta
#define true 1 //boolean true
#define false 0 //boolean false
using std::cout; //using namespace std;

//deklarasi membuat linked list
typedef int typeinfo; //typedef=tipedatanya
typedef struct typenode *typeptr; //typeptr = pointer

struct typenode{
	typeinfo info;
	typeptr next;
}; typeptr awal,akhir;

void buatlistbaru(); 
void sisipnode(typeinfo IB); //menyiapkan sebuah fungsi sisipnode(menyisipkan node) dengan parameter IB yang bertipe typeinfo pada linked list
void bacamaju();
void bacamundur();
int listkosong();


int main()
{
	 cout<<"  List mula-mula :\n";
	 
	 buatlistbaru();
	 
	 sisipnode(60);
	 sisipnode(20);
	 sisipnode(10);
	 sisipnode(100);
	 sisipnode(80);
	 sisipnode(30);
	 
	 bacamaju();
	
	 cout<<"\n\n  Cetak Linked List dari belakang :\n";
	 bacamundur();
	 
	 return 0;
}


void buatlistbaru() //untuk mendefinisikan kondisi awal linked list masih dalam keadaan kosong
{ 
	 typeptr list;
	 
	 list=NULL;
	 awal=list; //awal=null
	 akhir=list; //akhir=null
}

int listkosong() //untuk mengecek linked listnya kosong atau tidak
{ 
	if(awal==NULL)
		return(true);
	else
		return(false); 
}

void sisipnode(typeinfo IB)
{ 
	typeptr nodebaru, bantu;
	 
	nodebaru=(typenode *) malloc(sizeof(typenode)); //malloc(size_t size) untuk mendeklarasikan sebuah pointer kosong pada memory
	 
	nodebaru->info=IB;
	nodebaru->next=NULL; //next=awal=null
	 
	if (listkosong()) 
	{
	 	awal=nodebaru;
		akhir=nodebaru; 
	}
	
	else if (IB <= awal->info) //Sisip di depan
	{
		nodebaru->next=awal;
		awal=nodebaru; 
	}
	else
	{
		bantu=awal;
		while (bantu->next!=NULL && IB > bantu->next->info)
			bantu=bantu->next;
			nodebaru->next=bantu->next; //Sisip di tengah atau di belakang
			bantu->next=nodebaru;
		if (IB>akhir->info)
			akhir=nodebaru;
	}
}

void bacamaju() //mencetak dari depan
{
	typeptr bantu;
	
	bantu=awal;
	while (bantu!=NULL)
	{
		cout<<"  "<<bantu->info;
		cout<<" | ";
		bantu=bantu->next;
	}
}
	
void bacamundur() //mencetak dari belakang
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
		cout<<"  "<<bantu->info;
		cout<<" | ";
		bantu=bantu->next;
	}
}

