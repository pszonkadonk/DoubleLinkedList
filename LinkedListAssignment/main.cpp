#include <iostream>
#include <memory>
#include <vector>
#include <iterator>
#include "List.h"

using namespace std;

template <class T>
List<T>::List() { list_size = 0; }

template <class T>
List<T>::List(const List<T> &other) {list_size = other.list_size;}

template <class T>
List<T>::List(List &&other) {list_size = other.list_size;}

template<class T>
shared_ptr<s_node<T>> List<T>::new_node(T elem, shared_ptr<s_node<T>> next, shared_ptr<s_node<T>> previous)
{
    
    s_node<T> newNode;
    newNode.elem = elem;
    newNode.next = next;
    newNode.prev = previous;
    shared_ptr<s_node<T>> newNodePTR = make_shared<s_node<T>>(newNode);
    return newNodePTR;
}

template<class T>
void List<T>::add_node(shared_ptr<s_node<T>> node, shared_ptr<s_node<T>>& head)
{
    shared_ptr<s_node<T>> temp;
    //List is empty
    if (head->next == nullptr) {
        head->next = node;
        node->prev = head;
    }
    // if head is pointing to next node, overwrite current head with node
    else {
        temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        
        
        
//        node->next = head->next;
//        head->elem = node->elem;
//        list_size+=1;
    }
    list_size+=1;
}

template<class T>
void List<T>::add_elem(T elem, shared_ptr<s_node<T>> &head)
{
    s_node<T> newNode;
    newNode->elem = elem;
    head->elem = newNode->elem;
    newNode->next = head->next; 
    
//    is it this instead?  **
//    head->elem = elem;
}

template<class T>
void List<T>::append(shared_ptr<s_node<T>> node, shared_ptr<s_node<T>> &head)
{
    shared_ptr<s_node<T>> traversal_node = head;
    
    // Step through list until null pointer is found.  When it is found
    // it means we've reached the current laast node in the list and we can then
    // append this new node to the end
    
    while(traversal_node->next!= nullptr) {
        
        traversal_node = traversal_node->next;
    }
    if(traversal_node->next == nullptr) {
        traversal_node->next = node;
        node->prev = traversal_node;
//        cout << node->elem << endl;
    }
    
    list_size+=1;
}

template<class T>
void List<T>::add_node_at(shared_ptr<s_node<T>> node, shared_ptr<s_node<T>> &head, int n) {
    
    if(n > list_size) {
        
        append(node, head);
    }
    else {
        
        int count = 0;
        shared_ptr<s_node<T>> traversal_node = head;
        
        while(count != n) {
            traversal_node = traversal_node->next;
            count+=1;
        }
        node->prev = traversal_node->prev;
        node->next = traversal_node;
        traversal_node->prev = node;
        node->prev->next = node; // link the node before nth node, to nth node
    }
    list_size+=1;
    
//    shared_ptr<s_node<T>> temp = head;
//    cout << "this is list size: " << list_size << endl;
//    for(int i = 0; i <= list_size; i++) {
//        
//        cout <<temp->elem << endl;
//        temp = temp->next;
//    }
    
}

template<class T>
T List<T>::remove_node(shared_ptr<s_node<T>> &head) {
    
    shared_ptr<s_node<T>> temp = head->next;
    T element;
    
    // if list is empty, return element of head
    if(temp == nullptr) {
        
        return head->elem;
    }
    else {
        // if List only contains head and one element, have head-> point to nullptr
        if(temp->next == nullptr ) {
            
            element = temp->elem;
            temp.reset(); //deallocate first element from memory
            head->next = nullptr;
        }
        // if List contains two or more elements, have head point to the next element in list
        else {
            element = temp->elem;
            head->next = temp->next;
            temp->next = head;
        }
        list_size-=1;
        
//            shared_ptr<s_node<T>> foo = head;
//            cout << "this is list size: " << list_size << endl;
//            for(int i = 0; i <= list_size; i++) {
//        
//                cout <<foo->elem << endl;
//                foo = foo->next;
//            }

        return element;
    }
}

template <class T>
T List<T>::remove_last(shared_ptr<s_node<T>> &head) {
    
    shared_ptr<s_node<T>> traversal_node = head;
    T element;

    while(traversal_node->next!= nullptr) {
        
        traversal_node = traversal_node->next;
    }
    if(traversal_node->next == nullptr) {
        
        element = traversal_node->elem;
        traversal_node->prev = nullptr;
        traversal_node.reset();
        
    }
    
    list_size-=1;
//                shared_ptr<s_node<T>> foo = head;
//                cout << "this is list size: " << list_size << endl;
//                for(int i = 0; i <= list_size; i++) {
//    
//                    cout <<foo->elem << endl;
//                    foo = foo->next;
//                }
    return element;
}

    

template <class T>
T List<T>::remove_node_at(shared_ptr<s_node<T>> &head, int n) {
    
    T element;
    
    if(n > list_size) {
        remove_last(head);
    }
    else {
        int count = 0;
        shared_ptr<s_node<T>> traversal_node = head;
        
        while(count != n-1) {
            traversal_node = traversal_node->next;
            count+=1;
        }
        traversal_node->next = traversal_node->next->next;
        element = traversal_node->elem;
        list_size -=1;
    }
    
//                    shared_ptr<s_node<T>> foo = head;
//                    cout << "this is list size: " << list_size << endl;
//                    for(int i = 0; i <= list_size; i++) {
//    
//                        cout <<foo->elem << endl;
//                        foo = foo->next;
//                    }

    return element;
}

template<class T>
int List<T>::count_s_node(shared_ptr<s_node<T>> head) {
    
    return list_size;
}

template<class T>
void List<T>::empty_list(shared_ptr<s_node<T>> &head) {
    while(list_size!=0)
        remove_last(head);
    
    //                    shared_ptr<s_node<T>> foo = head;
    //                    cout << "this is list size: " << list_size << endl;
    //                    for(int i = 0; i <= list_size; i++) {
    //
    //                        cout <<foo->elem << endl;
    //                        foo = foo->next;
    //                    }

    
}

template <class T>
shared_ptr<s_node<T>> List<T>::node_at(shared_ptr<s_node<T>> head, int n) {
    
    shared_ptr<s_node<T>> traversal_node = head;
    
    if(n > list_size) {
        while(traversal_node->next != nullptr)
            traversal_node = traversal_node->next;
    }
    else {
        int count = 0;
        while(count != n) {
            traversal_node = traversal_node->next;
            count+=1;
        }
    }
    return traversal_node;
}


template <class T>
T List<T>::elem_at(shared_ptr<s_node<T>> head, int n) {
    
    auto elemPTR = node_at(head, n);
    return elemPTR->elem;
    
}


int main() {
    
    
    List<int> dl = List<int>();
    auto head = dl.new_node(4, nullptr, nullptr);
    auto firstNode = dl.new_node(10, nullptr, nullptr);
    auto secondNode = dl.new_node(35, nullptr, nullptr);
    auto thirdNode = dl.new_node(70, nullptr, nullptr);
    auto fourthNode = dl.new_node(105, nullptr, nullptr);
    auto fifthNode = dl.new_node(400, nullptr, nullptr);

    


    
    dl.add_node(firstNode, head);
    dl.append(secondNode, head);
    dl.append(thirdNode, head);
    dl.append(fourthNode, head);
    dl.append(fifthNode, head);
    
   auto x = dl.elem_at(head, 15);
    cout << x << endl;
    
}


