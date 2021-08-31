#include <iostream>
#define max 5
#define maxS 3
#define True 1
#define False 0
using namespace std;

//struct tamu
struct tamu{
	string nama; 
	int jml;
	string souvenir;
};

struct typequeue{//deklarasi struct queue
	int belakang; 
	tamu t[max]; 
};
struct typequeue queue;

struct typestack{
	int top=2;
	string souvenir[maxS]={"Hijau","Kuning","Merah"};
};
struct typestack stack;
void buatstack();
void cetakstack();
void push(string warna);
void pop();
int stackkosong();
int stackpenuh();
void menu5();
void makequeue();
int queuenull();
int queuefull();
void enqueue(string nama, int jml, string souvenir);
void masuk();
void daftartamu();
void antrian();
void tamukeluar();
void souvenir();

int sisa=max, jmlsouvenir=3, pilih;
bool menu=true;
string warna[6]={"Hijau","Kuning","Merah","Hijau","Kuning","Merah"};
int indekswarna=0;
//=============================================================================================================================================================

int main()
{
	do
	{
		//system("cls");
		cout<<"|----------------------------------------------------|\n";
		cout<<"|         Sisa orang yang boleh masuk    =  "<<sisa<<"        |\n";
		cout<<"|         Tumpukan Souvenir              =  "<<jmlsouvenir<<"        |\n";
		cout<<"|----------------------------------------------------|\n";
		
		cout<<"|----------------------------------------------------|\n";
		cout<<"|                       M E N U                      |\n";
		cout<<"|----------------------------------------------------|\n";
		cout<<"|  1. Masuk                                          |\n";
		cout<<"|  2. Tamu yang masuk                                |\n";
		cout<<"|  3. Antrian                                        |\n";
		cout<<"|  4. Tamu Keluar                                    |\n";
		cout<<"|  5. Souvenir                                       |\n";
		cout<<"|  0. Exit                                           |\n";
		cout<<"|----------------------------------------------------|\n";
		cout<<"Pilih Menu : "; cin>>pilih;
		
		switch(pilih) 
		{
			case 1:
				//tambahTamu();
				masuk();
				break;
			case 2: //OUTPUT TAMU YANG MASUK Nama, banyak, souvenir
				//rapaham
				daftartamu();
				break;
			case 3: //OUTPUT ANTRI tamu yang belum bisa masuk
				//	cetakQueue();
				break;
			case 4: //TAMU KELUAR QUEUE dan tamu di antrian MASUK
					//dequeue();
				tamukeluar();	
				break;
			case 5:
				menu5();
				break;
			case 0:
				menu=false;
				exit(0);
				break;
			default:
				cout<<"Pilihan yang Anda masukkan salah"<<endl;
				break;
		}
		cout<<endl;		
	}while(menu==true);
	return 0;
}


//====================================================================TAMU============================================================================

//buat queue 
void makequeue(){
	queue.belakang=0; 
}

//cek queue kosong atau tidak 
int queuenull(){
	if(queue.belakang==0)
		return(True);
	else
		return(False);
}

//cek queue penuh atau tidak 
int queuefull(){
	if(queue.belakang==max)
		return(True);
	else
		return(False); 
}

void enqueue(string nama, int jml, string souvenir){
	if(queuefull())
		cout << "Sudah penuh, mohon mengantri dahulu\n";
	else{
		queue.belakang++;
		queue.t[queue.belakang].nama=nama; 
		queue.t[queue.belakang].jml=jml;
		queue.t[queue.belakang].souvenir=souvenir;  
		if(jml==2){
			queue.t[max-1];
		}
	}
}
//tambahTamu
void masuk(){
	string tempnama, tempsouvenir;
	int tempjml;
	cout<<"Nama yang diundang : ";cin>>tempnama;
	cout<<"Jumlah orang yang datang : ";cin>>tempjml;
	if(tempjml<0 || tempjml>2) {
		cout<<"Maaf tidak boleh lebih dari 2 orang"<<endl;
		cout<<"Jumlah orang yang datang : ";cin>>tempjml;
	}
	if(max>0) {
		sisa=sisa-tempjml;	
		jmlsouvenir--;	
		tempsouvenir=stack.souvenir[stack.top];
		pop();
		enqueue(tempnama, tempjml, tempsouvenir);
	}
	else{
		cout<<"Sudah penuh, mohon mengantri dahulu"<<endl;
	}
}

void daftartamu(){//menampilkan queue tamu
	int i=1;
	while(i<=queue.belakang){ 
		cout<<"Nama Undangan : "<<queue.t[i].nama<<endl;
		cout<<"Jumlah Anggota: "<<queue.t[i].jml<<endl;
		cout<<"Warna Souvenir: "<<queue.t[i].souvenir<<endl;
		cout<<endl;
		i++; 
	}
}

void antrian(){ //cetakqueueAntri
	if (queuenull()){
		cout << "Antrian masih kosong!";
	}else if(max==5){
		cout << "Di dalam masih kosong!";
	}else{
		//typeptrantri bantuAntri;
		//bantuAntri=depanAntri; int i=1;
//		do{
//			cout << " Antrian Ke-" << i << endl;
//			cout << "    Nama Undangan\t: " << bantuAntri->NamaAntri << endl;
//			cout << "    Jumlah\t\t: " << bantuAntri->JumlahAntri <<endl;
//			cout << "    Warna Souvenir\t: "<< bantuAntri->warnaAntri<<"\n\n";
//			bantuAntri=bantuAntri->nextAntri; i++;
//		}while(bantuAntri!=NULL);
	}

}

void tamukeluar(){//untuk enqueue
	tamu ID;
	if(queuenull()){
		cout << "queue underflow"<<endl;
	}	 
	else{
		ID=queue.t[1];
		sisa = sisa+queue.t[1].jml;
		for (int i=1; i<queue.belakang; i++){
			queue.t[i]=queue.t[i+1];
		}		 
		queue.belakang--;
	}
}


//=================================================================SOUVENIR=======================================================================================
void menu5()
{
	cout<<endl;
	cout<<"   +----------------------------------------------------|\n";
	cout<<"   |                       SOUVENIR                     |\n";
	cout<<"   +----------------------------------------------------|\n";
	cout<<"\t 1. Push\n";
	cout<<"\t 2. Kembali ke menu \n";
	cout<<"\tPilih : ";cin>>pilih;
	if(pilih==1){
		push(warna[indekswarna]);
		indekswarna++;
	}
	else{
		main();
	}
}

//Membuat dan mendefinisikan kondisi awal stack
void buatstack(){ 
	stack.top = 2; 
}

//Mengecek stack apakah dalam kondisi kosong atau tidak
int stackkosong(){ 
	if(stack.top == -1){
		return(1);
	}
  	else{
  		return(0);
	}
}

//Mengecek stack apakah dalam kondisi penuh atau tidak
int stackpenuh(){ 
	if(stack.top == 2){
		return(1);
	}
    else{
    	return(0);
	}
}

//Restock souvenir di meja
void push(string warna){  
	if(stackpenuh()){
		cout << "Souvenir di meja sudah penuh\n";
	}
	else{
		stack.top++;
		stack.souvenir[stack.top]=warna;
		jmlsouvenir++;
	}
}

void pop(){  
	string IP;
	if(stackkosong()){
		cout << "stack underflow\n";
	}
	else{
		IP=stack.souvenir[stack.top];
		stack.top--;
	}  
}

//Cetak Tumpukan Souvenir di kardus BELOM
void cetakstack(){
	int i=stack.top;
	while (i>=0){  
		cout << " " <<stack.souvenir[i] << endl;
		i--;
	}
}













