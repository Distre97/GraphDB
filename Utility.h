#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <set>
#include <map>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <variant>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
//#include <boost/bimap.hpp>
//#include <boost/bimap/set_of.hpp>
//#include <boost/bimap/multiset_of.hpp>
//#include <boost/bimap/support/lambda.hpp>
//#include <boost/graph/adjacency_list.hpp>

///醉后不知天在水,满船清梦压星河
namespace zecy {
using namespace std;
enum class Relat {OR, AND};                 //逻辑运算符与和或
enum class Order {DE, AS, UN};              //排序标志:降序,升序和无序
enum class Direc {IN, OUT, FROM, TO};       //图相关:入边,出边,起点和终点
enum class Stats {MIN, MAX, AVG, SUM};      //统计标志:最小值,最大值,平均值和求和
enum class Oprat {EQ, NE, GT, LT, GE, LE};  //关系运算符:=,<>,>,<,>=,<=

using _ID = size_t;                         //实体或关系编号
using _IDS = set<_ID>;                      //编号集
using _pack = pair<int, string>;            //数据:(类型,字符串),类型4种
using _type = variant<string, int, double, bool>;   //四种数据类型
using _prop = pair<string, _type>;          //属性1:(键,值)
using _cond = pair<Oprat, _prop>;           //条件:(关系运算符,属性)
using _attr = pair<_type, _ID>;             //属性2:(值,键)
using _edge = pair<_ID, _ID>;               //关系:(起点编号,终点编号)
using _lists = vector<string>;              //字符串数组,用于存放多个键
using _conds = vector<_cond>;               //条件序列,多个条件
using _popes = vector<_prop>;               //属性序列,多个属性
using _edges = map<_ID, _edge>;             //边表:<关系编号,关系>
using _verts = map<_ID, pair<_IDS, _IDS>>;  //点表:<实体编号,(出边集,入边集)>
using _props = unordered_map<_ID, map<string, _type>>;      //属性集1:<编号,<键,值>>
using _attrs = unordered_map<string, multimap<_type, _ID>>; //属性集2:<键,<值,编号>>,multimap多值

const static _IDS ANY = {0};                    //定义全集,0作为保留编号
const static size_t INF = (unsigned)!((int)0);  //定义无穷,用于运算除0错误处理
template <typename T>                           //定义二元四则运算
const T calculate(const char& ca, const T& t1, const T& t2) {
    switch(ca) {
    case '+':
        return (t1 + t2);
    case '-':
        return (t1 - t2);
    case '*':
        return (t1 * t2);
    case '/':
        return t2 == 0 ? INF : (t1 / t2);
    default:
        return INF;
    }
};
/********************************************//**
 * \brief   split:字符串分割
 *
 * \param   原字符串:str
 * \param   分割符正则表达式定义串:delims
 * \return  分割后的字符串序列
 *
 ***********************************************/
const function<_lists(string, string)> split = [](const string& str, const string& delims) {
    auto ss = istringstream(regex_replace(str, regex(delims), " "));
    return _lists{istream_iterator<string>(ss), {}};
};
/********************************************//**
 * \brief   pack_data,由于variant类型不可动态确定其类型和值,用于存储数据时转换为字符串
 *
 * \param   数据类型:_type
 * \param
 * \return  数据对:_pack
 *
 ***********************************************/
const function<_pack(_type)> pack_data = [](_type d) -> const _pack {
    switch(d.index()) {
    case 1:
        return _pack(1, to_string(get<int>(d)));
    case 2:
        return _pack(2, to_string(get<double>(d)));
    case 3:
        return _pack(3, get<bool>(d) ? string("true") : string("false"));
    default:
        return _pack(0, get<string>(d));
    }
};
/********************************************//**
 * \brief   make_data:将(类型,字符串)型数据转换为variant类型
 *
 * \param   数据对p:_pack
 * \param
 * \return  数据类型:_type
 *
 ***********************************************/
const function<_type(_pack)> make_data = [](_pack p) -> const _type {
    switch(p.first) {
    case 1:
        return stoi(p.second);
    case 2:
        return stod(p.second);
    case 3:
        return p.second == "true";
    default:
        return p.second;
    }
};
/********************************************//**
 * \brief   isDigits:用于判断字符串是否符合转换为数值的标准
 *
 * \param   字符串str
 * \param
 * \return  bool,true代表可以转换,false代表不行
 *
 ***********************************************/
const function<bool(const string)> isDigits = [](const string str) -> bool {
    return regex_match(str, regex("((\\-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?"));
};
/********************************************//**
 * \brief   set_token:将关系运算符的字符串值转化为枚举值
 *
 * \param   要转换的关系运算符op:string
 * \param
 * \return  关系原算符:Oprat
 *
 ***********************************************/
const function<Oprat(const string)> set_token = [](const string op) -> const Oprat {
    Oprat tmp;
    if(op == ">") {
        tmp = Oprat::GT;
    } else if(op == "<") {
        tmp = Oprat::LT;
    } else if(op == ">=") {
        tmp = Oprat::GE;
    } else if(op == "<=") {
        tmp = Oprat::LE;
    } else if(op == "=") {
        tmp = Oprat::EQ;
    } else if(op == "<>") {
        tmp = Oprat::NE;
    }  else {
        tmp = Oprat::EQ;
    }
    return tmp;
};

class Condt {
  private:
    _cond cond;
  public:
    Condt(string str, int type) {
        _lists tmp;
        str.erase(remove_if(str.begin(), str.end(), [](const auto a) {
            return isspace(a);
        }), str.end());
        regex re("([!<=>]|[^!<=>]+)");
        for(auto it = sregex_iterator(str.begin(), str.end(), re); it != sregex_iterator(); it++) {
            tmp.emplace_back(it->str());
        }
        if(tmp.size() == 3) {
            this->cond = _cond(set_token(tmp[1]), _prop(tmp[0], make_data(_pack(type, tmp[2]))));
        } else if(tmp.size() == 4) {
            this->cond = _cond(set_token(tmp[1] + tmp[2]), _prop(tmp[0], make_data(_pack(type, tmp[3]))));
        } else {
            cout << "synatx error : " << str;
        }
    }
    const _cond get_cond() {
        return this->cond;
    }
};

}

//using _edges = boost::bimap<_ID, pair<_ID, _ID>>;
//using _attrss = unordered_map<string, boost::bimap<boost::bimaps::set_of<_ID>, boost::bimaps::multiset_of<_type>>>;
//using _graph = boost::adjacency_list<boost::listS, boost::vecS, boost::bidirectionalS>;
//using _vedes = boost::graph_traits<_graph>::vertex_descriptor;
//using _egdes = boost::graph_traits<_graph>::edge_descriptor;
#endif // UTILITY_H_INCLUDED
