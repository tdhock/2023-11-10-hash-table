#include <stdio.h>
#define TABLE_SIZE 5
int hash(const char *string){
    int big = string[0];
    int index = big % TABLE_SIZE;
    printf("%s %d -> %d / %d\n", string, big, index, TABLE_SIZE);
    return index;
}
int main(void){
    int tel[TABLE_SIZE];
    tel[hash("Alice")]   = 3264277;
    tel[hash("Vincent")] = 8329881;
    tel[hash("Maude")]   = 9290028;
    char key[] = "Vincent";
    printf("name=%s tel=%d\n", key, tel[hash(key)]);
    return 0;
}
