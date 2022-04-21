#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void addfunction(Node* &node, int num);
void printfunction(Node* node, int depth);
void search(Node* node, int num);
void deletefunction(Node* &node, int num);

int main(){

  char input[100];
  int x;
  
  Node* head = NULL;

  bool running = true;
  
  cout << "Welcome to Binary Search Tree! This program reads in numbers, organizes them, and allows you to delete and print them!" << endl;

  while (running == true){

    cout << "What would you like to do? (ADD, SEARCH, PRINT, DELETE, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      cout << "Enter the number you would like to add:" << endl;

      cin >> x;

      addfunction(head, x);
      
    }
    if (strcmp(input, "SEARCH") == 0){

      cout << "What number are you searching for?" << endl;

      cin >> x;

      search(head, x);
      
      
    }
    if (strcmp(input, "PRINT") == 0){

      printfunction(head, 0);
      
    }
    if (strcmp(input, "DELETE") == 0){

      cout << "What number do you want to delete?" << endl;

      cin >> x;
      
      deletefunction(head, x);
      
    }
    if (strcmp(input, "QUIT") == 0){

      running = false;
      break;

    }

  }

  return 0;

}

void addfunction(Node* &node, int num){
  
  if (node == NULL){

    Node* temp = new Node();
    
    temp->data = num;

    node = temp;
    
  }
  
  if (node != NULL){

    if (node->data > num){

      addfunction(node->left, num);

    }

    if (node->data < num){

      addfunction(node->right, num);

    }

  }

  return;
  
}

void printfunction(Node* node, int depth){

  if (node == NULL){

    cout << "tree is empty!" << endl;
    return;
    
  }
  
  if (node->right != NULL){

    printfunction(node->right, depth + 1);
    
  }

  for (int i = 0; i < depth; i++){

    cout << "\t";
    
  }

  cout << node->data << endl;

  if (node->left != NULL){

    printfunction(node->left, depth + 1);

  }

}

void search(Node* node, int num){

  if (node == NULL){

    cout << "not in the tree!" << endl;

  }

  else if (node != NULL){

    if (node->data == num){

      cout << "in the tree!" << endl;

    }

    else {

      if (node->data > num) {

	search(node->left, num);

      }

      else if (node->data < num) {

	search(node->right, num);

      }

    }

  }
    
}

void deletefunction(Node* &node, int num){

  if (node == NULL){

    cout << "can't delete!" << endl;

  }
  
  if (node->data < num){

    deletefunction(node->right, num);

  }
  else if (node->data > num) {

    deletefunction(node->left, num);

  }
  else {
    // case 1: its a leaf
    if (node->right == NULL && node->left == NULL){

      node = NULL;

    }


  }

}
