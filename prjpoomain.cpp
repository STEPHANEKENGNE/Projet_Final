#include <iostream>
#include <vector>

using namespace std;

int main() {
    int lignes, colonnes, generations, choix;

    cout << "Entrez le nombre de lignes : ";
    cin >> lignes;
    cout << "Entrez le nombre de colonnes : ";
    cin >> colonnes;
    cout << "Entrez le nombre de générations : ";
    cin >> generations;

    cout << "Choisissez la variante du jeu (1 : Classique, 2 : Personnalisé) : ";
    cin >> choix;

    JeuDeLaVieBase* jeu = nullptr;

    if (choix == 1) {
        jeu = new JeuDeLaVieClassique(lignes, colonnes);
    } else if (choix == 2) {
        jeu = new JeuDeLaViePersonnalise(lignes, colonnes);
    } else {
        cout << "Choix invalide.\n";
        return 1;
    }

    jeu->chargerEtatInitial();

    for (int gen = 0; gen < generations; ++gen) {
        cout << "Génération " << gen + 1 << " :\n";
        jeu->afficherGrille();
        jeu->prochaineGeneration();
    }

    cout << "Simulation terminée.\n";
    delete jeu;
    return 0;
}

