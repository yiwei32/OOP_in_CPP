#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <limits>
using std::cout;
using std::endl;
using std::cin;

class Card{
        friend class CardFlipGame;
    private:
        char name;
        bool isFlipped;
    public:
        Card():name('?'), isFlipped(false){};
        Card(char name, bool isFlipped=false):name(name), isFlipped(isFlipped){};
        void flip(){isFlipped = !isFlipped;};
        void show(){cout<<name;};
};

class CardFlipGame{
private:
    int height;
    int width;
    Card **cards;
    int remaining;
public:
    CardFlipGame(); // default
    CardFlipGame(int h = 5, int w = 6);
    ~CardFlipGame();
    void display();
    void query();
    void start();
};


CardFlipGame::CardFlipGame(int h, int w){
    this->height = h;
    this->width = w;
    this->remaining = h * w;
    cards = new Card*[h];
    for (int i = 0; i < h; ++i) cards[i] = new Card[w];
    //TODO: given h*w//2 pairs of cards, randomize cards arrangements
    srand((int)time(NULL));
    std::vector<char> alphabets;
    for (int i = 0; i < 15; ++i){
        char c = 'A' + i;
        alphabets.push_back(c);
        alphabets.push_back(c);
    }
    std::random_shuffle(alphabets.begin(), alphabets.end());
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            cards[i][j] = alphabets.back();
            alphabets.pop_back();
        }
    }
};

CardFlipGame::~CardFlipGame(){
    for (int i = 0; i < height;++i){
        delete [] cards[i];
    }
    delete [] cards;
};

void CardFlipGame::display(){
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            if (cards[i][j].isFlipped) cards[i][j].show();
            else cout << "*";
            cout << " ";
        }
        cout << endl;
    }
};

void CardFlipGame::query(){
    
    Card* targets[2];
    this->display();
    for (int i = 0; i < 2; ++i){
        while(true){
            cout << "Please enter card index: ";
            char c[5];
            cin.getline(c, 5);
            cin.clear();
            if (strcmp(c, "exit") == 0){
                cout << "BYE" << endl;
                exit(1);
            }
            int idx = atoi(c);
            if (idx < 0 || idx >= height * width){
                cout << "Input range:[" << 0 << "," << height*width-1 << "]" << endl;
                continue;
            }
            targets[i] = &cards[idx/width][idx%width];
            if (targets[i]->isFlipped == true){
                cout << "Already flipped, try another one!" << endl;
                continue;
            }
            targets[i]->flip();
            this->display();
            break;
        }
    }
    if (targets[0]->name != targets[1]->name){
        cout << "Try again" << endl;
        targets[0]->flip();
        targets[1]->flip();
    } 
    else{
        this->remaining -= 2;
        if (remaining != 0) cout << "Good job!" << endl; 
    } 
};
void CardFlipGame::start(){
    while (remaining != 0){
        query();
    }
    cout << "Congratulation!!" << endl;
};


int main(){
    char ans = 'y';
    while (ans == 'y'){
        CardFlipGame game(5, 6);
        game.start();
        do{
            cout << "Still want to play? (y/n):";
            cin >> ans;
        } while(ans!='y' && ans != 'n');
    }
    return 0;
}





