#ifndef PROPERTY_H
#define PROPERTY_H

#include "Tree.h"

using namespace zecy;

class Property {                //属性基类
  protected:
    _IDS fre;                   //已经删除的编号与可用编号的集合,编号的可回收
    string name;                //文件名
    _ID id_generator();         //编号生成器
    Property(){}
    Property(string name);
    virtual ~Property(){}
    void init(string name);     //初始化

  public:
    _props pro;                 //属性编号表,用于通过编号查找
    _attrs atr;                 //属性查找表,用于通过属性值查找
    bool count(_ID id);         //判断是否存在某编号
    void save();                //将数据写回文件

    ///增
    _ID add(const _popes& ps);
    bool add(const _ID& id, const _prop& pr);
    bool add(const _ID& id, const _popes& ps);
    ///删
    bool del(const _ID& id, const string& key = "");
    bool del(const _IDS& ids, const _lists& keys);
    ///查
    _IDS inq(const _cond& cd, const _IDS& rg = ANY);
    _IDS inq(const Relat& re, const _cond& cd1, const _cond& cd2);
    _IDS inq(const Relat& re, const _cond& cd, const _IDS& rg);
    void inq(const string& key, const Stats& st, const _IDS& rg);
    ///改
    _ID alt(const _ID& id, const Assignment& ass);
    void alt(const _IDS& ids, const string& expression);
  private:
};

class VertexProperty: public Property {     //实体属性类
  public:
    VertexProperty() {
        this->init("vertex");
    }
    //显示
    bool show(const _ID& id, const _lists& keys = {});
    void show(const _IDS& ids, _lists keys, const Order& od);
  protected:
  private:
};

class EdgeProperty: public Property {   //关系属性类
  public:
    EdgeProperty() {
        this->init("edge");
    }
    //显示
    bool show(const _ID& id, const _edge& eg, const _lists& keys);
    void show(_edges egs, _lists keys, const Order& od);
  protected:
  private:
};
//重载|和&运算符用于集合的交集和并集运算
_IDS operator|(const _IDS& a, const _IDS& b);
_IDS operator&(const _IDS& a, const _IDS& b);
#endif // PROPERTY_H
