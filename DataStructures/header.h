#pragma once
using namespace std;
class node{
public:
    int data;
    bool colour;       // 1 for red , 0  for black
    node* left;
    node* right;
    node* parent;
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

};

// swapping the nodes of a btree

void swap_n(node* first,node* second){
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

// traversing the tree

void inorder(node* head){
    if(head == NULL){
        return ;
    }
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}

void preorder(node* head){
    if(head ==  NULL){
        return ;
    }
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}

void postorder(node* head){
    if(head ==  NULL){
        return ;
    }
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}

void dfs(node* head){
    vector<node*>v{head};
    while(v.size()!=0){
        node* temp = v[v.size()-1];
        cout<<temp->data<<" ";
        v.pop_back();
        if(temp->right){
            v.push_back(temp->right);
        }
        if(temp->left){
            v.push_back(temp->left);
        }
    }
    cout<<endl;
}

void bfs(node* head){
    queue<node*>q;
    q.push(head);
    while(q.size()!=0){
        node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}

void c_bfs(node* head){
    queue<node*>q;
    q.push(head);
    while(q.size()!=0){
        node* temp = q.front();
        q.pop();
        cout<<temp->colour<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}

// Tree operations

int size(node* head){
    if(head == NULL){
        return 0;
    }
    return 1+size(head->left)+size(head->right);
}

int depth(node* head){
    if(head == NULL){
        return 0;
    }
    return 1+max(depth(head->left),depth(head->right));
}

node* inordersucc(node* head){
        node* temp = head->right;
        while(temp->left){
            temp = temp->left;
        }
        return temp;
}

node* inorderpred(node* head){
    node* temp = head->left;
    while(temp->right){
        temp = temp->right;
    }
    return temp;

}

node* search(node* head,int key){
    node* temp = head;
    while(temp){
        if(key == temp->data){
            return temp;
        }
        else if(key > temp->data and temp->right){
            temp = temp->right;
        }
        else if(key > temp->data and temp->right == NULL){
            return NULL;
        }
        else if(key < temp->data and temp->left){
            temp = temp->left;
        }
        else if(key < temp->data and temp->left == NULL){
            return NULL;
        }
    }
}

// Rotation

void r_rotate(node* head,node* x){
    node* y = x->left;
    x->left = y->right;
    x->left->parent = x;
    y->parent = x->parent;
    if(x == head){
        head = y;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
    }
    else if(x == x->parent->right){
        x->parent->right = y;
    }
    x->parent = y;
    y->right = x;
    
}

void l_rotate(node* head,node*x){

    node* y = x->right;
    x->right = y->left;
    x->right->parent = x;
    y->parent = x->parent;
    if(x == head){
        head = y;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
    }
    else if(x == x->parent->right){
        x->parent->right = y;
    }
    x->parent = y;
    y->left = x;

}

// Graphs

