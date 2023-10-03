#include <stdio.h>
#define PRINT(NAME) printf(#NAME"=%f\n", get(age_table,#NAME));
#define TABLE_SIZE 100
int hash(const char *string){
    return string[0] % TABLE_SIZE;
}
void set(double *table, const char* key, double value){
    int index = hash(key);
    if(table[index]>0)printf("collision:%s/%d prev value=%f, new value=%f\n",key,index,table[index],value);
    table[index] = value;
}
double get(double *table, const char* key){
    int index = hash(key);
    return table[index];
}
int main(void){
    double age_table[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE;i++)age_table[i]=-100;
    set(age_table, "toby", 39);
    set(age_table, "maude", 40);
    set(age_table, "tim", 6);
    PRINT(toby);
    PRINT(maude);
    PRINT(tim);
    return 0;
}
