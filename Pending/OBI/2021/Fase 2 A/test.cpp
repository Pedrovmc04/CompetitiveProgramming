#include <iostream> // cin e cout
#include <cstdio> // scanf e printf
#include <map> // map
#include <string> // string

using namespace std;

int n;

// declaro um map de nome mapa, que tem uma string como chave e guarda uma double em cada posição
map<string, int> mapa;

int main(){
	
	cin >> n; // leio o valor de n
	
	for(int i=1; i<=n; i++){ // e para cada pagamento
		
		// declaro e leio o nome e o valor da conta do pagamento
		string conta;
		int valor;
		
		cin >> conta >> valor;
		
		// se tal conta já existir no vetor de contas, apenas adiciono o valor pago na sua posição
		if(mapa.find(conta)!=mapa.end()) mapa[conta]+=valor;
		
		// caso contrário, crio a nova posição conta e salvo nela o valor lido
		else mapa[conta]=valor; 
	}
	
	map<string, int>::iterator it; // declaro um iterador que sabe percorrer um map<string, double>
	
	for(it=mapa.begin(); it!=mapa.end(); it++){ // para cada posição de mapa
		
		cout << (*it).first; // uso cout para imprimir a string salva na chave
		printf(" %.2lf\n", (*it).second); // e printf para imprimir a double com precisão de duas casas decimais
	}
	
	return 0;
}