/**
 * @file: Flyweight.cpp
 *
 * @brief: Flyweight model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 *  @brief 文字を装飾して返すクラス
 **/
class CharFactory{
  public:
    string Create(string s){
      return "===="+s+"====";
    }

  private:
};

/**
 *  @brief 文字列を装飾するクラス 
 **/
class GorgeousString{
  public:

    GorgeousString(const string &str){
      CharFactory factory;
      for(int i=0;i<str.length();i++){
        string s=str.substr(i,1);
        string gs;
        //DBの中に無かったら、オブジェクトを作る
        if(stringDB_.find(s) == stringDB_.end()){
            gs=factory.Create(s);
            stringDB_[s] = gs;
        }
        else{//DBの中に合ったら、それを使う
            gs=stringDB_[s];
        }

        gString_.push_back(gs);
      }

      cout<<"DB Size:"<<stringDB_.size()<<endl;
    }

   /**
    *  @brief 文字列を表示する
    */
    void Show(void){
      for(int i=0;i<gString_.size();i++){
        cout<<gString_[i]<<endl;
      }
    }

  private:
    vector<string> gString_;      //装飾した文字列
    map<string,string> stringDB_; //文字のDB
};

int main(void){
  cout<<"Flyweight Pattern Sample Start!!"<<endl;

  GorgeousString gString("AABBBC");
  gString.Show();

  return 0;
}
