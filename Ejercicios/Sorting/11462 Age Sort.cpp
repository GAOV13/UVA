#include <stdio.h>
#include <map>
#include <iterator>

#define mii map<int, int>

using namespace std;

int main(){
    int n, num;
    int i, j;
    scanf("%d", &n);
    while(n){
        mii lista;
        for(i = 0; i < n; ++i){
            scanf("%d", &num);
            ++lista[num];
        }
       
        mii::iterator itr = lista.begin(), itr1;
        int dev = itr->first;
        printf("%d", dev);
        
        for(j = 1; j < itr->second; ++j) printf(" %d", dev);
        
        ++itr;
        for(itr1 = itr; itr1 != lista.end(); ++itr1){
            dev = itr1->first;
            for(int j = 0; j < itr1->second; ++j) printf(" %d", dev);
        }

        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
