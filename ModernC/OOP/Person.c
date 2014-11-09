#include<stdio.h>
#include"Person.h"

//プライベート変数
static int MAGIC_NUMBER=7;

//プライベート関数
static void Person_ShowSecret(void);

void Person_Test(void){
  printf("Person Class\n");
  Person_ShowSecret();
}


void Person_Bark(void){
  printf("こんにちは\n");
}

//====プライベート関数====

static void Person_ShowSecret(void){
  printf("MagicNumber is %d\n",MAGIC_NUMBER);
}
