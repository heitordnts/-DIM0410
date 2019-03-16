#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void insertElement(int e, queue<int> f, vector< vector<int> > t){

}

int main(){
	queue<int> fila;
	vector<vector<int> > times;
	string cmd;
	int t = 1, tam = 0;


	vector<int> aux;
	int e;
	while(t > 0){
		cin >> t;
		//preechendo times
		for(int i = 0;i < t;i++){
			cin >> tam;
			for(int j=0; j < tam; j++){
				cin >> e;
				aux.push_back(e);
			}
			times.push_back(aux);
			aux.clear();
		}
		int element;
		//receber comandos
		while(t > 0){
			cin >> cmd;
				
			if(!cmd.compare("ENQUEUE")){
				cin >> element;
				insertElement(element,fila,times);
			}
			else if(!cmd.compare("DEQUEUE")){
				fila.pop();	
			}
			else if(!cmd.compare("STOP")){
				break;
			}
		}
	}
	return 0;
}
