#include "doctest.h"
#include "BinaryTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE(" tree of strings"){
BinaryTree<string> tree_of_strings;
//BinaryTree<int> tree_of_ints;
tree_of_strings.add_root("root")
               .add_left("root","left")
               .add_right("root","right")
               .add_left("left","left_left")
               .add_right("left","left_right");
               //                       root
               //                      /     \
               //                    left     right
               //                   /    \
               //             left_left   left_right
               

string pre_arr[5]={"root","left","left_left","left_right","right"};
string in_arr[5]={"left_left","left","left_right","root","right"};
string post_arr[5]={"left_left","left_right","left","right","root"};
int i=0;
for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
    CHECK(*it==pre_arr[i]) ;
    i++;
  }  
i=0;
  for (auto it2=tree_of_strings.begin_inorder(); it2!=tree_of_strings.end_inorder(); ++it2) {
    CHECK(*it2==in_arr[i]) ;
    i++;
  }  
i=0;
  for (auto it3=tree_of_strings.begin_postorder(); it3!=tree_of_strings.end_postorder(); ++it3) {
    CHECK(*it3==pre_arr[i]) ;
    i++;
  }  




}

TEST_CASE(" tree of int"){
BinaryTree<int> tree_of_int;
//BinaryTree<int> tree_of_ints;
tree_of_int.add_root(1)
               .add_left(1,2)
               .add_right(1,3)
               .add_left(2,4)
               .add_right(2,5);
               //                        1
               //                      /   \
               //                     2     3
               //                   /   \
               //                  4      5

     CHECK_NOTHROW(tree_of_int.add_root(1));//there is allready a root
     CHECK_THROWS(tree_of_int.add_left(7,7)); // throw exeption because there is no 7 in the tree
     CHECK_THROWS(tree_of_int.add_right(11,8)); // throw exeption because there is no 11 in the tree 
     CHECK_THROWS(tree_of_int.add_left(6,9)); // throw exeption because there is no 6 in the tree
     CHECK_THROWS(tree_of_int.add_left(102,9));
     CHECK_THROWS(tree_of_int.add_right(100,9));

     CHECK_NOTHROW(tree_of_int.add_left(1,1));// legal because 1 exist
     CHECK_NOTHROW(tree_of_int.add_right(1,1));  //legal beacuse 1 exist 
     CHECK_NOTHROW(tree_of_int.add_root(1));  //legal beacuse 1 exist 

BinaryTree<string> tree_of_strings;
tree_of_strings.add_root("root")
               .add_left("root","left")
               .add_right("root","right")
               .add_left("left","left_left")
               .add_right("left","left_right");
               //                       root
               //                      /     \
               //                    left     right
               //                   /    \
               //             left_left   left_right
     CHECK_NOTHROW(tree_of_strings.add_root("root"));//there is allready a root
     CHECK_THROWS(tree_of_strings.add_left("not exist","check")); // throw exeption because there is no 7 in the tree
     CHECK_THROWS(tree_of_strings.add_right("also not exist","check")); // throw exeption because there is no 11 in the tree 
     CHECK_NOTHROW(tree_of_strings.add_left("left","new left")); // throw exeption because there is no 6 in the tree
     CHECK_NOTHROW(tree_of_strings.add_left("right","new right"));// legal because 1 exist
     CHECK_NOTHROW(tree_of_strings.add_right("new right","right right"));  //legal beacuse 1 exist
     CHECK_NOTHROW(tree_of_strings.add_root(" new root"));//there is allready a root 
     CHECK_THROWS(tree_of_strings.add_left("ashcjb","check"));// illegal
     CHECK_THROWS(tree_of_strings.add_left("fvgbhdc","check"));// illeagl


     BinaryTree<char> tree_of_char;
tree_of_char.add_root('a')
               .add_left('a','b')
               .add_right('a','c')
               .add_left('c','d')
               .add_right('d','e');
               //                         a
               //                      /     \
               //                     b       c
               //                             /
               //                            d
               //                             \
               //                              e
     CHECK_NOTHROW(tree_of_char.add_root('a'));//there is allready a root
     CHECK_THROWS(tree_of_char.add_left('q','w')); // throw exeption because there is no 7 in the tree
     CHECK_THROWS(tree_of_char.add_right('w','q')); // throw exeption because there is no 11 in the tree 
     CHECK_NOTHROW(tree_of_char.add_left('b','t')); // throw exeption because there is no 6 in the tree
     CHECK_NOTHROW(tree_of_char.add_left('c','f'));// legal because 1 exist
     CHECK_NOTHROW(tree_of_char.add_right('t','z'));  //legal beacuse 1 exist
     CHECK_NOTHROW(tree_of_char.add_root('x'));//there is allready a root 
     CHECK_THROWS(tree_of_char.add_left('u','k'));// illegal
     CHECK_THROWS(tree_of_char.add_left('j','r'));// illeagl


     
               
        



}