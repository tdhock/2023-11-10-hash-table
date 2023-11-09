#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 10
int main(void){
  int tel[TABLE_SIZE] = {3264277, 8329881, 9290028};
  char *name[TABLE_SIZE] = {"Alice", "Vincent", "Maude"};
  char key[] = "Vincent";
  for(int index=0; index<TABLE_SIZE; index++){
    if(!strcmp(key, name[index]))printf("%d est le numéro de tél de %s", tel[index], key);
  }
  return 0;
}
