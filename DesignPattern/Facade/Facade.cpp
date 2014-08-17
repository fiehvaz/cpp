/**
 * @file: Facade.cpp
 *
 * @brief: Facade model of the Design pattern.
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
 *  @brief 何かの複雑処理をするクラスA
 **/
class A{
  public:
    void DoSomething(void){
      cout<<"Class A does somthing"<<endl;
    }
  private:
};

/**
 *  @brief 何かの複雑処理をするクラスB
 **/
class B{
  public:
    void DoSomething(void){
      cout<<"Class B does somthing"<<endl;
    }
  private:
};

/**
 *  @brief 何かの複雑処理をするクラスC
 **/
class C{
  public:
    void DoSomething(void){
      cout<<"Class C does somthing"<<endl;
    }
  private:
};

/**
 *  @brief Class A,B,C用のFacadeクラス 
 **/
class Facade{
  public:
    /**
     * @brief クラスA,B,Cを使って何か複雑なことを実施する関数
     */
    void Do(void){
      a.DoSomething();
      b.DoSomething();
      c.DoSomething();
    }

  private:
    //facadeクラスが使用する複雑な処理を実施するクラスオブジェクト
    A a;
    B b;
    C c;
};

int main(void){
  cout<<"Facade Pattern Sample Start!!"<<endl;

  //ユーザが使用するのはfacadeクラスだけ
  Facade facade;
  //facadeの簡易的な関数を実行するだけで、クラスA,B,Cの複雑な処理を実施してくれる
  facade.Do();

  return 0;
}
