#include <iostream>
#include <cstring>

using namespace std;

// Criação da estrura de bandas. 
struct banda
{
	string nome, estilo;
	int id, ano, numFamosas;
};


// Escopo das funções utilizadas.
void listar(banda *rock, int tam);
banda *incluir(banda *rock, int& tam);
banda *redimencionar(banda *rock, int& tam);
void alterar(banda *rock, int alt, int opc2);
void excluir(banda *rock, int exl, int opc2);
void ordenar(banda *vetor, int menor, int maior, int tam, int opc2);
void junta(banda *vetor, int menor, int maior, int metade, int tam, int opc2);

// Programa principal.
// Todos
int main()
{
	// Declaração de variáveis.
	int opc, tam = 0, exl, alt, opc2;
	banda *rock = new banda[5];
	// Exibição do menu e suas funcionalidades.
	while(opc != 6)
	{
		cout <<    "\t MENU"  << endl;
		cout << "1 - Incluir" << endl;	// Inclui um novo elemento no vetor.
		cout << "2 - Exluir"  << endl;	// Exclui um elemento ou campo de uma posição do vetor.
		cout << "3 - Listar"  << endl;	// Lista os elementos do vetor.
		cout << "4 - Alterar" << endl;	// Altera um elemento ou uma posição inteira do vetor.
		cout << "5 - Ordenar" << endl;	// Ordena o vetor com base na escolha do usuário.
		cout << "6 - Sair"    << endl;	// Sair do menu e do programa.
		cout << "Digite a opcao desejada : " << endl;	
		cin  >> opc;
		switch(opc)
		{
			case 1 : 
            	rock = incluir(rock, tam);	// Chamada da função para preencher uma posição do vetor, retornando o vetor rock.
      		break;
			case 2 : 
				// Exclui um elemento ou campo específico fornecido pelo usuário do vetor.
            	cout << "Digite a posicao do vetor que deseja excluir : " << endl;
				cin  >> exl;
				cout << "1 - Nome | 2 - Estilo | 3 - Ano de criacao | 4 - Numero de musicas famosas | 5 - Excluir a posicao inteira" << endl;
				cout << "Digite a opcao que deseja excluir: " << endl;
				cin  >> opc2;
  		 		excluir(rock,exl,opc2);
      		break;
			case 3 : 
            	listar(rock, tam);	// Chamada da função para listar e apresentar o vetor.
      		break;
			case 4 : 
				// Altera um elemento ou campo específico fornecido pelo usuário do vetor.
           		cout << "Digite a posicao do vetor que deseja alterar : " << endl;
				cin  >> alt;
				cout << "1 - Nome | 2 - Estilo | 3 - Ano de criacao | 4 - Numero de musicas famosas | 5 - Todos os dados " << endl;
				cout << "Digite a opcao que deseja alterar: " << endl;
				cin  >> opc2;
				alterar(rock,alt,opc2);
      		break;
			case 5 :
				// Ordena o vetor com base nos parâmetros do usuário.
				cout << "1 - ID | 3 - Ano de criacao | 5 - Numero de musicas famosas"<< endl;
            	cout << "Digite o tipo que deseja ordenar : " << endl;
				cin  >> opc2;				
				ordenar(rock, 0, tam-1, tam, opc2);		
      		break;
		}
	}
	return 0;
}

// Função redimencionar, recebe um vetor e seu tamanho e aumenta sua posição em uma, e retorna o vetor.
// Marcos e Marcus
banda* redimencionar(banda *rock, int& tam)
{
	float p = tam + (tam * 0.2);
	banda *aux = new banda[(int)p];		   // cria um vetor auxiliar com tamanho 20% maior.
	memcpy(aux, rock, sizeof(banda)*tam);  // copia o vetor principal pro novo vetor auxiliar.
	delete []rock;                         // apaga o vetor principal.
	rock = NULL;                           // adiciona valor NULL para vetor principal.
	return aux;                            // retorna o vetor auxiliar no lugar do vetor principal.
}

// Função incluir, recebe um vetor e sua posição e a preenche.
// Marcus
banda* incluir(banda *rock, int& tam)
{
	// Se o vetor for maior ou igual a 5, chama a função redimencionar para aumentar o tamanho do vetor.
	if(tam >= 5)
	{	
		rock = redimencionar(rock,tam);
	}
	// Preenchimento do campo id da estruta banda, através de um contador.
	rock[tam].id = tam + 1;
	// Preenchimento das outras variáveis da estrura banda.
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

// Função excluir, exclui uma posição inteira do vetor ou campo especifico à marcando com uma flag, -1 para os campos int, e um espaço em branco para os campos string.
// Recebe um vetor de rock e a posição que será excluída.
// Marcus
void excluir(banda *rock, int exl, int opc2)
{	
	switch(opc2)
	{
		// Excluí o campo nome de uma posição específica do vetor.
		case 1 : 
			rock[exl].nome = " ";
		break;
		// Excluí o campo estilo musical de uma posição específica do vetor.
		case 2 : 
			rock[exl].estilo = " ";
		break;
		// Excluí o campo ano de criação de uma posição específica do vetor.
		case 3 : 
			rock[exl].ano = -1;
		break;
		// Excluí o campo numero de músicas famosas de uma posição específica do vetor.
		case 4 : 
			rock[exl].numFamosas = -1;
		break;
		// Excluí todos os campos de uma posição específica do vetor.
		case 5 : 
			rock[exl].id         = -1;
			rock[exl].nome       = " ";
			rock[exl].estilo     = " ";
			rock[exl].ano        = -1;
			rock[exl].numFamosas = -1;
		break;
	}
}

// Recebe um vetor e seu tamanho e lista as posições preenchidas, exibindo suas informações, através de um laço
// Marcus
void listar(banda *rock, int tam)
{
	for(int j = 0; j < tam; j++)
	{
		// Caso o campo ID esteja marcado pela fla, -1, essa posição do vetor não será exibida
		if(rock[j].id != -1)
		{
			cout << "\t"                           << rock[j].nome       << endl;
			cout << "ID da banda : "               << rock[j].id         << endl;
			cout << "Estilo da banda : "           << rock[j].estilo     << endl;
			cout << "Ano de criacao : "            << rock[j].ano        << endl;
			cout << "Numero de musicas famosas : " << rock[j].numFamosas << endl;
			cout << "Posicao no vetor : " <<  rock[j].id - 1 << endl;
			cout << endl;
		}
	}
}

// Função alterar, recebe um vetor, a posição que deseja alterar e qual campo
// Marcus
void alterar(banda *rock, int alt, int opc2)
{
	// Caso o campo ID esteja marcado pela fla, -1, essa posição não poderá ser alterada, pois foi excluída
	if(rock[alt].id == -1)
	{
		cout << "Essa posicao foi excluida, portanto nao pode ser alterada!" << endl;
	}
	else
	{
		switch(opc2)
		{
			// Altera o campo nome de uma posição específica do vetor.
			case 1 : 
				cout << "Digite o nome :" << endl;
				cin.ignore();
				getline(cin,rock[alt].nome);
			break;
			// Altera o campo estilo musical de uma posição específica do vetor.
			case 2 : 
				cout << "Digite o estilo musical :" << endl;
				cin  >> rock[alt].estilo;
			break;
			// Altera o campo ano de criação de uma posição específica do vetor.
			case 3 : 
				cout << "Digite o ano de criacao :" << endl;
				cin  >> rock[alt].ano;
			break;
			// Altera o campo numero de músicas famosas de uma posição específica do vetor.
			case 4 : 
				cout << "Digite o numero de musicas famosas:" << endl;
				cin  >> rock[alt].numFamosas;
			break;
			// Altera todos os campo de uma posição específica do vetor.
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

// Função para ordenar o vetor com base na opção escolhida pelo usuário
// Recebe o vetor de rock e seu tamanho, o menor e o maior campo e a opção com o campo na qual o vetor será será ordenado
// Marcos e Hudson

// Ordenação Merge Sort
void ordenar(banda *vetor, int menor, int maior, int tam, int opc2)
{
	// Divide o vetor até que cada vetor menor tenha um unico elemento
	int metade;
	if(menor < maior)
	{
		metade = (menor + maior) / 2;
		ordenar(vetor, menor, metade, tam, opc2);
		ordenar(vetor, metade+1, maior, tam, opc2);
		junta(vetor, menor, maior, metade, tam, opc2); 
	}
}

void junta(banda *vetor, int menor, int maior, int metade, int tam, int opc2)
{	
	// Junta dois vetores obtendo um vetor maior ordenado
	banda v[tam];
	int aux1 = menor;
	int aux2 = menor;
	int aux3 = metade+1;
	int pri_Posicao, ult_Posicao;
	while (aux1 <= metade and aux3 <= maior)
	{
		switch (opc2)
		{
			// seleciona o tipo de ordenação
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
