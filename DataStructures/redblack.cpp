#include<iostream>
#include<bits/stdc++.h>
#include"header.h"

node* uncle(node* neww){
    if(neww->parent == neww->parent->parent->right){
        return neww->parent->parent->left;
    }
    else{
        return neww->parent->parent->right;
    }
}

// node* delete_n(node* head,node* key){
//     if(key->colour){
        
//     }
// }

void evalute(node* head,node* neww){
    node* neww_uncle = uncle(neww);
    node* neww_grandp = neww_uncle->parent;
    if(neww_uncle->colour){
        neww_uncle->colour = false;
        neww->parent->colour = false;
        if(neww_grandp != head){
            neww_grandp->colour = true;
            evalute(head,neww_grandp);
        }
    }
    else{
        if(neww_grandp->right == neww->parent and neww == neww->parent->right){
            // RR
            l_rotate(head,neww_grandp);
            neww->parent->colour = !neww->parent->colour;
            neww->parent->left->colour = !neww->parent->left->colour;
        }
        else if(neww_grandp->right == neww->parent and neww == neww->parent->left){
            // RL
            r_rotate(head,neww->parent);
            l_rotate(head,neww_grandp);
            neww->colour = !neww->colour;
            ref_gra_p->colour = !ref_gra_p->colour;
        }
        else if(neww_grandp->left == neww->parent and neww == neww->parent->right){
            // LR
            l_rotate(head,neww->parent);
            r_rotate(head,neww_grandp);
            neww->colour = !neww->colour;
            ref_gra_p->colour = !ref_gra_p->colour;
        }
        else if(neww_grandp->left == neww->parent and neww == neww->parent->left){
            // LL
            r_rotate(head,neww_grandp);
            ref_p->colour = !ref_p->colour;
            ref_gra_p->colour = !ref_gra_p->colour;
        }
    }
}

void insert_n(node* head,int val){
    node* neww = new node(val);
    neww->colour = true;
    if(head == NULL){
        head = neww;
    }
    else{
        node* temp = head;
        bool c = true;
        while(temp!=NULL){
            if(temp->data == val){
                c = false;
                break;
            }
            else if(temp->data < val and temp->right){
                temp = temp->right;
            }
            else if(temp->data < val and temp->right == NULL){
                temp->right = neww;
                neww->parent = temp;
                break;
            }
            else if(temp->data > val and temp->left){
                temp = temp->left;
            }
            else if(temp->data > val and temp->left == NULL){
                temp->left = neww;
                neww->parent = temp;
                break;
            }
        }
        if(c){
            cout<<val<<" is inserted"<<endl;
            if(neww->parent->colour){
                evalute(head,neww);
            }
        }
    }
}

int main(){
    node* head = new node(10);
    head->colour = false;
    insert_n(head,18);
    insert_n(head,7);
    insert_n(head,19);
    insert_n(head,20);
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
    cout<<"colours : ";
    c_bfs(head);
    cout<<endl;
    return 0;
}