/**
 * @file: Visitor.cpp
 *
 * @brief: Visitor Method model of the Design pattern.
 *
 * @author: Atsushi Sakai 
 *
 * @copyright (c): 2014 Atsushi Sakai
 *
 * @license : GPL Software License Agreement
 **/

#include <iostream>
#include <vector>

using namespace std;

//クラスのプロトタイプ宣言
class File;
class Directory;

/**
 *  @brief Visitor用抽象クラス
 **/
class Visitor{
  public:
    virtual void Visit(File *file)=0;
    virtual void Visit(Directory *Directory)=0;
  private:
};

/**
 *  @brief Visitor受け入れ用抽象クラス 
 **/
class Element{
  public:
    virtual void Accept(Visitor &v)=0;
  private:
};

/**
 *  @brief ディレクトリ内に存在するエントリの抽象クラス 
 **/
class Entry: public Element{
  public:
    virtual string* GetName(void)=0;
    virtual int GetSize(void)=0;

    /**
     *  @brief Entryのデータを表示する関数
     */
    void ShowInfo(const string &prefix){
      cout<<prefix+"/"+*(GetName())+" ["+to_string(GetSize())+"]"<<endl;
    }
};

/**
 *  @brief ファイル用クラス
 **/
class File : public Entry{
  public:
    File(const string &name,int size){
      name_=name;
      size_=size;
    }

    string* GetName(void){return &name_;}
    
    int GetSize(void){return size_;}

   /**
    *  @brief Visitor用Accept関数 
    */
    void Accept(Visitor &v){
      v.Visit(this);
    }

  private:
    string name_;
    int size_;
};

/**
 *  @brief ディレクトリ用クラス
 **/
class Directory : public Entry{
  public:
    Directory(const string &name){
      name_=name;
    }

    string* GetName(void){return &name_;}
    
   /**
    *  @brief ディレクトリのデータのサイズを返す関数
    *         再帰的にサイズを取得する
    */
    int GetSize(void){
      int size=0;
      int dsize=directory_.size();
      for(int i=0;i<dsize;i++){
        size+=directory_[i]->GetSize();
      }
      return size;
    }

    /**
     *  @brief エントリを追加する関数
     */
    void Add(Entry* entry){
      directory_.push_back(entry);
    }

   /**
    *  @brief Visitor用Accept関数 
    */
    void Accept(Visitor &v){
      v.Visit(this);
    }

    vector<Entry*> directory_;//エントリ格納用DB
  private:
    string name_;//ディレクトリ名
};

/**
 *  @brief Entryの内容を表示する用Vistorクラス 
 **/
class ListVisitor:public Visitor{
  public:
    /**
     *  @brief Fileクラス用Visit関数
     */
    void Visit(File *file){
      file->ShowInfo(str_);
    }

    /**
     *  @brief Directoryクラス用Visit関数
     */
    void Visit(Directory *directory){
      directory->ShowInfo(str_);
      int dsize=directory->directory_.size();
      str_+="/"+*(directory->GetName());
      for(int i=0;i<dsize;i++){
        directory->directory_[i]->Accept(*this);
      }
    }

  private:
    string str_;
};

int main(void){
  cout<<"Visitor Method Pattern Sample Start!!"<<endl;

  cout<<"Making top directory..."<<endl;
  Directory rootdir("root");
  Directory bindir("bin");
  Directory tmpdir("tmp");
  Directory usrdir("usr");

  //ディレクトリの追加
  rootdir.Add(&bindir);
  rootdir.Add(&tmpdir);
  rootdir.Add(&usrdir);
  
  //ファイルの作成
  File vim("vim",100);
  File git("git",1000);
  bindir.Add(&vim);
  bindir.Add(&git);

  //エントリのデータの表示
  rootdir.Accept(*(new ListVisitor()));

  cout<<"Making User directory..."<<endl;
  Directory tomdir("Tom");
  File avi("123.avi",100000);
  usrdir.Add(&tomdir);
  tomdir.Add(&avi);

  //エントリのデータの表示
  rootdir.Accept(*(new ListVisitor()));

  return 0;
}
