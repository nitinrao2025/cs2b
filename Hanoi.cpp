// Student ID: 20558765
#include <iostream>
#include <sstream>
#include <string>
#include "Hanoi.h"
using namespace std;

string Hanoi::lookup_moves(int num_discs, int src, int dst) const {
    if((int)_cache.size() < (num_discs + 1))
        return "";
    if((int)_cache[num_discs].size() < (src + 1))
        return "";
    if ((int)_cache[num_discs][src].size() < (dst + 1))
        return "";
    
        
    return _cache[num_discs][src][dst];

}

string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
    string arr = std::to_string(src) + "->" + std::to_string(dst) + "\n";
    if (num_discs == 0)
        return "";
    if (num_discs >= 1){
        if(lookup_moves(num_discs,src,dst) != ""){
            return lookup_moves(num_discs,src,dst);
        }
        string moves = get_moves(num_discs - 1,src,tmp,dst) + arr + get_moves(num_discs - 1,tmp,dst,src);
        if((int)_cache.size() < (num_discs + 1)){
            _cache.resize(num_discs + 1);
        }
        if((int)_cache[num_discs].size() < (src + 1)){
            _cache[num_discs].resize(src + 1);
        }
        if((int)_cache[num_discs][src].size() < (dst + 1)){
            _cache[num_discs][src].resize(dst + 1);
        }

        _cache[num_discs][src][dst] = moves;
        _cache[num_discs - 1].clear();
        
        return moves;
    }

    return "";
}

string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
    string s = "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
    return s + get_moves(num_discs,src,dst,tmp);


}