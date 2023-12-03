//Domeniu: sPitAl - Patrascu Alice (pacient, departamentMedical, echipamentMedical)
#include <iostream>
#include<fstream>

using namespace std;

class Pacient {
private:
	const int nrPacient;
	static int nrGenerator;
	char* nume;
	int varsta;
	bool areAsigurare;
public:

	Pacient(): nrPacient(nrGenerator++) {
		this->nume = new char[strlen("Popescu Ion") + 1]; //alocare memorie
		strcpy_s(this->nume, strlen("Popescu Ion") + 1, "Popescu Ion"); 
		this->varsta = 40;
		this->areAsigurare = true;
	}
	Pacient(char* nume, int varsta, bool areAsigurare):nrPacient(nrGenerator)
	{
		nrGenerator++;
		this->nume = nume;
		this->varsta = varsta;
		this->areAsigurare = areAsigurare;
	}

	Pacient(int varsta, bool areAsigurare) :nrPacient(nrGenerator++) {
		this->nume = new char[strlen("Popa Ion") + 1];
		strcpy_s(this->nume, strlen("Popa Ion") + 1, "Popa Ion");
		this->varsta = varsta;
		this->areAsigurare = areAsigurare;
	}

	Pacient(const Pacient &p):nrPacient(nrGenerator++) {
		this->nume = new char[strlen(p.nume)+1];
		strcpy_s(this->nume, strlen(p.nume)+1, p.nume);
		this->varsta = p.varsta;
		this->areAsigurare = p.areAsigurare;
	}
	
	Pacient operator=(const Pacient& p) {
		if (this != &p)
		{
			if (this->nume)
				delete[] this->nume;
			this->nume = new char[strlen(p.nume)+1];
			strcpy_s(this->nume, strlen(p.nume)+1, p.nume);
			this->varsta = p.varsta;
			this->areAsigurare = p.areAsigurare;
		}
		return *this;
	}

	void AfisarePacient() {
		cout <<"Pacientul cu numarul "<<this->nrPacient+1<< " se numeste "<<this->nume << ", are varsta de " << this->varsta << " (de) ani si costurile de spitalizare ";
		if (this->areAsigurare) {
			cout << "sunt acoperite de asigurarea medicala.";
		}
		else {
			cout << "nu sunt acoperite de asigurarea medicala.";
		}
		cout << endl;
	}

	int getNrPacient() {
		return nrPacient;
	}
	
	int getVarsta() {
		return varsta;
	}

	void setVarsta(int varsta) {
		if (varsta > 0)
			this->varsta = varsta;
	}

	bool getAreAsigurare() {
		return areAsigurare;
	}

	void setAreAsigurare(bool areAsigurare) {
		this->areAsigurare = areAsigurare;
	}
	
	void setNume(char* nume) {
		if (strlen(nume) > 0)
			this->nume = nume;
	}

	char* getNume() {
		return nume;
	}

	
	static int getNrGenerator() {
		return nrGenerator;
	}
	~Pacient() {
		if (this->nume != NULL) {
			delete this->nume;
		}
	}

	Pacient operator++() {
		this->varsta++;
		return *this;
	}

	Pacient operator++(int) {
		Pacient copie = *this;
		this->varsta++;
		return copie;
	}

	bool operator>(Pacient p) {
		if (this->varsta != p.varsta)
			return this->varsta > p.varsta;
	}

	bool operator==(Pacient p) {
		if (this->varsta > 0 && p.varsta > 0)
			return this->varsta == p.varsta;
	}

	friend Pacient modificareAsigurare(Pacient& p); 

	friend ostream &operator<<(ostream& output_p, Pacient p){
		output_p << "Pacientul numarul " <<p.nrPacient<<" se numeste " << p.nume << ", are varsta de " << p.varsta << " ani si costurile de spitalizare ";
		if(p.areAsigurare)
			output_p << "sunt acoperite de asigurarea medicala.";
		else
			output_p << "nu sunt acoperite de asiguararea medicala.";
		output_p << endl;
		return output_p;
	}

	friend istream& operator>>(istream& input_p, Pacient& p) {
		cout << "Introduceti datele pacientului. Numele: ";
		if (p.nume) {
			delete[]p.nume;
		}
		char aux[40];
		input_p >> aux;
		p.nume = new char[strlen(aux) + 1];
		strcpy_s(p.nume, strlen(aux )+1, aux);
		cout << "Varsta: ";
		input_p >> p.varsta;
		cout << "Are asigurare? Introduceti 'D' pentru DA si 'N' pentru NU."<< endl;
		char var=0;
		input_p >> var;
		if (var == 'D')
			p.areAsigurare = true;
		else
			p.areAsigurare = false;
		return input_p;
	}

	friend ofstream& operator<<(ofstream& output_p, Pacient p) {
		output_p << p.nume << endl << p.varsta <<endl<< p.areAsigurare<<endl;
		return output_p;
	}

	friend ifstream& operator>>(ifstream& input_p, Pacient& p) {
		char aux[40];
		input_p >> aux;
		if (p.nume)
			delete[]p.nume;
		p.nume = new char[strlen(aux) + 1];
		strcpy_s(p.nume, strlen(aux) + 1, aux);
		input_p >> p.varsta;
		input_p >> p.areAsigurare;
		return input_p;
	}
};

int Pacient::nrGenerator = 0;

 Pacient modificareAsigurare(Pacient& p) {
	if (p.areAsigurare)
		p.areAsigurare = false;
	else
		p.areAsigurare = true;
	return p;
}

class DepartamentMedical {
	const string nume;
	static float salariuMinim;
	int nrAngajati;
	string* numeAngajati;
	float* salarii;

public:
	DepartamentMedical(): nume("Chirurgie") {
		nrAngajati = 3;
		numeAngajati=new string[nrAngajati];
		numeAngajati[0] = "Ionescu";
		numeAngajati[1] = "Popescu";
		numeAngajati[2] = "Popa";
		salarii = new float[nrAngajati];
		salarii[0] = salariuMinim+1000.00f;
		salarii[1] = salariuMinim+ 3500.00f;
		salarii[2] = salariuMinim;
	}

	DepartamentMedical(string nume, int nrAngajati, string* numeAngajati, float* salarii):nume(nume) {
		this->nrAngajati = nrAngajati;
		this->numeAngajati = new string[nrAngajati];
		for (int j = 0; j < nrAngajati; j++) {
			this->numeAngajati[j] = numeAngajati[j];
		}
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = salarii[i];
		}
	}

	DepartamentMedical(int nrAngajati, string* numeAngajati, float* salarii) : nume("Chirurgie") {
		this->nrAngajati = nrAngajati;
		this->numeAngajati = new string[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->numeAngajati[i] = numeAngajati[i];
		}
		this->salarii = new float[nrAngajati];
		for (int j = 0; j < nrAngajati; j++) {
			this->salarii[j] = salarii[j];
		}
	}

	DepartamentMedical(const DepartamentMedical &dm): nume(dm.nume){
		this->nrAngajati = dm.nrAngajati;
		this->numeAngajati = new string[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->numeAngajati[i] = dm.numeAngajati[i];
		}
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++)
			this->salarii[i] = dm.salarii[i];

	}

	DepartamentMedical operator =(const DepartamentMedical& dm) {
		if (this != &dm) {
			this->nrAngajati = dm.nrAngajati;
			if (this->numeAngajati)
				delete[] this->numeAngajati;
			this->numeAngajati = new string[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->numeAngajati[i] = dm.numeAngajati[i];
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++)
				this->salarii[i] = dm.salarii[i];
		}
		return *this;
	}

	string getNume() {
		return this->nume;
	}
	static float getSalariuMinim() {
		return salariuMinim;
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setAngajati(int nrAngajati, string* numeAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->numeAngajati != NULL)
				delete[] this->numeAngajati;
			if (this->salarii != NULL)
				delete[]this->salarii;
			this->numeAngajati = new string[nrAngajati];
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->numeAngajati[i] = numeAngajati[i];
				this->salarii[i] = salarii[i];
			}
		}
	}
	string getNumeAngajati() {
			return *numeAngajati;
	}

	string getNumeAngajati(int i) {
		if (i >= 0 && i < this->nrAngajati)
			return numeAngajati[i];
	}

	float getSalarii(int i) {
		if (i >= 0 && i < this->nrAngajati)
			return salarii[i];
	}

	static void MarireSalariu(int procent) {
		salariuMinim += salariuMinim * (procent / 100.00f);
	}

	void afisare() {
		cout << "Departamentul de " << this->nume << " are un numar de " << this->nrAngajati << " angajati cu salariile urmatoare: "<<endl;
		for (int i = 0; i < this->nrAngajati; i++) {
			cout <<"       "<<i+1<<". " << this->numeAngajati[i] << " are salariul de " << this->salarii[i] << " lei." << endl;
		}
		cout << endl;
	}

	~DepartamentMedical() {
		if (this->numeAngajati != NULL) {
			delete[]this->numeAngajati;
		}
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}
	
	float operator() () {
		float suma = 0;
		for (int i = 0; i < nrAngajati; i++) {
			suma += salarii[i];
		}
		return suma;
	}

	string &operator[](int index) {
		if (index >= 0 && index < this->nrAngajati)
			return numeAngajati[index];
 	}



	DepartamentMedical operator+=(const DepartamentMedical& dm) {
		int aux = this->nrAngajati + dm.nrAngajati;
		string* aux1 = new string[aux];
		float* aux2 = new float[aux];

		for (int i = 0; i < this->nrAngajati; i++) {
			aux1[i] = this-> numeAngajati[i];
			aux2[i] = this->salarii[i];
		}
		for (int i = this->nrAngajati; i < aux; i++) {
			aux1[i] = dm.numeAngajati[i - this->nrAngajati];
			aux2[i] = dm.salarii[i - this->nrAngajati];
		}

		this->nrAngajati = aux;
		if (this->numeAngajati)
			delete[]numeAngajati;
		if (this->salarii)
			delete[]salarii;
		this->numeAngajati = aux1;
		this->salarii = aux2;

		return *this;
	}

	friend ostream& operator<<(ostream& output_dm, DepartamentMedical dm) {
		output_dm << "Departamentul de " << dm.nume << " are un numar de " << dm.nrAngajati << " angajati cu salariile urmatoare: " << endl;
		for (int i = 0; i < dm.nrAngajati; i++) {
			output_dm << "       " << i + 1 << ". " << dm.numeAngajati[i] << " are salariul de " << dm.salarii[i] << " lei." << endl;
		}
		output_dm << endl;
		return output_dm;
	}

	friend istream& operator>>(istream& input_dm, DepartamentMedical& dm) {
		if (dm.numeAngajati != NULL) {
			delete[] dm.numeAngajati;
			dm.numeAngajati = NULL;
		}
		if (dm.salarii != NULL) {
			delete[] dm.salarii;
			dm.salarii = NULL; 
		}
		cout << "Numar angajati: ";
		input_dm >> dm.nrAngajati;
		if (dm.nrAngajati <= 0) {
			cerr << "Numarul de angajati trebuie sa fie un numar pozitiv nenul.";
			return input_dm;
		}
		dm.numeAngajati = new string[dm.nrAngajati];
		dm.salarii = new float[dm.nrAngajati];
		cout << " Introduceti numele angajatilor:\n";
		for (int i = 0; i < dm.nrAngajati; i++){
			input_dm >>dm. numeAngajati[i];
			cout << "Angajatul cu numele " << dm.numeAngajati[i] << " are salariul de (lei): ";
			input_dm >> dm.salarii[i];
		}
		return input_dm;
	}

	explicit operator int() {
		return this->nrAngajati;
	}


	void citireDinFisierBinar(fstream& f) {
		f.read((char*)&this->nrAngajati, sizeof(int));

		if (this->numeAngajati)
			delete[] this->numeAngajati;
		if (this->salarii)
			delete[] this->salarii;

		this->numeAngajati = new string[this->nrAngajati];
		this->salarii = new float[this->nrAngajati];

		for (int i = 0; i < this->nrAngajati; i++) {
			int lungimeNume=0;
			f.read((char*)&lungimeNume, sizeof(int));

			char* numeAngajat = new char[lungimeNume + 1];
			f.read((char*)numeAngajat, lungimeNume);
			numeAngajat[lungimeNume] = '\0';

			this->numeAngajati[i] = string(numeAngajat);

			f.read((char*)&this->salarii[i], sizeof(float) );

			delete[] numeAngajat;
		}

		

	}

	void scriereInFisierBinar(fstream& f) {
		f.write((char*)&this->nrAngajati, sizeof(int));

		for (int i = 0; i < this->nrAngajati; i++) {
			int lungimeNume = this->numeAngajati[i].length();
			f.write((char*)&lungimeNume, sizeof(int));
			f.write(this->numeAngajati[i].c_str(), lungimeNume);
			f.write((char*)&this->salarii[i], sizeof(float));
		}
	}



	friend void adaugareAngajat( DepartamentMedical& dm, string nume, float salariu);
};



float DepartamentMedical::salariuMinim = 3000;

void adaugareAngajat( DepartamentMedical& dm, string nume, float salariu) {
	string* aux = new string[dm.nrAngajati + 1];
	float* auxx = new float[dm.nrAngajati + 1];
	for (int i = 0; i < dm.nrAngajati; i++) {
		aux[i] = dm.numeAngajati[i];
		auxx[i] = dm.salarii[i];
	}
	aux[dm.nrAngajati] = nume;
	auxx[dm.nrAngajati] = salariu;
	dm.nrAngajati++;

	if (dm.numeAngajati)
		delete[]dm.numeAngajati;

	if (dm.salarii)
		delete[]dm.salarii;

	dm.numeAngajati = aux;
	dm.salarii = auxx;

}

class EchipamentMedical {

	static int nrGeneratorEchipament;
	const int nrEchipament;
	char* nume;
	int durataMedieFunctionare;
	bool estePortabil;

public:
	
	EchipamentMedical():nrEchipament(nrGeneratorEchipament) {
		nrGeneratorEchipament++;
		this->nume = new char[strlen("Defibrilator") + 1];
		strcpy_s(nume, strlen("Defibrilator") + 1, "Defibrilator");
		durataMedieFunctionare = 7;
		estePortabil = true;
	}

	EchipamentMedical(char* nume, int durataMedieFunctionare, bool estePortabil) : nrEchipament(nrGeneratorEchipament++) {
		this->nume = nume;
		this->durataMedieFunctionare = durataMedieFunctionare;
		this->estePortabil = estePortabil;
	}

	EchipamentMedical(int durataMedieFunctionare, bool estePortabil) : nrEchipament(nrGeneratorEchipament++),
		durataMedieFunctionare(durataMedieFunctionare), estePortabil(estePortabil) {
		this->nume = new char[strlen("Stetoscop") + 1];
		strcpy_s(nume, strlen("Stetoscop") + 1, "Stetoscop");

	}

	EchipamentMedical(const EchipamentMedical& ec) : nrEchipament(nrGeneratorEchipament++) {
		this->nume = new char[strlen(ec.nume)+1];
		strcpy_s(this->nume, strlen(ec.nume)+1, ec.nume);
		this->durataMedieFunctionare = ec.durataMedieFunctionare;
		this->estePortabil = ec.estePortabil;
	}

	EchipamentMedical operator=(const EchipamentMedical &ec) {
		if (this != &ec) {
			if (this->nume)
				delete[] this->nume;
			this->nume = new char[strlen(ec.nume)+1];
			strcpy_s(this->nume, strlen(ec.nume)+1, ec.nume);
			this->durataMedieFunctionare = ec.durataMedieFunctionare;
			this->estePortabil = ec.estePortabil;
		}
		return *this;
	}

	void afisareEchipament() {
		cout << "Echipamentul cu numarul de inregistrare " << nrEchipament+1 << " este un " << nume << " cu durata medie de functionare de "
			<< durataMedieFunctionare << " ani si ";
		if (estePortabil)
			cout << "este portabil.";
		else
			cout << "nu este portabil.";
		cout << endl;
	}

	static int getNumarTotal() {
		return nrGeneratorEchipament; 
	}

	

	int getNrEchipament() {
		return nrEchipament;
	}
	

	char* getNume() {
		return nume;
	}

	void setNume(char* nume) {
		if (strlen(nume) > 0)
			this->nume = nume;
	}

	int getDurataMedieFunctionare() {
		return durataMedieFunctionare;
	}

	void setDuarataMedieFunctionare(int ani) {
		if (ani > 0)
			this->durataMedieFunctionare = ani;
	}

	bool getEstePortabil() {
		return estePortabil;
	}

	void setEstePortabil(bool portabil) {
		this->estePortabil = portabil;
	}


	operator int() {
		return this->durataMedieFunctionare;
	}

	~EchipamentMedical() {
		if (nume) {
			delete this->nume;
		}
	}

	EchipamentMedical operator!() {
		EchipamentMedical copie = *this;
		copie.estePortabil = !this->estePortabil;
		return copie;
	}

	EchipamentMedical operator--() {
		this->durataMedieFunctionare--;
		return *this;
	}

	EchipamentMedical operator--(int) {
		EchipamentMedical copie = *this;
		this->durataMedieFunctionare--;
		return copie;
	}

	bool operator!=(EchipamentMedical em) {
		return this->durataMedieFunctionare != em.durataMedieFunctionare;
	}

	friend ostream& operator<<(ostream& output_em, EchipamentMedical em) {
		output_em << "Echipamentul cu numarul de inregistrare " <<em. nrEchipament + 1 << " este un " << em.nume << " cu durata medie de functionare de "
			<< em.durataMedieFunctionare << " ani si ";
			if(em.estePortabil)
				output_em << "este portabil.";
			else
				output_em << "nu este portabil.";
		return output_em;
	}

	friend istream& operator>>(istream& input_em, EchipamentMedical& em) {
		cout << "Introduceti datele echipamentului. Numele: ";
		if (em.nume) {
			delete[] em.nume;
		}
		char aux[50];
		input_em >> aux;;
		em.nume = new char[strlen(aux) + 1];
		strcpy_s(em.nume, strlen(aux) + 1, aux);
		cout << "Durata medie de functionare: ";
		input_em >> em.durataMedieFunctionare;
		cout << "Este portabil? Introduceti 'D' pentru DA si 'N' pentru NU." << endl;
		char var = 0;
		input_em >> var;
		if (var == 'D')
			em.estePortabil = true;
		else
			em.estePortabil = false;
		return input_em;
	}



	void scriereInFisierBinar(fstream& f) {
		int lungime =strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++)
			f.write((char*)&this->nume[i], sizeof(char));
		f.write((char*)&this->durataMedieFunctionare, sizeof(int));
		f.write((char*)&this->estePortabil, sizeof(bool));
	}

	void citireDinFisierBinar(fstream& f) {
		int lungime=0;
		f.read((char*)&lungime, sizeof(int));
		if (this->nume)
			delete[] this->nume;
		this->nume = new char[lungime + 1];
		for (int i = 0; i < lungime; i++)
			f.read((char*)&this->nume[i], sizeof(char));
		this->nume[lungime] = '\0';
		f.read((char*)&this->durataMedieFunctionare, sizeof(int));
		f.read((char*)&this->estePortabil, sizeof(bool));
	}


};
int EchipamentMedical::nrGeneratorEchipament = 0; 

class Doctor {
	string nume;
	int nrPacienti;
	Pacient* pacienti;

public:

	string getNume() {
		return this->nume;
	}

	int getNrPacienti() {
		return this->nrPacienti;
	}

	Pacient getPacienti(int index) {
		if (index > 0 && index < this->nrPacienti)
			return pacienti[index];
	}

	void setNume(string nume) {
		if (nume.length()>0)
		this->nume = nume;
	}

	void setPacienti(int nr, Pacient* pacienti) {
		if (nr > 0) {
			this->nrPacienti = nr;
			if (this->pacienti)
				delete[]pacienti;
			this->pacienti = new Pacient[nr];
			for (int i = 0; i < nr; i++)
				this->pacienti[i] = pacienti[i];
		}
	}

	Doctor(string nume, int nrPacienti, Pacient *pacienti) {
		this->nume = nume;
		this->nrPacienti = nrPacienti;
		this->pacienti = new Pacient[this->nrPacienti];
		for (int i = 0; i < this->nrPacienti; i++)
			this->pacienti[i] = pacienti[i];
	}

	Doctor() {
		this->nume = "Sociu Maria";
		this->nrPacienti = 2;
		this->pacienti = new Pacient[2];
	}

	Doctor(const Doctor& d) {
		this->nume = d.nume;
		this->nrPacienti = d.nrPacienti;
		this->pacienti = new Pacient[nrPacienti];
		for (int i = 0; i < this->nrPacienti; i++)
			this->pacienti[i] = d.pacienti[i];
	}


	Doctor operator=(const Doctor& d) {
		if (this != &d) {
			this->nume = d.nume;
			this->nrPacienti = d.nrPacienti;
			if (this->pacienti)
				delete[] pacienti;
			this->pacienti = new Pacient[nrPacienti];
			for (int i = 0; i < this->nrPacienti; i++)
				this->pacienti[i] = d.pacienti[i];
		}
		return *this;
	}

	~Doctor() {
		if (this->pacienti)
			delete[] pacienti;
	}

	bool operator>(Doctor d) {
		return this->nrPacienti > d.nrPacienti;
	}

	friend ostream& operator<< (ostream& out,const Doctor &d) {
		out << "Doctorul " << d.nume << " are " << d.nrPacienti << " pacienti: ";
		for (int i = 0; i < d.nrPacienti; i++)
			out << d.pacienti[i]<< endl;
		out << endl;
		return out;
	}

	friend istream& operator>> (istream& in, Doctor& d) {
		cout << "Introduceti datele doctorului. Nume: ";
		in >> d.nume;
		cout << "Numarul actual de pacienti in grija:";
		in >> d.nrPacienti;
		if (d.pacienti)
			delete[] d.pacienti;
		d.pacienti = new Pacient[d.nrPacienti];
		for (int i = 0; i < d.nrPacienti; i++) {
			cout << "Datele pacientului " << i + 1 << " sunt :  ";
			in >> d.pacienti[i];
		}

		return in;
	}

	friend ifstream& operator>> (ifstream& in, Doctor& d) {
		in >> d.nume;
		in >> d.nrPacienti;
		if (d.pacienti)
			delete[] d.pacienti;
		d.pacienti = new Pacient[d.nrPacienti];
		for (int i = 0; i < d.nrPacienti; i++) {
			in >> d.pacienti[i];
		}
		return in;
	}

	friend ofstream& operator<< (ofstream& out, const Doctor& d) {
		out << d.nume << endl << d.nrPacienti << endl;
		for (int i = 0; i < d.nrPacienti; i++)
			out << d.pacienti[i] << endl;
		return out;
	}
	
};

class Chirurgie : public DepartamentMedical {
	string tip;
	int nrDoctori;
	Doctor* drChirurgi;

public:


	Chirurgie(string tip, int nrAng, string* numeAng, float* salarii) : DepartamentMedical("Chirurgie", nrAng, numeAng, salarii) {
		this->tip = tip;
		this->nrDoctori = 2;
		this->drChirurgi = new Doctor[2];
	}

	Chirurgie() :DepartamentMedical() {
		this->tip = "Plastica";
		this->nrDoctori = 1;
		this->drChirurgi = new Doctor[1];
	}

	string getTip() {
		return this->tip;
	}

	int getNrDr() {
		return this->nrDoctori;
	}

	Doctor getDocotor(int index) {
		if (index < this->nrDoctori && index>0)
			return this->drChirurgi[index];
	}

	void setTip(string tip) {
		this->tip = tip;
	}

	void setDr(int nrDr, Doctor* dr) {
		if (nrDr > 0) {
			this->nrDoctori = nrDr;
			if (this->drChirurgi)
				delete[] drChirurgi;
			this->drChirurgi = new Doctor[nrDr];
			this->drChirurgi = dr;
		}
	}

	Chirurgie(const Chirurgie& c) : DepartamentMedical(c) {
		this->tip = c.tip;
		this->nrDoctori = c.nrDoctori;
		this->drChirurgi = new Doctor[this->nrDoctori];
		for (int i = 0; i < this->nrDoctori; i++)
			this->drChirurgi[i] = c.drChirurgi[i];
	}

	Chirurgie operator=(const Chirurgie& c) {
		if (this != &c) {
			DepartamentMedical :: operator=(c);
			this->tip = c.tip;
			this->nrDoctori = c.nrDoctori;
			if (this->drChirurgi)
				delete[] this->drChirurgi;
			this->drChirurgi = new Doctor[this->nrDoctori];
			for (int i = 0; i < this->nrDoctori; i++)
				this->drChirurgi[i] = c.drChirurgi[i];
		}
		return *this;
	}

	~Chirurgie() {
		if (this->drChirurgi)
			delete[] this->drChirurgi;
	}



	friend istream& operator>>(istream& in_c, Chirurgie& c) {
		in_c >> (DepartamentMedical&)c;
		cout << "Tipul chirurgiei: ";
		in_c >> c.tip;
		cout << "Numarul de doctori: ";
		in_c >> c.nrDoctori;
		if (c.drChirurgi)
			delete[] c.drChirurgi;
		c.drChirurgi = new Doctor[c.nrDoctori];
		for (int i = 0; i < c.nrDoctori; i++)
			in_c >> c.drChirurgi[i];
		return in_c;
	}

	friend ostream& operator<<(ostream& out_c, const  Chirurgie& c) {
		out_c << (DepartamentMedical)c << endl;
		out_c << "Departamentul de chirurgie " << c.tip << " are un colectiv de " << c.nrDoctori << " doctori: \n";
		for (int i = 0; i < c.nrDoctori; i++)
			out_c << c.drChirurgi[i] << endl;
		return out_c;
	}

	void adaugaDoctor(Doctor dr) {
		Doctor* aux = new Doctor[this->nrDoctori + 1];
		for (int i = 0; i < this->nrDoctori; i++)
			aux[i] = this->drChirurgi[i];
		aux[this->nrDoctori] = dr;
		this->nrDoctori++;
		if (this->drChirurgi)
			delete[]this->drChirurgi;
		this->drChirurgi = aux;
	}
};

class PacientPeListaAsteptare : public Pacient {
private:
	char* organAsteptat;
	int grupaSange;
	bool rh;

public:

	char* getOrganAsteptat() {
		return this->organAsteptat;
	}

	char* setOrganAsteptat(const char* organ) {
		if (this->organAsteptat)
			delete[]this->organAsteptat;
		this->organAsteptat = new char[strlen(organ) + 1];
		strcpy_s(this->organAsteptat, strlen(organ) + 1, organ);
	}

	
	int getGrupa() {
		return this->grupaSange;
	}

	void setGrupa(int gr) {
		if (gr == 1 || gr == 2 || gr == 3 || gr == 4) {
			this->grupaSange = gr;
		}
	}

	bool getRh() {
		return this->rh;
	}

	void setRh(bool Rh) {
		this->rh = Rh;
	}


	PacientPeListaAsteptare() :Pacient() {
		this->organAsteptat = new char[strlen("rinichi") + 1];
		strcpy_s(this->organAsteptat, strlen("rinichi") + 1, "rinichi");
		this->grupaSange = 1;
		this->rh = true;
	}

	PacientPeListaAsteptare(int varsta, bool asigurare, int grupaSange, bool rh) :Pacient(varsta, asigurare){
		this->organAsteptat = new char[strlen("rinichi") + 1];
		strcpy_s(this->organAsteptat, strlen("rinichi") + 1, "rinichi");
		this->grupaSange = grupaSange;
		this->rh = rh;
	}	

	PacientPeListaAsteptare(const PacientPeListaAsteptare& p) :Pacient(p){
		this->organAsteptat = new char[strlen(p.organAsteptat) + 1];
		strcpy_s(this->organAsteptat, strlen(p.organAsteptat) + 1, p.organAsteptat);
		this->grupaSange = p.grupaSange;
		this->rh = p.rh;
	}

	PacientPeListaAsteptare operator=(const PacientPeListaAsteptare& p) {
		if (this != &p) {
			Pacient :: operator=(p);
			if (this->organAsteptat)
				delete[]this->organAsteptat;
			this->organAsteptat = new char[strlen(p.organAsteptat) + 1];
			strcpy_s(this->organAsteptat, strlen(p.organAsteptat) + 1, p.organAsteptat);
			this->grupaSange = p.grupaSange;
			this->rh = p.rh;
		}
		return *this;
	}

	~PacientPeListaAsteptare() {
		if (this->organAsteptat)
			delete[]this->organAsteptat;
	}

	friend ostream& operator<<(ostream& out, const PacientPeListaAsteptare& p) {
		out << (Pacient)p;
		out << "Pacientul este pe lista de asteptare pentru " << p.organAsteptat << ".\n";
		switch (p.grupaSange) {
		case 1:
			out << "Grupa de sange: 0" << endl;
			break;
		case 2:
			out << "Grupa de sange: A" << endl;
			break;
		case 3:
			out << "Grupa de sange: B" << endl;
			break;
		case 4:
			out << "Grupa de sange: AB" << endl;
			break;
		default:
			out << "Numarul introdus nu corespunde unei grupe de sange valide." << endl;
			break;
		}
		out << (p.rh ? "Rh pozitiv." : "Rh negativ.")<<endl;
		return out;
	}

	friend istream& operator>> (istream& in, PacientPeListaAsteptare& p) {
		in >> (Pacient&)p;
		cout << "Introduceti datele. Pacientul este pe lista de asteptare pentru: ";
		char aux[30];
		in >> aux;
		if (p.organAsteptat)
			delete[]p.organAsteptat;
		p.organAsteptat = new char[strlen(aux) + 1];
		strcpy_s(p.organAsteptat, strlen(aux) + 1, aux);
		cout << "Grupa de sange: \n (1,2,3 sau 4):";
		in >> p.grupaSange;
		char var = 0;
		cout << "RH:\n+->pozitiv\n- ->negativ: ";
		in >> var;
		if (var == '+')
			p.rh = true;
		else
			p.rh = false;
		return in;

	}

	bool operator==(PacientPeListaAsteptare &p) {
		return this->grupaSange == p.grupaSange && this->rh==p.grupaSange;
	}


};



void main() {
	
	
	//clasa pacient(1)
	Pacient pacient1;
	pacient1.AfisarePacient();

	char* nume = new char[strlen("Ionescu Ion") + 1];
	strcpy_s(nume, strlen("Ionescu Ion") + 1, "Ionescu Ion");
	Pacient pacient2(nume, 25, false);
	pacient2.AfisarePacient();
	modificareAsigurare(pacient2);
	pacient2.AfisarePacient(); //apelare functie prietena cu clasa pacient 


	Pacient pacient3(50, true);
	pacient3.AfisarePacient();

	cout << "Numarul de pacienti consultati pana in acest moment este de " << Pacient::getNrGenerator() << "." << endl;



	Pacient pacient4(pacient2);//copiere prin constructorul de copiere 
	cout << "Pacientul cu numarul " << pacient4.getNrPacient() + 1 << " are numele de " << pacient4.getNume() << " , varsta de " << pacient4.getVarsta()
		<< " (de) ani  si costurile "
		<< (pacient4.getAreAsigurare() ? "vor fi acoperite de asigurarea medicala." : "nu vor fi acoperite de asigurarea medicala.") << endl;
	char* nume4 = new char[strlen("Palade Maria") + 1];
	strcpy_s(nume4, strlen("Palade Maria") + 1, "Palade Maria");
	pacient4.setNume(nume4);
	pacient4.setVarsta(15);
	pacient4.setAreAsigurare(true);
	cout << "Pacientul cu numarul " << pacient4.getNrPacient() + 1 << " are numele de " << pacient4.getNume() << " , varsta de " << pacient4.getVarsta()
		<< " (de) ani  si costurile "
		<< (pacient4.getAreAsigurare() ? "vor fi acoperite de asigurarea medicala." : "nu vor fi acoperite de asigurarea medicala.") << endl;

	Pacient pacient5;
	pacient5 = pacient2;//copiere prin operatorul =
	pacient5.AfisarePacient();

	//clasa doctor(4)
	Doctor dr1;
	Pacient* p = new Pacient[2]{ pacient1, pacient2 };
	Doctor dr5("Florescu", 2, p);
	cout << dr5;
	Doctor dr2 = dr1;
	cin >> dr2;
	cout << dr2;
	cout << (dr1 > dr2 ? "Primul doctor are mai multi pacienti." : "Al doilea doctor are mai multi pacienti.");

	Doctor dr3, dr4;
	cin >> dr3;
	ofstream afisareD("Doctori.txt", ios::out);
	afisareD << dr3;
	afisareD.close();
	cout << dr3;
	ifstream citireD("Doctori.txt", ios::in);
	citireD >> dr4;
	cout << dr4;
	citireD.close();



	//clasa pacient(1)
	Pacient pacient6;
	cin >> pacient6;
	cout << pacient6;
	pacient6++;
	++pacient6;
	cout << pacient6;
	Pacient pacient7;
	cin >> pacient7;
	cout << (pacient6 > pacient7 ? "Primul pacient este mai in varsta. " : "Al doilea pacient este mai in varsta.") << endl;
	cout << (pacient7 == pacient6 ? "Pacientii au aceeasi varsta." : "Pacientii nu au aceeasi varsta.") << endl;

	int Nr = 0;
	cout << "Introduceti numarul pacientilor: ";
	cin >> Nr;
	Pacient* pacienti;
	pacienti = new Pacient[Nr];
	for (int i = 0; i < Nr; i++) {
		cin >> pacienti[i];
	}
	for (int i = 0; i < Nr; i++)
		cout << pacienti[i];
	Pacient pacient8, pacient9;
	cin >> pacient8;
	ofstream afisareP("Pacienti.txt", ios::out);
	afisareP << pacient8;
	afisareP.close();
	cout << pacient8;
	ifstream citireP("Pacienti.txt", ios::in);
	citireP >> pacient9;
	cout << pacient9;
	citireP.close();



	//clasa departament medical(2)
	DepartamentMedical dm1;
	dm1.afisare();

	string* angajati2 = new string[2];
	angajati2[0] = "Florescu";
	angajati2[1] = "Nechifor";
	float* salarii2 = new float[2];
	salarii2[0] = DepartamentMedical::getSalariuMinim() + 2000.00f;
	salarii2[1] = DepartamentMedical::getSalariuMinim() + 650.00f;
	DepartamentMedical dm2(2, angajati2, salarii2);
	dm2.afisare();

	DepartamentMedical::MarireSalariu(20);

	string* angajati = new string[2];
	angajati[0] = "Marinescu";
	angajati[1] = "Stoica";
	float* salarii = new float[2];
	salarii[0] = 2000;
	salarii[1] = 6650;
	DepartamentMedical dm3("Pediatrie", 2, angajati, salarii);
	dm3.afisare();
	adaugareAngajat(dm3, "Palade", 3500); //apelare functie friend cu clasa departament medical
	dm3.afisare();



	DepartamentMedical dm4(dm1);
	DepartamentMedical dm5;
	cout << "Departamentul de " << dm4.getNume() << " are un numar de " << dm4.getNrAngajati() << " angajati cu salariile urmatoare: " << endl;
	for (int i = 0; i < dm4.getNrAngajati(); i++) {
		cout << "       " << i + 1 << ". " << dm4.getNumeAngajati(i) << " are salariul de " << dm4.getSalarii(i) << " lei." << endl;
	}
	cout << endl;
	dm5 = dm1;
	dm5.afisare();
	string* vec1 = new string[4]{ "Stoica", "Marinescu","Pop", "Popovici" };
	float* vec2 = new float[4] {3978, 4587, 6700, 4567};
	dm4.setAngajati(4, vec1, vec2);
	cout << "Departamentul de " << dm4.getNume() << " are un numar de " << dm4.getNrAngajati() << " angajati cu salariile urmatoare: " << endl;
	for (int i = 0; i < dm4.getNrAngajati(); i++) {
		cout << "       " << i + 1 << ". " << dm4.getNumeAngajati(i) << " are salariul de " << dm4.getSalarii(i) << " lei." << endl;
	}
	cout << endl;
	cout << "Salariul minim din spital este de " << DepartamentMedical::getSalariuMinim() << " lei." << endl;
	cout << endl;



	cout << "Bugetul pentru salarii in sectia de " << dm3.getNume() << " este de " << dm3() << " lei." << endl;
	cout << dm3;
	cin >> dm3;
	dm3[0] = "Amariei";
	cout << "Noul angajat al departamentului " << dm3.getNume() << " este " << dm3[0] << "." << endl;
	dm3 += dm2;
	cout << dm3;
	cout << "Introduceti numarul departamentelor: ";
	int NR = 0;
	cin >> NR;
	DepartamentMedical* dm = new DepartamentMedical[NR];
	for (int i = 0; i < NR; i++) {
		cin >> dm[i];
	}
	for (int i = 0; i < NR; i++) {
		cout << dm[i];
	}
	int nrAngajatiDep1 = (int)dm1;
	cout << endl << "Departamentul 1 are " << nrAngajatiDep1 << " angajati";
	DepartamentMedical dm6, dm7;
	cin >> dm6;
	fstream fisierDM("Departamente.txt", ios::out | ios::binary);
	dm6.scriereInFisierBinar(fisierDM);
	fisierDM.close();

	fstream fisierDMcitire("Departamente.txt", ios::in | ios::binary);
	dm7.citireDinFisierBinar(fisierDMcitire);
	fisierDMcitire.close();
	cout << dm7;


	//clasa echipament medical (3)
	EchipamentMedical em1;
	em1.afisareEchipament();

	EchipamentMedical em2(10, true);
	em2.afisareEchipament();

	char* em = new char[strlen("Aparat de Radiografie") + 1];
	strcpy_s(em, strlen("Aparat de Radiografie") + 1, "Aparat de Radiografie");
	EchipamentMedical em3(em, 10, false);
	em3.afisareEchipament();



	EchipamentMedical em4(em3); //copiere prin constructorul de copiere
	EchipamentMedical em5;
	em5 = em3; //copiere prin operatorul =
	cout << "Echipamentul cu numarul de inregistrare " << em4.getNrEchipament() + 1 << " este un " << em4.getNume() << " cu durata medie de functionare de "
		<< em4.getDurataMedieFunctionare() << " ani si " << (em4.getEstePortabil() ? "este portabil." : "nu este portabil.");
	cout << endl;
	em4.setDuarataMedieFunctionare(20);
	em4.setEstePortabil(true);
	char* numeEM = new char[strlen("Termometru") + 1];
	strcpy_s(numeEM, strlen("Termometru") + 1, "Termometru");
	em4.setNume(numeEM);
	cout << "Echipamentul cu numarul de inregistrare " << em4.getNrEchipament() + 1 << " este un " << em4.getNume() << " cu durata medie de functionare de "
		<< em4.getDurataMedieFunctionare() << " ani si " << (em4.getEstePortabil() ? "este portabil." : "nu este portabil.");
	cout << endl;
	em5.afisareEchipament();
	cout << endl;
	cout << "Numarul total de echipamente existente in spital este de " << EchipamentMedical::getNumarTotal() << "." << endl;


	cin >> em5;
	cout << em5--;
	cout << --em5;
	cout << !em5;
	cout << (em5 != em4 ? "Au durata medie de functionare diferite." : "Au aceeasi durata medie de functionare.") << endl;


	cout << "Introduceti numarul echipamentelor: ";
	int numar = 0;
	cin >> numar;
	EchipamentMedical* Em = new EchipamentMedical[numar];
	for (int i = 0; i < numar; i++)
		cin >> Em[i];
	for (int i = 0; i < numar; i++)
		cout << Em[i] << endl;

	int nrLinii;
	int nrColoane;
	cout << "Cate tipuri de echipamente doriti sa introduceti? ";
	cin >> nrColoane;
	cout << "Cate echipamente din fiecare tip aveti?";
	cin >> nrLinii;
	EchipamentMedical** echipamente = new EchipamentMedical * [nrLinii];
	for (int i = 0; i < nrLinii; i++)
	{
		echipamente[i] = new EchipamentMedical[nrColoane];
	}

	for (int j = 0; j < nrColoane; j++)
		for (int i = 0; i < nrLinii; i++) {
			cout << "Echipamentul de tipul " << j + 1 << " cu numarul " << i + 1 << ":  ";
			cin >> echipamente[i][j];
		}
	for (int i = 0; i < nrLinii; i++)
		for (int j = 0; j < nrColoane; j++)
			cout << echipamente[i][j] << endl;

	EchipamentMedical em6;
	EchipamentMedical em7;
	cin >> em6;
	fstream fisierBinarScriere("Echipamente.dat", ios::out | ios::binary);
	em6.scriereInFisierBinar(fisierBinarScriere);
	fisierBinarScriere.close();

	fstream fisierBinarCitire("Echipamente.dat", ios::in | ios::binary);
	em7.citireDinFisierBinar(fisierBinarCitire);
	fisierBinarCitire.close();
	cout << em7;


	//clasas 5 (Chirurgie) ce mosteneste clasa Departament Medical
	Chirurgie ch1;
	cin >> ch1;
	cout << ch1;
	Chirurgie ch2;
	Doctor DR1;
	ch2.adaugaDoctor(DR1);
	cout << ch2;


	//Clasa 6(Pacient Aflat pe Lista de Asteptare) ce mosteneste clasa Pacient 
	PacientPeListaAsteptare pacientA1;
	cin >> pacientA1;
	cout << pacientA1;
	PacientPeListaAsteptare pacientA2;
	cout << (pacientA1 == pacientA2 ? "Pacientii sunt perfect compatibili." : "Pacientii nu sunt perfect compatibili.") << endl;


	delete[]salarii; delete[]salarii2; delete[] angajati; delete[] angajati2;
	delete[]pacienti; delete[]dm; delete[] em; delete[]p;
	
}
