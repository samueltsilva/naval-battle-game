#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;


// Recebe o numero de embarcacoes do usuario
int n_barcos() {
	int i;
	cout << "Bem vindo ao jogo batalha Naval!! \n" << "Entre com o numero de embarcacoes entre 5 e 15 que deseja jogar: " << endl;
	cin >> i;
	if (i < 5 || i>15) {
		i = 5 + rand() % 10;
	}
	cout << "Numero de navios e: " << i << endl;
	return i;
}

// Zerar o tabuleiro para o inicio do jogo
void zera_tabuleiro(char matriz[][10]) {
	int i, j;
	i = 0;
	j = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			matriz[i][j] = 'x';
		}
	}
}
// Preencher com agua a matriz
void zera_tabuleiro2(char matriz[][10]) {
	int i, j;
	i = 0;
	j = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			matriz[i][j] = '~';
		}
	}
}

// Exibir matriz em branco para o jogo
void exibir2(char matriz[][10]) {
	int i, j;
	i = 0;
	j = 0;
	cout << " 0123456789" << endl;
	for (i = 0; i < 10; i++) {
		cout << i;
		for (j = 0; j < 10; j++) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
}

//Exibir matriz limpa
void exibir(char matriz2[][10]) {
	int i, j;

	cout << " 0123456789" << endl;
	for (i = 0; i < 10; i++) {
		cout << i;
		for (j = 0; j < 10; j++) {
			if (matriz2[i][j] == 'x') {
				cout << ' ';
			}
			else {
				cout << matriz2[i][j];
			}
		}
		cout << endl;
	}
}

//Sorteia os tipos das embarcacoes e suas respectivas posicoes
void embarcacoes(char matriz[10][10]) {
	int l, c, f, range, erro = 0;
	int a = n_barcos();
	while (a != 0) {
		erro = 0;
		int h = rand() % 5;


		switch (h) {
		case 0:
			l = rand() % 10; c = rand() % 10;
			if (c == 9) {
				range = 1 - 1;

			}
			else {
				range = 1;
			}

			if (matriz[l][c] == '~') {
				if (matriz[l][c - 1] == '~' || c == 0) {
					for (f = c; f <= c + range; f++) {
						if (matriz[l][f + 1] != '~') {
							erro = 1;
							break;

						}
					}
					if (erro == 0) {
						for (f = c; f < c + 1; f++) {
							matriz[l][f] = 's';

						}
						a--;
					}
				}
			}

			break;

		case 1:
			l = rand() % 10; c = rand() % 9;
			if (c + 1 == 9) {
				range = 2 - 1;

			}
			else {
				range = 2;
			}

			if (matriz[l][c] == '~') {
				if (matriz[l][c - 1] == '~' || c == 0) {
					for (f = c; f <= c + range; f++) {
						if (matriz[l][f] != '~') {
							erro = 1;
							break;

						}
					}
					if (erro == 0) {
						for (f = c; f < c + 2; f++) {
							matriz[l][f] = 'c';

						}
						a--;
					}
				}
			}

			break;

		case 2:
			l = rand() % 10; c = rand() % 8;
			if (c + 2 == 9) {
				range = 3 - 1;

			}
			else {
				range = 3;
			}

			if (matriz[l][c] == '~') {
				if (matriz[l][c - 1] == '~' || c == 0) {
					for (f = c; f <= c + range; f++) {
						if (matriz[l][f] != '~') {
							erro = 1;
							break;

						}
					}
					if (erro == 0) {
						for (f = c; f < c + 3; f++) {
							matriz[l][f] = 'd';

						}
						a--;
					}
				}
			}

			break;

		case 3:
			l = rand() % 10; c = rand() % 7;
			if (c + 3 == 9) {
				range = 4 - 1;

			}
			else {
				range = 4;
			}

			if (matriz[l][c] == '~') {
				if (matriz[l][c - 1] == '~' || c == 0) {
					for (f = c; f <= c + range; f++) {
						if (matriz[l][f] != '~') {
							erro = 1;
							break;

						}
					}
					if (erro == 0) {
						for (f = c; f < c + 4; f++) {
							matriz[l][f] = 'e';

						}
						a--;
					}
				}
			}

			break;

		case 4:
			l = rand() % 10; c = rand() % 6;
			if (c + 4 == 9) {
				range = 5 - 1;

			}
			else {
				range = 5;
			}

			if (matriz[l][c] == '~') {
				if (matriz[l][c - 1] == '~' || c == 0) {
					for (f = c; f <= c + range; f++) {
						if (matriz[l][f] != '~') {
							erro = 1;
							break;

						}
					}
					if (erro == 0) {
						for (f = c; f < c + 5; f++) {
							matriz[l][f] = 'p';

						}
						a--;
					}
				}
			}

			break;
		}
	}
}
//Testar em qual embarcacao o usuario acertou os tiros
void dar_bala_posicao(int bala[2], char matriz2[10][10], char matriz[10][10]) {
	bool win = false;
	int pontos = 0;
	int pontoc = 0;
	int pontod = 0;
	int pontoe = 0;
	int pontop = 0;
	int quant_bala = 0;
	//Sistema de tiros
	while (quant_bala != 5 && win == false) {
		cout << endl;
		cout << "Entre com a linha a ser atingida : " << endl;
		cin >> bala[0];
		cout << "Entre com a coluna a ser atingida : " << endl;
		cin >> bala[1];
		cout << endl;
		matriz2[bala[0]][bala[1]] = matriz[bala[0]][bala[1]];
		exibir(matriz2);

		if (matriz2[bala[0]][bala[1]] == 'p') {
			pontop++;
		}
		if (matriz2[bala[0]][bala[1]] == 'e') {
			pontoe++;
		}
		if (matriz2[bala[0]][bala[1]] == 'd') {
			pontod++;
		}
		if (matriz2[bala[0]][bala[1]] == 'c') {
			pontoc++;
		}
		if (matriz2[bala[0]][bala[1]] == 's') {
			pontos++;
		}

		if (pontop == 5 || pontoe == 4 || pontod == 3 || pontoc == 2 || pontos == 1)
		{
			win = true;
		}
		quant_bala++;
	}
	if (win == true)
	{
		cout << "Parabens, voce venceu com " << quant_bala << " tiros\n" << endl;
		exibir(matriz);
	}
	else {
		{
			cout << "Que pena, voce perdeu\n" << endl;
			exibir(matriz);
		}
	}
}
// Chamando as funcoes para a funcao principal
int main() {
	int restart = 1;
	while (restart == 1)
	{
		int quant_bala = 0;
		char matriz[10][10];
		int bala[2];
		char matriz2[10][10];
		srand((unsigned)time(NULL));
		zera_tabuleiro(matriz2);
		zera_tabuleiro2(matriz);
		embarcacoes(matriz);

		dar_bala_posicao(bala, matriz2, matriz);
		cout << "Para recomecar digite 1, para encerrar digite um numero qualquer: ";
		cin >> restart;
	}
	return(0);
}







