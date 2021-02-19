#include "Graph.h"
/********************************************//**
 * \brief 构造函数,初始化
 *
 * \param 无
 * \param 无
 * \return 无
 *
 ***********************************************/
Graph::Graph() {
    _ID eid, vid1, vid2;
    ifstream fin("edge.db");
    while(fin >> eid >> vid1 >> vid2) {
        this->egs.emplace(make_pair(eid, _edge(vid1, vid2)));   //写边表
        this->vts[vid1].first.emplace(eid);                     //写入起点出边集
        this->vts[vid2].second.emplace(eid);                    //写入终点入边集
    }
    fin.close();
}
/********************************************//**
 * \brief 将数据写回文件
 *
 * \param 无
 * \param
 * \return 无
 *
 ***********************************************/
void Graph::save() {
    ofstream fout("edge.db");
    for(auto& a : this->egs) {
        fout << a.first << ' ' << a.second.first << ' ' << a.second.second << endl;
    }
    this->vps.save();
    this->eps.save();
}
/********************************************//**
 * \brief 获取边的编号
 *
 * \param 边_edge:pair<_ID, _ID>
 * \param
 * \return 编号_ID:size_t,若不存在返回保留编号0
 *
 ***********************************************/
_ID Graph::get_edge_id(const _edge& eg) {
    auto tmp = this->vts[eg.first].first & this->vts[eg.second].second;
    return tmp.size() == 0 ? *tmp.begin() : 0;
}
/********************************************//**
 * \brief 获取一个点集的所有边
 *
 * \param 顶点集编号_IDS: set<_ID>
 * \param
 * \return 边集编号_IDS: set<_ID>
 *
 ***********************************************/
_IDS Graph::get_edges(const _IDS& vids) {
    _IDS eids;
    for(auto& id : vids) {
        if(this->vts.count(id)) {
            for(auto& out : this->vts[id].first) {
                if(vids.count(this->egs[out].second)) {
                    eids.emplace(out);
                }
            }
        }
    }
    return eids;
}
/********************************************//**
 * \brief 添加一个点
 *
 * \param 实体名字name:string,不可缺省
 * \param 实体类别label:string,缺省值"none"
 * \param 实体其他属prs:_popes,可缺省
 * \return 实体编号_ID,添加成功返回id,失败返回0
 *
 ***********************************************/
_ID Graph::add_vert(const string& name, const string& label, _popes prs) {
    prs.emplace_back(_prop("name", name));
    prs.emplace_back(_prop("label", label));
    auto id = this->vps.add(prs);
    this->vps.show(id, {});
    this->vts[id];
    return id;
}
/********************************************//**
 * \brief 向图中添加一条边
 *
 * \param 关系eg:_eg,不可缺省
 * \param 关系类别type:string,缺省值"none"
 * \param 关系属性prs:_popes,可缺省
 * \return 关系编号_IDS,添加成功返回id,失败返回0
 *
 ***********************************************/
_ID Graph::add_edge(const _edge& eg, const string& type, _popes prs) {
    prs.emplace_back(_prop("name", type));
    if(this->vts.count(eg.first) && this->vts.count(eg.second)) {
        auto tmp = this->get_edge_id(eg);
        if(tmp == 0) {
            auto id = this->eps.add(prs);
            this->egs.emplace(make_pair(id, eg));
            this->vts[eg.first].first.emplace(id);
            this->vts[eg.second].second.emplace(id);
            this->eps.show(id, eg, {});
            return id;
        } else {
            cout << "there was edge No." << tmp << " of vertex No." << eg.first << " and vertext No." << eg.second << endl;
            return 0;
        }
    } else if(this->vts.count(eg.first)) {
        cout << "there is no vertex No." << eg.second << endl;
        return 0;
    } else if(this->vts.count(eg.second)) {
        cout << "there is no vertex No." << eg.first << endl;
        return 0;
    } else {
        cout << "there is no vertex No." << eg.first << " and No." << eg.second << endl;
        return 0;
    }
}
/********************************************//**
 * \brief 添加一个实体的属性
 *
 * \param 实体编号id:_ID,不可缺省
 * \param 实体属性集ps:_popes,不可缺省
 * \return 无.有则改之,无则添加
 *
 ***********************************************/
void Graph::add_vert_prop(const _ID& id, const _popes& ps) {
    if(this->vps.add(id, ps)) {
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief 添加一个关系的属性
 *
 * \param 关系id:_ID,不可缺省
 * \param 属性集ps:_popes,不可缺省
 * \return 无.有则改之,无则增加
 *
 ***********************************************/
void Graph::add_edge_prop(const _ID& id, const _popes& ps) {
    if(this->eps.add(id, ps)) {
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief 删除单个实体的单个属性
 *
 * \param 实体编号id:_ID,不可缺省
 * \param 实体属性key:string,可缺省.缺省值"",代表删除整个实体
 * \return 无
 *
 ***********************************************/
void Graph::del_vert(const _ID& id, const string& key) {
    if(this->vts.count(id)) {
        if(key.size() == 0) {
            auto out = this->vts[id].first;      //删除出边
            auto in = this->vts[id].second;    //删除入边
            for(auto& a : in) {
                this->del_edge(a);
            }
            for(auto& a : out) {
                this->del_edge(a);
            }
            this->vts.erase(id);            //从点表删除
        }
    }
    if(this->vps.del(id, key)) {            //从属性集删除
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief 删除实体集的多个属性
 *
 * \param 实体编号集ids:_IDS,不可缺省
 * \param 属性集keys:_lists,可缺省.缺省值为{},表示删除实体集中所有实体
 * \return 无
 *
 ***********************************************/
void Graph::del_vert(const _IDS& ids, const _lists& keys) {
    if(!ids.empty()) {
        if(keys.size() == 0) {
            for(auto& id : ids) {
                auto out = this->vts[id].first;     //出边
                auto in = this->vts[id].second;     //入边
                for(auto& a : in) {
                    this->del_edge(a);
                }
                for(auto& a : out) {
                    this->del_edge(a);
                }
                this->vts.erase(id);
            }
        }
        if(this->vps.del(ids, keys)) {
            this->print(__FUNCTION__);
        }
    }
}
/********************************************//**
 * \brief 删除单个关系的单个属性
 *
 * \param 关系编号id:_ID,不可缺省
 * \param 属性键名key:string.缺省时删除关系
 * \return 无
 *
 ***********************************************/
void Graph::del_edge(const _ID& id, const string& key) {
    if(this->egs.count(id)) {
        if(key.size() == 0) {
            this->vts[this->egs[id].first].first.erase(id);     //从起点入边删除
            this->vts[this->egs[id].second].second.erase(id);   //从终点出边删除
            this->egs.erase(id);
        }
    }
    if(this->eps.del(id, key)) {
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief 删除关系集中多个属性
 *
 * \param 关系编号集ids:_IDS,不可缺省
 * \param 属性集keys:_lists,缺省时删除关系集
 * \return 无
 *
 ***********************************************/
void Graph::del_edge(const _IDS& ids, const _lists& keys) {
    if(!ids.empty()) {
        if(keys.size() == 0) {
            for(auto id : ids) {
                this->vts[this->egs[id].first].first.erase(id);     //从起点出边删除
                this->vts[this->egs[id].second].second.erase(id);   //从终点入边删除
                this->egs.erase(id);
            }
        }
        if(this->eps.del(ids, keys)) {
            this->print(__FUNCTION__);
        }
    }
}
/********************************************//**
 * \brief 查询实体(单个关系)
 *
 * \param 限制条件cd:_cond, 不可缺省
 * \param 查询范围rg:_IDS,缺省时全局查找
 * \return 实体编号集_IDS
 *
 ***********************************************/
_IDS Graph::inq_vert(const _cond& cd, const _IDS& rg) {
    return this->vps.inq(cd, rg);
}
/********************************************//**
 * \brief 在一个实体集中查找满足条件的实体
 *
 * \param 关系运算符re:Relat,Relat::AND与,Relat::OR或,不可缺省
 * \param 限制条件cd:_cond,不可缺省
 * \return 实体编号集_IDS
 *
 ***********************************************/
_IDS Graph::inq_vert(const Relat& re, const _cond& cd, const _IDS& rg) {
    return this->vps.inq(re, cd, rg);
}
/********************************************//**
 * \brief 通过关系集查找实体
 *
 * \param 关系编号集eids:_IDS,不可缺省
 * \param 方向drc:Direc,Direc::FROM表示起点,Direc::TO表示终点,缺省为Direc::FROM
 * \return 实体编号集_IDS
 *
 ***********************************************/
_IDS Graph::inq_vert(const _IDS& eids, const Direc& drc) {
    _IDS tempset;
    if(drc == Direc::FROM) {
        for(auto& id : eids) {
            tempset.emplace(this->egs[id].first);
        }
    } else {
        for(auto& id : eids) {
            tempset.emplace(this->egs[id].second);
        }
    }
    return tempset;
}
/********************************************//**
 * \brief 统计实体属性集,并输出
 *
 * \param 实体属性key:string,不可缺省
 * \param 统计类别:st:Stats,Stats::MAX表示最大值,Stat::MIN表示最小值,Stat::SUM表示求和
 * \return 无
 *
 ***********************************************/
void Graph::inq_vert(const string& key, const Stats& st, const _IDS& rg) {
    this->vps.inq(key, st, rg);
}
/********************************************//**
 * \brief 查询符合条件的关系
 *
 * \param 查询条件cd:_cond,不可缺省
 * \param 查询范围rg:_IDS,缺省时全局查找
 * \return 关系编号集
 *
 ***********************************************/
_IDS Graph::inq_edge(const _cond& cd, const _IDS& rg) {
    return this->eps.inq(cd, rg);
}
/********************************************//**
 * \brief 在一个关系集中查找满足条件的实体
 *
 * \param 关系运算符re:Relat,Relat::AND与,Relat::OR或,不可缺省
 * \param 限制条件cd:_cond,不可缺省
 * \return 关系编号集_IDS
 *
 ***********************************************/
_IDS Graph::inq_edge(const Relat& re, const _cond& cd, const _IDS& rg) {
    return this->eps.inq(re, cd, rg);
}
/********************************************//**
 * \brief 查询实体集的出边或入编编号
 *
 * \param 实体编号集vids:_IDS,不可缺省
 * \param 关系方向dirc:Direc,Direc::IN表示入编,Direc::OUT表示出边
 * \return 关系编号集
 *
 ***********************************************/
_IDS Graph::inq_edge(const _IDS& vids, const Direc& drc) {
    _IDS tempset;
    if(drc == Direc::OUT) {
        for(auto& id : vids) {
            for(auto& a : this->vts[id].first) {
                tempset.emplace(a);
            }
        }
    } else {
        for(auto& id : vids) {
            for(auto& a : this->vts[id].second) {
                tempset.emplace(a);
            }
        }
    }
    return tempset;
}
/********************************************//**
 * \brief 统计关系属性集,并输出
 *
 * \param 关系属性key:string,不可缺省
 * \param 统计类别:st:Stats,Stats::MAX表示最大值
 *        Stat::MIN表示最小值,Stat::SUM表示求和
 * \return 无
 *
 ***********************************************/
void Graph::inq_edge(const string& key, const Stats& st, const _IDS& rg) {
    this->eps.inq(key, st, rg);
}
/********************************************//**
 * \brief 输出单个关系属性,默认输出标号和对应实体编号
 *
 * \param 关系编号id:_ID,不可缺省
 * \param 属性集keys:_lists,缺省时输出关系所有属性
 * \return 无
 *
 ***********************************************/
void Graph::show_edge(const _ID& id, const _lists& keys) {
    if(!this->eps.show(id, this->egs[id], keys)) {
        cout << "there is no edge No." << id << endl;
    }
}
/********************************************//**
 * \brief 输出关系集,并排序
 *
 * \param 关系编号集ids:_IDS,不可缺省
 * \param 属性集keys:_lists,不可缺省
 * \param 排序顺序od:Order,有升序AS,降序DE,无序UN.缺省值为无序
 * \return 无
 *
 ***********************************************/
void Graph::show_edge(const _IDS& ids, const _lists& keys, const Order& od) {
    if(ids.empty()) {
        cout << "no edges matched to show" << endl;
    } else {
        _edges egtmp;
        for(auto id : ids) {
            egtmp.emplace(make_pair(id, _edge(this->egs[id])));
        }
        this->eps.show(forward<decltype(egtmp)>(egtmp), keys, od);
    }
}
/********************************************//**
 * \brief 输出单个实体属性,默认输出标号和对应实体编号
 *
 * \param 实体编号id:_ID,不可缺省
 * \param 属性集keys:_lists,缺省时输出关系所有属性
 * \return 无
 *
 ***********************************************/
void Graph::show_vert(const _ID& id, const _lists& keys) {
    if(!this->vps.show(id, keys)) {
        cout << "there is no vertex No." << id << endl;
    }
}
/********************************************//**
 * \brief 输出实体集,并排序
 *
 * \param 关系编号集ids:_IDS,不可缺省
 * \param 属性集keys:_lists,不可缺省,按第一个属性进行排序
 * \param 排序顺序od:Order,有升序AS,降序DE,无序UN.缺省值为无序
 * \return 无
 *
 ***********************************************/
void Graph::show_vert(const _IDS& ids, const _lists& keys, const Order& od) {
    if(ids.empty()) {
        cout << "no vertices matched" << endl;
    } else {
        this->vps.show(ids, keys, od);
    }
}
/********************************************//**
 * \brief 增加或修改关系属性
 *
 * \param 关系编号集ids:_IDS,不可缺省
 * \param 算术表达式express:string,例如"total = (unit - 5 )* mount".不可缺省
 * \return 无.有则改之,表达式错误时放弃修改或添加
 *
 ***********************************************/
void Graph::alt_edge(const _IDS& ids, const string& express) {
    this->eps.alt(ids, express);
    this->print("add_edge_prop");
}
/********************************************//**
 * \brief 增加或修改实体属性
 *
 * \param 关系编号集ids:_IDS,不可缺省
 * \param 算术表达式express:string,例如"area = 3.14159 * radius",不可缺省
 * \return 无.有则改之,表达式错误时放弃修改或添加
 *
 ***********************************************/
void Graph::alt_vert(const _IDS& ids, const string& express) {
    this->vps.alt(ids, express);
    this->print("add_vert_prop");
}
/********************************************//**
 * \brief 调用dot命令,以PNG格式输出子图
 *
 * \param 实体编号集vids:_IDS
 * \param
 * \return 无
 *
 ***********************************************/
void Graph::show_graph(const _IDS& vids) {
    auto eids = this->get_edges(vids);
    ofstream fout("out.dot");           //写dot文件
    fout << "digraph out {" << endl;
    fout << "node [shape=record];" << endl;
    for(auto& id : vids) {
        auto name = pack_data(this->vps.pro[id]["name"]).second;
        fout << "node" << id << " [label=\"<f0>" << id << "|<f1>" << name << "\"];" << endl;
    }
    for(auto& e : eids) {
        auto fst = this->egs[e].first;
        auto snd = this->egs[e].second;
        auto edgt = pack_data(this->eps.pro[e]["name"]).second;
        fout << "node" << fst << " -> " << "node" << snd << " [label = \"" << edgt << "\"];" << endl;
    }
    fout << "}" << endl;
    system("dot -Tpng -o out.png out.dot");
    system("out.png");
}
/********************************************//**
 * \brief 用于测试
 *
 * \param 无
 * \param 无
 * \return 无
 *
 ***********************************************/
void Graph::test() {
    //this->vps.show(this->add_vert("Test"));
    _popes test;
    test.emplace_back(_prop("Test", string("此地无银三百两")));
    //this->add_vert_prop(1, test);
    //auto cd1 = _cond(Oprat::EQ, _prop("label", string("customer")));
    //auto cd2 =_cond(Oprat::EQ, _prop("country", string("Pakistan")));
    //auto tset = this->inq_vert(cd1);
    //tset = this->inq_vert(cd2, tset);
    _lists keys = {string("name"), string("addr")};
//    this->show_vert(tset, keys);
    //this->show_graph(tset);
    this->add_vert_prop(1, test);
//    this->show_vert(1);
    //cout << tset.size() << endl;
    //cout<<*tset.begin();
    _IDS vte = {1, 2, 3, 4, 5, 6};
    this->show_graph(vte);
    this->show_vert(vte, keys);
    //this->vps.show(*tset.begin());
}
