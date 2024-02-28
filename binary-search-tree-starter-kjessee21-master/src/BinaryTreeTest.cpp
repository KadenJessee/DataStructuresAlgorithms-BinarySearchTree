#include <iostream>
#include <string>
#include <memory>
#include "BinaryTree.h"

using namespace std;
bool checkTest(string testName, bool condition);
bool checkTest(string testName, int whatItShouldBe, int whatItIs);
void testFindMethod();
void testRightMostNodeSearch();
void deleteTest();
void testHeight();
void testLeavesCount();

BinaryTree<int> populateTree();

int main() {
   BinaryTree<int> myTree = populateTree();
   myTree.inOrder();
   cout << endl;
  testFindMethod();
  testRightMostNodeSearch();
  deleteTest();
  testHeight();
  testLeavesCount();
  cout << "Completed the Program" << endl;
  return 0;
}


BinaryTree <int> populateTree(){
  BinaryTree<int> myTree;
  int values[] = {37, 32, 73, 95, 42, 12, 0, 49, 98, 7, 27, 17, 47, 87, 77, 97, 67, 85, 15, 5, 35, 55, 65, 75, 25, 45, 3, 93, 83, 53, 63, 23, 13, 43, 33};
  int size = (sizeof(values)/sizeof(*values));

  for(int i = 0; i < size; i++){
      myTree.insert(values[i]);
  }

  return myTree;
}

void testFindMethod( ){
    BinaryTree<int> myTree = populateTree();
    auto ptr = myTree.find(49);
    checkTest("Test 1: Find(49)", 49, ptr->item);
    ptr = myTree.find(200);
    checkTest("Test 2: Find(200)", ptr == nullptr);
}

void testRightMostNodeSearch(){
  BinaryTree<int> myTree = populateTree();
  auto ptr = myTree.find(49);
  auto ptrchild = myTree.findRightMostNode(ptr);

  checkTest("Test 3: RightNodeTest(49)", 67, ptrchild->item);
}

void deleteTest(){
  BinaryTree<int> myTree = populateTree();
  myTree.remove(33);
  auto ptr = myTree.find(33);
  if(!checkTest("Test 4: Delete Leaf: 33", ptr == nullptr)){
    cout << "In Order: ";
    myTree.inOrder();
    cout << endl;
  }

  myTree.remove(67);
  ptr = myTree.find(67);
  if(!checkTest("Test 5: Delete Node with Left Child: 67", ptr == nullptr)){
    cout << "In Order: ";
    myTree.inOrder();
    cout << endl;
  }

 myTree.remove(42);
  ptr = myTree.find(42);
  if(!checkTest("Test 6: Delete Node with Right Child: 42", ptr == nullptr)){
    cout << "In Order: ";
    myTree.inOrder();
    cout << endl;
  }

   myTree.remove(73);
  ptr = myTree.find(73);
  if(!checkTest("Test 7: Delete Node with two children: 73", ptr == nullptr)){
    cout << "In Order: ";
    myTree.inOrder();
    cout << endl;
  }

   myTree.remove(37);
  ptr = myTree.find(37);
  if(!checkTest("Test 8: Delete root: 37", ptr == nullptr)){
    cout << "In Order: ";
    myTree.inOrder();
    cout << endl;
  }
}

void testHeight(){
  BinaryTree<int> myTree = populateTree();
   checkTest("Test 9: height()", 7 == myTree.height());
}

void testLeavesCount(){
    BinaryTree<int> myTree = populateTree();
    checkTest("Test 10: leavesCount()", 11 == myTree.leavesCount());
}

//Helps with Testing
bool checkTest(string testName, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "***Failed test " << testName << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
    return false;
  }
}
//Helps with Testing
 bool checkTest(string testName, bool condition) {

  if (condition) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "***Failed test " << testName << " *** " << endl;
    return false;
  }

}
