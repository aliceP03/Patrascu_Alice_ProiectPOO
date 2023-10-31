//Domeniu: sPitAl - Patrascu Alice (pacient, departamentMedical, echipamentMedical)
#include <iostream>
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
	friend Pacient modificareAsigurare(Pacient& p); 
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

	~EchipamentMedical() {
		if (nume) {
			delete this->nume;
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
	modificareAsigurare(pacient2);
	pacient2.AfisarePacient(); //apelare functie prietena cu clasa pacient 


	Pacient pacient3(50, true);
	pacient3.AfisarePacient();

	cout<< "Numarul de pacienti consultati pana in acest moment este de "<< Pacient::getNrGenerator()<<"." << endl;

	Pacient pacient4(pacient2);//copiere prin constructorul de copiere 
	cout<<"Pacientul cu numarul " << pacient4.getNrPacient()+1 <<" are numele de "<< pacient4.getNume() << " , varsta de "<< pacient4.getVarsta() 
		<<" (de) ani  si costurile " 
		<<( pacient4.getAreAsigurare()? "vor fi acoperite de asigurarea medicala.": "nu vor fi acoperite de asigurarea medicala.") << endl;
	char* nume4 = new char[strlen("Palade Maria")+1];
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


	//clasa 2
	DepartamentMedical dm1;
	dm1.afisare();

	string* angajati2 = new string[2];
	angajati2[0] = "Florescu";
	angajati2[1] = "Nechifor";
	float* salarii2 = new float[2];
	salarii2[0] = DepartamentMedical::getSalariuMinim() + 2000.00f;
	salarii2[1] = DepartamentMedical::getSalariuMinim() + 650.00f;
	DepartamentMedical dm2(2,angajati2,salarii2);
	dm2.afisare();

	DepartamentMedical::MarireSalariu(20);
	
	string* angajati = new string[2];
	angajati[0] = "Marinescu";
	angajati[1] = "Stoica";
	float* salarii = new float[2];
	salarii[0] =  2000;
	salarii[1] =  6650;
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
	cout << "Salariul minim din spital este de " << DepartamentMedical::getSalariuMinim()<<" lei." << endl;
	cout << endl;


	
	//clasa 3
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
		<< em4.getDurataMedieFunctionare() << " ani si " <<( em4.getEstePortabil() ? "este portabil." : "nu este portabil.");
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
	delete[]salarii; delete[]salarii2; delete[] angajati; delete[] angajati2;

}
