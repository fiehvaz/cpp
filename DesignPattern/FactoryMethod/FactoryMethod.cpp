/**
 * @file: FactoryMethod.cpp
 *
 * @brief: Factory Method model of the Design pattern.
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
 *  @brief Productの抽象クラス
 */
class Product{
  public:
    virtual void Use(void)=0;
};

/**
 * @brief IDCardを表すクラス
 */
class IDCard: public Product{
  public:
    /**
     *  @brief コンストラクタで使用者を登録する。
     */
    IDCard(string name){
      ownerName_=name;
    }

    /**
     *  @brief IDCardを使用する関数
     */
    void Use(void){
      cout<<"これは"<<ownerName_<<"さんのIDCardです."<<endl;
    }

  private:
    string ownerName_;//使用者の名前
};

/**
 * @brief BusinessCardを表すクラス
 */
class BusinessCard: public Product{
  public:
    /**
     *  @brief コンストラクタで使用者を登録する。
     */
    BusinessCard(string name){
      ownerName_=name;
    }

    /**
     *  @brief BusinessCardを使用する関数
     */
    void Use(void){
      cout<<"これは"<<ownerName_<<"さんのBusinessCardです."<<endl;
    }

  private:
    string ownerName_;//使用者の名前
};

/**
 *  @brief 抽象Factoryクラス
 */
class Factory{
  public:
    /**
     *  @brief Productを生成し、そのインスタンスを返す関数
    */
    Product* Create(string name){
      Product* p=CreateProduct(name); 
      return p;
    }

  private:
    virtual Product* CreateProduct(string name)=0;
};

/**
 *  @brief IDCardを作るFactoryクラス
 */
class IDCardFactory: public Factory{
  public:
    Product* CreateProduct(string name){
      return new IDCard(name);
    }
};

/**
 *  @brief BusinessCardを作るFactoryクラス
 */
class BusinessCardFactory: public Factory{
  public:
    Product* CreateProduct(string name){
      return new BusinessCard(name);
    }
};

int main(void){
  cout<<"Factory Method Pattern Sample Start!!"<<endl;

  //Factoryの作成
  Factory *IDfactory=new IDCardFactory(); 
  Factory *businessCardfactory=new BusinessCardFactory(); 

  //Factoryから文房具を生成する
  Product *item1  = IDfactory->Create("TOM");
  Product *item2  = IDfactory->Create("SAM");
  Product *item3  = businessCardfactory->Create("RAI");
  Product *item4  = businessCardfactory->Create("TED");

  //それぞれの文房具を使用する
  item1->Use();
  item2->Use();
  item3->Use();
  item4->Use();

  return 0;
}
