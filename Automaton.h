#ifndef Automaton_h
#define Automaton_h
#include <vector>
#include <sstream>
using namespace std;

class Automaton {
    private:
    static const size_t MAX_PARENTS = 5;

    bool _is_valid;
    size_t _num_parents; // 2^(_num_parents) = possible parent combination

    vector<bool> _rules; // size() = 2 ^ (_num_parents) rules. One for each parent combination
    int _extreme_bit;

    public:
    Automaton(size_t _num_parents, size_t rule);
    bool set_rule(size_t rule);
    bool equals(const Automaton& that);

    bool make_next_gen(const vector<int>& current_gen, vector<int>& next_gen);
    string get_first_n_generations(size_t n = 100, size_t width = 101);

    // instance utility
    string generation_to_string(const vector<int>& gen, size_t width);

    // static utility
    static inline size_t pow_2(size_t n) {return 1 << n;}
    static size_t translate_n_bits_starting_at(const vector<int>& bits, size_t pos, size_t n);
    friend class Tests; // Do not remove this line

};

# endif