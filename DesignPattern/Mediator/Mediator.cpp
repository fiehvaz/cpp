/**
 * @file: Mediator.cpp
 *
 * @brief: Mediator model of the Design pattern.
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
 *  @brief Mediatorインターフェースクラス 
 **/
class Mediator{
  public:
    virtual void CreateColleagues(void)=0;
    virtual void ColleageModeChangeed(const string &name)=0;
  private:
};

/**
 *  @brief Colleagesインターフェース
 **/
class Colleages{
  public:
    Colleages(Mediator *mediator):mediator_(mediator){};
    //自分のモードを変更する関数
    virtual void ModeChange(void)=0;
    //他のColleageからモード変更を知らされる関数
    virtual void ReceiveModeChange(const string &name)=0;
  protected:
    Mediator* mediator_;
};

/**
 *  @brief Component Aクラス
 **/
class ComponentA:public Colleages{
  public:
    ComponentA(Mediator *mediator):Colleages(mediator){};

    void ModeChange(void){
      cout<<"ComponentA change mode"<<endl;
      mediator_->ColleageModeChangeed("a");
    }

    void ReceiveModeChange(const string &name){
      cout<<"ComponentA receive mode change from "<<name<<endl;
    }
    
  private:
};

/**
 *  @brief Component Bクラス
 **/
class ComponentB:public Colleages{
  public:
    ComponentB(Mediator *mediator):Colleages(mediator){};

    void ModeChange(void){
      cout<<"ComponentB change mode"<<endl;
      mediator_->ColleageModeChangeed("b");
    }

    void ReceiveModeChange(const string &name){
      cout<<"ComponentB receive mode change from "<<name<<endl;
    }

  private:
};

/**
 *  @brief Component Cクラス
 **/
class ComponentC: public Colleages{
  public:
    ComponentC(Mediator *mediator):Colleages(mediator){};

    void ModeChange(void){
      cout<<"ComponentC change mode"<<endl;
      mediator_->ColleageModeChangeed("c");
    }

    void ReceiveModeChange(const string &name){
      cout<<"ComponentC receive mode change from "<<name<<endl;
    }

  private:
};

/**
 *  @brief Concreate Mediator
 **/
class ConcreteMediator:public Mediator{
  public:
   /**
    *  @brief Colleagesを作成する関数
    */
    void CreateColleagues(void){
      //それぞれのコンポーネントのポインタをDBに登録
      ComponentA *a=new ComponentA(this);
      colleages_["a"]=a;
      ComponentB *b=new ComponentB(this);
      colleages_["b"]=b;
      ComponentC *c=new ComponentC(this);
      colleages_["c"]=c;
    }

    /**
     *  @brief Colleageのモードが変更された時に呼ばれる関数
     */
    void ColleageModeChangeed(const string &name){
      //イテレータの作成
      //DBを探索して他のColleageに変更があったことを伝える
      for (auto it=colleages_.begin();it!=colleages_.end();++it){
        if(it->first!=name){
          it->second->ReceiveModeChange(name);
        }
      }
    }

    /**
     *  @brief 外部からColleageのモードを変更する関数
     */
    void ChangeMode(const string &name){
      //イテレータの作成
      for(auto it=colleages_.begin();it!=colleages_.end();++it){
        if(it->first==name){
          it->second->ModeChange();
        }
      }
    }

  private:
    map<string, Colleages*> colleages_;//ColleagesのDB 
};

int main(void){
  cout<<"Mediator Pattern Sample Start!!"<<endl;

  ConcreteMediator *mediator=new ConcreteMediator;
  mediator->CreateColleagues();

  //aのモードを変更する
  mediator->ChangeMode("a");
  
  //cのモードを変更する
  mediator->ChangeMode("c");

  return 0;
}

