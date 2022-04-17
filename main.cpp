#include <iostream>
#include <cstring>

using namespace std;

struct banda
{
	int id, ano, numFamosas;
	string nome, estilo;
};

void junta(banda *vetor, int menor, int maior, int metade, int tam);
void ordenar(banda *vetor, int menor, int maior, int tam);
void excluir(banda *rock, int exl, int opc2);
void alterar(banda *rock, int alt, int opc2);
banda *redimencionar(banda *rock, int& tam);
banda *incluir(banda *rock, int& tam);
void listar(banda *rock, int tam);

int main()
{
	int opc, tam = 0, exl, alt, opc2;
	banda *rock = new banda[5];
	while(opc != 6)
	{
		cout << "\t MENU" << endl;
		cout << "1 - Incluir" << endl;
		cout << "2 - Exluir" << endl;
		cout << "3 - Listar" << endl;
		cout << "4 - Alterar" << endl;
		cout << "5 - Ordenar" << endl;
		cout << "6 - Sair" << endl;
		cout << "Digite a opcao desejada : " << endl;	
		cin >> opc;
		switch(opc)
		{
			case 1 : 
            	rock = incluir(rock, tam);
      			break;
			case 2 : 
            	cout << "Digite a posicao do vetor que deseja excluir : " << endl;
				cin >> exl;
				cout << "1 - Nome | 2 - Estilo | 3 - Ano de criacao | 4 - Numero de musicas famosas | 5 - Excluir a posicao inteira" << endl;
				cout << "Digite a opcao que deseja excluir: " << endl;
				cin >> opc2;
  		 		excluir(rock,exl,opc2);
      			break;
			case 3 : 
            	listar(rock, tam);
      			break;
			case 4 : 
           		cout << "Digite a posicao do vetor que deseja alterar : " << endl;
				cin >> alt;
				cout << "1 - Nome | 2 - Estilo | 3 - Ano de criacao | 4 - Numero de musicas famosas | 5 - Todos os dados " << endl;
				cout << "Digite a opcao que deseja alterar: " << endl;
				cin >> opc2;
				alterar(rock,alt,opc2);
      			break;
			case 5 :
            	ordenar(rock, 0, tam-1, tam);
      			break;
		}
	}
	return 0;
}

banda* redimencionar(banda *rock, int& tam)
{
	banda *aux = new banda[tam+1];
	memcpy(aux, rock, sizeof(banda)*tam);
	delete []rock;
	rock = NULL;
	return aux;
}

banda* incluir(banda *rock, int& tam)
{
	if(tam >= 5)
	{	
		rock = redimencionar(rock,tam);
	}
	rock[tam].id = tam + 1;
	cout << "Digite o nome :" << endl;
	cin.ignore();
	getline(cin,rock[tam].nome);
	cout << "Digite o estilo musical :" << endl;
	cin >> rock[tam].estilo;
	cout << "Digite o ano de criacao :" << endl;
	cin >> rock[tam].ano;
	cout << "Digite o numero de musicas famosas:" << endl;
	cin >> rock[tam].numFamosas;
	tam++;

	return rock;
}


void excluir(banda *rock, int exl, int opc2)
{	
	switch(opc2)
	{
		case 1 : 
			rock[exl].nome = " ";
			break;
		case 2 : 
			rock[exl].estilo = " ";
			break;
		case 3 : 
			rock[exl].ano = -1;
			break;
		case 4 : 
			rock[exl].numFamosas = -1;
			break;
		case 5 : 
			rock[exl].id = -1;
			rock[exl].nome = " ";
			rock[exl].estilo = " ";
			rock[exl].ano = -1;
			rock[exl].numFamosas = -1;
			break;
	}
}

void listar(banda *rock, int tam)
{
	for(int j = 0; j < tam; j++)
	{
		if(rock[j].id != -1)
		{
			cout << "\t" << rock[j].nome << endl;
			cout << "ID da banda : " << rock[j].id << endl;
			cout << "Estilo da banda : " << rock[j].estilo << endl;
			cout << "Ano de criacao : " << rock[j].ano << endl;
			cout << "Numero de musicas famosas : " << rock[j].numFamosas << endl;
			cout << endl;
		}
	}
}

void alterar(banda *rock, int alt, int opc2)
{
	if(rock[alt].id == -1)
	{
				cout << "Essa posicao foi excluida, portanto nao pode ser alterada!" << endl;
	}
	else
	{
		switch(opc2)
		{
			case 1 : 
				cout << "Digite o nome :" << endl;
				cin.ignore();
				getline(cin,rock[alt].nome);
				break;
			case 2 : 
				cout << "Digite o estilo musical :" << endl;
				cin >> rock[alt].estilo;
				break;
			case 3 : 
				cout << "Digite o ano de criacao :" << endl;
				cin >> rock[alt].ano;
				break;
			case 4 : 
				cout << "Digite o numero de musicas famosas:" << endl;
				cin >> rock[alt].numFamosas;
				break;
			case 5 :
				cout << "Digite o nome :" << endl;
				cin.ignore();
				getline(cin,rock[alt].nome);
				cout << "Digite o estilo musical :" << endl;
				cin >> rock[alt].estilo;
				cout << "Digite o ano de criacao :" << endl;
				cin >> rock[alt].ano;
				cout << "Digite o numero de musicas famosas:" << endl;
				cin >> rock[alt].numFamosas;
		}
	}
}

void junta(banda *vetor, int menor, int maior, int metade, int tam)
{	
	int aux1, aux2, aux3;
	aux1 = menor;
	aux2 = menor;
	aux3 = metade+1;
	banda v[tam];

	while (aux1 <= metade and aux3 <= maior)
	{
		if (vetor[aux1].ano < vetor[aux3].ano) 
		{
			v[aux2] = vetor[aux1];
			aux1++;
			aux2++;
		}
		else
		{
			v[aux2] = vetor[aux3];
			aux2++;
			aux3++;
		}
	}
	while (aux1 <= metade) 
	{
		v[aux2] = vetor[aux1];
		aux2++;
		aux1++;
	}
	while (aux3 <= maior) 
	{
		v[aux2] = vetor[aux3];
		aux2++;
		aux3++;
	}
    for (int i = menor; i < aux2; i++)
	{
        vetor[i] = v[i];
    }	
}

void ordenar(banda *vetor, int menor, int maior, int tam)
{
	int metade;
	if(menor < maior){
		metade = (menor + maior) / 2;
		ordenar(vetor, menor, metade, tam);
		ordenar(vetor, metade+1, maior, tam);
		junta(vetor, menor, maior, metade, tam);
	}
}
