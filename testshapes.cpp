#include "Shapes.cpp"

int main(){
    Screen S(40,40);
    Line L1(30,2,45,2);
    //Upright_Rectangle U(1,1,8,8);
    Stick_Man M(24,14,38,35);
    S.clear();
    M.draw(S,'F');
    cout << S.to_string() << endl;
}


bool Stick_Man::draw(Screen &scr, char ch){
    vector<bool> result = {true, true, true, true, true, true};
    for(size_t i = 0; i < _parts.size(); i++){
        result[i] = _parts[i]->draw(scr,ch);
    }
    return result[0] && result[1] && result[2] && result[3] && result[4] && result[5];
}