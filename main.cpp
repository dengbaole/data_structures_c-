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
    listnode *head = new listnode(0);
    return head;
} 


void headinsert(listnode *head, int data) {
    listnode *newnode = new listnode(data);
    newnode -> next = head -> next;
    head -> next = newnode;
    head -> data++;
}


void tailinsert(listnode *head, int data) {
    listnode *newnode = new listnode(data);
    listnode *p = head;
    while (p -> next != nullptr) {
        p = p -> next;
    }
    p -> next = newnode;
    head -> data++;
}


void deletenode(listnode *head, int data) {
    listnode *p = head;
    while (p -> next != nullptr) {
        if (p -> next -> data == data) {
            listnode *temp = p -> next;
            p -> next = p -> next -> next;
            delete temp;
            head -> data--;
            return;
        } else {
            p = p -> next;
        }   
    }
}


void printlist(listnode *head) {
    listnode *p = head -> next;
    while (p != nullptr) {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main() {
    listnode *head = listinit();
    headinsert(head, 1);
    headinsert(head, 2);
    headinsert(head, 3);
    headinsert(head, 3);
    headinsert(head, 3);
    headinsert(head, 3);
    headinsert(head, 4);
    headinsert(head, 5);
    headinsert(head, 6);
    tailinsert(head, 7);
    deletenode(head, 3);
    printlist(head);

    return 0;
}