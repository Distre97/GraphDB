#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Property.h"

using namespace zecy;
class Graph {
  private:
    _edges egs;             //边表,存放所有关系编号,及对应的(起点编号,终点编号)
    _verts vts;             //点表,存放所有实体编号,及对应的(出边集合,入边集合),即双重邻接表
    VertexProperty vps;     //点属性集,包含增,删,查,改等方法
    EdgeProperty eps;       //边属性集,同上
    Graph();
    _ID get_edge_id(const _edge& eg);   //根据起点和终点获取对应的边编号
    _IDS get_edges(const _IDS& vids);   //获取一个点集的所有边
  public:
    ~Graph(){
    }
    Graph(Graph const&) = delete;             //删除拷贝构造
    Graph(Graph&&) = delete;                  //删除移动构造
    Graph& operator=(Graph const&) = delete;  //删除拷贝赋值
    Graph& operator=(Graph &&) = delete;      //删除移动赋值
    static Graph& getInstance() {             //将Graph构造为单例,避免多次构造读脏数据
        static Graph instance;
        return instance;
    }
    bool isVertM, isEdgeM;                     //标志数据是否被修改
    void save();                               //将数据写回文件
    ///增
    _ID add_vert(const string& name, const string& label = "none", _popes prs = {});
    _ID add_edge(const _edge& egs, const string& type, _popes prs = {});
    void add_vert_prop(const _ID& id, const _popes& ps);
    void add_edge_prop(const _ID& id, const _popes& ps);
    ///删
    void del_vert(const _ID& id, const string& key = "");
    void del_edge(const _ID& id, const string& key = "");
    void del_vert(const _IDS& ids, const _lists& keys = {});
    void del_edge(const _IDS& ids, const _lists& keys = {});
    ///查
    _IDS inq_vert(const _cond& cd, const _IDS& rg = ANY);
    _IDS inq_edge(const _cond& cd, const _IDS& rg = ANY);
    _IDS inq_vert(const Relat& re, const _cond& cd, const _IDS& rg);
    _IDS inq_edge(const Relat& re, const _cond& cd, const _IDS& rg);
    _IDS inq_vert(const _IDS& eids, const Direc& de = Direc::FROM);
    _IDS inq_edge(const _IDS& vids, const Direc& de = Direc::OUT);
    ///统计
    void inq_vert(const string& key, const Stats& st = Stats::MAX, const _IDS& rg = ANY);
    void inq_edge(const string& key, const Stats& st = Stats::MAX, const _IDS& rg = ANY);
    ///显示
    void show_vert(const _ID& id, const _lists& keys = {});
    void show_vert(const _IDS& ids, const _lists& keys, const Order& od = Order::UN);
    void show_edge(const _ID& id, const _lists& keys = {});
    void show_edge(const _IDS& ids, const _lists& keys, const Order& od = Order::UN);
    void show_graph(const _IDS& ids);
    ///改
    void alt_edge(const _IDS& ids, const string& express);
    void alt_vert(const _IDS& ids, const string& express);

    void test();    //测试
    void print(string t) const {
        //cout << t << endl;
    }
};

#endif // GRAPH_H_INCLUDED
