#include <iostream>
//#include <windows.h>
#include <unistd.h>
#include <vector>
#include <fstream>
#define P 6.5;
using namespace std;

#include "mylib.h"
int main()
{
	system("clear");
	cout<<"Welcome to CNS++!"<<endl<<"loading...";
	vector<mycns> data;
	load(data);
	bool exit = false;
	do{
		switch(menu()){
			case 0://uscita
				cout<<endl<<"A presto...";
				store(data);
				exit=true;
				break;
			case 1://resoconto turni
				//
				sort(data);
				print(data);
				break;
			case 2://inserisci turni 
				add(data);
				break;
			case 3://cancella turni
				deletec(data);
				break;
			case 4://modifica turni
				edit(data);
				break;
			case 5://modifica turni
				print_month(data);
				break;
			default:
				cerr<<"DIGITA UN VALORE VALIDO!";
				sleep(1000);
		}
	}while(!exit);
}
