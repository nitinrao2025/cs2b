// Student ID: 20558765
#include <iostream>
#include <sstream>
#include <string>
#include "Automaton.cpp"

int main(){
    vector<int> bits = {0,0,1,0,0};
    Automaton a(3,1);
    vector<int> cgen = {1};
    vector<int> ngen;
    size_t pos = 2;
    size_t n = 5;
    size_t result = a.translate_n_bits_starting_at(bits,0,3);
    a.make_next_gen(cgen, ngen);
    for(size_t i = 0; i < ngen.size(); i++){
        cout << ngen[i] << " " ;
    }
    cout << a.get_first_n_generations(2,9);
    

    //cout << "Decimal: " << result << endl;


}