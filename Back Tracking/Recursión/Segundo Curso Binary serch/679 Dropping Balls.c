#include <stdio.h>

int main(){
  int n, d, l;
  int num;
  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &d, &l);
    num = 1;
    while(--d){
        num = 2*num + (l + 1)%2;
        l = (l+1)/2;
    }
    printf("%d\n", num);
  }
  scanf("%d", &num);
  return 0;
}