#include <iostream>
#include <sstream>    // 包含字符串流
#include <string>     // 包含字符串类


#include <iostream>
using namespace std;

 
// struct listnode {
//     int data;
//     listnode *next;
//     listnode(int d) : data(d), next(nullptr) {} // 构造函数
// };


struct listnode {
    int data;
    listnode *next;
    listnode(int d); // 构造函数
};


listnode::listnode(int d) {
    data = d;
    next = nullptr;
}

listnode* listinit(void) {
    listnode *head = new listnode(1);
    return head;
} 


void headinsert(listnode *head, int data) {
    listnode *newnode = new listnode(data);
    newnode->next = head;
    head = newnode;
}

int main() {
    listnode *head = new listnode(1);
    listnode *p = head;
    for (int i = 2; i <= 5; ++i) {
        p->next = new listnode(i);
        p = p->next;
    }

    // 打印链表
    p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }

    return 0;
}