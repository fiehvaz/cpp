/**
 * @file: Abstract Facroty.cpp
 *
 * @brief: Abstract Facroty Method model of the Design pattern.
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
 *  @brief 仮想主食クラス
 */
class AbstructStapleMeal{
  public:

   /**
    *  @brief 食べる関数 
    */
    virtual void Eat(void)=0;
};

/**
 *  @brief 仮想メイン食事クラス
 */
class AbstructMainMeal{
  public:

    /**
     *  @brief 食べる関数
     */
    virtual void Eat(void)=0;
};

/**
 *  @brief 仮想スープクラス
 */
class AbstructSoup{
  public:

    /**
     *  @brief 食べる関数
     */
    virtual void Eat(void)=0;
};

/**
 *  @brief 仮想食事向上
 */
class AbstructMealFactory{
  public:
    virtual AbstructStapleMeal* CreateStapleMeal(void)=0;
    virtual AbstructMainMeal* CreateMainMeal(void)  =0;
    virtual AbstructSoup* CreateSoup(void)      =0;
};

/**
 *  @brief 日本食の主食クラス
 */
class JapaneaseStapleMeal:public AbstructStapleMeal{
  public:
    void Eat(void){
      cout<<"ご飯を食べます"<<endl;
    }
};

/**
 *  @brief 日本食のメイン食事クラス
 */
class JapaneaseMainMeal:public AbstructMainMeal{
  public:
    void Eat(void){
      cout<<"焼き魚を食べます"<<endl;
    }
};

/**
 *  @brief 日本食のスープクラス
 */
class JapaneaseSoup:public AbstructSoup{
  public:
    void Eat(void){
      cout<<"味噌汁を食べます"<<endl;
    }
};

/**
 *  @brief 日本食作成工場クラス
 */
class JapaneaseMealFactory:public AbstructMealFactory{
  public:
    AbstructStapleMeal* CreateStapleMeal(void){
      AbstructStapleMeal *meal=new JapaneaseStapleMeal;
      return meal;
    }

    AbstructMainMeal* CreateMainMeal(void){
      AbstructMainMeal *meal=new JapaneaseMainMeal;
      return meal;
    }

    AbstructSoup* CreateSoup(void){
      AbstructSoup *meal=new JapaneaseSoup;
      return meal;
    }

};

/**
 *  @brief アメリカ主食クラス
 */
class AmericanStapleMeal:public AbstructStapleMeal{
  public:
    void Eat(void){
      cout<<"パンを食べます"<<endl;
    }
};

/**
 *  @brief アメリカメイン食事クラス
 */
class AmericanMainMeal:public AbstructMainMeal{
  public:
    void Eat(void){
      cout<<"ステーキを食べます"<<endl;
    }
};

/**
 *  @brief アメリカスープクラス
 */
class AmericanSoup:public AbstructSoup{
  public:
    void Eat(void){
      cout<<"チキンスープを食べます"<<endl;
    }
};

/**
 *  @brief アメリカの食事作成工場クラス 
 */
class AmericanMealFactory:public AbstructMealFactory{
  public:
    AbstructStapleMeal* CreateStapleMeal(void){
      AbstructStapleMeal *meal=new AmericanStapleMeal;
      return meal;
    }

    AbstructMainMeal* CreateMainMeal(void){
      AbstructMainMeal *meal=new AmericanMainMeal;
      return meal;
    }

    AbstructSoup* CreateSoup(void){
      AbstructSoup *meal=new AmericanSoup;
      return meal;
    }
};

int main(void){
  cout<<"Abstract Facroty Pattern Sample Start!!"<<endl;

  cout<<"====日本食を食べます===="<<endl;

  AbstructMealFactory *factory=new JapaneaseMealFactory();

  AbstructStapleMeal *stapleMeal=factory->CreateStapleMeal();
  stapleMeal->Eat();

  AbstructMainMeal *mainMeal=factory->CreateMainMeal();
  mainMeal->Eat();

  AbstructSoup *soupMeal=factory->CreateSoup();
  soupMeal->Eat();

  cout<<"====アメリカ料理を食べます===="<<endl;

  AbstructMealFactory *factory2=new AmericanMealFactory();

  AbstructStapleMeal *stapleMeal2=factory2->CreateStapleMeal();
  stapleMeal2->Eat();

  AbstructMainMeal *mainMeal2=factory2->CreateMainMeal();
  mainMeal2->Eat();

  AbstructSoup *soupMeal2=factory2->CreateSoup();
  soupMeal2->Eat();

  return 0;
}
