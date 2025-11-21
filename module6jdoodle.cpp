#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 定义一个类 Item，用来管理物品
class Item {
public:
    string name;     // 物品名称
    int quantity;    // 数量

    // 将物品写入文件
    void saveToFile() {
        ofstream out("items.txt");
        if (out.is_open()) {
            out << name << "," << quantity << endl;
            out.close();
            cout << "Item saved to file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    // 从文件读出内容
    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                cout << "File content: " << line << endl;
            }
            in.close();
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    // 创建一个 Item 对象
    Item tool;
    tool.name = "Screwdriver";
    tool.quantity = 10;

    // 写入文件
    tool.saveToFile();

    // 从文件读取内容
    tool.loadFromFile();

    return 0;
}
