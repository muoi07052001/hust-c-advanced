#include "btree.h"
#include "SOUNDEX.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//=========================================================
BTA *taotudien()
{
  BTA *p;
  p = btcrt("tdanhviet", 0, 0);
  return p;
}

BTA *taosoundex()
{
  	BTA *p;
	p = btcrt("tdanhvietsoundex", 0,0);
	return p;
}

char *tachXau(char *s,char **val){
  int i=0,j=0;
  char *key,*value;
  key = (char*)malloc(30*sizeof(char));
  value = (char*)malloc(1000*sizeof(char));
  while(s[i++]!='{');
  while(s[i]!='}')key[j++] = s[i++];
  j = 0;
  while(s[i++]!='{');
  while(s[i]!='}')value[j++] = s[i++];
  *val = value ;
  return key;
}

void *nhandulieu(FILE *f,BTA *p,BTA *q)
{
  char *s,*key,*val;
	s=(char *)malloc(1000);
  int i=0;
  while(fgets(s, 1000, f)!=NULL){
    if ((s[0]=='/'&&s[1]  =='/')||s[0]=='['||s[0]==']'||strlen(s)<6) continue;
    s[strlen(s)-1] = '\0';
    key = tachXau(s,&val);
    puts(key);
    puts(val);
    btins(p, key, val,strlen(val)+1);
    q = xulysoundex(q,key);
  }
  return f;
}
void make_file(char filename[]){
  FILE *f = fopen(filename,"r");
  BTA *p = taotudien();
  BTA *q = taosoundex();
  f = nhandulieu(f,p,q);
  btcls(p);
  btcls(q);
  fclose(f);
}
