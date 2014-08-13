/**
 * @file: Composite.cpp
 *
 * @brief: Composite Method model of the Design pattern.
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

/**
 *  @brief ディレクトリ内に存在するエントリの抽象クラス 
 **/
class Entry{
  public:
    virtual string* GetName(void)=0;
    virtual int GetSize(void)=0;
    virtual void ShowListInfo(const string& prefix)=0;

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
    *  @brief ファイルのデータを表示する関数 
    */
    void ShowListInfo(const string &prefix){
      ShowInfo(prefix);
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
    *  @brief リストのデータを表示する関数 再帰的にデータを表示
    */
    void ShowListInfo(const string &prefix){
      ShowInfo(prefix);
      int dsize=directory_.size();
      for(int i=0;i<dsize;i++){
        directory_[i]->ShowListInfo(prefix+"/"+*(GetName()));
      }
    }

   /**
    *  @brief リストのデータを表示する関数
    *         トップディレクトリでは引数無しで呼び出せるようにオーバロードする
    */
    void ShowListInfo(void){
      ShowListInfo("");
    }

  private:
    string name_;//ディレクトリ名
    vector<Entry*> directory_;//エントリ格納用DB
};

int main(void){
  cout<<"Composite Method Pattern Sample Start!!"<<endl;

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

  rootdir.ShowListInfo();//エントリのデータの表示

  cout<<"Making User directory..."<<endl;
  Directory tomdir("Tom");
  File avi("123.avi",100000);
  usrdir.Add(&tomdir);
  tomdir.Add(&avi);

  rootdir.ShowListInfo();//エントリのデータの表示

  return 0;
}
