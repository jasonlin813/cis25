#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// ----------------------------
// Item class for each row
// ----------------------------
class Company {
public:
    string symbol;
    string name;
    string sector;
    string industry;
    string founded;

    Company(string s, string n, string sec, string ind, string f)
        : symbol(s), name(n), sector(sec), industry(ind), founded(f) {}

    void print() {
        cout << "Symbol: "   << symbol   << "\n"
             << "Name: "     << name     << "\n"
             << "Sector: "   << sector   << "\n"
             << "Industry: " << industry << "\n"
             << "Founded: "  << founded  << "\n"
             << "-----------------------------\n";
    }
};

// ----------------------------
// Dataset loader class
// ----------------------------
class DatasetLoader {
public:
    vector<Company> companies;

    void loadFromCSV(const string& csvData) {
        string line;
        stringstream ss(csvData);

        getline(ss, line); // skip header

        while (getline(ss, line)) {
            stringstream row(line);
            string symbol, name, sector, industry, founded;

            getline(row, symbol, ',');
            getline(row, name, ',');
            getline(row, sector, ',');
            getline(row, industry, ',');
            getline(row, founded, ',');

            companies.push_back(Company(symbol, name, sector, industry, founded));
        }
    }

    void displayAll() {
        for (auto& c : companies) {
            c.print();
        }
    }
};

// ----------------------------
// Main program
// ----------------------------
int main() {

    // Small CSV sample (5 fields, 10 rows)
    string csvData =
        "Symbol,Name,Sector,Industry,Founded\n"
        "AAPL,Apple Inc.,Technology,Consumer Electronics,1976\n"
        "MSFT,Microsoft Corp.,Technology,Software,1975\n"
        "GOOG,Alphabet Inc.,Communication Services,Internet Content,1998\n"
        "AMZN,Amazon.com Inc.,Consumer Cyclical,Internet Retail,1994\n"
        "TSLA,Tesla Inc.,Consumer Cyclical,Auto Manufacturers,2003\n"
        "NVDA,NVIDIA Corp.,Technology,Semiconductors,1993\n"
        "META,Meta Platforms Inc.,Communication Services,Social Media,2004\n"
        "JPM,JP Morgan Chase,Financial Services,Banks,1799\n"
        "V,Visa Inc.,Financial Services,Transaction Services,1958\n"
        "WMT,Walmart Inc.,Consumer Defensive,Discount Stores,1962\n";

    DatasetLoader loader;
    loader.loadFromCSV(csvData);

    cout << "Loaded " << loader.companies.size() << " companies.\n\n";

    loader.displayAll();

    return 0;
}