#include <iostream>
#include <sstream>    // 包含字符串流
#include <string>     // 包含字符串类
#include <vector>   // 包含向量类
#include <algorithm>

#include <iostream>
using namespace std;

struct Pair{
    public:
        int key;
        string val;
        Pair(int key,string val) {
            this -> key = key;
            this -> val = val;
        }
};


class hashmapchaining {
    private:
        int size;           //键值对数量
        int capacity;      //哈希表容量
        double loadthres;   //触发扩容的负载因子阈值
        int extendratio;    //扩容倍数
        vector<vector<Pair *>>buckets;
    public:
        //构造方法
        hashmapchaining():size(0),capacity(4),loadthres(2.0/3.0),extendratio(2){
            buckets.resize(capacity);
        }
        //析构方法
        ~hashmapchaining(){
            for(auto & bucket:buckets){
                for(Pair *pair:bucket){
                    delete pair;
                }
            }
        }
        int hashfunc(int key) {
            return key % capacity;
        }
        double loadfactor(){
            return (double)size / capacity;
        }
        string get(int key){
            int index = hashfunc(key);
            for(Pair *pair:buckets[index]){
                if(pair -> key == key){
                    return pair -> val;
                }
            }
            return "null";
        }

        void put(int key,string val){
            int index = hashfunc(key);
            for(Pair *pair:buckets[index]){
                if(pair -> key == key){
                    pair -> val = val;
                    return;
                }
            }
            Pair *pair = new Pair(key,val);
            buckets[index].push_back(pair);
            size++;
            if(loadfactor() > loadthres){
                extend();
            }
        }

        void remove (int key){
            int index = hashfunc(key);
           auto & bucket = buckets[index];
            for(auto it = bucket.begin(); it != bucket.end(); ++it){
                if((*it) -> key == key){
                    bucket.erase(it);
                    size--;
                    return;
                }
            }
        }

        void extend(){
            vector<vector<Pair *>>bucketstmp = buckets;
            capacity *= extendratio;
            buckets.clear();
            buckets.resize(capacity);
            size = 0;
            for(auto & bucket:bucketstmp){
                for(Pair *pair:bucket){
                    put(pair -> key,pair -> val);
                    delete pair;
                }
            }
        }
        void print(){
            for(auto & bucket:buckets){
                for(Pair *pair:bucket){
                    cout<<pair -> key<<" "<<pair -> val<<endl;
                }
            }
        }
};


int main() {
    
   
    return 0;
}