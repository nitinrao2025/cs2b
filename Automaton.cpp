// Student ID: 20558765
#include <iostream>
#include <sstream>
#include <string>
#include "Automaton.h"
using namespace std;

size_t Automaton::translate_n_bits_starting_at(const vector<int>& bits, size_t pos, size_t n) {
    size_t result = 0;
    if((pos + n) <= bits.size() ){
        for (size_t i = pos; i < pos + n; i++) {
            result = (result*2) + bits[i];
        }

    }
    
    return result;
}

string Automaton::generation_to_string(const vector<int>& gen, size_t width){
    string result = "";
    if(_is_valid == true && width % 2 == 1){
        if(gen.size() > width){
            size_t start = (gen.size() - width) / 2;
            size_t end = (start + width);
            for(size_t i = start; i < end; i++){
                result += (gen[i] ? '*' : ' ');
            }
        }
        else {
            string eb = (_extreme_bit ? "*" : " " );
            size_t pad = (width - gen.size()) / 2;
            result += string(pad, eb[0]);
            for(int i : gen){
                result += (i ? "*" : " ");
            }
            result += string(pad, eb[0]);
        }
    }
    return result;
}

bool Automaton::set_rule(size_t rule){
    size_t max_rule = pow_2(pow_2(_num_parents)) - 1;
    if(_num_parents > MAX_PARENTS || rule > max_rule || _num_parents < 0 )
        return false;
    _rules.resize(pow_2(_num_parents));
    for(size_t i = 0; i < _rules.size(); i++ ){
        _rules[i] = (1 << i) & rule;
    }
    _is_valid = true;

    return true;
}

Automaton::Automaton(size_t num_parents, size_t rule){
    _num_parents = num_parents;
    if(!set_rule(rule)){
        _is_valid = false;
        return;
    }
    _extreme_bit = 0;
}

bool Automaton::equals(const Automaton& that){
    if(_is_valid == false && that._is_valid == false){
        return true;
    }
    if(_extreme_bit == that._extreme_bit && _rules == that._rules && _num_parents == that._num_parents && (_is_valid == true && that._is_valid == true)){
        return true;
    }
    return false;

}

bool Automaton::make_next_gen(const vector<int> &current_gen, vector<int> &next_gen){
    vector<int> temp;
    if(current_gen.size() % 2 == 0 && current_gen.size() != 0)
        return false;
    if(_is_valid == false)
        return false;
    if(current_gen.empty()){
        next_gen = {1};
        _extreme_bit = 0;
    }
    else {
        next_gen.resize(current_gen.size()+_num_parents-1);
        temp.resize(next_gen.size()+_num_parents - 1);
        size_t start = temp.size()- next_gen.size();
        size_t end = next_gen.size();
        size_t pad = _extreme_bit;
        for(size_t i = 0; i < start; i++){
            temp[i] = pad;
        }
        for(size_t i = 0; i < end; i++){
            temp[start + i] = current_gen[i];
        }
        for(size_t i = end; i < temp.size(); i++){
            temp[i] = pad;
        }
        
        for(size_t i = 0; i < next_gen.size(); i++){
            size_t ind = translate_n_bits_starting_at(temp, i, _num_parents);
            next_gen[i] = _rules[ind];
        }
        _extreme_bit = _extreme_bit ? _rules.back() : _rules.front();

    }
    return true;
}


string Automaton::get_first_n_generations(size_t n, size_t width){
    string result = "";
    if(width % 2 != 0 && _is_valid == true){
        vector<int> gen;
        while(n--){
            make_next_gen(gen,gen);
            result += generation_to_string(gen,width) + "\n";
        }
    }
    return result;
}


