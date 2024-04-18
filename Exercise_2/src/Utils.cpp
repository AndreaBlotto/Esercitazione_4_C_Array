#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportaVettori(const string& FileInput, double& S, size_t& n, double*& w, double*& r){
    // apro il file
    ifstream file;
    file.open(FileInput);
    // controllo se aperto correttamente
    if (file.fail())
    {
        cerr<< "file non aperto correttamente"<< endl;
        return false;
    }
    // Salvo la somma totale
    string line;
    string inutile;
    getline(file, inutile, ';');
    getline(file, line);
    istringstream ConvertS;
    ConvertS.str(line);
    ConvertS >> S;

    // Salvo la grandezza
    getline(file, inutile, ';');
    getline(file, line);
    istringstream ConvertN;
    ConvertN.str(line);
    ConvertN >> n;

    // Leggo il commento della terza riga
    string header;
    getline(file, header);

    // Metto dentro i vettori w e r i valori letti dal file tramite un ciclo for di lunghezza n (grandezza dei vettori)
    string frazione;
    string revenue;
    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i < n; i++)
    {
        getline(file, frazione, ';');
        getline(file, revenue);

        istringstream convertW;
        istringstream convertR;

        convertW.str(frazione);
        convertR.str(revenue);

        convertW >> w[i];
        convertR >> r[i];
    }

    // Chiudo il file
    file.close();
    return true;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)  // Ciclo sugli elementi del vettore v
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}

double TassoDiInteresse(const size_t& n,
                        const double* const& w,
                        const double* const& r,
                        double& V,
                        const double& S)
{
    double TassoDiInteresse = 0; // lo calcolo come un prodotto vettoriale tra w e r
    for (unsigned int i = 0; i < n; i++)
        TassoDiInteresse += w[i] * r[i];
    V = (1 + TassoDiInteresse) * S;
    return TassoDiInteresse;
}

bool EsportaRisultati(const string& outputFilePath,
                      const size_t& n,
                      const double* const& w,
                      const double* const& r,
                      const double& dotProduct,
                      const double& S,
                      const double& V)
{
    // Apro il file
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // scrivo ciò che richiesto, facendo attenzione agli zeri decimali tramite fixed e setprecision
    file<< fixed << setprecision(2) << "S = "<< S << ", n = " << n<< endl;

    file<< "w = "<< ArrayToString(n, w) << endl;

    file<< "r = "<< ArrayToString(n, r) << endl;

    file<< setprecision(4) << "Rate of return of the portfolio: "<< dotProduct << endl;

    file << fixed << setprecision(2) << "V: " << V << endl;

    // Chiudo il file
    file.close();

    return true;
}

