// Student ID: 20558765
#include <iostream>
#include <sstream>
#include <string>
#include "Playlist.h"
using namespace std;

// Song Entry Functions

bool Playlist::Song_Entry::set_id(int id){
    if(id >= 0 ){
        _id = id;
        return true;
    }
       return false;   
}
bool Playlist::Song_Entry::set_name(string name){
    if(name != ""){
        _name = name;
        return true;
    }
        return false;
}

// Node Functions
Playlist::Node* Playlist::Node::insert_next(Node *p) {
    p->_next = this->_next;
    this->_next = p;
    return p;
}

Playlist::Node* Playlist::Node::remove_next(){
    Node* removenode = this->_next;
    this->_next = this->_next->_next;
    delete removenode;
    return this;
}

// Playlist Constructor

Playlist::Playlist(){
    Song_Entry s1 (-1, "HEAD"); 
    _head = new Node(s1);
    _tail = _head;
    _prev_to_current = _head;
    _size = 0;
}

// Playlist Destructor 

Playlist::Node::~Node() {
    this->_next = nullptr;
}
Playlist::~Playlist() {
    Node* currnode = _head;
    while (currnode != nullptr){
        Node* temp = currnode;
        currnode = currnode->get_next();
        delete temp;
    }
    _tail = nullptr;
    _prev_to_current = nullptr;
}

// Insert Song at Current Location

//Playlist *Playlist::insert_at_cursor(const Song_Entry& s){
    // Node::insert_next(new Node(s));

//}


Playlist::Song_Entry& Playlist::find_by_id(int id) const {
    Node* current = _head->get_next();
    while (current != nullptr){
        if(current->get_song().get_id() == id){
            return current->get_song();
        }
            current = current->get_next();    
    }
    return _head->get_song();
}

Playlist::Song_Entry& Playlist::find_by_name(string id) const{
    Node* current = _head->get_next();
    while (current != nullptr){
        if(current->get_song().get_name() == id){
            return current->get_song();
        }
            current = current->get_next();
    }
    return _head->get_song();
}

Playlist* Playlist::clear(){
    Node* current = _head;
    while(current->get_next() != nullptr){
        current->remove_next();
    }
    _prev_to_current = _head;
    _tail = _head;
    _size = 0;
    return this;

}

Playlist* Playlist::rewind() {
    _prev_to_current = _head;
    return this;
}


Playlist* Playlist::insert_at_cursor(const Song_Entry& s){
    Node* newnode = new Node(s);
    _prev_to_current->insert_next(newnode);
    if(_prev_to_current == _tail)
        _tail = newnode;
    _size++;
    return this;
}

Playlist* Playlist::push_back(const Song_Entry& s){
    Node* savedvalue = _prev_to_current;
    _prev_to_current = _tail;
    insert_at_cursor(s);
    _prev_to_current = savedvalue;
    return this;
}

Playlist* Playlist::push_front(const Song_Entry& s){
    Node* savedvalue = _prev_to_current;
    _prev_to_current = _head;
    insert_at_cursor(s);
    _prev_to_current = savedvalue;
    return this;
}

Playlist* Playlist::advance_cursor(){
    if(_prev_to_current == _tail){
        return nullptr;
    }
    _prev_to_current = _prev_to_current->get_next();
    return this;
}

Playlist::Song_Entry &Playlist::get_current_song() const{
    if(_prev_to_current->get_next() != nullptr)
        return _prev_to_current->get_next()->get_song();
    else
        return _head->get_song();
}

Playlist* Playlist::remove_at_cursor(){
     if (_prev_to_current->get_next() == _tail)
        _tail = _prev_to_current;
    _prev_to_current->remove_next();
    _size--;
    return this;
}

Playlist* Playlist::circular_advance_cursor(){
    if(_prev_to_current->get_next() == _tail)
        _prev_to_current = _head;
    else
        _prev_to_current = _prev_to_current->get_next();
    
    return this;
}

string Playlist::to_string() const{
    stringstream ss;
    const size_t maxentries = 25;
    size_t entries = 0;
    ss << _size;
    string s = "";
    Node* current = _head->get_next();
    s = "Playlist: " + ss.str() + " entries.\n";
    while (current != nullptr && entries < maxentries){
        s = s + "{ id: ";
        ss.str("");
        ss << current->get_song().get_id();
        s = s + ss.str() + ", name: ";
        ss.str("");
        ss << current->get_song().get_name();
        s = s + ss.str() + " }";
        if(current == _prev_to_current)
           s = s + " [P]\n";
        else if(current == _tail)
            s = s + " [T]\n";
        else
            s = s + "\n";
        current = current->get_next();
        entries++;

    }

    if(_size > maxentries)
        s = s + "...\n";
    
    return s;
}