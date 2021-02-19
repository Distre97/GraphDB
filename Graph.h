#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Property.h"

using namespace zecy;
class Graph {
  private:
    _edges egs;             //�߱�,������й�ϵ���,����Ӧ��(�����,�յ���)
    _verts vts;             //���,�������ʵ����,����Ӧ��(���߼���,��߼���),��˫���ڽӱ�
    VertexProperty vps;     //�����Լ�,������,ɾ,��,�ĵȷ���
    EdgeProperty eps;       //�����Լ�,ͬ��
    Graph();
    _ID get_edge_id(const _edge& eg);   //���������յ��ȡ��Ӧ�ı߱��
    _IDS get_edges(const _IDS& vids);   //��ȡһ���㼯�����б�
  public:
    ~Graph(){
    }
    Graph(Graph const&) = delete;             //ɾ����������
    Graph(Graph&&) = delete;                  //ɾ���ƶ�����
    Graph& operator=(Graph const&) = delete;  //ɾ��������ֵ
    Graph& operator=(Graph &&) = delete;      //ɾ���ƶ���ֵ
    static Graph& getInstance() {             //��Graph����Ϊ����,�����ι����������
        static Graph instance;
        return instance;
    }
    bool isVertM, isEdgeM;                     //��־�����Ƿ��޸�
    void save();                               //������д���ļ�
    ///��
    _ID add_vert(const string& name, const string& label = "none", _popes prs = {});
    _ID add_edge(const _edge& egs, const string& type, _popes prs = {});
    void add_vert_prop(const _ID& id, const _popes& ps);
    void add_edge_prop(const _ID& id, const _popes& ps);
    ///ɾ
    void del_vert(const _ID& id, const string& key = "");
    void del_edge(const _ID& id, const string& key = "");
    void del_vert(const _IDS& ids, const _lists& keys = {});
    void del_edge(const _IDS& ids, const _lists& keys = {});
    ///��
    _IDS inq_vert(const _cond& cd, const _IDS& rg = ANY);
    _IDS inq_edge(const _cond& cd, const _IDS& rg = ANY);
    _IDS inq_vert(const Relat& re, const _cond& cd, const _IDS& rg);
    _IDS inq_edge(const Relat& re, const _cond& cd, const _IDS& rg);
    _IDS inq_vert(const _IDS& eids, const Direc& de = Direc::FROM);
    _IDS inq_edge(const _IDS& vids, const Direc& de = Direc::OUT);
    ///ͳ��
    void inq_vert(const string& key, const Stats& st = Stats::MAX, const _IDS& rg = ANY);
    void inq_edge(const string& key, const Stats& st = Stats::MAX, const _IDS& rg = ANY);
    ///��ʾ
    void show_vert(const _ID& id, const _lists& keys = {});
    void show_vert(const _IDS& ids, const _lists& keys, const Order& od = Order::UN);
    void show_edge(const _ID& id, const _lists& keys = {});
    void show_edge(const _IDS& ids, const _lists& keys, const Order& od = Order::UN);
    void show_graph(const _IDS& ids);
    ///��
    void alt_edge(const _IDS& ids, const string& express);
    void alt_vert(const _IDS& ids, const string& express);

    void test();    //����
    void print(string t) const {
        //cout << t << endl;
    }
};

#endif // GRAPH_H_INCLUDED
