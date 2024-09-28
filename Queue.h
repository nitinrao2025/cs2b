// Student ID: 20558765
#ifndef Queue_h
#define Queue_h
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

 // TODO: Fill in as necessary
template <typename T>
class Queue {
    private:
        std::vector<T> _data;
        size_t _head, _tail;
        static T _sentinel;
    public:
        static const int MAX_DISP_ELEMS = 100;
        Queue(size_t size);
        static void set_sentinel(const T& elem) { _sentinel = elem; }
        static T get_sentinel() { return _sentinel; }
        size_t size() const {
            return (_tail - _head + _data.size()) % _data.size();
        }
        bool is_empty() const{
            return _head == _tail;
        }
        void resize(size_t size){
            vector<T> newdata;
            newdata.resize(_data.size());
            for(size_t i = 0; i <= _data.size(); i++){
                newdata[i] = _data[(_head + i) % _data.size()];
            }
            _tail = this->size();
            _head = 0;
            _data = newdata;
            _data.resize(size + 1);
            
        }
        const T& peek() const{
            if (is_empty()) {
                return _sentinel;
            }
            return _data[_head];
        }
        bool dequeue(){
            if(_head == _tail){
                return false;
            }
            else{
                _head = (_head + 1) % _data.size();
                return true;
            }
        }
        bool enqueue(const T& elem){
            size_t nextTail = (_tail + 1) % _data.size();
            if (nextTail == _head) {
                return false; // Queue is full
            } 
            else {
                _data[_tail] = elem;
                _tail = nextTail;
                return true;
            }
        }
        std::string to_string(size_t limit = MAX_DISP_ELEMS) const{
            stringstream ss;
            ss << "# Queue - size = " << size() << endl;
            ss << "data :\n";

            // for(size_t i = 0; i <= _data.size(); i++){
           //     ss << _data[(_head + i) % _data.size()] << " ";
            // }

            return ss.str();
        }
        friend class Tests; // Don't remove this line
};
template <typename T> T Queue<T>::_sentinel = T();
template <typename T>
Queue<T>::Queue(size_t size) {
    if (size > 0) {
        _data.resize(size + 1);
        _head = 0;
        _tail = 0;
    } 
    else{
        _data.resize(1);
        _head = 0;
        _tail = 0;
    }
            
}
//TODO- Fill in the missing implementations. Experimentwith the aesthetics by moving
// some of these implementations inline (into your class def above). See which gives
// you more readable code
template <typename T>
void popalot(Queue<T>& q){
    q.resize(0);
}














#endif