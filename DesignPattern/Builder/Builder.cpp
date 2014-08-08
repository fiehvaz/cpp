/**
 * @file: Builder.cpp
 *
 * @brief: Builder model of the Design pattern.
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
 * @brief Builder用抽象クラス
 */
class Builder{
  public:
    /**
     *  @brief ヘッダを作る関数
     */
    virtual void MakeHeader(string &text_)=0;

    /**
     *  @brief MainTextを作る関数
     */
    virtual void MakeMainText(string maintext, string &text_)=0;

    /**
     *  @brief Footerを作る関数
     */
    virtual void MakeFooter(string &text_)=0;
};

/**
 *  @brief PlainText作成用クラス
 */
class PlainTextBuilder:public Builder{

  void MakeHeader(string &text_){
    text_+="----------\n";
  }

  void MakeMainText(string maintext, string &text_){
    text_+="|"+maintext+"|\n";
  }

  void MakeFooter(string &text_){
    text_+="----Fin---\n";
  }

};

/**
 *  @brief PlainText作成用クラス
 */
class GorgeousTextBuilder:public Builder{

  void MakeHeader(string &text_){
    text_+="*********\n";
  }

  void MakeMainText(string maintext, string &text_){
    text_+="*"+maintext+"*\n";
  }

  void MakeFooter(string &text_){
    text_+="***Fin***\n";
  }

};

/**
 *  @brief 文書を作成するクラス
 */
class Director{
  public:
    Director(){}

    /**
     * @brief 文書を作成する関数
     */
    void Construct(void){
      builder_->MakeHeader(text_);
      builder_->MakeMainText("本文",text_);
      builder_->MakeFooter(text_);
    }

    /**
     * @brief 作成した文書を返す関数
     */
    const string& GetText(void){
      return text_;      
    }

    /**
     * @brief Builderのインスタンスを登録するクラス
     */
    void SetBuilder(Builder* builder){
      builder_=builder;
    }

  private:
    Builder* builder_;//登録されたBuilderインスタンスのポインタ
    string text_;//作成したテキストデータ
};

/**
 *  @brief Main
 */
int main(int argc,char *argv[]){
  cout<<"Builder Pattern Sample Start!!"<<endl;

  //引数を指定していない場合
  if(argc<2){
    cout<<"Add Command-line parameter"<<endl;
    return 0;//プログラム終了
  }

  string arg=argv[1];//コマンドライン引数を取得

  Director director;//文書作成クラスの作成

  if(arg=="plain"){
    cout<<"Create Plain Text"<<endl;
    PlainTextBuilder plain;
    director.SetBuilder(&plain);
  }
  else if(arg=="gorgeous"){
    cout<<"Create Gorgeous Text"<<endl;
    GorgeousTextBuilder gorg;
    director.SetBuilder(&gorg);
  }
  else{//予期されない引数の場合
    cout<<"Invalid text mode.Plase use plain or gorgeous"<<endl;
    return 0;
  }

  director.Construct();//文書作成
  string text=director.GetText();//作成した文書を取得
  cout<<text<<endl;

  return 0;
}
