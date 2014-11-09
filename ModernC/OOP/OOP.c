/**
 * @file: OOP.c
 *
 * @brief: Object Oriented Programing sample with C
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <stdio.h>
#include "Person.h"
#include "Dog.h"

typedef struct Animal{
  void (*Bark)(void);
}Animal;

int main(void){
  printf("Object Oriented C Sample!!\n");

  //===カプセル化のサンプル===
  //Person.cのMAGIC_NUMBERやPerson_Secretは
  //Person.cからしか参照しない
  printf("===カプセル化のサンプル===\n");
  Person_Test();

  //===ポリモーフィズムのサンプル===
  printf("===ポリモーフィズムのサンプル===\n");
  Animal person=newPerson();//人間のオブジェクトを作成
  Animal dog   =newDog();   //犬のオブジェクトを作成

  person.Bark();
  dog.Bark();

  return 0;
}
