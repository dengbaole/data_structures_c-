#include <iostream>
#include <sstream>    // 包含字符串流
#include <string>     // 包含字符串类
#include <vector>   // 包含向量类
#include <algorithm>

#include <iostream>
using namespace std;

struct Pair {
    public:
        int key;
        string val;
        Pair(int k, string v) : key(k), val(v) {}
};



class ArrayHashTable {
    private:
        vector<Pair*> tables;
    public:
        ArrayHashTable() {
            tables = vector<Pair*>(100);
        }
        ~ArrayHashTable() {
            for (auto pair : tables) {
                delete pair;
            }
            tables.clear();
        }

        int hashFunc(int key){
            return key % tables.size();
        }

        string get(int key) {
            int index = hashFunc(key);
            Pair* pair = tables[index];
            if(pair == nullptr) {
                return "'";
            }
            return pair->val;
        }

        void put(int key, string val) {
            Pair* pair = new Pair(key, val);
            int index = hashFunc(key);
            tables[index] = pair;
        }

        void remove (int key) {
            int index = hashFunc(key);
            delete tables[index];
            tables[index] = nullptr;
        }

        vector<Pair*> pairset() {
            vector<Pair*> pairset;
            for (auto pair : tables) {
                if(pair != nullptr) {
                    pairset.push_back(pair);
                }
            }
            return pairset;
        }

        vector<int> keyset() {
            vector<int> keyset;
            for (auto pair : tables) {
                if(pair != nullptr) {
                    keyset.push_back(pair->key);
                }
            }
            return keyset;
        }

        vector<string> valueset() {
            vector<string> valueset;
            for (auto pair : tables) {
                if(pair != nullptr) {
                    valueset.push_back(pair->val);
                }
            }
            return valueset;
        }

        void print() {
            for (auto pair : tables) {
                if(pair != nullptr) {
                    cout << pair->key << " : " << pair->val << endl;
                }
            }
        }
};


int main() {
    
    ArrayHashTable* hashTable = new ArrayHashTable();
    hashTable->put(1, "one");
    hashTable->put(2, "two");
    hashTable->put(3, "three");
    hashTable->put(4, "four");
    hashTable->put(5, "five");
    hashTable->put(6, "six");


    
    cout << hashTable->get(1) << endl;
    cout << hashTable->get(2) << endl;
    cout << hashTable->get(3) << endl;
    cout << hashTable->get(4) << endl;
    cout << hashTable->get(5) << endl;
    cout << hashTable->get(6) << endl;

     hashTable->remove(3);


    hashTable->print();
        // 使用 pairset() 方法获取所有有效的 Pair 对象
    
  // 使用 keyset() 方法获取所有有效的键
    vector<int> allKeys = hashTable->keyset();

    // 打印所有键
    cout << "All keys in the hash table:" << endl;
    for (auto key : allKeys) {
        cout << key << endl;
    }
    return 0;
}