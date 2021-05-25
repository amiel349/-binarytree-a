#include <stdio.h>
#pragma once





namespace ariel{

template<typename T>
class BinaryTree
{

class Node{ 


public:
Node* left;
Node * right;
Node * parent;
T value;
Node(T value ):left(nullptr),right(nullptr),parent(nullptr){};

};

private:

Node * root;
    /* data */
public:
    BinaryTree():root(nullptr){};
    

     BinaryTree<T> &add_root(T val){ return *this;};
      BinaryTree<T> &add_left(T exists,T val ){return *this;};
       BinaryTree<T> &add_right(T exists, T data){return *this;};

class in_order_iter {

	  private:
		Node* ptr_to_node;

	public:

		in_order_iter(Node* ptr = nullptr)
			: ptr_to_node(ptr) {
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		T& operator*() const {
			//return *pointer_to_current_node;
			return ptr_to_node->value;
		}

		T* operator->() const {
			return &(ptr_to_node->value);
		}

		// ++i;
		in_order_iter& operator++() {
			//++pointer_to_current_node;
			ptr_to_node = ptr_to_node->left;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const in_order_iter operator++(int) {
			in_order_iter tmp= *this;
			ptr_to_node= ptr_to_node->left;
			return tmp;
		}

		bool operator==(const in_order_iter& rhs) const {
			return ptr_to_node == rhs.ptr_to_node;
		}

		bool operator!=(const in_order_iter& node) const {
			return ptr_to_node != node.ptr_to_node;
		}
	};  // END OF CLASS


    class pre_order_iter {

	  private:
		Node* ptr_to_node;

	public:

		pre_order_iter(Node* ptr = nullptr)
			: ptr_to_node(ptr) {
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		T& operator*() const {
			//return *pointer_to_current_node;
			return ptr_to_node->value;
		}

		T* operator->() const {
			return &(ptr_to_node->value);
		}

		// ++i;
		pre_order_iter& operator++() {
			//++pointer_to_current_node;
			ptr_to_node = ptr_to_node->left;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const pre_order_iter operator++(int) {
			pre_order_iter tmp= *this;
			ptr_to_node= ptr_to_node->left;
			return tmp;
		}

		bool operator==(const pre_order_iter& rhs) const {
			return ptr_to_node == rhs.ptr_to_node;
		}

		bool operator!=(const pre_order_iter& node) const {
			return ptr_to_node != node.ptr_to_node;
		}
	};  // END OF CLASS

    class post_order_iter {

	  private:
		Node* ptr_to_node;

	public:

		post_order_iter(Node* ptr = nullptr)
			: ptr_to_node(ptr) {
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		T& operator*() const {
			//return *pointer_to_current_node;
			return ptr_to_node->value;
		}

		T* operator->() const {
			return &(ptr_to_node->value);
		}

		// ++i;
		post_order_iter& operator++() {
			//++pointer_to_current_node;
			ptr_to_node = ptr_to_node->left;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const post_order_iter operator++(int) {
			post_order_iter tmp= *this;
			ptr_to_node= ptr_to_node->left;
			return tmp;
		}

		bool operator==(const post_order_iter& rhs) const {
			return ptr_to_node == rhs.ptr_to_node;
		}

		bool operator!=(const post_order_iter& node) const {
			return ptr_to_node != node.ptr_to_node;
		}
	};  // END OF CLASS


	pre_order_iter begin_preorder() {
		// return &(m_first->m_value); 
		return pre_order_iter{root};
	}
	
	pre_order_iter end_preorder() {
		// return nullptr; 
		return pre_order_iter{nullptr};
	}

    in_order_iter begin_inorder() {
		// return &(m_first->m_value); 
		return in_order_iter{root};
	}
	
	in_order_iter end_inorder() {
		// return nullptr; 
		return in_order_iter{nullptr};
	}

    post_order_iter begin_postorder() {
		// return &(m_first->m_value); 
		return post_order_iter{root};
	}
	
	post_order_iter end_postorder() {
		// return nullptr; 
		return post_order_iter{nullptr};
	}


    
    in_order_iter begin() {
		// return &(m_first->m_value); 
		return in_order_iter{root};
	}
	
	in_order_iter end() {
		// return nullptr; 
		return in_order_iter{nullptr};
	}

    

	 friend std::ostream& operator<< (std::ostream& os, const BinaryTree& n){return os;};

};



}