
typedef int KeyType;

struct Node {
    
    KeyType key;
    int priority, size;
    Node *left, *right;
    
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    
    void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
    void setRight(Node* newRight) { right = newRight; calcSize(); }
    
    void calcSize() { 
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;

//쪼개기 연산과 노드의 추가
NodePair split(Node* root, KeyType key) {
    if(root == NULL) return NodePair(NULL, NULL);
    
    //루트가 key미만이면 오른쪽 서브트리를 쪼갠다 
    if(root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    
    //루트가 key 이상이면 왼쪽 서브트리를 쪼갠다 
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
    if(root == NULL) return node;
    
    //node의 우선순위가 더 클경우 
    if(root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if(node->key < root-> key) {
        root->setLeft(insert(root->left, node));
    }
    else {
        root->setRight(insert(root->right, node));
    }
    return root;
}

//합치기 연산과 노드의 삭제
Node* merge(Node*a, Node*b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a -> priority < b -> priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}

Node* erase(Node* root, KeyType key) {
    if(root == NULL) return root;
    
    //root를 지우기 
    if(root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if(key < root->key)
        root->setLeft(erase(root->left, key));
    else 
        root->setRight(erase(root->right, key));
    return root;
}

//k번째 원소 찾기
Node* kth(Node* root, int k) {
    //왼쪽부터 쭉 찾기 
    int leftSize = 0;
    if(root->left != NULL) leftSize = root->left->size;
    if(k <= leftSize) return kth(root->left, k);
    if(k == leftSize + 1) return root;
    return kth(root->right, k - leftSize - 1);
}

//X보다 작은 원소의 수 찾기
int countLessThan(Node* root, KeyType key) {
    if(root == NULL) return 0;
    if(root -> key >= key) 
        return countLessThan(root->left, key);
    int ls = (root->left ? root->left->size : 0);
    return ls + 1 + countLessThan(root->right, key);
}
