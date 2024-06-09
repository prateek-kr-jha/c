#include <iostream>

bool winner(int pile1, int pile2, int pile3) {
    if(pile1 == 0 && pile2 == 0 && pile3 == 0) {
        return false;
    }

    for(int i = 1; i <= pile1; i++) {
        if(!winner(pile1 - i, pile2, pile3)) {
            return true;
        }  
    }
    for(int i = 1; i <= pile2; i++) {
    if(!winner(pile1, pile2 - i, pile3)) {
        return true;
    }
        
    }
    for(int i = 1; i <= pile3; i++) {
        if(!winner(pile1, pile2, pile3 - i)) {
            return true;
        }

    }

    return false;
}

int main() {
    int pile1{}, pile2{},pile3{}; 
    std::cout << "enter stones in first pile: ";
    std::cin >> pile1;
    std::cout << "enter stones in second pile: ";
    std::cin >> pile2;
    std::cout << "enter stones in third pile: ";
    std::cin >> pile3;

    bool can_win = winner(pile1, pile2, pile3);


    std::cout << "can win: " << std::boolalpha << can_win << "\n";

}