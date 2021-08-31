#include <iostream>
using namespace std;

void akhirx(int *x)
{
	*x = *x *4 + 5;	
}

void akhiry(int *y)
{
	*y = *y *3 - 8;	
}

void akhirz(int *z)
{
	*z = *z *3 - 9;	
}

int x=30, y=60, z=95;

int main ()
{
	
 	cout<<"  Nilai awal x, y, z : "<<endl;
    cout<<"\t "<<x<<"   "<<y<<"   "<<z<<endl;
    
   	cout<<"  Nilai akhir of x, y, and z : "<<endl;
    akhirx(&x); akhiry(&y); akhirz(&z);
    cout<<"\t"<<x<<"   "<<y<<"   "<<z<<endl;
    
    

		
}

