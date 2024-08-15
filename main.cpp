#include <iostream>
#include <math.h>
#include <vector>
#include <locale.h>


using namespace std;

//vetores 

vector<float> saques;
vector<float> depositos;

//armazena valores para o historico

void guardaSaque(float valor){
	saques.push_back(valor);
}

void guardaDeposito(float valor){
	depositos.push_back(valor);
}

//funcao para realizar o saque
float sacar(float valor){
	float saque;
	cout << "Valor do Saque: R$";
	cin >> saque;
	
	
	float total =  valor - saque ;
	
	//verifica se e possivel fazer o saque
	if (valor < saque){
		cout <<"Não há como fazer esse saque!" << endl << endl;
		return valor;
		
	} else{
	
	cout << endl << "Dinheiro: " << endl;	
	
	//add o valor no vetor
	guardaSaque(saque);
	
	//variaveis para notas e moedas
	int moeda1, nota2, nota5, nota10, nota20, nota50, nota100;
	float moeda50, moeda25, moeda10, moeda5;
			
			//calculo para mostrar notas e moedas sacadas
			if (saque/ 100 >= 1){
				nota100 = abs(saque / 100);
				saque -= (100 * nota100); 
				cout << "Notas de 100: " << nota100 << endl;
			} 
			if(saque/ 50 >= 1){
				nota50 = saque/50;
				saque -= (50 * nota50); 
				cout << "Notas de 50: " << nota50 << endl;
			} 
			if(saque/20 >= 1){
				nota20 = abs(saque / 20); 
				saque -= (20 * nota20); 
				cout << "Notas de 20: " << nota20 << endl;
				
			} 
			if(saque/10 >= 1){
				nota10 = abs(saque / 10); 
				saque -= (10 * nota10); 
				cout << "Notas de 10: " << nota10 << endl;
				
			}  
			if(saque/5 >= 1){
				nota5 = abs(saque / 5); 
				saque -= (5 * nota5); 
				cout << "Notas de 5: " << nota5 << endl;
			} 
			if(saque/2 >= 1){
				nota2 = abs(saque / 2); 
				saque -= (2 * nota2); 
				cout << "Notas de 2: " << nota2 << endl;
			}
			if (saque/ 1 >= 1){
				moeda1 = abs(saque / 1);
				saque -= (1 * moeda1); 
				cout << "Moedas de 1: " << moeda1 << endl;
			} 
			if (saque/ 0.5 >= 1){
				moeda50 = abs(saque / 0.5);
				saque -= (0.5 * moeda50); 
				cout << "Moedas de 50: " << moeda50 << endl;
			}
			if (saque/ 0.25 >= 1){
				moeda25 = abs(saque / 0.25);
				saque -= (0.25 * moeda25); 
				cout << "Moedas de 25: " << moeda25 << endl;
			}
			if (saque/ 0.1 >= 1){
				moeda10 = abs(saque / 0.1);
				saque -= (0.1 * moeda10); 
				cout << "Moedas de 10: " << moeda10 << endl;
			}
			if (saque/ 0.05 >= 1){
				moeda5 = abs(saque / 0.05);
				saque -= (0.05 * moeda5); 
				cout << "Moedas de 5: " << moeda5 << endl;
			}	
				cout << endl << "Saque realizado com sucesso!" << endl << endl;			
			
}
	return total;
}


// funcao para realizar o deposito
float depositar(float saldo){
	float valor;
	
	cout << "Valor do depósito: R$";
	cin >> valor;
	saldo += valor;
	guardaDeposito(valor);
	
	cout << endl << "Deposito concluido com sucesso!" << endl << endl;
	
	return saldo;
}






//funcao para mostrar o historico
void historico() {
	
	if(saques.size() != 0){
	
		cout << "Saques: " << endl << endl;
		for (int i = saques.size() - 1; i >= 0 ; i--){
			cout << "Sacou: R$" << saques[i] << endl;
		}
	}
	
	if (depositos.size() != 0){
		cout << endl <<  "Depositos: " << endl << endl;
		for (int i = depositos.size() - 1; i >= 0 ; i--){
			cout << "Depositou: R$" << depositos[i] << endl;
		}
	}
}

//funcao para mostra o extrato
void extrato(float saldo){
	cout << "Total - R$" << saldo << endl;
	cout << endl << endl <<"EXTRATO" << endl << endl;
	
	if(saques.size() == 0 && depositos.size() == 0){
		cout << "Não houve nenhuma transação!" << endl << endl;
	} else{
	
	
	historico();
	}
	cout << endl;
}

int main(){
	setlocale(LC_ALL, "portuguese");
	//variaveis iniciais
	int tecla;
	float conta = 100; 
	
	//inicio do programa
	do{
		system("cls");
		cout << "BANCO ELETRÔNICO!" << endl << endl;
		cout << "Total: R$" << conta << endl << endl;
		cout << "1- Sacar \n2- Depositar \n3- Extrato \n4- Sair" << endl << endl;
		cout << "Opção: ";
		cin >> tecla;
		//case para cada opcao
		switch (tecla){
			case 1:
				system("cls");
				cout << "Total: R$" << conta << endl << endl;
				conta = sacar(conta);
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Total: R$" << conta << endl << endl;
				conta = depositar(conta);
				system("pause");
				break;
			case 3:
				system("cls");
				extrato(conta);
				system("pause");
				break;
			case 4:
				exit(0);
			default:
				cout << "Digite outra opção!" << endl;
				system ("pause");
			} 	
	} while(tecla != 4);
		
	return 0;
	
}
