#include <iostream>

using namespace std;

struct anime {
    string title, author;
    int release;
   
    anime *next;
    
} *head, *tail, *cur, *newN, *delN, *befN;

void createNode(string title, string author, int release) //create a node for single linked list
{
    head = new anime();
    head->title   = title;
    head->author  = author;
    head->release = release;
    head->next    = NULL;
    tail = head;
}

void addFirst (string title, string author, int release) //create the first node of SSL
{
    newN = new anime();
    newN->title   = title;
    newN->author  = author;
    newN->release = release;
    newN->next    = head;
    head = newN;
}

int countNode()
{
    cur = head;
    int sum = 0;
    while (cur != NULL){
        sum++;
        cur = cur->next;
        
    }
    
    return sum;
}

void addMiddle (string title, string author, int release, int position) //add a node in the addMiddle
{
	if (position < 1 || position > countNode()){
		
		cout << "Out of reach position" << endl;
		
	}else if (position == 1){
		
		cout << "Not in the middle position" << endl;
	}else{
		
		newN = new anime();
    	newN->title   = title;
    	newN->author  = author;
    	newN->release = release;
    
    	cur = head;
    	int nomor = 1;
    	while (nomor < position - 1){
       	 cur = cur->next;
       	 nomor++;
    	}
    	newN->next = cur->next;
    	cur->next  = newN;
	}
}

void addLast (string title, string author, int release) //create the first node of SSL
{
    newN = new anime();
    newN->title   = title;
    newN->author  = author;
    newN->release = release;
    newN->next    = NULL;
    tail->next    = newN;
    tail = newN;
}

void delFirst () //delete the first node
{
    delN = head;
    head = head->next;
    delete delN;
}

void delMiddle (int position) //delete the middle node
{
    if (position < 1 || position > countNode()){
		
		cout << "Out of reach position" << endl;
		
	}else if (position == 1 || position == countNode()){
		
		cout << "Not in the middle position" << endl;
	}else{
        cur = head;
        int nomor = 1;
        while (nomor <= position){
          if (nomor == position - 1){
                befN = cur;
            }   
            if (nomor == position){
                delN = cur;
            }
        
            cur = cur->next;
            nomor++;
        }
        befN->next = cur;
        delete delN;
	}
}

void delLast () //delete the last node
{
    delN = tail;
    cur  = head;
    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete delN;
}

void changeFirst(string title, string author, int release) // change the first node in SSL
{
	head->title   = title;
	head->author  = author;
	head->release = release;
}

void changeMiddle(string title, string author, int release, int position) //change the middle node in SSL
{
    if (position < 1 || position > countNode()){
		
		cout << "Out of reach position" << endl;
		
	}else if (position == 1){
		
		cout << "Not in the middle position" << endl;
	}else{
        cur = head;
        int nomor = 1;
        while (nomor < position){
            cur = cur->next;
            nomor++;
        }
        cur->title   = title;
        cur->author  = author;
        cur->release = release;
	}
}

void changeLast(string title, string author, int release) // change the last node in SSL
{
	tail->title   = title;
	tail->author  = author;
	tail->release = release;

}

void delALL()
{
    cur = head;
    while (cur != NULL){
        delete cur;
        cur = cur->next;
        
    }
}

void printSSL() //print the SSL
{
    
    cur = head;
    while (cur != NULL){
        cout << "Title           : " << cur->title << endl;
        cout << "Author          : " << cur->author << endl;
        cout << "Release         : " << cur->release << endl;
       
        cur = cur->next;
    }
    cout << "Number of nodes : " << countNode() << endl;
   
}

int main(){
   
    createNode ("Naruto", "Masashi Kishimoto", 2007);
    printSSL   ();
    
    cout << endl;
    
    addFirst ("Detective Conan", "Kirei Suki", 1997);
    printSSL();

    cout << endl;

    addLast ("Demon Slayer", "Agata Purwa", 2009);
    printSSL();
    
}