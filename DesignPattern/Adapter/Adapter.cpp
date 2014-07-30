/**
 * @file: Adapter.cpp
 *
 * @brief: Adapter model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <iostream>
#include <string>

using namespace std;

/**
 *  @brief 日本語で表示指令をするインターフェースクラス
 */
class PrintInterface{
  public:
    //一重角括弧
    virtual string Kakko(string str)=0;
    //二重角括弧
    virtual string DaburuKakko(string str)=0;
};

/**
 *  @brief 英語版Printクラス
 */
class EnglishPrint{
  public:
    string Brackets(string str){
      return ("["+str+"]");
    }

    string DoubleBrackets(string str){
      return ("[["+str+"]]");
    }
};

/**
 *  @brief 英語Printクラスを使用した日本語アダプタ
 */
class JapanesePrint : public PrintInterface{
  public:
    /**
     *  @brief 日本語版Blackets(一重括弧)
     */
    string Kakko(string str){
      return (eng_.Brackets(str));
    }

    /**
     *  @brief 日本語版Double Blackets(二重括弧)
     */
    string DaburuKakko(string str){
      return (eng_.DoubleBrackets(str));
    }

  private:
    EnglishPrint eng_;
};

int main(void){
  std::cout<<"Adapter Pattern Sample Start!!"<<std::endl;

  //英語命令のクラスをそのまま使った場合
  EnglishPrint eng;
  cout<<eng.Brackets("Hi!")<<endl;
  cout<<eng.DoubleBrackets("Ho!")<<endl;

  //日本語アダプタを使用した場合
  JapanesePrint jap;
  cout<<jap.Kakko("こんにちは!")<<endl;
  cout<<jap.DaburuKakko("ほー!")<<endl;

  return 0;
}
