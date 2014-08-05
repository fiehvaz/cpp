/**
 * @file: Prototype.cpp
 *
 * @brief: Prototype model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <iostream>
#include <map>

using namespace std;

/**
 *  @brief 文字を装飾するクラス
 */
class Decoration{
  public:
    /**
     *  @brief コンストラクタで取得した文字列を装飾文字とする
     */
    Decoration(string dec){
      decstr_=dec;
    }

    /**
     *  @brief 装飾文字で挟んで文字列を表示する関数
     */
    void Use(string str){
      cout<<decstr_<<str<<decstr_<<endl;
    }

  private:
    string decstr_;//装飾用の文字列
};

/**
 *  @brief Decorationクラスのオブジェクトのコピーを作る
 *         Prototypeクラス
 */
class PrototypeCreator{
  public:
    PrototypeCreator(){}

    /**
     *  @brief オブジェクトの登録をするクラス
     */
    void Register(string name, Decoration* dec){
      db_[name]=dec;
    }

    /**
     *  @brief 登録したオブジェクトをKeyから取得する関数
     */
    Decoration* GetDecoration(string key){
      return db_[key];
    }

  private:
    map<string,Decoration*> db_;//オブジェクトのDB
};

int main(void){
  cout<<"Prototype Pattern Sample Start!!"<<endl;

  //文字のデコレーション方法1
  Decoration dec1("**");
  dec1.Use("Hello");

  //文字のデコレーション方法2
  Decoration dec2("~~~~~~~");
  dec2.Use("Hi");

  //Prototype形式のオブジェクトを作成し、登録する
  PrototypeCreator creator;
  creator.Register("TwoStar", &dec1);
  creator.Register("Wave", &dec2);

  //登録したオブジェクトを取得
  Decoration *TwoStar=creator.GetDecoration("TwoStar");
  Decoration *Wave   =creator.GetDecoration("Wave");

  TwoStar->Use("Good");
  Wave->Use("Bye");

  return 0;
}
