/*
* Ejercicios de Uva relacionado con la sección de Matematica
* Nombre del Archivo: Matematica.c
* Fecha de Creación: 18 de septiembre del 2019
* Ultima Fecha de Modificacion: 26 de octubre del 2019
* Version: alfa 1.0
* Autor: Guido Ernesto Salazar Muñoz
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void hashmatTheBraveWarrior10055(){
	unsigned long long int n, m, resultado = 0;
	while(scanf("%llu %llu", &n , &m) != EOF){
		resultado =  n >= m ? (n - m) : (m - n);
		printf("%lli\n", resultado);
	}
} 

void numberingRoads11723(){
	unsigned int n, m, resultado;
	int casos = 1;
	scanf("%d %d", &n , &m);
	while(n && m){
		resultado = (n%m == 0) ? (n/m) - 1 : (n/m);
		resultado > 26 ? printf("Case %d: impossible\n", casos++) : printf("Case %d: %d\n", casos++, resultado);
		scanf("%d %d", &n , &m);
	}
}

void backToHighSchoolPhysics10071(){
	int n, m, resultado;
	while(scanf("%d %d", &n , &m) != EOF){
		resultado = (n*m)*(2);
		printf("%d\n", resultado);
	}
}

void bafanaBafana11805(){
	int total, inicio, pases, n;
	int i, casos = 1;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d %d", &total, &inicio, &pases);
		for(i = 0; i < pases; i++){
			if(inicio == total) inicio = 1;
			else inicio++;
		}
		printf("Case %d: %d\n", casos, inicio);
	}
}

void decimalAbinario(unsigned int n, int *m, int* cadena){
	int binario[32];
	int j, k;
	int* i = m;
	while(n > 0){
		binario[(*i)] = n%2;
		n = n/2;
		*i = *i + 1;
	}
	
	for(j = 0; j < *i/2; j++){
		k = binario[j];
		binario[j] = binario[*i - j - 1];
		binario[*i - j - 1] = k;
	}
	
	for(j = 0; j < *i; j++){
		cadena[j] = binario[j];	
	}	
}

int binarioAdecimal(int* binario, int n){
	int i, resul = 0;
	for(i = 0; i < n; i++){
		if(binario[n - 1 - i] == 1) resul += pow(2, i);
	}
	return resul;
}

void toCarryornottoCarry10469(){
	int indice1, indice2;
	unsigned int n, m;
	int i, resul;
	int num1[32], num2[32], res[32];
	while(scanf("%d %d", &n, &m) != EOF){
		if(n > m){
			indice1 = n;
			n = m;
			m = indice1;
		}
		indice1 = indice2 = 0;
		decimalAbinario(n, &indice1, num1);
		decimalAbinario(m, &indice2, num2);
		for(i = 0; i < indice2; i++){
			if(i < indice1){
				if(num1[indice1 - 1 - i] == num2[indice2 - 1 - i] && num1[indice1 - 1 - i] == 1) res[indice2 - 1 - i] = 0; 
				else res[indice2 - 1 - i] = num1[indice1 - 1 - i] + num2[indice2 - 1 - i];
			}
			else{
				res[indice2 - 1 - i] = num2[indice2 - 1 - i];
			}
		}
		resul = binarioAdecimal(res, indice2);
		printf("%d\n", resul);
	}
}

void perfection382(){
	int n, suma, i;
	printf("PERFECTION OUTPUT\n");
	scanf("%d", &n);
	while(n){
		suma = 0;
		for(i = 2; i <= n; i++){
			if(n%i == 0) suma += (n/i);
		}
		
		if(suma < n) printf("%5d  DEFICIENT\n", n);
		
		else if(suma > n) printf("%5d  ABUNDANT\n", n);
		
		else printf("%5d  PERFECT\n", n);
		scanf("%d", &n);
	}
	printf("END OF OUTPUT\n");
}

void digitCounting1225(){
	string largo;
	int n, m, i;
	cin >> n;
	while(n--){
		cin >> m;
		vector<int> repeticiones(10, 0);
		largo = "";
		for(i = 1; i <= m; i++){
			ostringstream temp;
			temp << i;
			largo += temp.str();
		}
		for(i = 0; i < largo.size(); i++){
			m = (int)largo[i] - 48;
			repeticiones[m]++;
		}
		
		cout << repeticiones[0];
		for(i = 1; i < 10; i++) cout << " " << repeticiones[i];
		
		cout << endl;
	}
}

void PetersSmokes0346(){
	long long int n, k, resto;
	long long int suma;
	while(scanf("%lli %lli", &n, &k) != EOF){
		suma = n;
		while(n >= k){
			resto = n%k;
			n = n/k;
			suma += n;
			n = n + resto;
		}
		printf("%lli\n", suma);
	}
}

void ackermannFunctions371(){
	long long int n, m, k, rep;
	long long int valor[2];
	long long int i;
	int ver;
	scanf("%lli %lli", &n, &m);
	while(n && m){
		if(n > m){
			i = n;
			n = m;
			m = i;
		}
		valor[0] = valor[1] = 0;
		ver = 1;
		for(i = n; i <= m; i++){
			k = i;
			rep = 0;
			if(i == 1) rep = 3;
			
			while(k != 1){
				if(k%2 == 0) k = k/2;
				
				else{
					k = (3*k) + 1;
				} 
				
				rep++; 
			}
			
			if(ver){
				valor[0] = i;
				valor[1] = rep;
				ver = 0;
			}
			
			else{
				if(rep > valor[1]){
					valor[1] = rep;
					valor[0] = i;
				}
			}
		}
		
		printf("Between %lli and %lli, %lli generates the longest sequence of %lli values.\n"
				 , n, m, valor[0], valor[1]);
		
		scanf("%lli %lli", &n, &m);
	}
}








int main(){
	bafanaBafana11805();
	return 0;
}

