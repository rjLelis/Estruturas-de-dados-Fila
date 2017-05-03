#include<iostream>
#include<stdlib.h>
using namespace std;

struct itemFila{
	int valor;
	struct itemFila *prox;
}*prim,*ult,*primaux,*ultaux;

void enfileirar(int valor);
void desinfileirar();
int cabeca();

void enfileirarAux(int valor);
void desinfileirarAux();
int cabecaAux();

int verifica(int v);
int ContaValor(int v);
void esvaziar();
int ContaElementos();
void contaPares();

main(){
	int op,v;
	do{
		system("CLS");
		cout << "1 - Enfileirar\n";
		cout << "2 - Desinfileirar\n";
		cout << "3 - Primeiro na fila\n";
		cout << "4 - Verificar se um valor esta na fila\n";
		cout << "5 - Verificar quantas vezes um valor se repete na lista\n";
		cout << "6 - Esvaziar lista\n";
		cout << "7 - Contar os elementos da fila\n";
		cout << "8 - Mostrar os elementos pares na fila\n";
		cout << "0 - Sair\n";
		cout << ">>> ";
		cin >> op;
		if(op == 1){
			system("CLS");
			cout << "Digite um numero para enfileirar: ";
			cin >> v;
			enfileirar(v);
		} else if(op == 2){
			system("CLS");
			if(cabeca() != -1){
				cout << "O valor " << cabeca() << " saiu da fila\n";
				desinfileirar();
			} else{
				cout << "Fila vazia\n";
			}
			system("pause");
		} else if(op == 3){
			system("CLS");
			if(cabeca() != -1){
				cout << "O valor " << cabeca() << " e o primeiro da fila\n";
			} else{
				cout << "Fila vazia\n";
			}
			system("pause");
		} else if(op == 4){
			system("CLS");
			if(cabeca() != -1){
				cout << "Digite um valor para verificar: ";
				cin >> v;
				if(verifica(v) == 1){
					cout << "O valor digitado ESTA na fila\n";
				} else{
					cout << "O valor digitado NAO ESTA na fila\n";
				}
			} else{
				cout << "Fila vazia\n";
			}
			system("pause");
		} else if(op == 5){
			system("CLS");
			if(cabeca() != -1){
				cout << "Digite um valor para verificar: ";
				cin >> v;
				cout << "O valor digitado se repete " << ContaValor(v) << " veze(s)\n";
			} else{
				cout << "Fila vazia\n";
			}
			system("pause");
		} else if(op == 6){
			system("CLS");
			if(cabeca() != -1){
				esvaziar();
				cout << "Fila Esvaziada\n";
			}
			else{
				cout << "A fila ja esta vazia\n";
			}
			system("pause");
		} else if(op == 7){
			system("CLS");
			if(cabeca() != -1){
				cout << "A fila tem " << ContaElementos() << " elementos\n";
			} else{
				cout << "Fila vazia\n";
			}
			system("pause");
		} else if(op == 8){
			system("CLS");
			if(cabeca() != -1){
				cout << "Numeros pares: \n";
				contaPares();
			} else{
				cout << "Fila vazia\n";
			}
			system("pause");
		}
	}while(op != 0);
}

void enfileirar(int valor){
	struct itemFila *aux;
	aux = (struct itemFila *) malloc(sizeof(struct itemFila));
	if(!prim)
		prim = aux;
	else
		ult->prox = aux;
	ult = aux;
	ult->valor = valor;
	ult->prox = NULL;	
}

void desinfileirar(){
	struct itemFila *aux;
	if(!prim){
		cout << "Fila vazia\n";
	} else{
		aux = prim;
		if(prim == ult){
			prim = ult = NULL;
		}
		else{
			prim = prim->prox;
		}
		free(aux);
	}
}

int cabeca(){
	if(!prim)
		return (-1);
	else
		return (prim->valor);
}

void enfileirarAux(int valor){
	struct itemFila *aux;
	aux = (struct itemFila *) malloc(sizeof(struct itemFila));
	if(!primaux)
		primaux = aux;
	else
		ultaux->prox = aux;
	ultaux = aux;
	ultaux->valor = valor;
	ultaux->prox = NULL;	
}

void desinfileirarAux(){
	struct itemFila *aux;
	if(!primaux)
		cout << "Fila vazia\n";
	else{
		aux = primaux;
		if(primaux == ultaux)	{
			primaux = ultaux = NULL;
		} else{
			primaux = primaux->prox;
		}
		free(aux);
	}
}

int cabecaAux(){
	if(!primaux)
		return (-1);
	else
		return (primaux->valor);
}

int verifica(int v){
	int ret = -1, achei = 0;
	primaux = ultaux = NULL;
	while(cabeca() != -1){
		ret = cabeca();
		if(ret == v)
			achei = 1;
		enfileirarAux(cabeca());
		desinfileirar();
	}
	while(cabecaAux() != -1){
		enfileirar(cabecaAux());
		desinfileirarAux();
	}
	if(achei == 1)
		return (1);
	else
		return (0);
}

int ContaValor(int v){
	int c = 0,aux = -1;
	primaux = ultaux = NULL;
	while(cabeca() != -1){
		aux = cabeca();
		if(aux == v)
			c++;
		enfileirarAux(cabeca());
		desinfileirar();
	}
	while(cabecaAux() != -1){
		enfileirar(cabecaAux());
		desinfileirarAux();
	}
	return c;
}

void esvaziar(){
	while(cabeca() != -1){
		desinfileirar();
	}
}

int ContaElementos(){
	int c = 0,aux = -1;
	primaux = ultaux = NULL;
	while(cabeca() != -1){
		aux = cabeca();
		c++;
		enfileirarAux(cabeca());
		desinfileirar();
	}
	while(cabecaAux() != -1){
		enfileirar(cabecaAux());
		desinfileirarAux();
	}
	return c;
}

void contaPares(){
	int aux = -1;
	primaux = ultaux = NULL;
	while(cabeca() != -1){
		aux = cabeca();
		if(aux % 2 == 0){
			cout << aux << "\n";
		}
		enfileirarAux(cabeca());
		desinfileirar();
	}
	while(cabecaAux() != -1){
		enfileirar(cabecaAux());
		desinfileirarAux();
	}
}
