#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;

public:
    // 构造函数（初始化属性）
    Product(int i, string n, float p) : id(i), name(n), price(p) {
        cout << "Constructor called!" << endl;
    }

    // 析构函数（对象结束时触发）
    ~Product() {
        cout << "Destructor called!" << endl;
    }

    // 打印商品信息
    void printDetails() {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Price: $" << price << endl;
    }
};

int main() {
    // 建立一个 product 对象
    Product p(101, "Notebook", 4.99);

    // 显示信息
    p.printDetails();

    return 0;
}
