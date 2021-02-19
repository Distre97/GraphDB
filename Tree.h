#ifndef TREE_H
#define TREE_H

#include "Utility.h"
#include <stack>
#include <regex>
#include <memory>
#include <sstream>

using namespace zecy;
//定义表达式二叉树节点,只存操作符或操作数
template <typename oprator, typename operand>
class Node {
  private:
    shared_ptr<oprator> _oprator;               //操作符
    shared_ptr<operand> _operand;               //操作数
  public:
    shared_ptr<Node<oprator, operand>> left;    //左孩子
    shared_ptr<Node<oprator, operand>> right;   //右孩子
    oprator& getOpr() {                         //获取节点的操作符
        return *_oprator;
    }
    operand& getOpd() {                         //获取节点的操作数
        return *_operand;
    }
    bool isOpr() {                              //判断节点是否存操作符
        return this->_oprator != nullptr;
    }
    bool isOpd() {                              //判断节点是否存操作符
        return this->_operand != nullptr;
    }
    //空节点构造函数
    Node(): _oprator(nullptr), _operand(nullptr), left(nullptr), right(nullptr) {}
    //操作符节点构造函数
    Node(const oprator& op): _operand(nullptr), left(nullptr), right(nullptr) {
        this->_oprator = shared_ptr<oprator>(new oprator(op));
    }
    //操作数节点构造函数
    Node(const operand& ex): _oprator(nullptr), left(nullptr), right(nullptr) {
        this->_operand = shared_ptr<operand>(new operand(ex));
    }
};

using _Node = Node<char, string>;   //定义操作符为char,操作数为string的节点
using _pNode = shared_ptr<_Node>;   //节点指针

class Expression {
  private:
    stack<char> opr;    //操作符栈
    stack<_pNode> opd;  //操作数栈
    _lists exp;         //表达式字符串序列
    void build() {      //生成表达式二叉树并进行语法检查
        for(auto rit = rbegin(this->exp); rit != rend(this->exp); rit++) {
            if(*rit == "*" || *rit == "/" || *rit == ")") {
                this->opr.push((char)(*rit)[0]);
            } else if(*rit == "+" || *rit == "-") {
                if(!this->opr.empty() && (this->opr.top() == '*' || this->opr.top() == '/')) {
                    while(!this->opr.empty() && (this->opr.top() == '*' || this->opr.top() == '/')) {
                        _pNode tmp(new _Node(this->opr.top()));
                        this->opr.pop();
                        tmp->left = this->opd.top(), this->opd.pop();
                        if(!this->opd.empty()) {
                            tmp->right = this->opd.top(), this->opd.pop();
                        } else {
                            this->valid = false;    ///栈内无操作数,语法错误
                        }
                        this->opd.push(tmp);
                    }
                }
                this->opr.push((char)(*rit)[0]);
            } else if(*rit == "(") {
                while(this->opr.top() != ')') {
                    _pNode tmp(new _Node(this->opr.top()));
                    this->opr.pop();
                    tmp->left = this->opd.top(), this->opd.pop();
                    if(!this->opd.empty()) {
                        tmp->right = this->opd.top(), this->opd.pop();
                    } else {
                        this->valid = false;       ///栈内无操作数,语法错误
                    }
                    this->opd.push(tmp);
                }
                if(!this->opr.empty()) {
                    this->opr.pop();
                } else {
                    this->valid = false;           ///栈内无符号,即括号不匹配,语法错误
                }
            } else {
                _pNode tmp(new _Node(*rit));
                this->opd.push(tmp);
            }
        }
        while(!this->opr.empty()) {
            _pNode tmp(new _Node(this->opr.top()));
            this->opr.pop();
            tmp->left = this->opd.top(), this->opd.pop();
            if(!this->opd.empty()) {
                tmp->right = this->opd.top(), this->opd.pop();
            } else {
                this->valid = false;    ///栈内无操作数,语法错误
            }
            this->opd.push(tmp);
        }
        this->tree = this->valid ? this->opd.top() : nullptr;   ///语法错误则将树指针置空
    }

    void pre(string str) {  //表达式预处理,将字符串按空格和运算符分割,合并负号,转化为表达式序列
        regex_replace(str, regex("^ +| +$|( ) +"), "$1");
        regex re("([\\s/\\-*+()]|[^\\s/\\-*+()]+)");
        for(auto it = sregex_iterator(str.begin(), str.end(), re); it != sregex_iterator(); it++) {
            this->exp.emplace_back(it->str());
        }//分割字符串
        this->exp.erase(remove_if(this->exp.begin(), this->exp.end(), [](auto const st) {
            return all_of(st.begin(), st.end(), [](auto const a) {
                return isspace(a);
            });
        }), this->exp.end());  //去空格
        for(auto i = this->exp.size() - 1; i > 0 ; i--) {   //合并操作数与负号
            if(i != 1) {    //不为第一个操作数,前方两个符号且第二个为'-'合并为负数
                if(isDigits(this->exp[i]) && this->exp[i - 1] == "-" && this->exp[i - 2].size() < 2 &&
                        !isDigits(this->exp[i - 2]) && this->exp[i - 2] != ")") {
                    this->exp[i] = this->exp[i - 1] + this->exp[i];
                    this->exp[i - 1] = string("");
                }
            } else {        //为第一个操作数,前面符号为'-'合并为负数
                if(isDigits(this->exp[i]) && this->exp[i - 1] == "-") {
                    this->exp[i] = this->exp[i - 1] + this->exp[i];
                    this->exp[i - 1] = string("");
                }
            }
        }
        this->exp.erase(remove_if(this->exp.begin(), this->exp.end(), [](auto const st) {
            return all_of(st.begin(), st.end(), [](auto const a) {
                return isspace(a);
            });
        }), this->exp.end());//再次去空格
    }
  public:
    bool valid;        //标志表达式是否有效
    Expression() {
    }
    shared_ptr<Node<char, string>> tree;    //表达式树根节点
    Expression(string str) {//构造函数
        this->valid = true;
        this->pre(str);
        this->build();
    }
    void show() {   //将预处理后de表达式序列以空格间隔输出,用作测试
        copy(this->exp.cbegin(), this->exp.cend(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
};

class Assignment {  //赋值语句的构造
  public:
    bool valid;     //标志赋值语句是否有效
    string key;     //赋值的属性名
    Expression exp; //赋值表达式
    Assignment(string str) {
        this->build(str);
    }
    virtual ~Assignment() {
    }
    bool build(string str) {    //初始化并检查语法,返回valid标志位
        auto pos = str.find("=");
        if(pos != std::string::npos) {
            this->key = str.substr(0, pos);
            this->exp = Expression(str.substr(pos + 1));
        }
        this->key.erase(remove_if(this->key.begin(), this->key.end(), [](auto const a) {
            return isspace(a);
        }), this->key.end());
        if(this->key.empty() || isDigits(this->key)) {
            cout << "invalid property name : " << this->key;
            this->valid = false;
        } else if(!this->exp.valid) {
            cout << "expression syntax error : " << str;
            this->valid = false;
        } else {
            this->valid = true;
        }
        return this->valid;
    }
  private:

};

#endif // TREE_H
