//Domeniu: sPitAl - Patrascu Alice (pacient, departamentMedical, echipamentMedical)
#include <iostream>
using namespace std;
class Pacient {
public:
	const int nrPacient;
	static int nrGenerator;
	char* nume;
	int varsta; 
	bool areAsigurare;

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

	~Pacient() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
	}
	static int NrPacienti() {
		return nrGenerator;
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
};
int Pacient::nrGenerator = 0;



class DepartamentMedical {
public:
	const string nume;
	static float salariuMinim;
	int nrAngajati;
	string* numeAngajati;
	float* salarii;

	DepartamentMedical(): nume("Cardiologie") {
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

	~DepartamentMedical() {
		if (this->numeAngajati!=NULL) {
			delete[]this->numeAngajati;
		}
		if (this->salarii!=NULL) {
			delete[]this->salarii;
		}
	}

	static void MarireSalariu(int procent) {
		salariuMinim += salariuMinim * (procent / 100.00f);
	}

	void afisare() {
		cout << "Departamentul de " << nume << " are un numar de " << nrAngajati << " angajati cu salariile urmatoare: "<<endl;
		for (int i = 0; i < nrAngajati; i++) {
			cout <<"       "<<i+1<<". " << numeAngajati[i] << " are salariul de " << salarii[i] << " lei." << endl;
		}
		cout << endl;
	}

};
float DepartamentMedical::salariuMinim = 3000;



class EchipamentMedical {
public:
	static int nrGeneratorEchipament;
	const int nrEchipament;
	char* nume;
	int durataMedieFunctionare;
	bool estePortabil;

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

	~EchipamentMedical() {
		if (nume) {
			delete[]nume;
		}
	}

};
int EchipamentMedical::nrGeneratorEchipament = 0; 

void main() {
	//clasa 1
	Pacient pacient1;
	pacient1.AfisarePacient();

	char* nume = new char[strlen("Ionescu Ion") + 1];
	strcpy_s(nume, strlen("Ionescu Ion") + 1, "Ionescu Ion");
	Pacient pacient2(nume,25,false);
	pacient2.AfisarePacient();

	Pacient pacient3(50, true);
	pacient3.AfisarePacient();

	cout<< "Numarul de pacienti consultati pana in acest moment este de "<< Pacient::NrPacienti()<<"." << endl;

	//clasa 2
	DepartamentMedical dm1;
	dm1.afisare();

	string* angajati2 = new string[2];
	angajati2[0] = "Florescu";
	angajati2[1] = "Nechifor";
	float* salarii2 = new float[2];
	salarii2[0] = DepartamentMedical::salariuMinim + 2000.00f;
	salarii2[1] = DepartamentMedical::salariuMinim + 650.00f;
	DepartamentMedical dm2(2,angajati2,salarii2);
	dm2.afisare();

	DepartamentMedical::MarireSalariu(20);
	
	string* angajati = new string[2];
	angajati[0] = "Marinescu";
	angajati[1] = "Stoica";
	float* salarii = new float[2];
	salarii[0] = DepartamentMedical::salariuMinim+ 2000;
	salarii[1] = DepartamentMedical::salariuMinim + 650;
	DepartamentMedical dm3("Pediatrie", 2, angajati, salarii);
	dm3.afisare();

	//clasa 3
	EchipamentMedical em1;
	em1.afisareEchipament();

	EchipamentMedical em2(10, true);
	em2.afisareEchipament();

	char* em = new char[strlen("Aparat de Radiografie") + 1];
	strcpy_s(em, strlen("Aparat de Radiografie") + 1, "Aparat de Radiografie");
	EchipamentMedical em3(em, 10, false);
	em3.afisareEchipament();

	cout << "Numarul total de echipamente existente in spital este de " << EchipamentMedical::getNumarTotal()<<"."<<endl;

}