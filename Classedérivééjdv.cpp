class JeuDeLaVieClassique : public JeuDeLaVieBase {
public:
    JeuDeLaVieClassique(int lignes, int colonnes) : JeuDeLaVieBase(lignes, colonnes) {}

    void prochaineGeneration() override {
        vector<vector<int>> nouvelleGrille = grille;

        for (int i = 0; i < lignes; ++i) {
            for (int j = 0; j < colonnes; ++j) {
                int voisinsVivants = compterVoisinsVivants(i, j);

                if (grille[i][j] == 1) {
                    if (voisinsVivants < 2 || voisinsVivants > 3) {
                        nouvelleGrille[i][j] = 0;
                    }
                } else {
                    if (voisinsVivants == 3) {
                        nouvelleGrille[i][j] = 1;
                    }
                }
            }
        }

        grille = nouvelleGrille;
    }

private:
    int compterVoisinsVivants(int ligne, int colonne) {
        int voisinsVivants = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;

                int voisinLigne = ligne + i;
                int voisinColonne = colonne + j;

                if (voisinLigne >= 0 && voisinLigne < lignes &&
                    voisinColonne >= 0 && voisinColonne < colonnes) {
                    voisinsVivants += grille[voisinLigne][voisinColonne];
                }
            }
        }
        return voisinsVivants;
    }
};
