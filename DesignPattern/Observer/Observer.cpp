/**
 * @file: Observer.cpp
 *
 * @brief: Observer model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <time.h>//乱数初期化用

#include <iostream>
#include <vector>

using namespace std;

class NumberGenerator;

/**
 *  @brief オブザーバー用抽象クラス
 **/
class Observer{
  public:
    //オブザーバにNotifyする時に呼ばれる関数
    virtual void Update(NumberGenerator *generator)=0;
};

/**
 *  @brief 数字作成の抽象クラス
 **/
class NumberGenerator{
  public:
   /**
    *  @brief Observerを追加する関数
    */
    void AddObserver(Observer *observer){
      observers_.push_back(observer);
    }

   /**
    *  @brief 登録されたObserverに通知を実施する関数 
    */
    void Notify(void){
      int nobserver=observers_.size();
      for(int io=0;io<nobserver;io++){
        //登録されたすべてのオブザーバのUpdate関数を呼ぶ
        observers_[io]->Update(this); 
      }
    }

    virtual int GetNum(void)=0;
    virtual void Generate(void)=0;

  private:
    vector<Observer*> observers_;//オブザーバのポインタのリスト
};

/**
 *  @brief 数字を表示するオブザーバー
 */
class DigitObserver:public Observer{
  public:
   /**
    *  @brief Updateされた時に数字として表示する関数
    */
    void Update(NumberGenerator *generator){
      cout<<"DigitObserver:"<<generator->GetNum()<<endl;
    }
  private:
};

/**
 *  @brief 数字をスターで表示するオブザーバー
 */
class StarObserver:public Observer{
  public:
   /**
    *  @brief Updateされた時に*として表示する関数
    */
    void Update(NumberGenerator *generator){
      cout<<"DigitObserver:";
      for(int i=0;i<generator->GetNum();i++){
        cout<<"*";
      }
      cout<<endl;
    }
  private:
};


/**
 *  @brief 乱数発生クラス
 **/
class RandomNumberGenerator:public NumberGenerator{
  public:
    RandomNumberGenerator(void){
      srand((unsigned int)time(NULL));//乱数初期化
    }

   /**
    *  @brief 生成された乱数を返す関数 
    */
    int GetNum(void){return number_;}

   /**
    *  @brief 乱数を10個発生させ、オブザーバに通知する関数 
    */
    void Generate(void){
      for(int i=0;i<10;i++){
        number_=rand()%100;
        Notify();//登録されたオブザーバーに通知 
      }
    }
    
  private:
    int number_;//生成した値
};


int main(void){
  cout<<"Observer Pattern Sample Start!!"<<endl;

  NumberGenerator* generator=new RandomNumberGenerator();
  Observer *ob1=new DigitObserver();
  Observer *ob2=new StarObserver();

  //オブザーバーの登録
  generator->AddObserver(ob1);
  generator->AddObserver(ob2);
  
  //数字の発生
  generator->Generate();

  return 0;
}
