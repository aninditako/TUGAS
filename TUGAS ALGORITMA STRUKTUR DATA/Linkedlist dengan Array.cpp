/*Program List Dengan Array*/
#include <iostream>

using namespace std;

typedef struct{
	int info; int next;
	}typenode;
typenode elemen[12];

int list, listakhir, kosong, kosongakhir, pilih, sisip, hapus;
char kembali;

int listkosong();
void menu();
void menu1();
void menu2();
void menu3();
void menu4();
void buatlist();
void sisipnode(int IB);
void hapusnode(int IH);
void cetaklist();

int main(){
	menu();
}

void menu(){
	system("cls");
	cout << "Menu :\n";
	cout << "1. Buat List Dinamis\n";
	cout << "2. Cetak list\n";
	cout << "3. Sisip Node\n";
	cout << "4. Hapus Node\n";
	cout << "5. Keluar\n";
	cout << "Pilih : "; cin >> pilih;
	switch(pilih){
		case 1 :
			menu1();
			break;
		case 2 :
			menu2();
			break;
		case 3 :
			menu3();
			break;
		case 4 :
			menu4();
			break;
		case 5 :
			cout << "\n\nTerima Kasih";
			break;
		default :{
			cout << "\n\nSalah Memilih Menu\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
			if(kembali=='Y'||kembali=='y'){
				menu();
			}
		}
	}
}

void menu1(){
	cout << "\nList\t\t: "; cin >> list;
	cout << "List Terakhir\t: "; cin >> listakhir;
	cout << "Kosong\t\t: "; cin >> kosong;
	cout << "Kosong Terakhir\t: "; cin >> kosongakhir;
	buatlist();
}

void menu2(){
	cout << "\n";
	cetaklist();
	cout << "\n\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

void menu3(){
	cout << "\nInfo Yang Akan Disisipkan : "; cin >> sisip;
	sisipnode(sisip);
	cout << "\nHasil Setelah Disisipkan : \n";
	cetaklist();
	cout << "\n\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

void menu4(){
	cout << "Yang akan dihapus? "; cin >> hapus;
	hapusnode(hapus);
	cout << "\n\n";
	cetaklist();
	cout << "\n\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

void buatlist(){
	cout <<"\nMasukkan Info dan Next :\n";
	for(int i=1; i<=listakhir; i++){
		cout << "Elemen\t[" << i << "]\t: "; cin >> elemen[i].info;
		cout << "Next\t[" << i << "]\t: "; cin >> elemen[i].next;
	}
	cout << "\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

int listkosong(){
	if (list==0)
		return(true);
	else
		return(false);
}

void cetaklist(){
	int n,m;
	n=list;
	m=kosong;
	cout << "isi list : \n";
	do{
		cout << elemen[n].info << " ";
		n=elemen[n].next;
	}while (elemen[n].next!=0);
	cout << " "<< elemen[listakhir].info <<endl ;
	cout << "\nIndex tempat-tempat kosong: \n";
	do{
		cout << m << " ";
		m=elemen[m].next;
	}while(elemen[m].next!=0);
	cout << " " << kosongakhir;
}

void sisipnode(int IB){
	int listbaru,k,m,n,x;
	//-------------------------- sisip di awal
	if(IB<elemen[list].info){
		listbaru=kosong;
		kosong=elemen[kosong].next;
		elemen[listbaru].info=IB;
		elemen[listbaru].next=list;
		list=listbaru;
	}
	else{
	//-------------------------sisip di akhir
		if(IB>elemen[listakhir].info){
			listbaru=kosong;
			kosong=elemen[kosong].next;
			elemen[listbaru].info=IB;
			elemen[listbaru].next=0;
			elemen[listakhir].next=listbaru;
			listakhir=listbaru;
		}
		else{//--------------------------sisip di tengahn=list;
			x=elemen[n].info;
			while(IB>x){
				m=n;
				n=elemen[n].next;
				x=elemen[n].info;
			}
			k=elemen[kosong].next;
			elemen[m].next=kosong;
			elemen[kosong].info=IB;
			elemen[kosong].next=n;
			kosong=k;
		}
	}
}

void hapusnode(int IH)
{
    int listbaru, k;
    			
	
	
	
	//------------------------------------------ hapus di awal
    if (IH == elemen[list].info)
    {
        listbaru=elemen[list].next;
        k = kosong;
        kosong = list;
        list = listbaru ;
        elemen [kosong].next = k;

    }
    else
		//------------------------- hapus di akhir
		if(IH == elemen[listakhir].info){
			k = list;
				do{
					k = elemen[k].next; 
				}
				while(elemen[k].next != listakhir);
			  	elemen[listakhir].next = kosong;
			  	kosong = listakhir;
			 	listakhir = k;
			  	elemen[k].next = 0;		  
		}
	
    //--------------------------- hapus di tengah
	    else{
			int a,b;
			int nn = list; 
	        int  xx = elemen[nn].info;
	        int mm;
	        while (IH>xx)
	        {
	            mm=nn;
	            nn = elemen[nn].next;
	            xx = elemen[nn].info;
	        }
	        
	        a = elemen[nn].next; // 8; n=3
	        b = elemen[mm].next; // 3; m=1
	        elemen[mm].next = a;
	        elemen[b].next = kosong;
	        elemen[b].info = 0;
	        kosong = b;
	        
	         cout << endl;
 
	}
}
