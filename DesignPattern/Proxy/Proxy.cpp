/**
 * @file: Proxy.cpp
 *
 * @brief: Proxy model of the Design pattern.
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
 *  @brief 名前DBのインターフェースクラス
 **/
class INameDB{
  public:
    virtual void SetName(string &name)=0;
    virtual string GetName(void)=0;
    virtual int GetNameSize(void)=0;
  private:
};

/**
 *  @brief 名前DBのクラス
 **/
class NameDB:public INameDB{
  public:
    NameDB(){
      cout<<"=====Create NameDB====="<<endl;
    }

    void SetName(string &name){name_=name;}

    string GetName(void){return name_;}

    int GetNameSize(void){
      return name_.size();
    }

  private:
    string name_;
};


/**
 *  @brief 名前DBのプロキシクラス
 **/
class NameDBProxy:public INameDB{
  public:
    void SetName(string &name){name_=name;}

    string GetName(void){return name_;}

    /**
    *  @brief 名前の大きさを取得する関数
    *         プロキシクラスは実装していないため、
    *         NodeDBのオブジェクトを使う
    **/
    int GetNameSize(void){
      if(nameDB==NULL){
        nameDB=new NameDB();
      }

      nameDB->SetName(name_);
      return nameDB->GetNameSize();
    }

  private:
    NameDB *nameDB;
    string name_;
};

int main(void){
  cout<<"Proxy Pattern Sample Start!!"<<endl;

  INameDB *iNameDB = new NameDBProxy();

  string name="taro";
  iNameDB->SetName(name);
  cout<<iNameDB->GetName()<<endl;
  cout<<iNameDB->GetNameSize()<<endl;
  return 0;
}
