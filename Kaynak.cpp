

#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

class Kayit
{

	friend ostream& operator<<(ostream& outStream, const Kayit& kayit);


	friend istream& operator>>(istream& inStream, Kayit& kayit);
public:

	Kayit(const string & kelime1 = "", const string & aciklamaa = "");


	Kayit(const string & kelime, const vector<string> & aciklamalar);


	const Kayit & operator +(const Kayit & digerKayit);


	const Kayit &operator +(const string & aciklama);


	const Kayit &operator -(const string & aciklama);


	bool operator!();


	bool operator==(const Kayit & digerKayit);


	bool operator==(const string & digerKelime);
private:
	string kelime;
	vector<string> aciklama;
};


ostream& operator<<(ostream& outStream, const Kayit& kayit) {
	outStream << kayit.kelime << endl;
	for (unsigned int i = 0; i < kayit.aciklama.size(); i++) {
		outStream << kayit.aciklama[i] << " ";
	}
	return outStream;
}

istream& operator>>(istream& inStream, Kayit& kayit) {
	cout << "kelime giriniz";
	for (int n = 0; inStream >> kayit.aciklama[n]; ++n) {
		getline(inStream, kayit.aciklama[n]);
		cout << kayit.aciklama[n];
	}
	getline(inStream, kayit.kelime);
	while (kayit.aciklama.empty()) {
		exit(1);
	}
	return inStream;
}


Kayit::Kayit(const string&  kelime1, const string& aciklamaa) {
	int sayi = 0;
	kelime = kelime1;
	if (sayi < 1) {
		aciklama.push_back(aciklamaa);
		sayi++;
	}
}


Kayit::Kayit(const string & kelime1, const vector<string> & aciklamalar) {
	kelime = kelime1;

	aciklama = aciklamalar;
}

const Kayit& Kayit::operator +(const Kayit & digerKayit) {
	if (kelime == digerKayit.kelime) {
		for (unsigned int i = 0; i < digerKayit.aciklama.size(); i++) {
			if (digerKayit.kelime != aciklama[i]) {
				aciklama.push_back(digerKayit.aciklama[i]);
			}
		}
	}
	return digerKayit;
}

const Kayit &Kayit::operator +(const string & aciklama) {
	for (unsigned int u = 0; u < aciklama.size(); u++) {
		if (aciklama != this->aciklama[u]) {
			this->aciklama.push_back(aciklama);
		}
	}
	return *this;
}



bool  Kayit::operator! () {

	return !(kelime == "" && aciklama.empty());
}

bool Kayit::operator==(const Kayit & digerKayit) {
	if (aciklama.size() == 1)
		cout << "esanlamli";
	return  (kelime == digerKayit.kelime && aciklama == digerKayit.aciklama) ? true : false;

}

bool Kayit::operator==(const string & digerKelime) {
	if (aciklama.size() == 1)
		cout << "esanlamli";

	return 	(this->kelime == digerKelime && this->aciklama == aciklama) ? true : false;
}
