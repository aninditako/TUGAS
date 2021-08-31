#include <iostream>
using namespace std;

struct pembuat
{
	char nama[30];
	char alamat[30];
	char kota[30];
	
};
struct penerima
{
	char kota[20];
	char nama[30];
	char alamat [20];
};
struct datakwitansi
	{
		int no;
		char jenisbarang[30];
		char satuan[10];
		int banyak;
		int harga;
		int jumlah;
	};
	
typedef struct
{
	char tglskrng[15];
	char no[15];
	char nofaktur[15];
	char tglfaktur[30];
	struct datakwitansi data[100];
	struct penerima receiver; 
	struct pembuat maker;
	char pembuatkwitansi[30];
	int total;
	
}	datafaktur;
	datafaktur faktur[100];
	
	int terbanyak(int jmlh)
		{	
			int i=0,j,highest=0;
			for(j=0;j<jmlh;j++)
				{
					if ( (faktur[i].data[j+1].banyak) > (faktur[i].data[j].banyak))
						highest = j+1;
				
				}
				cout << endl;
				cout << " Jenis Barang Yang Paling Banyak Dibeli Adalah : " << faktur[i].data[highest].jenisbarang;
		}
	int main()
	{
		int i=0;
		cout << "Masukkan Nama Pembuat KWITANSI : " ; cin >> faktur[i].pembuatkwitansi;
		cout << "Masukkan Nama Toko :" ; cin >> faktur[i].maker.nama;
		cout << "Masukkan Alamat Toko : "; cin >> faktur[i].maker.alamat;
		cout << "Masukkan Kota Toko : " ; cin >> faktur[i].maker.kota;
		cout << endl;
		cout << "Masukkan Nama  Penerima :"; cin >> faktur[i].receiver.nama;
		cout << "Masukkan Alamat Penerima :"; cin >> faktur[i].receiver.alamat;
		cout << "Masukkan Kota Penerima : ";  cin >> faktur[i].receiver.kota;
		cout << endl;
		cout << "Masukkan No KWITANSI :"; cin >> faktur[i].no;
		cout << "Masukkan No Faktur   :"  ; cin >> faktur[i].nofaktur;
		cout << "Masukkan Tgl Faktur  :"  ; cin >> faktur[i].tglfaktur;
		cout << endl;
		cout << "Masukkan Jumlah barang :" ; int jmlh;int j; cin >> jmlh;
		for(j=0;j<jmlh;j++)
			{
				faktur[i].data[j].no = j+1;
				cout << "Masukkan Jenis Barang : "; cin >> faktur[i].data[j].jenisbarang;
				cout << "Masukkan Banyaknya    : "; cin >>	faktur[i].data[j].banyak;
				cout << "Masukkan Satuan	   : "; cin >> faktur[i].data[j].satuan;
				cout << "Masukkan Harga Satuan : "; cin >> faktur[i].data[j].harga;
				faktur[i].data[j].jumlah = faktur[i].data[j].banyak*faktur[i].data[j].harga;
				cout << endl;
			}
			
		cout << endl << endl;
		cout << faktur[i].maker.nama << endl;
		cout << faktur[i].maker.alamat << endl;
		cout << faktur[i].maker.kota << endl << endl;
		cout << " Kepada : " << endl;
		cout << faktur[i].maker.kota << ", " << faktur[i].tglskrng << endl;
		cout << "Yth; " << faktur[i].receiver.nama << endl;
		cout << faktur[i].receiver.alamat;
		cout << faktur[i].receiver.kota << endl << endl;
		
		cout << "                             KWITANSI                       " ;
		cout << endl;
		cout << " No         : " << faktur[i].no << endl;
		cout << " No Faktur  : " << faktur[i].nofaktur << endl;
		cout << " Tgl Faktur : " << faktur[i].tglfaktur << endl;
		cout << endl;
		cout << endl;
		cout << "|------------------------------------------------------------" << endl;
		cout << "|No Urut | Jenis Barang |      Jumlah     |   Harga         |" << endl;
		cout << "|        |              | Banyak | Satuan | Satuan | Jumlah |" << endl;
		cout << "|-----------------------------------------------------------|" << endl;
		for(j=0;j<jmlh;j++)
			{
		cout << "|" << faktur[i].data[j].no << "       |" << faktur[i].data[j].jenisbarang << "|" << faktur[i].data[j].banyak << "|" << faktur[i].data[j].satuan << "|" << faktur[i].data[j].harga << "|" << faktur[i].data[j].jumlah ;
		cout << endl;
			}
		for (j=0;j<jmlh;j++)
			{
				faktur[i].total += faktur[i].data[j].jumlah;
			}
			
		cout << "-------------------------------------------------------------" ; cout << endl;
		cout << "                                                  | " << faktur[i].total << " | " << endl;
		cout << "                                          PPN 10% | " << faktur[i].total*(0.1) <<"|" << endl;
		cout << "                                                  | " << faktur[i].total-(faktur[i].total*0.1) << "|" << endl;
		cout << endl << endl;
		cout << "                                                      Hormat Kami " << endl;
		cout << endl<< endl;
		cout << "                                                     " << faktur[i].pembuatkwitansi;
		
		
		cout << endl;
		terbanyak(jmlh);
			
		
	}
	
	
