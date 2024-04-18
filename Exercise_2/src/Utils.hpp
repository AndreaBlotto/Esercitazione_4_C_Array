#pragma once
#include "iostream"

using namespace std;

// Scrivo una funzione che mi permetta di aprire i file e tradurrre i due vettori, uno della frazione della somma totale e l'altro dei profitti,
// che legga anche la somma totale di partenza e la grandezza dei vettori:
// S: somma totale; n: numero di assets o grandezza vettori; w: vettore delle frazioni; r: vettore dei profitti;
// Se ritrona true vuol dire che è stato possibile leggere il file e salvare i dati, altrimenti false
bool ImportaVettori(const string& FileInput, double& S, size_t& n, double*& w, double*& r);

// Scrivo una funzione che mi permetta di scrivere il vettore v passato come parametro di lunghezza n
string ArrayToString(const size_t& n,
                     const double* const& v);

// Scrivo una funzione che  mi permetta, tramite i vettori w e r, di calcolare il tasso di rendimento del portfolio tramite il prodotto scalare dei
// vettori w e r, con cui tramite la somma iniziale investita S trovo il valore totale del portfolio V alla fine del periodo
double TassoDiInteresse(const size_t& n,
                        const double* const& w,
                        const double* const& r,
                        double& V,
                        const double& S);

// Scrivo una funzione che mi permetta di scrivere in un file di output le righe richieste dall'esercizio
bool EsportaRisultati(const string& outputFilePath,
                      const size_t& n,
                      const double* const& w,
                      const double* const& r,
                      const double& dotProduct,
                      const double& S,
                      const double& V);

