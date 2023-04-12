#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {

  HashMap *local=map;
  long i;
  Pair **elementos=local->buckets;
  long indice=hash(key,local->capacity);
  if(elementos[indice]==NULL)
  {
    elementos[indice]->key=key;
    elementos[indice]->value=value;
  }
  else{
    for(i=indice+1;i<local->capacity;i++)
      {
        if(elementos[i]==NULL)
        {
          elementos[i]->key=key;
          elementos[i]->value=value;
          break;
        }
        if(elementos[i]->key==NULL)
        {
          elementos[i]->key=key;
          elementos[i]->value=value;
          break;
        }
      }
      
  }
  local->size++;
  local->current=i;
  return;

}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {

  HashMap *local=malloc(sizeof(HashMap));
  Pair **elementos=(Pair**)malloc(sizeof(Pair)*capacity);
  for(int i=0;i<capacity;i++)
    {
      elementos[i]=NULL;
    }
  local->buckets=elementos;
  local->size=0;
  local->current=-1;
  local->capacity=capacity;

  return local;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
