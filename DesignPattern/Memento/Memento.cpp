/**
 * @file: Memento.cpp
 *
 * @brief: Memento model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <iostream>

using namespace std;

/**
 *  @brief 数字を保存するMementoクラス 
 **/
class Memento{
  public:
    Memento(int num):num_(num){}
    int GetNum(void){return num_;}
  private:
    int num_;
};

/**
 *  @brief 数字を生成するクラス
 **/
class Number{
  public:
    Number(int num):num_(num){}
    int GetNum(void){return num_;}
    void Increment(void){num_++;}

   /**
    *  @brief 現在の状態からMemetoを作成する関数
    */
    Memento* CreateMemento(void){
      Memento *memento=new Memento(num_);
      return memento;
    }

   /**
    *  @brief Mementoを使用して、数字を復元する関数
    */
    void RestoreMemento(Memento *memento){
      num_=memento->GetNum();
    }

  private:
    int num_;
};

int main(void){
  cout<<"Memento Pattern Sample Start!!"<<endl;

  //数字オブジェクト作成
  Number number(100);
  Memento* memento=number.CreateMemento();//初期値を覚えておく
  for(int i=0;i<100;i++){
    cout<<number.GetNum()<<endl;
    number.Increment();//数字にインクリメント
    if(number.GetNum()%10==0){
      cout<<"Restore"<<endl;
      number.RestoreMemento(memento);
    }
  }

  return 0;
}
