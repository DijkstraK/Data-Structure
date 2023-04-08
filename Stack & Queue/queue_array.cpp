#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define max 5

using namespace std;

class Queue{
	private :
		int front, rear;
		int *queue;
	
	public :
		Queue()
		{
			front 	= -1; 
			rear	= -1;
			queue	= new int[max];
		}
		
		bool queueFull() //stack(tumpukan) telah penuh
		{
			if (rear == max - 1)
			{
				return true;
			
			}else{
				
				return false;
			}
		}
		
		bool queueEmpty() //belum terdapat stack(tumpukan)
		{
			if (rear == -1)
			{
				return true;
			
			}else{
				
				return false;
			}
		}
		
		void enQueue(int item) //menambah antrian
		{
			if (queueFull())
			{
				cout << "-> Antrian sudah penuh" << endl;
			
			}else if (queueEmpty()){
				
				front++;
				rear++;
				queue[rear] = item;
				cout << "-> Data [" << queue[rear] <<"] telah ditambahkan ke antrian" << endl;
			}else{
				
				rear++;
				queue[rear] = item;
				cout << "-> Data [" << queue[rear] <<"] telah ditambahkan ke antrian" << endl;
			}
		}
		
		void deQueue() //menghapus antrian
		{
			if (queueEmpty())
			{
				cout << "-> Antrian masih kosong" << endl;
			
			}else{
				
				cout << "-> Data ["<< queue[front] << "] pada antrian telah dihapus " << endl;
				for (int i = 0; i < rear; i++)
				{
					queue[i] = queue[i+1];
				}
				rear--;
			}
		}
		
		int peek() //mengecek tumpukan paling atas (top)
		{
			if (queueEmpty())
			{
				cout << "antrian kosong " << endl;
				return -1;
			
			}else{
				
				return queue[rear];
			}	
		}
		
		int countQueue()
		{
			if (queueEmpty())
			{
				return -1;
			
			}else{
				
				return rear - front + 1;
			}
			
		}
		
		void displayQueue()
		{
			if (queueEmpty())
			{
				cout << "Antrian masih kosong!" << endl;
			
			}else{
				
				cout << "======== QUEUE ========" << endl;
				for (int i = 0; i <= rear; i++)
				{
					cout << "Data : " << queue[i] << endl;
				}
				cout << "=======================" << endl;
			}
		}
};

int main()
{
	Queue eq;
	int pilih;
	int item;
	
	do{
		
		cout << "===== PROGRAM STACK C++ =====" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Display" << endl;
		cout << "4. Keluar" << endl;
		cout << "Masukan pilihan : ";
		cin  >> pilih;
		
		ulang:
		switch (pilih)
		{
			case 1 :
				cout << "Input data : ";
				cin  >> item;
				eq.enQueue(item);
				getch();
				break;
				
			case 2 :
				eq.deQueue();
				getch();
				break;
				
			case 3 :
				eq.displayQueue();
				getch();
				break;
					
			case 4 :
				cout << "-> Terimakasih" << endl;
				getch();
				break;
				
			default :
				cout << "-> Pilihan tidak ada/Format inputan salah" << endl;
				getch();
				break;
				goto ulang;
		}
		
		system ("cls");
	}while (pilih != 4);
	
	return 0;
	
}