#include "Graph.h"
/********************************************//**
 * \brief ���캯��,��ʼ��
 *
 * \param ��
 * \param ��
 * \return ��
 *
 ***********************************************/
Graph::Graph() {
    _ID eid, vid1, vid2;
    ifstream fin("edge.db");
    while(fin >> eid >> vid1 >> vid2) {
        this->egs.emplace(make_pair(eid, _edge(vid1, vid2)));   //д�߱�
        this->vts[vid1].first.emplace(eid);                     //д�������߼�
        this->vts[vid2].second.emplace(eid);                    //д���յ���߼�
    }
    fin.close();
}
/********************************************//**
 * \brief ������д���ļ�
 *
 * \param ��
 * \param
 * \return ��
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
 * \brief ��ȡ�ߵı��
 *
 * \param ��_edge:pair<_ID, _ID>
 * \param
 * \return ���_ID:size_t,�������ڷ��ر������0
 *
 ***********************************************/
_ID Graph::get_edge_id(const _edge& eg) {
    auto tmp = this->vts[eg.first].first & this->vts[eg.second].second;
    return tmp.size() == 0 ? *tmp.begin() : 0;
}
/********************************************//**
 * \brief ��ȡһ���㼯�����б�
 *
 * \param ���㼯���_IDS: set<_ID>
 * \param
 * \return �߼����_IDS: set<_ID>
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
 * \brief ���һ����
 *
 * \param ʵ������name:string,����ȱʡ
 * \param ʵ�����label:string,ȱʡֵ"none"
 * \param ʵ��������prs:_popes,��ȱʡ
 * \return ʵ����_ID,��ӳɹ�����id,ʧ�ܷ���0
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
 * \brief ��ͼ�����һ����
 *
 * \param ��ϵeg:_eg,����ȱʡ
 * \param ��ϵ���type:string,ȱʡֵ"none"
 * \param ��ϵ����prs:_popes,��ȱʡ
 * \return ��ϵ���_IDS,��ӳɹ�����id,ʧ�ܷ���0
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
 * \brief ���һ��ʵ�������
 *
 * \param ʵ����id:_ID,����ȱʡ
 * \param ʵ�����Լ�ps:_popes,����ȱʡ
 * \return ��.�����֮,�������
 *
 ***********************************************/
void Graph::add_vert_prop(const _ID& id, const _popes& ps) {
    if(this->vps.add(id, ps)) {
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief ���һ����ϵ������
 *
 * \param ��ϵid:_ID,����ȱʡ
 * \param ���Լ�ps:_popes,����ȱʡ
 * \return ��.�����֮,��������
 *
 ***********************************************/
void Graph::add_edge_prop(const _ID& id, const _popes& ps) {
    if(this->eps.add(id, ps)) {
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief ɾ������ʵ��ĵ�������
 *
 * \param ʵ����id:_ID,����ȱʡ
 * \param ʵ������key:string,��ȱʡ.ȱʡֵ"",����ɾ������ʵ��
 * \return ��
 *
 ***********************************************/
void Graph::del_vert(const _ID& id, const string& key) {
    if(this->vts.count(id)) {
        if(key.size() == 0) {
            auto out = this->vts[id].first;      //ɾ������
            auto in = this->vts[id].second;    //ɾ�����
            for(auto& a : in) {
                this->del_edge(a);
            }
            for(auto& a : out) {
                this->del_edge(a);
            }
            this->vts.erase(id);            //�ӵ��ɾ��
        }
    }
    if(this->vps.del(id, key)) {            //�����Լ�ɾ��
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief ɾ��ʵ�弯�Ķ������
 *
 * \param ʵ���ż�ids:_IDS,����ȱʡ
 * \param ���Լ�keys:_lists,��ȱʡ.ȱʡֵΪ{},��ʾɾ��ʵ�弯������ʵ��
 * \return ��
 *
 ***********************************************/
void Graph::del_vert(const _IDS& ids, const _lists& keys) {
    if(!ids.empty()) {
        if(keys.size() == 0) {
            for(auto& id : ids) {
                auto out = this->vts[id].first;     //����
                auto in = this->vts[id].second;     //���
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
 * \brief ɾ��������ϵ�ĵ�������
 *
 * \param ��ϵ���id:_ID,����ȱʡ
 * \param ���Լ���key:string.ȱʡʱɾ����ϵ
 * \return ��
 *
 ***********************************************/
void Graph::del_edge(const _ID& id, const string& key) {
    if(this->egs.count(id)) {
        if(key.size() == 0) {
            this->vts[this->egs[id].first].first.erase(id);     //��������ɾ��
            this->vts[this->egs[id].second].second.erase(id);   //���յ����ɾ��
            this->egs.erase(id);
        }
    }
    if(this->eps.del(id, key)) {
        this->print(__FUNCTION__);
    }
}
/********************************************//**
 * \brief ɾ����ϵ���ж������
 *
 * \param ��ϵ��ż�ids:_IDS,����ȱʡ
 * \param ���Լ�keys:_lists,ȱʡʱɾ����ϵ��
 * \return ��
 *
 ***********************************************/
void Graph::del_edge(const _IDS& ids, const _lists& keys) {
    if(!ids.empty()) {
        if(keys.size() == 0) {
            for(auto id : ids) {
                this->vts[this->egs[id].first].first.erase(id);     //��������ɾ��
                this->vts[this->egs[id].second].second.erase(id);   //���յ����ɾ��
                this->egs.erase(id);
            }
        }
        if(this->eps.del(ids, keys)) {
            this->print(__FUNCTION__);
        }
    }
}
/********************************************//**
 * \brief ��ѯʵ��(������ϵ)
 *
 * \param ��������cd:_cond, ����ȱʡ
 * \param ��ѯ��Χrg:_IDS,ȱʡʱȫ�ֲ���
 * \return ʵ���ż�_IDS
 *
 ***********************************************/
_IDS Graph::inq_vert(const _cond& cd, const _IDS& rg) {
    return this->vps.inq(cd, rg);
}
/********************************************//**
 * \brief ��һ��ʵ�弯�в�������������ʵ��
 *
 * \param ��ϵ�����re:Relat,Relat::AND��,Relat::OR��,����ȱʡ
 * \param ��������cd:_cond,����ȱʡ
 * \return ʵ���ż�_IDS
 *
 ***********************************************/
_IDS Graph::inq_vert(const Relat& re, const _cond& cd, const _IDS& rg) {
    return this->vps.inq(re, cd, rg);
}
/********************************************//**
 * \brief ͨ����ϵ������ʵ��
 *
 * \param ��ϵ��ż�eids:_IDS,����ȱʡ
 * \param ����drc:Direc,Direc::FROM��ʾ���,Direc::TO��ʾ�յ�,ȱʡΪDirec::FROM
 * \return ʵ���ż�_IDS
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
 * \brief ͳ��ʵ�����Լ�,�����
 *
 * \param ʵ������key:string,����ȱʡ
 * \param ͳ�����:st:Stats,Stats::MAX��ʾ���ֵ,Stat::MIN��ʾ��Сֵ,Stat::SUM��ʾ���
 * \return ��
 *
 ***********************************************/
void Graph::inq_vert(const string& key, const Stats& st, const _IDS& rg) {
    this->vps.inq(key, st, rg);
}
/********************************************//**
 * \brief ��ѯ���������Ĺ�ϵ
 *
 * \param ��ѯ����cd:_cond,����ȱʡ
 * \param ��ѯ��Χrg:_IDS,ȱʡʱȫ�ֲ���
 * \return ��ϵ��ż�
 *
 ***********************************************/
_IDS Graph::inq_edge(const _cond& cd, const _IDS& rg) {
    return this->eps.inq(cd, rg);
}
/********************************************//**
 * \brief ��һ����ϵ���в�������������ʵ��
 *
 * \param ��ϵ�����re:Relat,Relat::AND��,Relat::OR��,����ȱʡ
 * \param ��������cd:_cond,����ȱʡ
 * \return ��ϵ��ż�_IDS
 *
 ***********************************************/
_IDS Graph::inq_edge(const Relat& re, const _cond& cd, const _IDS& rg) {
    return this->eps.inq(re, cd, rg);
}
/********************************************//**
 * \brief ��ѯʵ�弯�ĳ��߻������
 *
 * \param ʵ���ż�vids:_IDS,����ȱʡ
 * \param ��ϵ����dirc:Direc,Direc::IN��ʾ���,Direc::OUT��ʾ����
 * \return ��ϵ��ż�
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
 * \brief ͳ�ƹ�ϵ���Լ�,�����
 *
 * \param ��ϵ����key:string,����ȱʡ
 * \param ͳ�����:st:Stats,Stats::MAX��ʾ���ֵ
 *        Stat::MIN��ʾ��Сֵ,Stat::SUM��ʾ���
 * \return ��
 *
 ***********************************************/
void Graph::inq_edge(const string& key, const Stats& st, const _IDS& rg) {
    this->eps.inq(key, st, rg);
}
/********************************************//**
 * \brief ���������ϵ����,Ĭ�������źͶ�Ӧʵ����
 *
 * \param ��ϵ���id:_ID,����ȱʡ
 * \param ���Լ�keys:_lists,ȱʡʱ�����ϵ��������
 * \return ��
 *
 ***********************************************/
void Graph::show_edge(const _ID& id, const _lists& keys) {
    if(!this->eps.show(id, this->egs[id], keys)) {
        cout << "there is no edge No." << id << endl;
    }
}
/********************************************//**
 * \brief �����ϵ��,������
 *
 * \param ��ϵ��ż�ids:_IDS,����ȱʡ
 * \param ���Լ�keys:_lists,����ȱʡ
 * \param ����˳��od:Order,������AS,����DE,����UN.ȱʡֵΪ����
 * \return ��
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
 * \brief �������ʵ������,Ĭ�������źͶ�Ӧʵ����
 *
 * \param ʵ����id:_ID,����ȱʡ
 * \param ���Լ�keys:_lists,ȱʡʱ�����ϵ��������
 * \return ��
 *
 ***********************************************/
void Graph::show_vert(const _ID& id, const _lists& keys) {
    if(!this->vps.show(id, keys)) {
        cout << "there is no vertex No." << id << endl;
    }
}
/********************************************//**
 * \brief ���ʵ�弯,������
 *
 * \param ��ϵ��ż�ids:_IDS,����ȱʡ
 * \param ���Լ�keys:_lists,����ȱʡ,����һ�����Խ�������
 * \param ����˳��od:Order,������AS,����DE,����UN.ȱʡֵΪ����
 * \return ��
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
 * \brief ���ӻ��޸Ĺ�ϵ����
 *
 * \param ��ϵ��ż�ids:_IDS,����ȱʡ
 * \param �������ʽexpress:string,����"total = (unit - 5 )* mount".����ȱʡ
 * \return ��.�����֮,���ʽ����ʱ�����޸Ļ����
 *
 ***********************************************/
void Graph::alt_edge(const _IDS& ids, const string& express) {
    this->eps.alt(ids, express);
    this->print("add_edge_prop");
}
/********************************************//**
 * \brief ���ӻ��޸�ʵ������
 *
 * \param ��ϵ��ż�ids:_IDS,����ȱʡ
 * \param �������ʽexpress:string,����"area = 3.14159 * radius",����ȱʡ
 * \return ��.�����֮,���ʽ����ʱ�����޸Ļ����
 *
 ***********************************************/
void Graph::alt_vert(const _IDS& ids, const string& express) {
    this->vps.alt(ids, express);
    this->print("add_vert_prop");
}
/********************************************//**
 * \brief ����dot����,��PNG��ʽ�����ͼ
 *
 * \param ʵ���ż�vids:_IDS
 * \param
 * \return ��
 *
 ***********************************************/
void Graph::show_graph(const _IDS& vids) {
    auto eids = this->get_edges(vids);
    ofstream fout("out.dot");           //дdot�ļ�
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
 * \brief ���ڲ���
 *
 * \param ��
 * \param ��
 * \return ��
 *
 ***********************************************/
void Graph::test() {
    //this->vps.show(this->add_vert("Test"));
    _popes test;
    test.emplace_back(_prop("Test", string("�˵�����������")));
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
