// DescidaGradiente.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float learningRate;		// Taxa de aprendizado
char pow2 = 253;		// ASCII code para pot�ncia 2
char pow3 = 252;		// ASCII code para pot�ncia n
char beta = 225;		// ASCII code para beta

int mainMenu()
{
	bool inMenu = true;
	int menuPos = 1;

	while (inMenu)
	{
		cout << "|-----------                                                   ------------|" << endl;
		cout << "|------------------              Main Menu              -------------------|" << endl;
		cout << "|-----------                                                   ------------|" << endl << endl << endl;

		cout << "    Please select function to test:" << endl << endl;

		cout << " 1 -" << " x" << pow2 << endl;
		cout << " 2 -" << " x" << pow3 << " + 2x" << pow2 << " + 2 : n=3" << endl;
		cout << " 3 -" << " Exit" << endl << endl;

		cin >> menuPos;

		// Verifica tecla pressionada
		switch (menuPos) {
		case 1:
			inMenu = false;
			break;
		case 2:
			inMenu = false;
			break;
		case 3:
			inMenu = false;
			break;
		default:
			break;
		}
	}

	// Atualiza a taxa de aprendizado
	if (menuPos != 3)
	{
		learningRate = 0.0;
		while (learningRate < 0.1 || learningRate > 1)
		{
			cout << "Please type a learning rate (" << beta << ") between 0.1 and 1.0: ";
			cin >> learningRate;
		}
	}

	return menuPos;
}

// C�lculo da derivada
float calulaDerivada(float x, int func)
{
	switch (func) {
	case 1:
		return 2 * x;
		break;
	case 2:
		return (3 * pow(x,2)) + (4 * x);
		break;
	default:
		break;
	}
	
}

// C�culo da fun��o
float calulaFuncao(float x, int func)
{
	switch (func) {
	case 1:
		return pow(x, 2);
		break;
	case 2:
		return (pow(x, 3)) + (2*pow(x,2)) + 2;
		break;
	default:
		break;
	}
}

// Fun��o principal
int main()
{
	while (1)
	{
		int menu = mainMenu();					// Aciona menu principal
		bool isok = true;						// Veri�vel de controle de loop
		float x = 2;							// Vari�vel X
		float f = calulaFuncao(x, menu);		// Vari�vel para guardar o resultado da fun��o / derivada
		int i = 0;								// Vari�vel para guardar o n�mero de itera��es

		if (menu == 3) { return 0; }			// Sai do programa

		cout << "f'(x) = " << f << " | x = " << x << endl;

		while (abs(f) > 0.00000000001 && isok)			// Loop principal
		{
			float s = calulaDerivada(x, menu);		// Vari�vel que guarda o resultado da derivada
			x -= (learningRate * s);				// C�lculo do novo valor de X da itera��o
			f = calulaDerivada(x, menu);			// Atualiza o valor da derivada
			cout << "f'(x) = " << f << " | x = " << x << endl;
			i++;									// Atualiza a itera��o
			if (isinf(x)) { isok = false; }
		}

		if (abs(f) > 0.00000000001 || isinf(x) || !isok)
		{
			cout << endl << "Couldn't find solution" << endl;	// Exibe erro
		}
		else
		{
			cout << endl << "Result: x = " << x << endl;		// Exibe os resultados
			cout << "Iterations: " << i << endl;
		}
		cin.get();
		cin.get();
	}
}