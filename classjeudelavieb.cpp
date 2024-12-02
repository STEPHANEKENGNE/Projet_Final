#include <iostream>
#include <vector>
using namespace std;

// Classe de base abstraite
class JeuDeLaVieBase {
protected:
    vector<vector<int>> grille;
    int lignes, colonnes;

public:
    JeuDeLaVieBase(int lignes, int colonnes) : lignes(lignes), colonnes(colonnes) {
        grille.resize(lignes, vector<int>(colonnes, 0));
    }

    virtual ~JeuDeLaVieBase() {}

    virtual void prochaineGeneration() = 0; // Méthode virtuelle pure

    void chargerEtatInitial() {
        cout << "Entrez l'état initial de la grille (" << lignes << "x" << colonnes << ") :\n";
        for (int i = 0; i < lignes; ++i) {
            for (int j = 0; j < colonnes; ++j) {
                cin >> grille[i][j];
                if (grille[i][j] != 0 && grille[i][j] != 1) {
                    cout << "Erreur : seules les valeurs 0 ou 1 sont autorisées.\n";
                    exit(1);
                }
            }
        }
    }

    void afficherGrille() {
        cout << "État actuel de la grille :\n";
        for (const auto& ligne : grille) {
            for (int cellule : ligne) {
                cout << cellule << " ";
            }
            cout << endl;
        }
    }
};
