// Student ID: 20558765
#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"
using namespace std;

Tree::Node* Tree::Node::insert_sibling(Node *p){
    Node *temp = this;
    while (temp->_sibling != nullptr){
        temp = temp->_sibling;
    }
    temp->_sibling = p;
    return p;
}

Tree::Node* Tree::Node::insert_child(Node *p){
    Node* temp = this;

        if (temp->_child == nullptr){
        temp->_child = p;
        }
        else{
        temp->_child->insert_sibling(p);
        }
        return p;    
}

const Tree::Node& Tree::Node::operator=(const Tree::Node& that){
    if(this != &that){
        this->_child = nullptr;
        this->_data = that._data;
        Node* child = that._child;
        Node* sibling = that._sibling;
        if(child != nullptr){
            Node* newchild = new Node(*child);
            this->insert_child(newchild);
        }
        if(sibling != nullptr){
            Node* newsibling = new Node(*sibling);
            this->insert_sibling(newsibling);
        }
    }
    return *this;
}

Tree::Node::Node(const Tree::Node& that){
    if (this != &that) {
        *this = that;
    }

}

bool Tree::Node::is_equal(const Node *p1, const Node *p2){
    if(p1 == nullptr && p2 == nullptr){
        return true;
    }
    if(p1 == nullptr || p2 == nullptr){
        return false;
    }
    if(p1->_data != p2->_data){
        return false;
    }
    return is_equal(p1->_sibling, p2->_sibling) && is_equal(p1->_child, p2->_child);
}

bool Tree::Node::operator==(const Node& that) const{
    return is_equal(this, &that);
}

bool Tree::Node::operator!=(const Node& that) const{
    return !(*this == that );
}

string Tree::Node::to_string() const{
    string result = this->_data + " :";
    Node* sibling = this->_sibling;
    Node* child = this->_child;
    while(child != nullptr){
        result += " " + child->_data ;
        child = child->_sibling;
    }
    
    result += "\n";
    child = this->_child;
    if(child != nullptr){
        result += "# Child of " + this->_data + "\n";
        result += child->to_string();
    }
    if(sibling != nullptr){
        result += "# Next sib of " + this->_data + "\n";
        result += sibling->to_string();
    }
    return result;

}

Tree::Node::~Node(){
    if(this->_sibling != nullptr){
        delete this->_sibling;
        this->_sibling = nullptr;
    }
    if(this->_child != nullptr){
        delete this->_child;
        this->_child = nullptr;
    }

}

Tree::Tree(){
    _root = new Node("ROOT");
}

Tree::~Tree(){
    delete _root;
    _root = nullptr;
}

Tree& Tree::operator=(const Tree& that){
    if(this != &that){
        this->_root = new Tree::Node(*that._root);
    }
    return *this;
}

bool Tree::operator==(const Tree& that) const {
    return Node::is_equal(this->_root, that._root);
}

bool Tree::operator!=(const Tree& that) const {
    return !Node::is_equal(this->_root, that._root);
}

string Tree::to_string() const{
    if(_root == nullptr){
        return "";
    }
    string result;
    string rootnode;
    if(_root->_data.empty()){
        rootnode = "ROOT";
    }
    else{
        rootnode = _root->_data;
    }
    result += "# Tree rooted at " + rootnode + "\n";
    result += "# The following lines are of the form:\n";
    result += "#   node: child1 child2...\n";
    result += _root->Node::to_string();
    result += "# End of Tree\n";

    return result;
}

void Tree::make_special_config_1(const std::vector<std::string>& names){
    delete(_root);

    // If the names vector is empty, return
    if (names.empty()) {
        return;
    }

    // Create the root node
    _root = new Node("ROOT");

    // Create nodes for ABBA, ABAB, AABA, BABA
    Node* ABBA = _root->insert_sibling(new Node("ABBA"));
    Node* ABAB = ABBA->insert_sibling(new Node("ABAB"));
    Node* AABA = ABAB->insert_sibling(new Node("AABA"));
    Node* BABA = AABA->insert_sibling(new Node("BABA"));

    // Add children for ABBA
    Node* COCO = ABBA->insert_child(new Node("COCO"));
    Node* COBO = COCO->insert_sibling(new Node("COBO"));

    // Add children for ABAB
    Node* COFO = ABAB->insert_child(new Node("COFO"));
    Node* CODO = COFO->insert_sibling(new Node("CODO"));

    // Add children for AABA
    Node* COHO = AABA->insert_child(new Node("COHO"));
    Node* COGO = COHO->insert_sibling(new Node("COGO"));

    // Add children for BABA
    Node* COKO = BABA->insert_child(new Node("COKO"));
    Node* COJO = COKO->insert_sibling(new Node("COJO"));

    // Add children for each CO* node
    COCO->insert_child(new Node("DIBI"));
    COBO->insert_child(new Node("DIDI"));
    COFO->insert_child(new Node("DIFI"));
    CODO->insert_child(new Node("DIGI"));
    COHO->insert_child(new Node("DIHI"));
    COGO->insert_child(new Node("DIJI"));
    COKO->insert_child(new Node("DIKI"));
    COJO->insert_child(new Node("DILI"));
}







