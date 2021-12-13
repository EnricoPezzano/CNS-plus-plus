float month[12]; //guadagni mensili - ore mensili (/6.5)
float year; //guadagno annuale - ore totali annuali (/6.5)

struct mycns{//struttura per il giorno del turno
	//int year;  // year since 1900
	string wday;
	int day;  // day of month from 1 to 31
	string month;
	int month_n;   // month of year from 1 to 12
	float start; //ora di inizio turno
	float end; //ora di fine turno
	float daysalary; //guadagno giornaliero
};

int menu(){
	system("clear");
	int in=0;
	cout<<"CNS++"<<endl<<endl
		<<"0) Esci"<<endl
		<<"1) Resoconto turni"<<endl
		<<"2) Inserisci turni"<<endl
		<<"3) Cancella turni"<<endl
		<<"4) Modifica turni"<<endl
		<<"5) Guadagni mensili"<<endl<<endl
		<<"-- Digita la tua scelta: ";
	cin>>in;
	return in;
}

void calcolo_parziali(const vector<mycns>& v){
	year=month[0]=month[1]=month[2]=month[3]=month[4]=month[5]=month[6]=month[7]=month[8]=month[9]=month[10]=month[11]=0;

	for(int i=0; i<v.size(); i++)
		switch(v[i].month_n){
			case 1:
				month[0]+=v[i].daysalary;
				break;
			case 2:
				month[1]+=v[i].daysalary;
				break;
			case 3:
				month[2]+=v[i].daysalary;
				break;
			case 4:
				month[3]+=v[i].daysalary;
				break;
			case 5:
				month[4]+=v[i].daysalary;
				break;
			case 6:
				month[5]+=v[i].daysalary;
				break;
			case 7:
				month[6]+=v[i].daysalary;
				break;
			case 8:
				month[7]+=v[i].daysalary;
				break;
			case 9:
				month[8]+=v[i].daysalary;
				break;
			case 10:
				month[9]+=v[i].daysalary;
				break;
			case 11:
				month[10]+=v[i].daysalary;
				break;
			case 12:
				month[11]+=v[i].daysalary;
				break;
		}
	for(int i=0; i<12; i++)
		year+=month[i];
}

void print_parziali(const vector<mycns>& v){
	int last;
	for(int i=0;i<v.size();i++)
		if(v[i].daysalary)
			last=v[i].month_n;
	if(year)
		cout<<endl<<"   Ultimo mese: "<<(char)(128)<<" "<<month[last-1]
			<<"   Totale 2020: "<<(char)(128)<<" "<<year;
}

void print_month(const vector<mycns>& v){
	system("clear");
	cout<<"   Gennaio:\t "<<(char)(128)<<month[0]<<endl
		<<"   Febbraio:\t "<<(char)(128)<<month[1]<<endl
		<<"   Marzo:\t "<<(char)(128)<<month[2]<<endl
		<<"   Aprile:\t "<<(char)(128)<<month[3]<<endl
		<<"   Maggio:\t "<<(char)(128)<<month[4]<<endl
		<<"   Giugno:\t "<<(char)(128)<<month[5]<<endl
		<<"   Luglio:\t "<<(char)(128)<<month[6]<<endl
		<<"   Agosto:\t "<<(char)(128)<<month[7]<<endl
		<<"   Settembre:\t "<<(char)(128)<<month[8]<<endl
		<<"   Ottobre:\t "<<(char)(128)<<month[9]<<endl
		<<"   Novembre:\t "<<(char)(128)<<month[10]<<endl
		<<"   Dicembre:\t "<<(char)(128)<<month[11]<<endl<<endl
		<<"   Totale 2020:\t "<<(char)(128)<<year<<endl<<endl;
		int c = getchar();
}

void print(const vector<mycns>& v){
	if(v.size()){
		system("clear");
		//SetConsoleOutputCP(1252);
		cout<<"   Turni CNS:\t\tInizio\tFine\t"<<"Guadagno:"<<endl;
		for(int i=0;i<v.size();i++){
			if(v[i].day < 10)
				cout<<"   "<<v[i].wday<<"\t "<<v[i].day<<" - "<<v[i].month<<"\t"<<v[i].start<<"\t"<<v[i].end<<"\t"<<(char)(128)<<" "<<v[i].daysalary<<endl;
			else
				cout<<"   "<<v[i].wday<<"\t"<<v[i].day<<" - "<<v[i].month<<"\t"<<v[i].start<<"\t"<<v[i].end<<"\t"<<(char)(128)<<" "<<v[i].daysalary<<endl;
		}
		print_parziali(v);
	}
	else cout<<endl<<"   Non ci sono turni...";

	cout<<endl<<"   ";
	int c; cin>>c;
}

bool control(mycns& t){
	//controlla la stringa per il giorno della settimana
	if(t.wday == "lun") t.wday = "Lun";
	else if(t.wday == "mar") t.wday = "Mar";
		 else if(t.wday == "mer") t.wday = "Mer";
			  else if(t.wday == "gio") t.wday = "Gio";
				   else if(t.wday == "ven") t.wday = "Ven";
						else if(t.wday == "sab") t.wday = "Sab";
							 else if(t.wday == "dom") t.wday = "Dom";

	if(!(t.wday == "Lun"  || t.wday == "Mar"  || t.wday == "Mer"  || t.wday == "Gio"  || t.wday == "Ven"  || t.wday == "Sab"  || t.wday == "Dom")){
		cerr<<endl<<endl<<"INSERISCI UN GIORNO DELA SETTIMANA VALIDO!"<<endl<<"Turno non inserito.";
		sleep(2000);
		return false;
	}

	//controlla il numero del mese
	if(t.day < 1 || t.day > 31){
		cerr<<endl<<endl<<"INSERISCI UN NUMERO VALIDO!"<<endl<<"Turno non inserito.";
		sleep(2000);
		return false;
	}

	//controlla la stringa per il mese
	if(t.month == "gen") t.month_n=1;
	else if(t.month == "feb") t.month_n=2;
		 else if(t.month == "mar") t.month_n=3;
			  else if(t.month == "apr") t.month_n=4;
				   else if(t.month == "mag") t.month_n=5;
						else if(t.month == "giu") t.month_n=6;
							 else if(t.month == "lug") t.month_n=7;
								  else if(t.month == "ago") t.month_n=8;
									   else if(t.month == "set") t.month_n=9;
											else if(t.month == "ott") t.month_n=10;
												 else if(t.month == "nov") t.month_n=11;
													  else if(t.month == "dic") t.month_n=12;
														   else {cerr<<endl<<endl<<"INSERISCI UN MESE VALIDO!"<<endl<<"Turno non inserito.";
																 sleep(2000);
																 return false;
														   }

	//controlla orario
	if(t.start > t.end || t.start+t.end > 48 || t.end-t.start < 0){
		cerr<<endl<<endl<<"INSERISCI UN ORARIO VALIDO!"<<endl<<"Turno non inserito.";
		sleep(2000);
		return false;
	}

	//se arriva qua è tutto giusto e quindi return true
	return true;
}

void load(vector<mycns>& v){
	fstream file;
	filed.open("saves.txt");
	if(!file.good()){//file non presente per qualsiasi motivo
		cerr<<endl<<endl<<"'Database' not found!";
		cerr<<endl<<"Manually restart the program.";
		return;
	}
	mycns tmp;
	while(!file.eof()){
		file>>tmp.wday;
		file>>tmp.day;
		file>>tmp.month;
		file>>tmp.start;
		file>>tmp.end;
		file>>tmp.daysalary;
		if(control(tmp))
			v.push_back(tmp);
		else{
			cerr<<"Errore nel file di salvataggio! Un turno non e' stato caricato.";
			break;
		}
	}
	file.close();
	calcolo_parziali(v);
}

void store(const vector<mycns>& v){
	remove("saves.txt");
	ofstream file;
	file.open("saves.txt");
	if(!file.good()){//file non presente per qualsiasi motivo
		cerr<<endl<<endl<<"'Database' not found!";
		cerr<<endl<<"Manually restart the program.";
		return;
	}

	for(int i=0; i<v.size(); i++){
		file<<v[i].wday;
		file<<" ";
		file<<v[i].day;
		file<<" ";
		file<<v[i].month;
		file<<" ";
		file<<v[i].start;
		file<<" ";
		file<<v[i].end;
		file<<" ";
		file<<v[i].daysalary;
		if(i<v.size()-1) file<<endl;
	}
	file.close();
}

bool come_first(mycns a, mycns b){
	if(a.month_n < b.month_n) return true;
	if(a.month_n == b.month_n && a.day < b.day) return true;
	if(a.month_n == b.month_n && a.day == b.day && a.start < b.start) return true;
	return false;
}
void sort(vector<mycns>& v){
	//selection sort
	if(v.size()){
		mycns tmp;
		int min;
		for(int i=0;i<v.size()-1;i++){
			min = i;
			for(int j=i;j<v.size();j++)
				if(come_first(v[j], v[min]))
					min = j;
			tmp = v[min];
			v[min] = v[i];
			v[i] = tmp;
		}
	}
}

void add(vector<mycns>& v){
	cout<<"Quanti turni vuoi aggiungere? "<<endl;
	int in;	cin>>in;
	if(in){
		for(int i=1;i<=in;i++){
			mycns tmp;
			system("clear");
			cout<<"Turno +"<<i<<endl;
			cout<<endl<<"Giorno della settimana (Aaa): "; cin>>tmp.wday;
			cout<<endl<<"Numero del giorno: "; cin>>tmp.day;
			cout<<endl<<"Mese (aaa): "; cin>>tmp.month;
			cout<<endl<<"Ora inizio: "; cin>>tmp.start;
			cout<<endl<<"Ora fine: "; cin>>tmp.end;
			tmp.daysalary = (tmp.end - tmp.start) * P;
			if(control(tmp))
				v.push_back(tmp);
		}
		sort(v);
		calcolo_parziali(v);
		print(v);
	}
}

void deletec(vector<mycns>& v){
	char in_c;
	do{
		if(!v.size()){
			cout<<endl<<"   Non ci sono turni...";
			sleep(1500);
			return;
		}
		system("clear");
		for(int i=0;i<v.size();i++){
			if(v[i].day < 10)
				cout<<i<<") "<<v[i].wday<<"\t "<<v[i].day<<" - "<<v[i].month<<"\t"<<v[i].start<<"\t"<<v[i].end<<"\t"<<v[i].daysalary<<endl;
			else
				cout<<i<<") "<<v[i].wday<<"\t"<<v[i].day<<" - "<<v[i].month<<"\t"<<v[i].start<<"\t"<<v[i].end<<"\t"<<v[i].daysalary<<endl;
		}
		cout<<"-- Quale turno vuoi cancellare? Numero: "; int in; cin>>in;
		if(in < v.size() && in >= 0)
			v.erase(v.begin()+in);
		else cerr<<endl<<"INSERISCI UN NUMERO VALIDO! Turno non cancellato.";
		print(v);
		calcolo_parziali(v);
		cout<<endl<<"-- Ne vuoi cancellare un altro? s/n"<<endl; cin>>in_c;
	}while(in_c == 's');
}

void edit(vector<mycns>& v){
	char in_c;
	int in;
	do{
		if(!v.size()){
			cout<<endl<<"   Non ci sono turni...";
			sleep(1500);
			return;
		}
		system("clear");
		do{
			for(int i=0;i<v.size();i++){
				if(v[i].day < 10)
					cout<<i<<") "<<v[i].wday<<"\t "<<v[i].day<<" - "<<v[i].month<<"\t"<<v[i].start<<"\t"<<v[i].end<<"\t"<<v[i].daysalary<<endl;
				else
					cout<<i<<") "<<v[i].wday<<"\t"<<v[i].day<<" - "<<v[i].month<<"\t"<<v[i].start<<"\t"<<v[i].end<<"\t"<<v[i].daysalary<<endl;
			}
			cout<<"-- Quale turno vuoi modificare? Numero: "; cin>>in;
			if(in < v.size()) cerr<<endl<<"DIGITA UN VALORE VALIDO";
		}while(!(in < v.size()));

		system("clear");
		cout<<v[in].wday<<"\t"<<v[in].day<<" - "<<v[in].month<<"\t"<<v[in].start<<"\t"<<v[in].end<<endl;
		cout<<endl<<"Cosa vuoi modificare?"<<endl
		<<"0) Giorno della settimana"<<endl
		<<"1) Giorno del mese"<<endl
		<<"2) Mese"<<endl
		<<"3) Inizio turno"<<endl
		<<"4) Fine turno"<<endl<<endl
		<<"-- Digita la tua scelta: "; int choice; cin>>choice;

		system("clear");
		cout<<v[in].wday<<"\t"<<v[in].day<<" - "<<v[in].month<<"\t"<<v[in].start<<"\t"<<v[in].end<<endl;
		int backup_int;
		string backup_string;
		switch(choice){
			case 0:
				backup_string = v[in].wday;
				cout<<endl<<"Nuovo giorno: "; cin>>v[in].wday;
				if(!control(v[in]))
					v[in].wday = backup_string;
				break;
			case 1:
				backup_int = v[in].day;
				cout<<endl<<"Nuovo giorno del mese: "; cin>>v[in].day;
				if(!control(v[in]))
					v[in].day = backup_int;
				break;
			case 2:
				backup_string = v[in].month;
				cout<<endl<<"Nuovo mese: "; cin>>v[in].month;
				if(!control(v[in]))
					v[in].month = backup_string;
				break;
			case 3:
				backup_int = v[in].start;
				cout<<endl<<"Nuovo inizio turno: "; cin>>v[in].start;
				if(!control(v[in]))
					v[in].start = backup_int;
				else
					v[in].daysalary = (v[in].end - v[in].start) * P;
				break;
			case 4:
				backup_int = v[in].end;
				cout<<endl<<"Nuova fine turno: "; cin>>v[in].end;
				if(!control(v[in]))
					v[in].end = backup_int;
				else
					v[in].daysalary = (v[in].end -v[in].start) * P;
				break;
			default:
				cerr<<"DIGITA UN VALORE VALIDO";
		}
		cout<<endl<<endl<<"-- Ne vuoi modificare un altro? s/n"<<endl; cin>>in_c;
		sort(v);
		calcolo_parziali(v);
	}while(in_c == 's');
	print(v);
}
