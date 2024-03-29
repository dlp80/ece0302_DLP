#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs.root;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> rhs)
{
    swap(rhs);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& rhs)
{
    std::swap(root, rhs.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // TODO 
    Node<KeyType, ItemType>* newNode=new Node<KeyType, ItemType>();
    newNode->data=item;
    newNode->key=key;
    
    //if empty tree
    if(isEmpty()) 
    {
        root = newNode;
        return true;
    }
    else
    {
        if(retrieve(newNode->key, newNode->data))
        {
          return false;
        }
        else
        {
            Node<KeyType, ItemType>* curr;
            Node<KeyType, ItemType>* par;

            search(newNode->key, curr, par);
            if(newNode->key < curr->key)
            {
                curr->left=newNode;
            }
            if(newNode->key > curr->key)
            {
                curr->right = newNode;
            }
            return true;
        }  
        
    }
    delete newNode;
    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
//TODO
    if (isEmpty()) {
        return false; // empty tree
    }

    Node<KeyType, ItemType>* curr = nullptr;
    Node<KeyType, ItemType>* parent = nullptr;
    search(key, curr, parent);

    if (curr == nullptr) {
        return false; // key not found
    }

    // case 1: one thing in the tree
    if (curr == root && curr->left == nullptr && curr->right == nullptr) {
        delete curr;
        root = nullptr;
        return true;
    }

    // case 2: found deleted item at leaf
    if (curr->left == nullptr && curr->right == nullptr) {
        if (parent->left == curr) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete curr;
        return true;
    }

    // case 3: item to delete has only a right child
    if (curr->left == nullptr) {
        if (parent == nullptr) {
            root = curr->right;
        } else if (parent->left == curr) {
            parent->left = curr->right;
        } else {
            parent->right = curr->right;
        }
        delete curr;
        return true;
    }

    // case 4: item to delete has only a left child
    if (curr->right == nullptr) {
        if (parent == nullptr) {
            root = curr->left;
        } else if (parent->left == curr) {
            parent->left = curr->left;
        } else {
            parent->right = curr->left;
        }
        delete curr;
        return true;
    }

    // case 5: item to delete has two children
    Node<KeyType, ItemType>* inorderSuccessorParent = nullptr;
    Node<KeyType, ItemType>* inorderSuccessor = nullptr;
    inorder(curr, inorderSuccessor, inorderSuccessorParent);
    curr->key = inorderSuccessor->key;
    if (inorderSuccessorParent->left == inorderSuccessor) {
        inorderSuccessorParent->left = inorderSuccessor->right;
    } else {
        inorderSuccessorParent->right = inorderSuccessor->right;
    }
    delete inorderSuccessor;
    return true;

}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
   
    // TODO: find inorder successor of "curr" and assign to "in"
        if (curr == nullptr) {
        in = nullptr;
        parent = nullptr;
        return;
    }

    if (curr->right != nullptr) {
        // If curr has a right child, then inorder successor is leftmost node in right subtree
        in = curr->right;
        while (in->left != nullptr)
            in = in->left;
        parent = curr;
        return;
    }

    // If curr does not have a right child, then we need to backtrack to find inorder successor
    parent = nullptr;
    in = nullptr;
    Node<KeyType, ItemType>* temp = root;
    while (temp != curr) {
        if (curr->key < temp->key) {
            parent = temp;
            in = temp;
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }


}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int size) {
    // TODO: check for duplicate items in the input array

    // TODO: use the tree to sort the array items

    // TODO: overwrite input array values with sorted values
}
