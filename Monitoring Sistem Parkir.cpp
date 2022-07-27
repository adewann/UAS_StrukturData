#include <iostream>
#include<conio.h>

using namespace std;

struct Node
{
 string data;
 string time;
 string lokasi;
 Node *next;
};
Node *headNode = NULL;
Node *currentNode = NULL;
Node *temp;
Node *rear;

bool isEmpty();
void addPlat(string data, string lokasi, string time);
void deletePlat(int n);
void printPlat();
void printLokasi();
void printTanggal();
void search(string plat);

int main()
{
	int menu;
	string data;
	char ulang;
	int n;
	string plat;
	string time;
	string lokasi;
	
	do
	{
		cout << ">>> PILIHAN MENU PARKIRAN <<<"<<endl<<endl;
		cout << "1. Input data kendaraan"<<endl;
		cout << "2. Tampilkan Kendaraan dan biaya"<<endl;
		cout << "3. Keluarkan Kendaraan"<<endl;
		cout << "4. Cari Kendaraan"<<endl;
		cout << "5. Selesai"<<endl<<endl;
		
		cout << "Masukkan nomor menu pilihan Anda : "; cin >> menu;
		cout <<endl;
		
		switch(menu)
		{
			case 1 :
			    addPlat(data, time, lokasi);
			    
			    cout<<endl;
				break;
				
			case 2 :
				printPlat();
				
				cout<<endl;
				break;
				
			case 3 :
				deletePlat(n);
			
				cout<<endl;
					break;
					
			case 4 :
			    search(plat);
				
				cout<<endl;
				break;
				
			case 5 :
				cout << "Terimakasih...";
  					cout << endl;
					  return 0;
				return 0;
							
			default:
        			cout << "Menu tidak tersedia" << endl;
    	}
    				cout << endl;
 
    				cout << "Ingin memilih menu lain (y/t)? ";
    				cin >> ulang;
    				
    				while(ulang == 't'){
    				cout << "Terimakasih...";
  					cout << endl;
					  return 0;	
    				}
    				while(ulang != 'y'){
    					cout<< "Menu tidak tersedia"<<endl;
    					cout<< "Ingin kembali ke menu yang lain (y/t)? ";
    					cin>>ulang;
    						while(ulang == 't'){
    				          cout << "Terimakasih...";
  					          cout << endl;
					          return 0;	
    				        }
    				}
    				
    				cout << endl;
  	}
  		while (ulang != 't');
  					cout << "Terimakasih...";
  					cout << endl;
 					 return 0;
}

bool isEmpty()
{
 return (headNode == NULL);
}

void addPlat(string data, string time, string lokasi)
{
 
 temp=new Node;
 cin.ignore();
 cout<< " Masukkan nomor plat : ";
 getline(cin, data);
 cout<< " Masukkan tanggal : ";
 getline(cin, time);
 cout<< " Masukkan lokasi parkir : ";
 getline(cin, lokasi);
 
 temp->data=data;
 temp->time=time;
 temp->lokasi=lokasi;
 temp->next=NULL;
 
 if(headNode==NULL)
 {
 	headNode=rear=temp;
 }
 else
 {
 	rear -> next = temp;
 	rear = temp;
 }
}


void deletePlat(int n)
{
	 if (headNode == currentNode && headNode == NULL) {
      cout<<"Tempat parkir kosong!!!"<<endl;
      return;
   }

   cout<<endl<<"Masukkan posisi kendaraan yang ingin dikeluarkan : ";
   cin>>n;
   
   int i;
   Node *temp1 = headNode;
   
   if(n == 1){
   	headNode = temp1 -> next;
   	delete temp1;
   	cout<<"Kendaraan dikeluarkan!!!";
   	return;
   }
   
   for (i = 0; i<n-2; i++)
   temp1 = temp1 -> next;
   Node *temp2 = temp1 -> next;
   temp1 -> next = temp2 -> next;
   delete temp2;
   cout<<"Kendaraan dikeluarkan!!!";   
}

void printPlat()
{
 if (headNode==NULL)
 {
 	cout<<"Data belum diinputkan.";
 	getch();
 }
 
 else
 {
 	temp = headNode;
 	int i = 1;
 	while(temp!=NULL)
 	{
 		cout<<i<<". Nomor plat : "<<temp->data<<endl;
 		cout<<"   Tanggal : "<<temp->time<<endl;
 		cout<<"   Lokasi : "<<temp->lokasi<<endl;
 		cout<<"   Biaya : RP 6.000"<<endl;
 		cout<<"---------------------------"<<endl;
 		temp=temp->next;
 		i++;
 	}
 	getch();
 }
}


void search(string plat)
{
	cin.ignore();
	cout << "Masukkan plat kendaraan yang ingin dicari : ";
	getline(cin, plat);
	Node *p;
	int pos = 1;
	p = headNode;
	while(p!=NULL)
	{
		if(p->data==plat)
		{
			cout<<"Kendaraan dengan plat "<<plat<<" ditemukan pada posisi list ke - "<<pos;
			return;
		}
		p=p->next;
		pos++;
	}
	cout<<"Plat tidak ditemukan.";
}
