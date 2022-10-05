/*
Archivo de ejercicios de UVA Introduccioon Easy-Medium
Nombre Archivo: Introducción.c
Version: BETA 1.9.6
Fecha de Creacion: 16 de Agosto del 2019
Fecha Ultima modificacion: 24 de Octubre del 2019
Autor: Guido Salazar
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void jumpingMario11764(){
	int n, tamano, i, pared, caso = 1;
	int saltos_altos, saltos_bajos;
	int paredes[50];
	scanf("%d", &n);
	while(n--){
		scanf("%d", &tamano);
		for(i = 0; i < tamano; i++){
			scanf("%d", &pared);
			paredes[i] = pared;
		}
		saltos_altos = saltos_bajos = 0;
		for(i = 0; i < tamano - 1; i++){
			if(paredes[i] - paredes[i + 1] < 0)
				saltos_altos += 1;
			else if(paredes[i] - paredes[i + 1] > 0)
				saltos_bajos += 1;
		}
		printf("Case %d: %d %d\n", caso++, saltos_altos, saltos_bajos);
	}
}

void horrorDash11799(){
	int n, m, vel, max, caso = 1;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		max = 0;
		while(m--){
			scanf("%d", &vel);
			if(vel > max)
				max = vel;
		}
		printf("Case %d: %d\n", caso++, max);
	}	
}

int ayuda11332(int n){
	int suma = 0, mod;
	while(n >= 10){
		mod = n % 10;
		n = n / 10;
		suma += mod;
	}	
	suma += n;
	if(suma >= 10){
		ayuda11332(suma);	
	}
	else{			
		return suma;
	}
}

void summingDigists11332(){
	int suma, num1, ver = 1;
	unsigned long long int num;
	while(ver){
		scanf("%llu", &num);
		if(num == 0) ver = 0;
		else{
			suma = ayuda11332(num);
			printf("%d\n", suma);
		}
	}
}

void packingForHoliday12372(){
	int n, largo, ancho, alto, casos = 1;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d %d", &largo, &ancho, &alto);
		if(largo <= 20 && ancho <= 20 && alto <= 20)
			printf("Case %d: good\n", casos++);
		else
			printf("Case %d: bad\n", casos++);
	}
}

void automaticAnswer11547(){
	int n, num;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &num);
		num = (((((((num*567)/9)+ 7492)*235)/47) - 498)/10) % 10;
		if(num < 0) num *= -1;
		printf("%d\n", num);
	}
}

void lumberjackSequencing11942(){
	int n, ver1, ver2, i, num, rep;
	int lista[10];
	scanf("%d", &n);
	printf("Lumberjacks:\n");
	while(n--){
		for(i = 0; i < 10; i++){
			scanf("%d", &num);
				lista[i] = num;
		}
		ver1 = ver2 = rep = 1;
		i = 0;
		while(rep && i < 9){
			if(lista[i] > lista[i + 1]) rep =  ver1 = 0;
			i++;
		}
		i = 0;
		rep = 1;
		while(rep && i < 9 && ver1 == 0){
			if(lista[i] < lista[i + 1]) rep = ver2 = 0;
			i++;
		}
		if(ver1 != 0 || ver2 != 0) 
			printf("Ordered\n");
			
		else printf("Unordered\n");
	}		
}

void googleIsFeelingLucky12015(){
	int n, prefer, indice, max, casos = 1;
	int preferencias[10];
	char urls[10][101], temp[101];	
	scanf("%d", &n);
	while(n--){
		max = 0;
		for(indice = 0; indice < 10; indice++){
			scanf("%s %d", &temp, &prefer);
			preferencias[indice] = prefer;
			strcpy(urls[indice], temp);
			if(max < prefer) max = prefer;
		}
		printf("Case #%d:\n", casos++);
		for(indice = 0; indice < 10; indice++){
			if(preferencias[indice] == max){
				printf("%s\n", urls[indice]);
			}
		}
	}
}

void optimalParking11364(){
	int i, j, n, m, distancia, suma;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		int tiendas[m];
		for(i = 0; i < m; i++){
			scanf("%d", &distancia);
			tiendas[i] = distancia;
		}
		
		i = 0;
		while(i < m - 1){
			j = i + 1;
			while(j < m){
				if(tiendas[i] > tiendas[j]){
					distancia = tiendas[i];
					tiendas[i] = tiendas[j];
					tiendas[j] = distancia;
				}
				j++;
			}
			i++;
		}
		
		distancia = 0;	
		for(i = 0; i < m - 1; i++){
				if(tiendas[i + 1] - tiendas[i] > distancia){
					distancia = (tiendas[i + 1] + tiendas[i])/2; 
				}
		}
		
		if(distancia - tiendas[0] > tiendas[m - 1] - distancia){
			suma = 0;
			
			for(i = 0; i < m ; i++){
				if(i == 0)
				suma += distancia - tiendas[0];
				else{
					j = tiendas[i] - tiendas[i - 1];
					suma += j;
				}
			}
			suma += tiendas[m-1] - distancia;
			printf("%d\n", suma);
		}
		
		else{
			suma = 0;
			for(i = 0; i < m ; i++){
				if(i == 0)
				suma += tiendas[m - 1 - i] - distancia;
				else{
					j = tiendas[m - i] - tiendas[m - i - 1];
					suma += j;
				}
			}
			suma += distancia - tiendas[0];
			printf("%d\n", suma);
		}	
	}
}

void aSpecialHappyBirthdaySong12554(){
	int n, i, indice, i_song;
	char personas[100][101];
	char quien[101];
	char cancion[16][9] = {"Happy", "birthday", "to", "you", "Happy", "birthday", 
						"to", "you", "Happy", "birthday", "to", "Rujia", "Happy", 
						"birthday", "to", "you"};
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", quien);
		strcpy(personas[i], quien);
	}
	
	i = indice = i_song = 0;
	while(i < n || (i) % 16 != 0){
		printf("%s: %s\n", personas[indice], cancion[i_song]);
		if(indice == n - 1) indice = -1;
		else if(i_song == 15) i_song = -1;
		i++,
		indice++;
		i_song++;
	}
}

void languageDetection12250(){
	int ver1, ver2, i, indice, casos = 1;
	char palabras[6][13] = {"HELLO", "HOLA", "HALLO", "BONJOUR",
							"CIAO", "ZDRAVSTVUJTE"};
	char idioma[7][8] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH",
						 "ITALIAN", "RUSSIAN", "UNKNOWN" };
	char temp[13];
	ver1 = 1;
	while(ver1){
		scanf("%s", &temp);
		if(strcmp(temp, "#") == 0){
			ver1 = 0;
		}
		else{
			ver2 = 1;
			i = 0;
			while(ver2){
				if(i < 6){
					if(strcmp(temp, palabras[i]) == 0){
						indice = i;
						ver2 = 0;
					}
				}
				else if(i == 6){
						indice = i;
						ver2 = 0;
				}
				i++;
			}
			printf("Case %d: %s\n", casos++, idioma[indice]);
		}
	}
}

void ecologicalPremium10300(){
	int n, granjeros, metros, animals, fe;
	int resultado, suma;
	scanf("%d", &n);
	while(n--){
		suma = 0;
		scanf("%d", &granjeros);
		while(granjeros--){
			scanf("%d %d %d", &metros, &animals, &fe);
			resultado = metros*fe;
			suma += resultado;
		}
		printf("%d\n", suma);
	}
} 

void emoogleBalance12279(){
	int ver, n, razon, dado, caso, m;
	ver = caso = 1;
	while(ver){
		scanf("%d", &n);
		if(n == 0) ver = 0;
		else{
			razon = dado = 0;
			while(n--){
				scanf("%d", &m);
				if(m == 0) dado += 1;
				else{
					razon += 1;
				}
			}
			n = razon - dado;
			printf("Case %d: %d\n", caso++, n);
		}
	}
}

void relationalOperators11172(){
	int n, a, b;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &a, &b);
		if(a > b) printf(">\n");
		else if(a < b) printf("<\n");
		else printf("=\n");
	}	
}

void eventPlanning11559(){
	int people, budget, hotels, weeks, i, j, ver = 1;
	int precio_hotel, disp_hotel;
	int precio_min;
	while(scanf("%d %d %d %d", &people, &budget, &hotels, &weeks) != EOF){
		precio_min = budget + 1;
		for(i = 0; i < hotels; i++){
			scanf("%d", &precio_hotel);
			for(j = 0; j < weeks; j++){
				scanf("%d", &disp_hotel);
				if(disp_hotel >= people){
					if(precio_min > (precio_hotel*people)){
						precio_min = precio_hotel*people;
					} 
				}
			}
		}
		if(precio_min <= budget) printf("%d\n", precio_min);
		else printf("stay home\n");
	}
}

void zapping12468(){
	int ver = 1, a, b, max;
	while(ver){
		scanf("%d %d", &a, &b);
		max = 0;
		if(a == b && a == -1){
			ver = 0;
		}
		else{
			if(b > a){
				if(b - a < (a+100) - b) max = b - a;
				else max = a + 100 - b;
			}
			else if(a > b){
				if(a - b < (b + 100) - a) max = a - b;
				else max = b + 100 - a;
			}
			else max = 0;
			printf("%d", max);
		}
	}
}

void tariffPlan12157(){
	int t, n, i, casos = 1, num;
	int mile, juice;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mile = juice = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &num);
			mile += ((num/30) + 1)*10;
			juice += ((num/60) + 1)*15;
		}
		if(mile < juice) printf("Case %d: Mile %d\n", casos++, mile);
		else if(juice < mile) printf("Case %d: Juice %d\n", casos++, juice);
		else printf("Case %d: Mile Juice %d\n", casos++, mile);
	}
}

void theSnail573(){
	float h, u, d, f, num;
	int i, dia, ver, ver1;
	ver = 1;
	while(ver){
		scanf("%f", &h);
		if(h == 0) ver = 0;
		else{
			scanf("%f %f %f", &u, &d, &f);
			dia = ver1 = 1;
			num = i = 0;
			while(num >= 0 && num <= h && ver1){ 
				if(num > num + (u - (i*(u*(f/100))))){
					num -= d;
					if(num < 0){
						num = 0;
						ver1--;
					}
					
					else{
						dia++;
					}
				}
				else{
					num += (u - (i*(u*(f/100))));
					if(num > h){
					i = 0;
					}
					else{
						num -= d;
						if(num < 0){
							num = 0;
							ver1--;
						}
						else{
							dia++; i++;
						}
						
					}
				}
			}
			if(ver1) printf("success on day %d\n", dia);
			else printf("failure on day %d\n", dia);
		}
	}
}

void burgerTime11661(){
	int n, i, posR, posD, distancia, ver;
	char hamburguesas[2000001], temp[2];
	scanf("%d", &n);
	while(n){
		scanf("%s", hamburguesas);
		distancia = 2000001;
		ver = 1; i = 0;
		posR = posD = -1;
		while(ver && i < n){
			temp[0] = hamburguesas[i];
			if(strcmp(temp, "Z") == 0){
				ver = 0; distancia = 0;
			} else {
				if(strcmp(temp, "D") == 0) posD = i;
				else if(strcmp(temp, "R") == 0) posR = i;
			}
			
			if(posD != -1 && posR != -1 && distancia > fabs(posD - posR)) distancia = fabs(posD - posR);
			i++;
		}
		printf("%d\n", distancia);
		scanf("%d", &n);
	}
}

void subPrime11679(){
	int bancos, prestamos, i, deudor, prestador, deuda;
	int ver;
	int plata[20];
	scanf("%d %d", &bancos, &prestamos);
	while(bancos && prestamos){
		for(i = 0; i < bancos; i++){
			scanf("%d", &plata[i]);
		}
		
		for(i = 0; i < prestamos; i++){
			scanf("%d %d %d", &deudor, &prestador, &deuda);
			plata[deudor - 1] -= deuda;
			plata[prestador - 1] += deuda;
		}
		ver = 0;
		for(i = 0; i < bancos; i++){
			if(plata[i] < 0) ver = 1;
		}
		if(ver) printf("N\n");
		else printf("S\n");
		scanf("%d %d", &bancos, &prestamos);
	}
}

void divisionOfNlogonia11498(){
	int n, x, y, i;
	int division[2];
	scanf("%d", &n);
	while(n){
		scanf("%d %d", &division[0], &division[1]);
		for(i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			if(x > division[0] && y > division[1]) printf("NE\n");
			else if(x < division[0] && y > division[1]) printf("NO\n");
			else if(x < division[0] && y < division[1]) printf("SO\n");
			else if(x > division[0] && y < division[1]) printf("SE\n");
			else printf("divisa\n");
		}
		scanf("%d", &n);
	}
}

void secretResearch621(){
	char numero[3][3] = {"1", "4", "78"};
	char cadena[3][4] = {"35", "190", "94"};
	char verificacion[1000];
	int n, i, largo;
	scanf("%d", &n);
	while(n--){
		scanf("%s", verificacion);
		largo = strlen(verificacion);
		if(largo <= 2){
			if(strcmp(verificacion, numero[0]) == 0 || strcmp(verificacion, numero[1]) == 0 || strcmp(verificacion, numero[2]) == 0) printf("+\n");
			else printf("?\n");
		} 
		else{
			if(verificacion[largo - 2] == cadena[0][0] && verificacion[largo - 1] == cadena[0][1]) printf("-\n");
			else if(verificacion[0] == cadena[2][0] && verificacion[largo - 1] == cadena[2][1]) printf("*\n");
			else printf("?\n");
		}	
	}
}

void searchingForNessy11044(){
	int n, fila, columna, min;
	int i;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &fila, &columna);
		min = 0;
		i = 2;
		while(i < fila - 1){
			min += (columna)/3;		
			if(i + 3 >= fila - 1){
				if(i + 2 < fila - 1) i = i + 2;
				else i += 3;
			}
			else i += 3;
		}
		printf("%d\n", min);
	}
}

void trainTracks11586(){
int n, masculino, femenino, i, len;
	char x[200], temp1[2];
	char temp[100];
	fgets(temp, 100, stdin);
	n = atoi(temp);
	while(n--){
		fgets(x, 200, stdin);
		temp1[0] = x[0];
		femenino = masculino = i = 0;
		len = strlen(x);
		while(i < len){
			i++;
			if(strcmp(temp1, "F") == 0) femenino++;
			if(strcmp(temp1, "M") == 0) masculino++;
			temp1[0] = x[i];
		}
		if(femenino == masculino && femenino > 1) printf("LOOP\n");
		else printf("NO LOOP\n");
	}
}

int ayuda10424_1(char* temp){
	int num = 0;
	if(strcmp(temp, "A") == 0 || strcmp(temp, "a") == 0) num = 1;
	else if(strcmp(temp, "B") == 0 || strcmp(temp, "b") == 0) num = 2;
	else if(strcmp(temp, "C") == 0 || strcmp(temp, "c") == 0) num = 3;
	else if(strcmp(temp, "D") == 0 || strcmp(temp, "d") == 0) num = 4;
	else if(strcmp(temp, "E") == 0 || strcmp(temp, "e") == 0) num = 5;
	else if(strcmp(temp, "F") == 0 || strcmp(temp, "f") == 0) num = 6;
	else if(strcmp(temp, "G") == 0 || strcmp(temp, "g") == 0) num = 7;
	else if(strcmp(temp, "H") == 0 || strcmp(temp, "h") == 0) num = 8;
	else if(strcmp(temp, "I") == 0 || strcmp(temp, "i") == 0) num = 9;
	else if(strcmp(temp, "J") == 0 || strcmp(temp, "j") == 0) num = 10;
	else if(strcmp(temp, "K") == 0 || strcmp(temp, "k") == 0) num = 11;
	else if(strcmp(temp, "L") == 0 || strcmp(temp, "l") == 0) num = 12;
	else if(strcmp(temp, "M") == 0 || strcmp(temp, "m") == 0) num = 13;
	else if(strcmp(temp, "N") == 0 || strcmp(temp, "n") == 0) num = 14;
	else if(strcmp(temp, "O") == 0 || strcmp(temp, "o") == 0) num = 15;
	else if(strcmp(temp, "P") == 0 || strcmp(temp, "p") == 0) num = 16;
	else if(strcmp(temp, "Q") == 0 || strcmp(temp, "q") == 0) num = 17;
	else if(strcmp(temp, "R") == 0 || strcmp(temp, "r") == 0) num = 18;
	else if(strcmp(temp, "S") == 0 || strcmp(temp, "s") == 0) num = 19;
	else if(strcmp(temp, "T") == 0 || strcmp(temp, "t") == 0) num = 20;
	else if(strcmp(temp, "U") == 0 || strcmp(temp, "u") == 0) num = 21;
	else if(strcmp(temp, "V") == 0 || strcmp(temp, "v") == 0) num = 22;
	else if(strcmp(temp, "W") == 0 || strcmp(temp, "w") == 0) num = 23;
	else if(strcmp(temp, "X") == 0 || strcmp(temp, "x") == 0) num = 24;
	else if(strcmp(temp, "Y") == 0 || strcmp(temp, "y") == 0) num = 25;
	else if(strcmp(temp, "Z") == 0 || strcmp(temp, "z") == 0) num = 26;
	
	return num;
}

float ayuda10424_2(int n){
	int n1 = 0;
	while(n >= 10){
		n1 += n % 10;
		n /= 10;
	}
	
	n1 += n;
	if(n1 >= 10) ayuda10424_2(n1);
	
	else{
		return n1;	
	} 
}

void LoveCalculator10424(){
	char nombre1[26], nombre2[26], temp[2];
	int num1, num2, i; 
	float n1, n2, resul;
	while(fgets(nombre1, 30, stdin) != NULL){
		fgets(nombre2, 30, stdin);
		num1 = num2 = 0;
		for(i = 0; i < strlen(nombre1); i++){
			temp[0] = nombre1[i];
			if(strcmp(temp, " ")) num1 += ayuda10424_1(temp);
		}
		
		for(i = 0; i < strlen(nombre2); i++){
			temp[0] = nombre2[i];
			if(strcmp(temp, " "))num2 += ayuda10424_1(temp);
		}
		n1 = ayuda10424_2(num1);
		n2 = ayuda10424_2(num2);

		resul = 0;		
		resul = (n1 >= n2) ? (n2/n1) : (n1/n2);
		resul = resul * 100;
		printf("%.2f %%\n", resul);
		}
}

void blowingFuses661(){
	int casos = 1;
	int devices[20], estado[20];
	int aparatos, switches, capacidad, max, suma;
	int i, j, ver;
	
	scanf("%d %d %d", &aparatos, &switches, &capacidad);
	while(aparatos && switches && capacidad){
		max = 0;
		for(i = 0; i < aparatos; i++){
			scanf("%d", &devices[i]);
			estado[i] = -1;
		}
		
		suma = 0;
		ver = 1;
		for(j = 0; j < switches; j++){
			scanf("%d", &i);
			if(ver){
				if(estado[i - 1] == -1){
					estado[i - 1] = 1;
					suma += devices[i - 1];
					max = suma > max ? suma : max;
					if(max > capacidad){
						ver = 0;	
						}
				}
				else{
					estado[i - 1] = -1;
					suma -= devices[i - 1];
				}
			}	
		}
		
		if(ver){
			printf("Sequence %d\n"
                "Fuse was not blown.\n"
					 "Maximal power consumption was %d amperes.\n", casos++, max);
		}
		else{
			printf("Sequence %d\n"
					 "Fuse was blown.\n", casos++);
		}
	
		scanf("%d %d %d", &aparatos, &switches, &capacidad);
		printf("\n");
	}
}

void zerosAndOnes10324(){
	//Escrito en c++
	int i, j, k, n, ver, ver1, casos = 1;
	char tam[20];
	string numero, prueba;
	
	while(getline(cin, numero) && numero.size() != 0){
		ver1 = 1;
		getline(cin, prueba);
		strcpy(tam, prueba.c_str());
		sscanf(tam, "%d", &n);
		while(n--){
			ver = 1;
			getline(cin, prueba);
			strcpy(tam, prueba.c_str());
			sscanf(tam, "%d %d", &i, &j);
			if(j < i){
				k = i;
				i = j;
				j = k;
			}
			
			for(k = i; k < j; k++){
				if(numero[k] != numero[k + 1]){
					ver = 0;
					break;
				}
			}
			
			if(ver1) printf("Case %d:\n", casos++);
					
			if(ver) printf("Yes\n");
			
			else printf("No\n");
			ver1 = 0;
		}
	}
}

void FindtheTelephone10921(){
	char numero[31];
	int i;
	while(scanf("%s", numero) != EOF){
		for(i = 0; i < strlen(numero); i++){
			if(numero[i] == '-' || numero[i] == '1' || numero[i] == '0') printf("%c", numero[i]);
			
			else{
				if(numero[i] == 'A' || numero[i] == 'B' || numero[i] == 'C') printf("2");
				
				else if(numero[i] == 'D' || numero[i] == 'E' || numero[i] == 'F') printf("3");
				
				else if(numero[i] == 'G' || numero[i] == 'H' || numero[i] == 'I') printf("4");
				
				else if(numero[i] == 'J' || numero[i] == 'K' || numero[i] == 'L') printf("5");
				
				else if(numero[i] == 'M' || numero[i] == 'N' || numero[i] == 'O') printf("6");
				
				else if(numero[i] == 'P' || numero[i] == 'Q' || numero[i] == 'R' || numero[i] == 'S') printf("7");
				
				else if(numero[i] == 'V' || numero[i] == 'T' || numero[i] == 'U') printf("8");
				
				else if(numero[i] == 'W' || numero[i] == 'X' || numero[i] == 'Y' || numero[i] == 'Z') printf("9");
			}
		}
		printf("\n");
	}
}

void motherBear10945(){
	string dato, respuesta;
	bool ver;
	int i, largo;
	getline(cin, dato);
	while(dato != "DONE"){
		respuesta = "";
		for(i = 0; i < dato.size(); i++){
			if((int)dato[i] >= 65 && (int)dato[i] <= 90) respuesta += (int)dato[i] + 32;
			
			else if((int)dato[i] >= 97 && (int)dato[i] <= 122) respuesta += dato[i];
		}
		largo = respuesta.size();
		ver = true;
		for(i = 0; i < largo/2 && ver; i++){
			if(respuesta[i] != respuesta[largo - 1 - i]) ver = false;
		}
		
		if(ver) cout << "You won\'t be eaten!" << endl;
		
		else cout << "Uh oh.." << endl;
		
		getline(cin, dato);
	}
}

void ReverseandAdd10018(){
	long long int n, m, resultado;
	int casos, itr, i, largo;
	bool ver;
	cin >> casos;
	string m1, n1;
	while(casos--){
		itr = 0;
		ver = true;
		cin >> n;
		while(ver){
			ostringstream temp3;
			temp3 << n;
			n1 = temp3.str();
			m1 = n1;
			reverse(m1.begin(), m1.end());
			if(m1 == n1 && itr){
				stringstream temp(n1);
				temp >> resultado;
				ver = false;
			}	
			
			else{
				stringstream temp1(n1);
				temp1 >> n;
				stringstream temp2(m1);
				temp2 >> m;
				resultado = n + m;
				n = resultado;
				itr++;
			}
		}
		cout << itr << " " << resultado << endl;
	}
}

void kindergartenCountingGame494(){
	string palabra;
	int i, contador;
	bool espacio;
	while(getline(cin, palabra)){
		contador = 1;
		espacio = false;
		for(i = 0; i < palabra.size(); i++){
			if((int)palabra[i] < 65 || ((int)palabra[i] > 90 && (int)palabra[i] < 97) || (int)palabra[i] > 122){
				if(i == 0) contador--;
				
				espacio = true;
			} 
			
			else{
				if(espacio && (((int)palabra[i] >= 65 && (int)palabra[i] <= 90) || ((int)palabra[i] >= 97 && (int)palabra[i] <= 122))){
					contador++;
					espacio = false;
				}
			} 
		}
		
		if(palabra.size() == 0) contador--;
		
		cout << contador << endl;
	}
}

void combinationLock10550(){
	
}

// Ejercicios sin completar o con algunos problemas

void robotInstructions12503(){
	// Corregir entrega de uva en python
	int n, m, i, j, posicion;
	int orden[100], num;
	char instruccion[100][8], temp[8];
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		posicion = 0;
		for(i = 0; i < m; i++){
			fgets(temp, 8, stdin);
			printf("%s", temp);
			printf("%d\n", strcmp(temp, "LEFT"));
			if(strcmp(temp, "SAME AS") == 0){
				strcpy(instruccion[i], temp);
				scanf("%d", num);
				orden[i] = num - 1;
				
				j = i;
				printf("1\n");
				while(strcmp(instruccion[j], "SAME AS") == 0){
					j = orden[j];
					printf("2\n");
					if(strcmp(instruccion[j], "SAME AS") == 0){
						printf("3\n");	
						continue;
					} 
					else{
						printf("4\n");
						if(strcmp(instruccion[j], "LEFT") == 0){
							posicion -= 1;
						} 
						else if(strcmp(instruccion[j], "RIGHT") == 0){	
							posicion += 1;
						} 	
					}
				}	
			}
			
			else{
				if(strcmp(temp, "LEFT") == 0){
					printf("5\n");
					posicion -= 1;
					strcpy(instruccion[i], temp);
					orden[i] = -1;
					
				}
				
				else if(strcmp(temp, "RIGHT") == 0){
					printf("6\n");
					posicion += 1;
					strcpy(instruccion[i], temp);
					orden[i] = -1;
				} 
			}
		}
		printf("%d\n", posicion);
	}
}

void oneTwoThree12289(){
	int n, num, ver1, ver2;
	char numero[6], *p, temp[2];
	scanf("%d", &n);
	while(n--){
		scanf("%s", numero);
		if(strlen(numero) > 3){
			num = 3;
		}
		else{
			ver1 = ver2 = num = 0;
			p = numero;
			while(num < 3){
				temp[0] = *p;
				if(num == 0){
					if(strcmp(temp, "o") == 0) ver1++;
					else if(strcmp(temp, "t") == 0)ver2++;
				}
				else if(num == 1){
					if(strcmp(temp, "n") == 0) ver1++;
					else if(strcmp(temp, "w") == 0) ver2++;
				}
				else{
					if(strcmp(temp, "e") == 0) ver1++;
					else if(strcmp(temp, "o") == 0) ver2++;
				}
				num++;
				p++;
			}
			if(ver1 > ver2) num = 1;
			else num = 2;
		}
		printf("%d\n", num);
	}
}

void polePosition12150(){
	int n, i, j, ver1, ver2;
	int autos[10000], posicion[10000];
	int inicio[10000];
	ver1 = 1;
	ver2 = 1000000;
	printf("%d\n", ver2);
	while(ver1){
		scanf("%d", &n);
		if(n == 0) ver1 = 0;
		
		else{
			for(i = 0; i < n; i++){
			scanf("%d %d", &autos[i], &posicion[i]);
			inicio[i] = 0;
			}
			
			ver2 = 1;
			i = 0;
			while(ver2 && i < n){
				if(fabs(posicion[i]) > n) ver2 = 0;
				else{
				 	j = i + posicion[i];
					
					if(inicio[j]) ver2 = 0;
					else{
						inicio[j] = autos[i];
					}
				}
				i++;
			}
			
			if(ver2 == 0) printf("-1\n");
			else{
				for(i = 0; i < n; i++){
					if(i == n - 1) printf("%d\n", inicio[i]);
					else printf("%d ", inicio[i]);
				}
			}
		}
	}
} 

void lookAndSay11660(){
	//Una primera aproximación, pero estimando con una complejidad de O(e^n) por lo cual el codigo se demorar mucho tiempo si esq logra acabar sin que la memoria se desborde
	int i, j, num, largo;
	int i1, indice, r;
	char x[100000], temp[100000], numero[1000];
	char p1[2], p2[2];
	scanf("%s %d %d", x, &i, &j);
	while(strcmp(x, "0") && i && j){
		for(i1 = 1; i1 < i; i1++){
			largo = strlen(x);
			num = 1;
			r = 1;
			for(indice = 0; indice < j; indice++){
				p1[0] = x[indice]; p2[0] = x[indice + 1];
				if(strcmp(p1, p2)){
					itoa(num, numero, 10);
					if(r){
						strcpy(temp, numero);
						r--;
					} 
					else strcat(temp, numero);
					
					strcat(temp, p1);
					num = 1;
				}
				else num++;
			}
			p1[0] = x[indice];
			itoa(num, numero, 10);
			
			if(r) strcpy(temp, numero);
			else strcat(temp, numero);
			
			strcat(temp, p1);
			strcpy(x, temp);
		}
		p1[0] = x[j - 1];
		printf("%s\n", p1);	
		scanf("%s %d %d", x, &i, &j);	
	}	
}





int main(){
	lookAndSay11660();
	return 0;
}

