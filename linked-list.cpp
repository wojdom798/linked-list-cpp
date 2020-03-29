#include <iostream>
#include <cstring>

using namespace std;

class Node {
  private:
  int data;
  Node* next;

  public:
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  ~Node() {
    delete next;
  }

  int getValue(void) {
    return this->data;
  }

  void setData(int d) {
    this->data = d;
  }

  Node* getNext(void) {
    return this->next;
  }

  void setNext(Node* n) {
    this->next = n;
  }
};

class LinkedList {
  private:
  Node* head;
  int numberOfItems;

  public:
  LinkedList() : head(NULL), numberOfItems(0) {};
  LinkedList(int value) {
    head = new Node(value);
    numberOfItems = 1;
  }

  // debug
  Node* getHead(void) {
    return head;
  }

  int length(void) {
    return this->numberOfItems;
  }

  void addItem(int value) {
    if (this->head == NULL) {
      head = new Node(value);
      numberOfItems = 1;
    } else if (this->numberOfItems == 1) {
      Node* newNode = new Node(value);
      head->setNext(newNode);
      this->numberOfItems++;
    } else {
      Node* currentNode = this->head;
      for (int i = 0; i < this->length() - 1; i++) {
        currentNode = currentNode->getNext();
      }
      currentNode->setNext(new Node(value));
      this->numberOfItems++;
    }
  }

  string toString(void) {
    string s = "[ ";
    Node* currentNode = this->head;
    int i = 1;

    while (currentNode != NULL) {
      s += to_string(currentNode->getValue());
      currentNode = currentNode->getNext();
      if (i < this->numberOfItems) {
        s += ", ";
      }
      i++;
    }
    s += " ]";

    return s;
  }

};


int main(void) {

  Node n = Node(3);
  LinkedList ll = LinkedList(11);
  ll.addItem(25);
  ll.addItem(41);


  cout << n.getValue() << endl;
  cout << ll.toString() << endl;


  return 0;
}