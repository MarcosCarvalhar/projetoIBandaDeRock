#include <iostream>
#include <cstring>

using namespace std;

struct banda
{
	string nome, estilo;
	int id, ano, numFamosas;
};

void listar(banda *rock, int tam);
banda *incluir(banda *rock, int& tam);
banda *redimencionar(banda *rock, int& tam);
void alterar(banda *rock, int alt, int opc2);
void excluir(banda *rock, int exl, int opc2);
void ordenar(banda *vetor, int menor, int maior, int tam, int opc2);
void junta(banda *vetor, int menor, int maior, int metade, int tam, int opc2);

int main()
{
	int opc, tam = 0, exl, alt, opc2;
	banda *rock = new banda[5];

	while(opc != 6)
	{
		cout <<    "\t MENU"  << endl;
		cout << "1 - Incluir" << endl;
		cout << "2 - Exluir"  << endl;
		cout << "3 - Listar"  << endl;
		cout << "4 - Alterar" << endl;
		cout << "5 - Ordenar" << endl;
		cout << "6 - Sair"    << endl;
		cout << "Digite a opcao desejada : " << endl;	

		cin  >> opc;

		switch(opc)
		{
			case 1 : 
            	rock = incluir(rock, tam);
      		break;

			case 2 : 
            	cout << "Digite a posicao do vetor que deseja excluir : " << endl;
				cin  >> exl;
				cout << "1 - Nome | 2 - Estilo | 3 - Ano de criacao | 4 - Numero de musicas famosas | 5 - Excluir a posicao inteira" << endl;
				cout << "Digite a opcao que deseja excluir: " << endl;
				cin  >> opc2;
  		 		excluir(rock,exl,opc2);
      		break;

			case 3 : 
            	listar(rock, tam);
      		break;

			case 4 : 
           		cout << "Digite a posicao do vetor que deseja alterar : " << endl;
				cin  >> alt;
				cout << "1 - Nome | 2 - Estilo | 3 - Ano de criacao | 4 - Numero de musicas famosas | 5 - Todos os dados " << endl;
				cout << "Digite a opcao que deseja alterar: " << endl;
				cin  >> opc2;
				alterar(rock,alt,opc2);
      		break;

			case 5 :
				cout << "1 - ID | 3 - Ano de criacao | 5 - Numero de musicas famosas"<< endl;
            	cout << "Digite o tipo que deseja ordenar : " << endl;
				cin  >> opc2;
				
				ordenar(rock, 0, tam-1, tam, opc2);
				
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
	cin  >> rock[tam].estilo;

	cout << "Digite o ano de criacao :" << endl;
	cin  >> rock[tam].ano;

	cout << "Digite o numero de musicas famosas:" << endl;
	cin  >> rock[tam].numFamosas;

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
			rock[exl].id         = -1;
			rock[exl].nome       = " ";
			rock[exl].estilo     = " ";
			rock[exl].ano        = -1;
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
			cout << "\t"                           << rock[j].nome       << endl;
			cout << "ID da banda : "               << rock[j].id         << endl;
			cout << "Estilo da banda : "           << rock[j].estilo     << endl;
			cout << "Ano de criacao : "            << rock[j].ano        << endl;
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
				cin  >> rock[alt].estilo;
			break;

			case 3 : 
				cout << "Digite o ano de criacao :" << endl;
				cin  >> rock[alt].ano;
			break;

			case 4 : 
				cout << "Digite o numero de musicas famosas:" << endl;
				cin  >> rock[alt].numFamosas;
			break;

			case 5 :
				cout << "Digite o nome :" << endl;
				cin.ignore();
				getline(cin,rock[alt].nome);
				
				cout << "Digite o estilo musical :" << endl;
				cin  >> rock[alt].estilo;

				cout << "Digite o ano de criacao :" << endl;
				cin  >> rock[alt].ano;

				cout << "Digite o numero de musicas famosas:" << endl;
				cin  >> rock[alt].numFamosas;
			break;
		}
	}
}

void ordenar(banda *vetor, int menor, int maior, int tam, int opc2)
{
	int metade;

	if(menor < maior){
		metade = (menor + maior) / 2;
		ordenar(vetor, menor, metade, tam, opc2);
		ordenar(vetor, metade+1, maior, tam, opc2);
		junta(vetor, menor, maior, metade, tam, opc2);
	}
}

void junta(banda *vetor, int menor, int maior, int metade, int tam, int opc2)
{	
	banda v[tam];
	int aux1 = menor;
	int aux2 = menor;
	int aux3 = metade+1;

	int pri_Posicao, ult_Posicao;

	while (aux1 <= metade and aux3 <= maior)
	{
		switch (opc2)
		{
			case 1:
			pri_Posicao = vetor[aux1].id;
			ult_Posicao = vetor[aux3].id;
			break;

			case 3:
			pri_Posicao = vetor[aux1].ano;
			ult_Posicao = vetor[aux3].ano;
			break;

			case 5:
			pri_Posicao = vetor[aux1].numFamosas;
			ult_Posicao = vetor[aux3].numFamosas;
			break;
		}

		if (pri_Posicao < ult_Posicao) 
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

