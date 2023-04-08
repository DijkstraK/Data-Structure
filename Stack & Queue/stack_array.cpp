#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define maxTop 10

using namespace std;

class Stack{
	
	private :
		int top;
		int *stack;
	
	public :
		Stack()
		{
			top 	= -1; 
			stack	= new int[maxTop];
		}
		
		bool stackFull() //stack(tumpukan) telah penuh
		{
			if (top == maxTop - 1)
			{
				return true;
			
			}else{
				
				return false;
			}
		}
		
		bool stackEmpty() //belum terdapat stack(tumpukan)
		{
			if (top == -1)
			{
				return true;
			
			}else{
				
				return false;
			}
		}
		
		void pushStack(int item) //menambah data pada stack(tumpukan)
		{
			if (stackFull())
			{
				cout << "-> Stack sudah penuh" << endl;
			
			}else{
		
				top++;
				stack[top] = item;
				cout << "-> Data [" << stack[top] << "] telah ditambahkan pada stack" << endl;
			}
		}
		
		void popStack() //mengambil data pada stack(tumpukan) 
		{
			if (stackEmpty())
			{
				cout << "-> Stack masih kosong" << endl;
			
			}else{
				cout << "-> Data ["<< stack[top] << "] pada stack telah dihapus " << endl;
				stack[top--];
			}
		}
		
		int peek() //mengecek tumpukan paling atas (top)
		{
			if (stackEmpty())
			{
				cout << "stack kosong " << endl;
				return -1;
			
			}else{
				
				return stack[top];
			}	
		}
		
		int countStack()
		{
			if (stackEmpty())
			{
				return -1;
			
			}else{
				
				return top + 1;
			}
		}
		
		void displayStack()
		{
			if (top == -1)
			{
				cout << "Stack masih kosong!" << endl;
			
			}else{
				
				cout << "======== STACK ========" << endl;
				for (int i = top; i >= 0; i--)
				{
					cout << "Data : " << stack[i] << endl;
				}
				cout << "=======================" << endl;
			}
		}
};

int main()
{
	Stack stck;
	int pilih;
	int item;
	
	do{
		
		cout << "===== PROGRAM STACK C++ =====" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Display" << endl;
		cout << "4. Peek" << endl;
		cout << "5. Keluar" << endl;
		cout << "Masukan pilihan : ";
		cin  >> pilih;
		
		ulang:
		switch (pilih)
		{
			case 1 :
				cout << "Input data : ";
				cin  >> item;
				stck.pushStack(item);
				getch();
				break;
				
			case 2 :
				stck.popStack();
				getch();
				break;
				
			case 3 :
				stck.displayStack();
				getch();
				break;
			
			case 4 :
				cout << "Top : " << stck.peek();
				getch();
				break;
	 			
			case 5 :
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
	}while (pilih != 5);
	
	return 0;
	
}