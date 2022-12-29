#include <iostream>

using namespace std;

template<typename T>
struct Node {
    Node<T> *prev, *next;
    int data;

    Node(T x) {
        prev = NULL;
        next = NULL;
        data = x;
    }
};

template<typename T>
class list {
public:
    using PNode = Node<T> *;

    PNode tail;
    PNode head;
    PNode crs;

    list<T>() {
        tail = NULL;
        head = NULL;
        crs = head;
    }

    friend ostream &operator<<(ostream &os, const list<T> &a) {
        PNode ptr = a.head;
        while (ptr != NULL) {
            if (ptr == a.crs && a.crs != NULL)
                os << "-->" << ptr->data << "<-- ";
            else
                os << ptr->data << ' ';
            ptr = ptr->next;
        }
        os << endl;
        return os;
    }

    void Addcrs(T x) {
        PNode y = new Node<T>(x);
        if (crs != NULL) {
            if (crs->prev == NULL) {
                head->prev = y;
                y->next = head;
                head = y;
            } else {
                crs->prev->next = y;
                y->prev = crs->prev;
                y->next = crs;
                crs->prev = y;
            }
        }
    }

    void Deletecrs() {
        if (crs != NULL)
            if (crs->prev == NULL and crs->next == NULL) {
                delete (head);
                head = NULL;
                tail = NULL;
                crs=NULL;
            } else {
                if (crs->prev==NULL){
                    PNode P=crs->next;
                    PNode tmp=head;
                    head=crs->next;
                    head->prev=NULL;
                    delete(tmp);
                    crs = P;
                } else {
                    if (crs->next==NULL){
                        PNode P=crs->prev;
                        PNode tmp=tail;
                        tail=crs->prev;
                        tail->next=NULL;
                        delete(tmp);
                        crs=P;
                    } else{
                        PNode P=crs->next;
                        crs->prev->next=crs->next;
                        crs->next->prev=crs->prev;
                        delete(crs);
                        crs=P;
                    }
                }

            }
    }

    void Movecrsright() {
        if (crs->next != NULL)
            crs = crs->next;
    }

    void Movecrsleft() {
        if (crs->prev != NULL)
            crs = crs->prev;
    }

    bool Isempty() {
        if (head == NULL)
            return true;
        return false;
    }


    void Pushfront(T x) {
        PNode y = new Node<T>(x);
        if (head == NULL) {
            crs = y;
            head = y;
            tail = y;
        } else {
            y->next = head;
            head->prev = y;
            head = y;
        }
    }

    void Pushback(T x) {
        PNode y = new Node<T>(x);
        if (head == NULL) {
            head = y;
            tail = y;
            crs = y;
        } else {
            y->prev = tail;
            tail->next = y;
            tail = y;
        }
    }

    void Deletefirst() {
        if (head != NULL) {
            if (head->next == NULL) {
                delete (head);
                tail = NULL;
                head = NULL;
                crs = NULL;
            } else {
                PNode tmp = head;
                head = head->next;
                delete (tmp);
                head->prev = NULL;
            }
        }
    }

    void Deletelast() {
        if (head != NULL) {
            if (head->next == NULL) {
                delete (head);
                head = NULL;
                tail = NULL;
                crs = NULL;
            } else {
                PNode tmp = tail;
                tail = tail->prev;
                delete (tmp);
                tail->next = NULL;
            }
        }
    }
};

int main() {
    list<int> s;
    string a;
    cout<<"Добавить элемент в конец - Pushback x"<<endl<<"Добавить в начало - Pushfront x"<<endl<<"Удалить первый-Deletefirst"<<endl;
    cout<<"удалить последний - Deletelast"<<endl<<"курсор вправо - Movecursorright"<<endl<<"курсор влево - Movecursorleft"<<endl;
    cout<<"Добавить перед курсором - Addcrs x"<<endl<<"удалить элемент, на который указывает курсор - Deletecrs"<<endl;
    while (true) {
        cin >> a;
        if (a == "Pushback") {
            cin >> a;
            s.Pushback(stoi(a));
            cout << s;
        }
        if (a == "Pushfront") {
            cin >> a;
            s.Pushfront(stoi(a));
            cout << s;
        }
        if (a == "Deletefirst") {
            s.Deletefirst();
            cout << s;
        }
        if (a == "Deletelast") {
            s.Deletelast();
            cout << s;
        }
        if (a == "Movecursorright") {
            s.Movecrsright();
            cout << s;
        }
        if (a == "Movecursorleft") {
            s.Movecrsleft();
            cout << s;
        }
        if (a == "Addcrs") {
            cin >> a;
            s.Addcrs(stoi(a));
            cout << s;
        }
        if (a=="Deletecrs"){
            s.Deletecrs();
            cout<<s;
        }
    }

    return 0;
}



