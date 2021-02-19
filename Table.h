#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include "Utility.h"
#include <iomanip>

using namespace zecy;
//Table:用于输出显示的表格构造
class Table {
  public:
    //默认构造函数,初始化水平分割符号:'-;,垂直分割符号:'|'和交点符号:'+'
    Table(char horizontal = '-', char vertical = '|', char corner = '+') :
        horizontal(horizontal), vertical(vertical), corner(corner) {
    }
    void add(string const & content = "") { //向当前列current添加一个表格项,默认为空字符串
        current.emplace_back(content);
    }
    void end_of_row() {                     //结束当前列.将当前列存入表格rows后清空当前列current
        rows.emplace_back(current);
        current.clear();
    }
  private:
    _lists current;                         //当前列,暂存表项内容
    vector<_lists> rows;                    //表格,存放所有表格数据
    vector<size_t> mutable width;           //水平,垂直,交点分隔符
    char horizontal, vertical, corner;
    size_t chlen(const string& str) const { //计算字串宽度,汉字字符length()为3,但是终端中只占用2个英文字符宽度,计算时应减去1
        return str.length() - count_if(str.begin(), str.end(), [](char ch)->bool { return (ch & 0xF0) == 0xE0;});
    }
    void setup() const {                    //设置宽度向量,将每列最长的字符串宽度作为列宽
        width.assign(rows[0].size(), 0);
        for(auto& a : rows) {
            for(size_t i = 0; i < a.size(); ++i) {
                width[i] = max(width[i], this->chlen(a[i]));
            }
        }
    }
    //重载<<符号将表格转化为ostream
    friend std::ostream & operator<<(std::ostream & stream, Table const & tb);
};

std::ostream & operator<<(std::ostream & stream, Table const & tb) {
    tb.setup();
    auto ruler = accumulate(tb.width.begin(), tb.width.end(), string(1, tb.corner), [&](string tmp, const auto & a) {
        return tmp + (string(a, tb.horizontal) + tb.corner);
    });//根据宽度向量构造表头和表尾的分割线
    stream << ruler << endl;    //表头分割线
    for(auto a : tb.rows) {
        stream << tb.vertical;
        for(size_t i = 0; i < a.size(); ++i) {//每行数据
            stream << setw(a[i].size() + tb.width[i] - tb.chlen(a[i])) << std::left << a[i] << tb.vertical;
        }
        stream << endl;
        if(a == tb.rows.back() || a == tb.rows.front()) {   //第一行和最后一行设置分割线,形成完整表格
            stream << ruler << endl;
        }
    }
    stream << endl;
    return stream;
}

#endif // TABLE_H_INCLUDED
