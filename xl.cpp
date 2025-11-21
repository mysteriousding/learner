#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*================ pe 类 ================*/
class pe 
{
public:
    string mz, dz;
    long long hm;
    pe(const string& m = "", long long h = 0, const string& d = ""): mz(m), hm(h), dz(d) { }

    void xg(const string& n, const string& m) 
    {
        if (n == "mz") mz = m;
        else if (n == "hm") hm = stoll(m);
        else dz = m;
        cout << "修改成功！\n";
    }

    void xs() const
    {
        cout << "名字 -- " << mz << "\n号码 -- " << hm << "\n地址 -- " << dz << "\n\n";
    }
};

/*================ xl 类 ================*/
class xl {
private:
    int num = 1;
    vector<pe> ls;
    int __select = 0;

    string _attr_str(const string& n, int i) const 
    {
        if (n == "hm")
            return to_string(ls[i].hm);
        return (n == "mz") ? ls[i].mz : ls[i].dz;
    }

public:
    xl(const string& mz, long long hm, const string& dz)
    {
        ls.emplace_back(mz, hm, dz);
    }

    void zj(const pe& p) 
    {
        ls.push_back(p);
        num++;
        __select = num - 1;
    }

    void cz(const string& n, const string& m)
    {
        for (int i = 1; i < num; i++)
            if (_attr_str(n, i) == m) 
            {
                __select = i;
                cout << m << " 查找成功!\n";
                _xs();
                return;
            }
        cout << m << " 不存在!\n";
    }

    void _xg(const string& n, const string& m) 
    {
        ls[__select].xg(n, m);
    }

    void sc() 
    {
        if (__select == 0) 
        {
            cout << "0 号记录（自己）不可删除！\n";
            return;
        }
        string name = ls[__select].mz;
        ls.erase(ls.begin() + __select);
        num--;
        __select = (__select + 1) % num;
        cout << name << " 删除成功!\n";
    }

    void q_xs() const 
    {
        for (int i = 0; i < num; ++i)
        {
            cout << "\n" << i << "\n";
            ls[i].xs();
        }
    }
    
    void _xs() const 
    {
        ls[__select].xs();
    }

    void xg_select(int idx)
    {
        if (idx >= 0 && idx < num)
        {
            __select = idx;
            cout << "已切换到位置 " << idx << "\n";
            _xs();
        }
        else cout << "下标越界！当前有效范围 0 ~ " << num - 1 << "\n";
    }

    /* 给菜单用的范围提示 */
    int get_num() const { return num; }
};

/*================ 演示 + 菜单 ================*/
void demo() {
    cout << "--- 演示开始 ---\n";
    xl d("自己", 0, "本地");
    d.zj(pe("张三", 13800138000, "北京"));
    d.zj(pe("李四", 13900139000, "上海"));

    cout << "\n① 查找 13800138000\n";
    d.cz("hm", "13800138000");

    cout << "\n② 修改当前选中地址为广州\n";
    d._xg("dz", "广州");

    cout << "\n③ 显示全部\n";
    d.q_xs();

    cout << "\n④ 手动切换选中位置到 0（自己）\n";
    d.xg_select(0);

    cout << "\n⑤ 再切换到 2（李四）\n";
    d.xg_select(2);

    cout << "\n⑥ 删除当前（李四）\n";
    d.sc();

    cout << "\n⑦ 再次显示全部\n";
    d.q_xs();

    cout << "\n⑧ 尝试删 0 号（自己）\n";
    d.sc();

    cout << "--- 演示结束 ---\n";
}

void main_menu() 
{
    cout << "=== 通讯录 ===\n";
    xl me("自己", 10086, "本地");
    string cmd;
    while (1) 
    {
        cout << "\n========== 主菜单 ==========\n"
            "1 添加联系人\n"
            "2 查找联系人\n"
            "3 修改当前选中\n"
            "4 删除当前选中\n"
            "5 显示全部\n"
            "6 显示当前选中\n"
            "7 切换选中位置\n"
            "0 退出\n"
            "============================\n";
        cout << "请选择操作序号：";
        getline(cin, cmd);
        if (cmd == "1")
        {
            string mz, dz, hm_str;
            cout << "名字：";
            getline(cin, mz);
            cout << "号码："; 
            getline(cin, hm_str);
            cout << "地址："; 
             getline(cin, dz);
            me.zj(pe(mz, stoll(hm_str), dz));
            cout << "已添加并自动选中新记录！\n";
        }
        else if (cmd == "2") 
        {
            string attr, val;
            cout << "按哪个属性查找(mz/hm/dz)：";
            getline(cin, attr);
            cout << "查找值：";            
            getline(cin, val);
            me.cz(attr, val);
        }
        else if (cmd == "3") 
        {
            string attr, val;
            cout << "修改当前记录的哪个属性(mz/hm/dz)：";
            getline(cin, attr);
            cout << "新值：";                          
            getline(cin, val);
            me._xg(attr, val);
        }
        else if (cmd == "4")
            me.sc();
        else if (cmd == "5") 
            me.q_xs();
        else if (cmd == "6") 
        {
            cout << "当前选中：\n"; 
            me._xs();
        }
        else if (cmd == "7") 
        {
            int idx; cout << "请输入新选中位置(0~" << me.get_num() - 1 << ")："; 
            cin >> idx;
            cin.ignore(); 
            me.xg_select(idx);
        }
        else if (cmd == "0")
        {
            cout << "再见！\n"; 
            break;
        }
        else cout << "输入有误，请重试！\n";
    }
}

int main()
{
    demo();
    cout << "\n";
    main_menu();

    return 0;
}