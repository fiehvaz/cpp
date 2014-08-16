/**
 * @file: ChainOfResponsibility.cpp
 *
 * @brief: Chain Of Responsibility model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <iostream>
#include <cstdint>

using namespace std;

/**
 *  @brief 物品購入用クラス 
 **/
class Purchase{
  public:
    Purchase(int itemNumber, uint64_t price):
      itemNumber_(itemNumber),
      price_(price){}

    uint64_t GetPrice(void) const {return price_;}

    int GetItemNumber(void) const {return itemNumber_;}

  private:
    int itemNumber_;//物品番号
    uint64_t price_;//値段
};

/**
 *  @brief 承認者の抽象クラス
 **/
class Approver{
  public:
    Approver(const string &name):name_(name){}

   /**
    *  @brief 次の承認者をセットする関数 
    */
    void SetNext(Approver* next){
      next_=next;
    }

    /**
     *  @brief 承認用仮想関数
     */
    virtual void Approve(const Purchase &item)=0;

  protected:
    string name_;//承認者の名前
    Approver* next_;//次の承認者
};

/**
 *  @brief Directorクラス 
 **/
class Director: public Approver{
  public:
    Director(const string &name):Approver(name){}

    void Approve(const Purchase &item){
      if(item.GetPrice()<100000.0){
        cout<<"Item "<<item.GetItemNumber()<<" is apprived by "<<name_<<endl;
      }
      else{//次の承認者に
        next_->Approve(item);
      }
    }
    
  private:
};

/**
 *  @brief VicePresidentクラス
 **/
class VicePresident: public Approver{
  public:
    VicePresident(const string &name):Approver(name){}

    void Approve(const Purchase &item){
      if(item.GetPrice()<10000000.0){
        cout<<"Item "<<item.GetItemNumber()<<" is apprived by "<<name_<<endl;
      }
      else{//次の承認者に
        next_->Approve(item);
      }
    }
    
  private:
};

/**
 *  @brief CEOクラス
 **/
class CEO: public Approver{
  public:
    CEO(const string &name):Approver(name){}

    void Approve(const Purchase &item){
      if(item.GetPrice()<10000000000.0){
        cout<<"Item "<<item.GetItemNumber()<<" is apprived by "<<name_<<endl;
      }
      else{//CEOでも決済できないのでCommityに
        cout<<"Item "<<item.GetItemNumber()<<" will be apprived by commity"<<endl;
      }
    }
    
  private:
};

int main(void){
  cout<<"Chain Of Responsibility Pattern Sample Start!!"<<endl;

  //承認者の作成
  Approver* taro= new Director("taro");
  Approver* ray=  new VicePresident("ray");
  Approver* jobs= new CEO("jobs");

  //承認者のchainを作成
  taro->SetNext(ray);
  ray->SetNext(jobs);

  //購入品
  Purchase books(1,5000);
  Purchase pc(2,300000);
  Purchase building(3,30000000);
  Purchase campany(4, 90000000000);

  //Directorから承認スタート
  taro->Approve(books);
  taro->Approve(pc);
  taro->Approve(building);
  taro->Approve(campany);

  return 0;
}
