#ifndef _MYLIST_H_
#define _MYLIST_H_

#include <memory>
#include <iterator>

using namespace std;

template <class T>
struct s_node {
    T elem;
    shared_ptr<s_node<T>> next;
    shared_ptr<s_node<T>> prev;
};

template <class T>
class List {
    
public:
    
    List();
    // Copy Constructor
    List(const List<T> &other);
    
    // Move Constructor
    List(List &&other);
    
    
    /*
     Allocates and returns a new node with the given pointers. You may create nodes with nullptrs.
     */
    shared_ptr<s_node<T>> new_node(T elem, shared_ptr<s_node<T>> next, shared_ptr<s_node<T>> previous);
    
    /*
     Inserts a node at the start of the list. DO NOT add a nullptr pointer.
     Do not iterate the list.
     */
    void add_node(shared_ptr<s_node<T>> node, shared_ptr<s_node<T>> &head);
    
    /*
     Creates a new node with elem and adds it to head.
     Do not iterate the list.
     */
    void add_elem(T elem, shared_ptr<s_node<T>> &head);
    
    /*
     Adds a node to the end of a list. DO NOT add a nullptr pointer.
     Iterate at most one time.
     */
    void append(shared_ptr<s_node<T>> node, shared_ptr<s_node<T>> &head);
    
    /*
     Adds a node at index n of a list or at the end of the list if n is too large.
     Iterate at most one time.
     */
    void add_node_at(shared_ptr<s_node<T>> node, shared_ptr<s_node<T>> &head, int n);
    
    /*
     Removes the first node from the list. Returns elem and frees the node from memory.
     Do not iterate the list.
     */
    T remove_node(shared_ptr<s_node<T>> &head);
    
    /*
     Removes the last node from the list.
     Iterate at most one time.
     */
    T remove_last(shared_ptr<s_node<T>> &head);
    
    /*
     Removes the node at index n or the last node.
     Iterate at most one time.
     */
    T remove_node_at(shared_ptr<s_node<T>> &head, int n);
    
    /*
     Returns the value the length of the list.
     Iterate at most one time.
     */
    int count_s_node(shared_ptr<s_node<T>> head);
    
    /*
     Frees all the nodes in the list.
     CHALLENGE: Write in two lines for +5 extra credit (allowed to use other methods written in this assignment)
     */
    void empty_list(shared_ptr<s_node<T>> &head);
    
    /*
     Returns a pointer to the node at index n or the last node.
     Iterate at most one time.
     */
    shared_ptr<s_node<T>> node_at(shared_ptr<s_node<T>> head, int n);
    
    /*
     Returns the elem at index n or the last node.
     Iterate at most one time.
     */
    T elem_at(shared_ptr<s_node<T>> head, int n);
    
    int list_size;
    
 };
#endif