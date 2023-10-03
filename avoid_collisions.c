#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 100
#define BUCKET_SIZE 1
struct bucket {
    int size;
    char* key[BUCKET_SIZE];
    double value[BUCKET_SIZE];
};
int hash(const char *string){
    return string[0] % TABLE_SIZE;
}
int find_index(struct bucket *b, const char *key){
    for(int i=0; i<b->size; i++){
	if(strcmp(key, b->key[i])==0){
	    return i;
	}
    }
    return -1;
}
void set(struct bucket *table, const char* key, double value){
    int table_index = hash(key);
    struct bucket *b = table+table_index;
    int bucket_index = find_index(b, key);
    int new_index;
    if(bucket_index<0){
	if(b->size==BUCKET_SIZE){
	    printf("bucket size=%d reached, not setting key=%s value=%f\n", BUCKET_SIZE, key, value);
	    return;
	}
	new_index = b->size++;
	b->key[new_index] = malloc(strlen(key)*sizeof(char));
	strcpy(b->key[new_index], key);
    }else{
	new_index = bucket_index;
    }
    b->value[new_index] = value;
}
int get(struct bucket *table, const char* key, double *out){
    int table_index = hash(key);
    struct bucket *b = table+table_index;
    int bucket_index = find_index(b, key);
    if(bucket_index<0)return bucket_index;
    *out = b->value[bucket_index];
    return 0;
}
void print_key(struct bucket *table, const char *key){
    double value;
    int status = get(table, key, &value);
    if(status==0)printf("key=%s value=%f\n", key, value);
    else printf("key=%s get failed\n", key);
}
void print_table(struct bucket *table){
    printf("table:\n");
    for(int table_i=0; table_i<TABLE_SIZE; table_i++){
	struct bucket b = table[table_i];
	for(int bucket_i=0; bucket_i<b.size; bucket_i++){
	    printf("%d %d %s %f\n", table_i, bucket_i, b.key[bucket_i], b.value[bucket_i]);
	}
    }
}
int main(void){
    struct bucket age_table[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++)age_table[i].size=0;
    set(age_table, "toby", 39);
    print_table(age_table);
    set(age_table, "maude", 40);
    print_table(age_table);
    set(age_table, "toby", 10);
    print_table(age_table);
    print_key(age_table, "toby");
    print_key(age_table, "maude");
    print_key(age_table, "tim");
    return 0;
}
