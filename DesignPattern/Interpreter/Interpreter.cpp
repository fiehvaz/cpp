/**
 * @file: Interpreter.cpp
 *
 * @brief: Interpreter model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 *  @brief 構文解析用データクラス
 */
class Context {
  public:
    Context(string input) 
      : input_(input)
        , output_(0)
  {}

   /**
    *  @brief 入力値を取得する関数
    */
    string Input() {
      return input_;
    }

   /**
    *  @brief 入力値の設定する関数
    */
    void SetInput(string input) {
      input_ = input;
    }

   /**
    *  @brief 出力値を取得する関数
    */
    int Output() {
      return output_;
    }

   /**
    *  @brief 出力値を設定する関数
    */
    void SetOutput(int output) {
      output_ = output;
    }

  private:
    string input_;//入力値
    int output_;  //出力値
};

/**
 *  @brief ローマ字解析用kルアス
 **/
class Expression {
  public:
   /**
    *  @brief 構文解析を実施する関数
    */
    void Interpret(Context* context) {
      //contextが無ければ処理終了
      if(context->Input().empty())
        return;
      

      //各文字の種類に対して処理
      if(context->Input().find(Nine()) == 0) {
        context->SetOutput(context->Output() + 9 * Multiplier());
        context->SetInput(context->Input().substr(2));//9の時は二文字飛ばす
      } 
      else if(context->Input().find(Four()) == 0) {
        context->SetOutput(context->Output() + 4 * Multiplier());
        context->SetInput(context->Input().substr(2));//4の時は2文字飛ばす
      } 
      else if(context->Input().find(Five()) == 0) {
        context->SetOutput(context->Output() + 5 * Multiplier());
        context->SetInput(context->Input().substr(1));//5の時は一文字飛ばす
      }

      while(context->Input().find(One()) == 0) {//1は複数個続くことがある
        context->SetOutput(context->Output() + 1 * Multiplier());
        context->SetInput(context->Input().substr(1));
      }

    }

    virtual string One() = 0;
    virtual string Four() = 0;
    virtual string Five() = 0;
    virtual string Nine() = 0;
    virtual int Multiplier() = 0;//桁数
};

/**
 *  @brief 千の位のローマ字クラス
 */
class ThousandExpression : public Expression {
  public:
    string One() { return "M"; }
    string Four() { return " "; }
    string Five() { return " "; }
    string Nine() { return " "; }
    int Multiplier() { return 1000; }
};

/**
 *  @brief 百の位のローマ字クラス
 */
class HundredExpression : public Expression {
  public:
    string One() { return "C"; }
    string Four() { return "CD"; }
    string Five() { return "D"; }
    string Nine() { return "CM"; }
    int Multiplier() { return 100; }
};

/**
 *  @brief 十の位のローマ字クラス
 */
class TenExpression : public Expression {
  public:
    string One() { return "X"; }
    string Four() { return "XL"; }
    string Five() { return "L"; }
    string Nine() { return "XC"; }
    int Multiplier() { return 10; }
};

/**
 *  @brief 一の位のローマ字クラス
 */
class OneExpression : public Expression {
  public:
    string One() { return "I"; }
    string Four() { return "IV"; }
    string Five() { return "V"; }
    string Nine() { return "IX"; }
    int Multiplier() { return 1; }
};

int main() {
  cout<<"Interpreter Pattern Sample Start!!"<<endl;

  //ローマ字による数字
  string roman = "MCMXVIIII";
  Context context(roman);

  //各位の構文解析のためにオブジェクト配列の作成
  vector<Expression*> tree;
  tree.push_back(new ThousandExpression());
  tree.push_back(new HundredExpression());
  tree.push_back(new TenExpression());
  tree.push_back(new OneExpression());

  //構文解析 各桁のオブジェクトのInterpretを呼ぶ
  for(int i=0;i<tree.size();i++){
    tree[i]->Interpret(&context);
  }

  //解析結果を表示
  cout << roman << " = " << context.Output() << endl;

  return 0;
}

