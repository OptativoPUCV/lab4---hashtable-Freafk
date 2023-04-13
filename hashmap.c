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
  Pair *par=createPair(key, value);
  Pair **elementos=local->buckets;
  long i=hash(key,local->capacity);
  
  while(1)
  {

    if(elementos[i]==NULL || elementos[i]->key==NULL)
     {
      elementos[i]=par;
      break;
      
     }
    if(strcmp(elementos[i]->key,key)==1)return;
    if(i==hash(key,local->capacity)-1)
    {
      break;
    }
    if(i==local->capacity-1)
    {
      i=-1;
    }
    i++;
  }
  local->size++;
  local->current=i;

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

  HashMap *local=map;
  Pair **elementos=local->buckets;
  long indice=hash(key,local->capacity);
    for (int k=0;k<local->capacity;k++)
    {
      
      if(elementos[k]!=NULL)
      {
        
        printf("%s, ",elementos[k]->key);
      } 
      else{
        printf("+espacio+");
      }
      
    }

  while(1)
    {
      if(elementos[indice]==NULL)return NULL;
      if(elementos[indice]->key==key)
      {
        return elementos[indice];
      }
      if(indice==local->capacity)
      {
        indice=-1;
      }
      if(indice==hash(key, local->capacity)-1)break;
      indice++;
      printf("HOLAAAA");
      
    }
    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
