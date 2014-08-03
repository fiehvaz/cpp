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
    Product* Create(string type,string name){
      Product* p=CreateProduct(type,name); 
      return p;
    }

  private:
    /**
     *  @brief Productを作成する純粋仮想関数
     *  @param type Productの種類
     *  @param name Productの所有者の名前
     */
    virtual Product* CreateProduct(string type, string name)=0;
};

/**
 *  @brief 文房具を作るFactoryクラス
 */
class StationeryFactory: public Factory{
  public:
    /**
     * @brief Productを作成する関数
     */
    Product* CreateProduct(string type,string name){
      if(type=="BusinessCard"){
        return new BusinessCard(name);
      }
      else if(type=="IDCard"){
        return new IDCard(name);
      }
      else{
        cout<<"Unknown Stationery:"<<type<<endl;
        return 0;
      }
    }
};

int main(void){
  cout<<"Factory Method Pattern Sample Start!!"<<endl;

  //Factoryの作成
  Factory *factory=new StationeryFactory(); 

  //Factoryから文房具を生成する
  Product *item1  = factory->Create("BusinessCard","TOM");
  Product *item2  = factory->Create("BusinessCard","SAM");
  Product *item3  = factory->Create("IDCard","RAI");
  Product *item4  = factory->Create("IDCard","TED");

  //それぞれの文房具を使用する
  item1->Use();
  item2->Use();
  item3->Use();
  item4->Use();

  return 0;
}
