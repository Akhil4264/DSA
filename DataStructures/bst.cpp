#include<iostream>
#include<bits/stdc++.h>
#include"header.h"

//operations on a btree

void insert(node* head,int val){
    node* temp = head;
    while(temp!=NULL){
        if(val == temp->data){
            break;
        }
        else if(val > temp->data and temp->right){
            temp = temp->right;
        }
        else if(val > temp->data and temp->right == NULL){
            temp->right = new node(val);
            break;
        }
        else if(val < temp->data and temp->left){
            temp = temp->left;
        }
        else if(val < temp->data and temp->left == NULL){
            temp->left = new node(val);
            break;
        }
    }
}

node* delete_n(node* head,int key){
    if(key != head->data and head->left == NULL and head->right == NULL){
        cout<<key<<" is not present in the tree"<<endl;
    }
    else if(key == head->data){
        if(head->left == NULL and head->right == NULL){
            head = NULL;
        }
        else if(head->right){
            node* succ = inordersucc(head);
            swap_n(head,succ);
            head->right = delete_n(head->right,key);
        }
        else if(head->left){
            node* pred = inorderpred(head);
            swap_n(head,pred);
            head->left = delete_n(head->left,key);
        }
    }
    else if(key > head->data){
        head->right = delete_n(head->right,key);
    }
    else if(key < head->data){
        head->left = delete_n(head->left,key);
    }
    return head;
}

void c_insert(node* head,int val){
    node* temp = head;
    while(temp!=NULL){
        if(val == temp->data){
            break;
        }
        else if(val > temp->data and temp->right){
            temp = temp->right;
        }
        else if(val > temp->data and temp->right == NULL){
            temp->right = new node(val);
            temp->right->parent = temp;
            break;
        }
        else if(val < temp->data and temp->left){
            temp = temp->left;
        }
        else if(val < temp->data and temp->left == NULL){
            temp->left = new node(val);
            temp->left->parent = temp;
            break;
        }
    }
}

int main(){
    node* head;
    head = new node(8);
    c_insert(head,4);
    c_insert(head,12);
    c_insert(head,2);
    c_insert(head,6);
    c_insert(head,10);
    c_insert(head,14);
    c_insert(head,1);
    c_insert(head,3);
    c_insert(head,5);
    c_insert(head,7);
    c_insert(head,9);
    c_insert(head,11);
    c_insert(head,13);
    c_insert(head,15);
    head = delete_n(head,12);
    cout<<"inorder : ";
    inorder(head);
    cout<<endl;
    cout<<"preorder : ";
    preorder(head);
    cout<<endl;
    cout<<"postorder : ";
    postorder(head);
    cout<<endl;
    cout<<"dfs: ";
    dfs(head);
    cout<<"bfs: ";
    bfs(head);
    cout<<endl;
    


      
    return 0;
}
