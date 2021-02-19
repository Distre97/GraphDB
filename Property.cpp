#include "Property.h"
#include "Table.h"
/********************************************//**
 * \brief 构造函数
 *
 * \param  文件名name:string
 * \param
 * \return 无
 *
 ***********************************************/
Property::Property(string name) {
    this->init(name);
}
/********************************************//**
 * \brief |:求并集
 *
 * \param 编号集合a
 * \param 编号集合b
 * \return 集合a与b的并集
 *
 ***********************************************/
_IDS operator|(const _IDS& a, const _IDS& b) {
    _IDS tmp;
    set_union(begin(a), end(a), begin(b), end(b), inserter(tmp, tmp.begin()));
    return tmp;
}
/********************************************//**
 * \brief &:求交集
 *
 * \param 编号集合a
 * \param 编号集合b
 * \return 集合a与b的交集
 *
 ***********************************************/
_IDS operator&(const _IDS& a, const _IDS& b) {
    _IDS tmp;
    set_intersection(begin(a), end(a), begin(b), end(b), inserter(tmp, tmp.begin()));
    return tmp;
}
/********************************************//**
 * \brief   save:将数据写回文件,包括属性文件和空闲编号文件
 *
 * \param   无
 * \param   无
 * \return  无
 *
 ***********************************************/
void Property::save() {
    ofstream fprop(this->name + "_property.db");
    for(auto& v : this->pro) {
        for(auto& u : v.second) {
            auto p = pack_data(u.second);
            fprop << v.first << ' ' << u.first << ' ' << p.first << ' ' << p.second << endl;
        }
    }
    fprop.close();
    ofstream fids(this->name + "_free_id.db");
    for(auto& v : this->fre) {
        fids << v << endl;
    }
    fids.close();
}
/********************************************//**
 * \brief   判断编号是否存在
 *
 * \param   编号id
 * \param
 * \return
 *
 ***********************************************/
bool Property::count(_ID id) {
    return this->pro.count(id);
}
/********************************************//**
 * \brief   根据文件名初始化
 *
 * \param   文件名name:string
 * \param
 * \return  无
 *
 ***********************************************/
void Property::init(string name) {
    this->name = name;
    _ID id, type;
    string key, valu;
    ifstream fprop(name + "_property.db");
    while(fprop >> id >> key >> type >> valu) {
        auto dt = make_data(_pack(type, valu));
        this->pro[id].emplace(_prop(key, dt));
        this->atr[key].emplace(_attr(dt, id));
    }
    fprop.close();
    ifstream fids(name + "_free_id.db");
    while(fids >> id) {
        this->fre.emplace(id);
    }
    fids.close();
}
/********************************************//**
 * \brief   编号生成器,用于新建节点时编号的分配
 *
 * \param   无
 * \param   无
 * \return  新编号
 *
 ***********************************************/
_ID Property::id_generator() {
    if(this->pro.empty()) {     //当属性集为空时,将2加入空闲编号集,返回1
        this->fre.clear();
        this->fre.emplace(2);
        return 1;
    } else {
        if(this->fre.empty()) { //当空闲编号集为空时,遍历找最大编号M,将M+2加入空闲编号集,返回M+1
            using pair_t = decltype(this->pro)::value_type;
            auto mx = max_element(begin(this->pro), end(this->pro), [](pair_t &p1, pair_t &p2) {
                return p1.first < p2.first;
            });
            this->fre.emplace(move(mx->first + 2));
            return mx->first + 1;
        } else if(this->fre.size() == 1) {  //编号集大小为1为属性集最大编号M+1,取第一个返回
            auto tmp = *this->fre.begin();
            this->fre.clear();
            this->fre.emplace(tmp + 1);
            return tmp;
        } else {        //取集合第一个,即为空闲编号最小值
            auto tmp = *this->fre.begin();
            this->fre.erase(this->fre.begin());
            return tmp;
        }
    }
}
/********************************************//**
 * \brief   新建实体或关系,并添加属性
 *
 * \param   属性值,包括name
 * \param   无
 * \return  新建节点编号
 *
 ***********************************************/
_ID Property::add(const _popes& ps) {
    _ID id = 0;
    if(!ps.empty()) {
        id = this->id_generator();
        for(auto& p : ps) {
            this->pro[id].emplace(p);
            this->atr[p.first].emplace(_attr(p.second, id));
        }
    }
    return id;
}
/********************************************//**
 * \brief   为一个实体或关系添加一个属性
 *
 * \param   实体或关系编号id
 * \param   属性键值对pr
 * \return  存在并添加后返回true,否则返回false
 *
 ***********************************************/
bool Property::add(const _ID& id, const _prop& pr) {
    if(this->pro.count(id)) {
        auto range = this->atr[pr.first].equal_range(this->pro[id][pr.first]);
        for(auto it = range.first; it != range.second; it++) {
            if(it->second == id) {
                this->atr[pr.first].erase(it);
                break;
            }
        }
        this->atr[pr.first].emplace(_attr(pr.second, id));
        this->pro[id][pr.first] = pr.second;
        return true;
    } else {
        cout << "there is no " << this->name << " No. " << id << endl;
        return false;
    }
}
/********************************************//**
 * \brief   为一个实体或关系删除多个属性
 *
 * \param   实体或关系编号id
 * \param   属性序列ps
 * \return  添加成功返回true,否则返回false
 *
 ***********************************************/
bool Property::add(const _ID& id, const _popes& ps) {
    bool btmp = false;
    for(auto& p : ps) {
        btmp = this->add(id, p);
    }
    return btmp;
}
/********************************************//**
 * \brief   删除一个实体或关系的单个属性
 *
 * \param   实体或关系编号
 * \param   属性名,当属性名为空时表示删除整个实体或关系
 * \return  存在编号且存在属性,删除后返回true,否则返回false
 *
 ***********************************************/
bool Property::del(const _ID& id, const string& key) {
    if(this->pro.count(id)) {
        if(key.size() == 0) {                   //属性名为空
            this->fre.emplace(id);
            auto tmp = this->pro[id];           //获取编号对应的属性名
            for(auto& a : tmp) {
                this->del(id, a.first);         //递归删除键-值
            }
            this->pro.erase(id);                //删除在属性编号表中的记录
            return true;
        } else if(this->pro[id].count(key)) {   //不为空,获取属性名和属性值,查找对应的编号
            auto range = this->atr[key].equal_range(this->pro[id][key]);
            for(auto it = range.first; it != range.second; it++) {
                if(it->second == id) {
                    this->atr[key].erase(it);   //从属性查找表中删除键值
                    break;
                }
            }
            this->pro[id].erase(key);           //从属性编号表中删除键名
            return true;
        } else {                                //没有对应的属性输出
            cout << "there is no " << key << " of " << this->name << " No. " << id << endl;
            return false;
        }
    } else {                                    //输出没有对应的编号
        return false;
        cout << "there is no " << this->name << " No. " << id << endl;
    }
}
/********************************************//**
 * \brief   删除多个编号的多个属性
 *
 * \param   编号集ids
 * \param   属性名序列keys,当序列为空时删除整个编号集
 * \return  删除成功返回true,失败返回false
 *
 ***********************************************/
bool Property::del(const _IDS& ids, const _lists& keys) {
    bool btmp = false;
    if(keys.size() == 0) {          //属性序列为空
        for(auto& id : ids) {
            this->del(id);          //遍历编号集逐个删除
        }
        btmp = true;
    } else {
        for(auto& key : keys) {     //不为空,循环删除每个编号对应的属性
            for(auto& id : ids) {
                btmp = this->del(id, key);
            }
        }
    }
    return btmp;
}
/********************************************//**
 * \brief   在给定集合按单个条件查询
 *
 * \param   限定条件cd
 * \param   查询范围rg,默认为ANY即全集
 * \return  符合条件的id集,没有则返回空集
 *
 ***********************************************/
_IDS Property::inq(const _cond& cd, const _IDS& rg) {
    if(rg.empty()) {    //查询范围为空,返回空集
        return rg;
    } else {            //查询范围不为空
        _IDS tmpset;
        auto& key = cd.second.first;    //键
        auto& val = cd.second.second;   //值
        switch(cd.first) {
        case Oprat::EQ:                 //[键] = 值
            if(rg == ANY) {
                auto range = this->atr[key].equal_range(val);
                for(auto it = range.first; it != range.second; it++) {
                    tmpset.emplace(it->second);
                }
            } else {
                for(auto& id : rg) {
                    if(this->pro[id][key] == val) {
                        tmpset.emplace(id);
                    }
                }
            }
            break;
        case Oprat::NE:                 //[键] <> 值
            if(rg == ANY) {
                auto lrange = make_pair(this->atr[key].begin(), this->atr[key].lower_bound(val));
                for(auto it = lrange.first; it != lrange.second; it++) {
                    tmpset.emplace(it->second);
                }
                auto urange = make_pair(this->atr[key].upper_bound(val), this->atr[key].end());
                for(auto it = urange.first; it != urange.second; it++) {
                    tmpset.emplace(it->second);
                }
            } else {
                for(auto id : rg) {
                    if(this->pro[id][key] != val) {
                        tmpset.emplace(id);
                    }
                }
            }
            break;
        case Oprat::LT:                 //[键] < 值
            if(rg == ANY) {
                auto range = make_pair(this->atr[key].begin(), this->atr[key].lower_bound(val));
                for(auto it = range.first; it != range.second; it++) {
                    tmpset.emplace(it->second);
                }
            } else {
                for(auto id : rg) {
                    if(this->pro[id][key] < val) {
                        tmpset.emplace(id);
                    }
                }
            }
            break;
        case Oprat::GT:                 //[键] > 值
            if(rg == ANY) {
                auto range = make_pair(this->atr[key].upper_bound(val), this->atr[key].end());
                for(auto it = range.first; it != range.second; it++) {
                    tmpset.emplace(it->second);
                }
            } else {
                for(auto id : rg) {
                    if(this->pro[id][key] > val) {
                        tmpset.emplace(id);
                    }
                }
            }
            break;
        case Oprat::LE:                 //[键] <= 值
            if(rg == ANY) {
                auto range = make_pair(this->atr[key].begin(), this->atr[key].upper_bound(val));
                for(auto it = range.first; it != range.second; it++) {
                    tmpset.emplace(it->second);
                }
            } else {
                for(auto id : rg) {
                    if(this->pro[id][key] <= val) {
                        tmpset.emplace(id);
                    }
                }
            }
            break;
        case Oprat::GE:                 //[键] >= 值
            if(rg == ANY) {
                auto range = make_pair(this->atr[key].lower_bound(val), this->atr[key].end());
                for(auto it = range.first; it != range.second; it++) {
                    tmpset.emplace(it->second);
                }
            } else {
                for(auto id : rg) {
                    if(this->pro[id][key] >= val) {
                        tmpset.emplace(id);
                    }
                }
            }
            break;
        default:
            ;
        }
        return tmpset;                  //返回查询结果
    }
}
/********************************************//**
 * \brief   查询同时符合两个条件或任一的编号
 *
 * \param   逻辑运算符re:AND或OR
 * \param   限制条件cd1:
 * \param   限制条件cd2
 * \return  符合条件的编号集
 *
 ***********************************************/
_IDS Property::inq(const Relat& re, const _cond& cd1, const _cond& cd2) {
    return re == Relat::AND ? this->inq(cd2, this->inq(cd1)) : this->inq(cd1) | this->inq(cd2);;
}
/********************************************//**
 * \brief   查询满足一个条件的编号与给定编号集的运算
 *
 * \param   关系运算符re:AND或OR
 * \param   限制条件cd
 * \param   查找范围或并集
 * \return  符合条件的集合
 *
 ***********************************************/
_IDS Property::inq(const Relat& re, const _cond& cd, const _IDS& rg) {
    //若为与运算则在给定范围查询并返回,否则在全集查找返回与给定集合的并集
    return re == Relat::AND ? this->inq(cd, rg) : this->inq(cd) | rg;
}
/********************************************//**
 * \brief   查询给定编号集的简单统计数据
 *
 * \param   查询的属性名key
 * \param   统计标志:SUM,AVG,MIN,MAx
 * \param   统计范围,缺省值为全集
 * \return  返回对应统计结果
 *
 ***********************************************/
void Property::inq(const string& key, const Stats& st, const _IDS& rg) {
    if(this->atr.count(key) && rg.size() != 0) {
        Table te;           //新建表格
        te.add(key);
        switch(st) {
        case Stats::MAX:    //查找最大值
            te.add("MAX");
            if(rg == ANY) {
                te.add(pack_data(this->atr[key].rbegin()->first).second);
            } else {
                auto maxid = max_element(rg.begin(), rg.end(), [ & ](const auto & a, const auto & b) {
                    return (this->pro[a][key] < this->pro[b][key]);
                });
                te.add(pack_data(this->pro[*maxid][key]).second);
            }
            te.end_of_row();
            cout << te;     //输出结果
            break;
        case Stats::MIN:    //查找最小值
            te.add("MIN");
            if(rg == ANY) {
                te.add(pack_data(this->atr[key].begin()->first).second);
            } else {
                auto minid = min_element(rg.begin(), rg.end(), [ & ](const auto & a, const auto & b) {
                    return (this->pro[a][key] < this->pro[b][key]);
                });
                te.add(pack_data(this->pro[*minid][key]).second);
            }
            te.end_of_row();
            cout << te;     //输出结果
            break;
        case Stats::SUM: {  //计算总和
            te.add("SUM");
            auto type = pack_data(this->atr[key].begin()->first).first;
            switch(type) {
            case 1:         //数据类型为int
                if(rg == ANY) {
                    auto sum = accumulate(this->atr[key].begin(), this->atr[key].end(), 0, [](_type i, _attr p) {
                        return get<int>(i) + get<int>(p.first);
                    });
                    te.add(to_string(sum));
                } else {
                    auto sum = accumulate(rg.begin(), rg.end(), 0, [ & ](_type i, const auto id) {
                        return get<int>(i) + get<int>(this->pro[id][key]);
                    });
                    te.add(to_string(sum));
                }
                te.end_of_row();
                cout << te; //输出结果
                break;
            case 2:         //数据类型为double
                if(rg == ANY) {
                    auto sum = accumulate(this->atr[key].begin(), this->atr[key].end(), 0.0, [](_type i, _attr p) {
                        return get<double>(i) + get<double>(p.first);
                    });
                    te.add(to_string(sum));
                } else {
                    auto sum = accumulate(rg.begin(), rg.end(), 0.0, [ & ](_type i, const auto id) {
                        return get<double>(i) + get<double>(this->pro[id][key]);
                    });
                    te.add(to_string(sum));
                }
                te.end_of_row();
                cout << te; //输出结果
                break;
            default: {      //数据类型为其他
                string stype = type == 4 ? string("bool") : string("string");
                cout << "type error : cannot get sum of " << stype << endl;
            }
            }
        }
        break;
        case Stats::AVG: {  //计算平均值
            te.add("AVG");
            auto type = pack_data(this->atr[key].begin()->first).first;
            switch(type) {
            case 1:         //数据类型为int
                if(rg == ANY) {
                    auto sum = accumulate(this->atr[key].begin(), this->atr[key].end(), 0, [](_type i, _attr p) {
                        return get<int>(i) + get<int>(p.first);
                    });
                    te.add(to_string((double)sum / this->atr[key].size()));
                } else {
                    auto sum = accumulate(rg.begin(), rg.end(), 0, [ & ](_type i, const auto id) {
                        return get<int>(i) + get<int>(this->pro[id][key]);
                    });
                    te.add(to_string((double)sum / rg.size()));
                }
                te.end_of_row();
                cout << te; //输出结果
                break;
            case 2:         //数据类型为double
                if(rg == ANY) {
                    auto sum = accumulate(this->atr[key].begin(), this->atr[key].end(), 0.0, [](_type i, _attr p) {
                        return get<double>(i) + get<double>(p.first);
                    });
                    te.add(to_string((double)sum / this->atr[key].size()));
                } else {
                    auto sum = accumulate(rg.begin(), rg.end(), 0.0, [ & ](_type i, const auto id) {
                        return get<double>(i) + get<double>(this->pro[id][key]);
                    });
                    te.add(to_string((double)sum / rg.size()));
                }
                te.end_of_row();
                cout << te; //输出结果
                break;
            default: {      //数据类型为其他
                string stype = type == 4 ? string("bool") : string("string");
                cout << "type error : cannot get average of " << stype << endl;
            }
            }
        }
        break;
        default:
            ;
        }
    }
}
/********************************************//**
 * \brief   以赋值语句设定新的属性或修改已有属性
 *
 * \param   要修改的编号id
 * \param   数学表达式ass
 * \return  编号存在并且表达式无误修改后返回编号,否则返回0
 *
 ***********************************************/
_ID Property::alt(const _ID& id, const Assignment & ass) {
    if(this->pro.count(id) && ass.valid) {
        auto valid = true;  //出错标志,提前结束递归
        function <double(_pNode)> evaluate = [&](const _pNode & tre) -> double {
            if(tre != nullptr && valid) {   //基于表达式二叉树的递归求值
                if(tre->isOpr()) {          //当前节点为操作符,返回自述求值结果
                    auto tmp = calculate(tre->getOpr(), evaluate(tre->left), evaluate(tre->right));
                    return tmp == INF ? (valid = false) : tmp; //发生除0错误,valid置false
                } else {                    //当前节点为操作数
                    auto& str = tre->getOpd();
                    if(isDigits(str)) {     //若操作数为数值类型则转化为数值类型返回
                        return stod(str);
                    } else if(this->pro[id].count(str)) {   //为字符串类型查找编号对应的属性表
                        switch(pack_data(this->pro[id][str]).first) {   //存在则根据对应类型返回
                        case 1:
                            return get<1>(this->pro[id][str]);
                        case 2:
                            return get<2>(this->pro[id][str]);
                        default:
                            return valid = false;       //非数值类型,valid置false
                        }
                    } else {                 //不为数值亦不为属性名,valid置false
                        return valid = false;
                    }
                }
            } else {    //表达式树根节点为空,valid置false
                return valid = false;
            }
        };
        auto result = evaluate(ass.exp.tree);   //求值
        if(valid == true) {                     //算式求值有效,给对应属性赋值,返回0
            this->add(id, _prop(ass.key, result));
            return 0;
        } else {                                //无效,返回当前编号
            return id;
        }
    } else {   //表达式无效或不存在对应编号返回0
        return 0;
    }
}
/********************************************//**
 * \brief   以表达式形式(如:area=pi*radius*radius)修改多个编号对应属性
 *
 * \param   要修改或添加的编号集ids
 * \param   数学表达式:string
 * \return  无
 *
 ***********************************************/
void Property::alt(const _IDS& ids, const string& expression) {
    Assignment ass(expression);     //根据字符串构造赋值语句
    for(auto id : ids) {            //遍历操作
        this->alt(id, ass);
    }
}
/********************************************//**
 * \brief   显示单个实体的信息
 *
 * \param   实体编号
 * \param   属性名序列keys,为空时默认输出所有属性
 * \return  存在实体则返回true,否则返回false
 *
 ***********************************************/
bool VertexProperty::show(const _ID& id, const _lists& keys) {
    if(this->pro.count(id)) {   //存在编号
        Table t;                //新建表
        t.add("id");
        if(keys.empty()) {
            for(auto a : this->pro[id]) {
                t.add(a.first);
            }
            t.end_of_row();
            t.add(to_string(id));
            for(auto a : this->pro[id]) {   //将属性值转换为字符串
                t.add(pack_data(a.second).second);
            }
            t.end_of_row();
        } else {
            for(auto key : keys) {
                t.add(key);
            }
            t.end_of_row();
            t.add(to_string(id));
            for(auto key : keys) {
                if(this->pro[id].count(key)) {      //将属性值转换为字符串
                    t.add(pack_data(this->pro[id][key]).second);
                } else {
                    t.add();
                }
            }
            t.end_of_row();
        }
        cout << t;
        return true;
    } else {
        return false;
    }
}
/********************************************//**
 * \brief   多个实体的多个属性,并对第一个属性排序输出
 *
 * \param   实体编号集ids
 * \param   属性名序列keys,为空时,取所有实体属性最多者
 * \param   排序标志:DE降序,AS升序,UN无序
 * \return  无
 *
 ***********************************************/
void VertexProperty::show(const _IDS& ids, _lists keys, const Order& od) {
    vector<_ID> tmp;
    copy(ids.begin(), ids.end(), back_inserter(tmp));  //将实体编号集转化为序列,以便排须
    tmp.erase(remove_if(begin(tmp), end(tmp), [&](const auto a) {   //移除无效的编号
        return !this->pro.count(a);
    }), end(tmp));
    if(!tmp.empty()) {          //清理后编号数量不为0
        if(keys.empty()) {      //属性序列为空查找属性最多的实体,并以之为准
            auto mk = max_element(ids.begin(), ids.end(), [&](const auto & a, const auto & b) {
                return this->pro[a].size() < this->pro[b].size();
            });
            for(auto& a : this->pro[*mk]) {
                keys.emplace_back(a.first);
            }
        }
        switch(od) {
        case Order::UN:     //无序,无需排序
            break;
        case Order::DE:     //降序
            sort(tmp.begin(), tmp.end(), [this, keys](auto & a, auto & b) {
                return this->pro[a][*begin(keys)] > this->pro[b][*begin(keys)];
            });
            break;
        case Order::AS:     //升序
            sort(tmp.begin(), tmp.end(), [this, keys](auto a, auto b) {
                return this->pro[a][*begin(keys)] < this->pro[b][*begin(keys)];
            });
            break;
        default:
            break;
        }
        Table t;        //构造表格
        t.add("id");
        for(auto key : keys) {
            t.add(key);
        }
        t.end_of_row();
        for(auto id : tmp) {
            t.add(to_string(id));
            for(auto key : keys) {
                if(this->pro[id].count(key)) {
                    t.add(pack_data(this->pro[id][key]).second);
                } else {
                    t.add();
                }
            }
            t.end_of_row();
        }
        cout << t;  //输出
    }
}
/********************************************//**
 * \brief   输出单个关系的信息
 *
 * \param   关系编号id
 * \param   边表eg,用于起点终点显示输出
 * \param   属性名列表keys,为空时显示所有属性
 * \return  存在编号返回true,否则返回false
 *
 ***********************************************/
bool EdgeProperty::show(const _ID& id, const _edge& eg, const _lists& keys) {
    if(this->pro.count(id)) {
        Table t;
        t.add("id");
        t.add("vs");
        t.add("vt");
        if(keys.empty()) {
            for(auto a : this->pro[id]) {
                t.add(a.first);
            }
            t.end_of_row();
            t.add(to_string(id));
            t.add(to_string(eg.first));
            t.add(to_string(eg.second));
            for(auto a : this->pro[id]) {
                t.add(pack_data(a.second).second);
            }
            t.end_of_row();
        } else {
            for(auto key : keys) {
                t.add(key);
            }
            t.end_of_row();
            t.add(to_string(id));
            if(eg.first != 0) {
                t.add(to_string(eg.first));
                t.add(to_string(eg.second));
            }
            for(auto key : keys) {
                if(this->pro[id].count(key)) {
                    t.add(pack_data(this->pro[id][key]).second);
                } else {
                    t.add();
                }
            }
            t.end_of_row();
        }
        cout << t;
        return true;
    } else {
        return false;
    }
}
/********************************************//**
 * \brief   多个关系的多个属性,并以第一个属性排序输出
 *
 * \param   边表egs
 * \param   属性名序列keys,为空时以属性最多者为准
 * \param   排序标志od:UN无序,DE降序,AS升序
 * \return  无
 *
 ***********************************************/
void EdgeProperty::show(_edges egs, _lists keys, const Order& od) {
    vector<_ID> tmp(egs.size());
    transform(egs.begin(), egs.end(), back_inserter(tmp), [](auto & kv) {
        return kv.first;
    });//取出边表里的关系编号
    tmp.erase(remove_if(begin(tmp), end(tmp), [&](const auto a) {
        return !this->pro.count(a);
    }), end(tmp));//移除无效编号
    if(!tmp.empty()) {  //关系编号集不为空时
        if(keys.empty()) {  //属性名序为空,查找属性最多者的属性
            auto mk = max_element(egs.begin(), egs.end(), [&](const auto & a, const auto & b) {
                return this->pro[a.first].size() < this->pro[b.first].size();
            });
            for(auto& a : this->pro[(*mk).first]) {
                keys.emplace_back(a.first);
            }
        }
        switch(od) {
        case Order::UN:         //无序
            break;
        case Order::DE: {       //降序
            sort(tmp.begin(), tmp.end(), [this, keys](auto a, auto b) {
                return this->pro[a][*keys.begin()] > this->pro[b][*keys.begin()];
            });
        }
        break;
        case Order::AS: {       //升序
            sort(tmp.begin(), tmp.end(), [this, keys](auto a, auto b) {
                return this->pro[a][*keys.begin()] < this->pro[b][*keys.begin()];
            });
        }
        break;
        default:;
        }
        Table t;            //构造表
        t.add("id");
        t.add("vs");
        t.add("vt");
        for(auto key : keys) {
            t.add(key);
        }
        t.end_of_row();
        for(auto tm : tmp) {
            t.add(to_string(tm));
            t.add(to_string(egs[tm].first));
            t.add(to_string(egs[tm].second));
            for(auto key : keys) {
                if(this->pro[tm].count(key)) {
                    t.add(pack_data(this->pro[tm][key]).second);
                } else {
                    t.add();
                }
            }
            t.end_of_row();
        }
        cout << t;  //输出
    }
}
