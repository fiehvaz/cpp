/**
 * @file: Decorator.cpp
 *
 * @brief: Foratoractory model of the Design pattern.
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
 *  @brief 仮想文字列表示クラス
 **/
class Display{
  public:
    //文字列の個数を返す
    virtual int GetColumns(void)=0;
    //文字列を返す
    virtual string GetRawText(void)=0;
    //文字列を表示
    void Show(void){
      cout<<GetRawText()<<endl;
    }
};

/**
 *  @brief 一つの文字列クラス
 **/
class StringDisplay:public Display{
  public:
    StringDisplay(const string &str):str_(str){}
    int GetColumns(void){return str_.size();}
    string GetRawText(void){return str_;};
  private:
    string str_;//文字列データ
};

/**
 *  @brief 文字を装飾するためのテンプレートクラス 
 **/
class Border:public Display{
  public:
    Border(Display *display):display_(display){}
    Display *display_;
};

/**
 *  @brief 文字の横方向に任意の飾り文字を付けるクラス 
 **/
class SideBorder:public Border{
  public:
    SideBorder(Display *display,string str):Border(display),str_(str){}

    string GetRawText(void){
      return (str_+display_->GetRawText()+str_);
    };

    int GetColumns(void){return display_->GetColumns()+2;}

  private:
    string str_;
};

/**
 *  @brief 文字の上下左右に飾り文字を付けるクラス 
 **/
class FullBorder:public Border{
  public:
    FullBorder(Display *display):Border(display){}

    string GetRawText(void){
      string str=GetLine(display_->GetColumns()+2);
      str+="*"+display_->GetRawText()+"*\n";
      str+=GetLine(display_->GetColumns()+2);
      return str;
    };

    int GetColumns(void){return (display_->GetColumns()+2);}

  private:
    /**
     *  @brief 横線を描画する関数 
     */
    string GetLine(int nCol){
      string str="";
      for(int i=0;i<nCol;i++){
        str+="-";
      }
      str+="\n";
      return str;
    }
};

int main(void){
  cout<<"Decorator Pattern Sample Start!!"<<endl;

  Display *d1=new StringDisplay("HogeHoge");
  cout<<endl;
  d1->Show();

  Display *d2=new SideBorder(d1,"@");
  cout<<endl;
  d2->Show();

  Display *d3=new FullBorder(d2);
  cout<<endl;
  d3->Show();

  return 0;
}
