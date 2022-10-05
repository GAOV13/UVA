#include <stdio.h>

int tab[30000][101];
int lista[100];

int max(int n, int m){
  return n > m ? n : m;
}

void llenar(int n, int m){
  int i, j;
  for(i = 0; i <= n; ++i)
    for(j = 0; j <= m; ++j)
      tab[i][j] = -1;
}

int coin(int n, int m){
  int ans = 0;
  if(tab[n][m] != -1) ans = tab[n][m];
  else{
    if(!(n && m)) ans = 0;
    else if(lista[m - 1] > n) ans = coin(n, m-1);
    else ans = max(coin(n, m-1), lista[m-1] + coin(n - lista[m-1], m-1));
    tab[n][m] = ans;
  }
  return ans;
}

int main(){
  int n, m;
  int i, j;
  int suma, mitad;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &m);
    suma = 0;
    for(i = 0; i < m; ++i){
      scanf("%d", (lista + i));
      suma += lista[i];
    }
    llenar(suma/2, m);
    printf("%d\n", suma - (2*coin(suma/2, m)));
  }
  return 0;
}
