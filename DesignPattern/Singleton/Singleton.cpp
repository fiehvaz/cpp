/**
 * @file: Singleton.cpp
 *
 * @brief: Singleton model of the Design pattern.
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
 *  @brief シングルトンなクラス(インスタンスを一つしか許さない)
 */
class Singleton{
  public:
    /**
     *  @brief インスタンスのポインタを取得する関数
     */
    static Singleton* GetInstance(void){
      static Singleton singleton;  
      return &singleton;
    }

    /**
     *  @brief Numを設定する関数
     */
    void SetNum(int num){num_=num;}

    /**
     *  @brief Numを取得する関数
     */
    int GetNum(void){return num_;}
    
  private:
    Singleton(){}//コンストラクタをprivateに置く
    Singleton(const Singleton& r){}			//コピーコンストラクタも private に置く
    Singleton &operator=(const Singleton& r); //代入演算子も private に置く
    int num_;//オブジェクト確認用変数
};

int main(void){
  cout<<"Singleton Pattern Sample Start!!"<<endl;

  //シングルトンインスタンスの取得
  Singleton *singleton1=Singleton::GetInstance();
  Singleton *singleton2=Singleton::GetInstance();

  //値をセット
  singleton1->SetNum(10);

  //値の確認
  cout<<"Singleton1:"<<singleton1->GetNum()<<endl;
  cout<<"Singleton2:"<<singleton2->GetNum()<<endl;

  return 0;
}
