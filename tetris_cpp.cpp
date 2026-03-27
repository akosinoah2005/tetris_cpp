#include "includes.h"

int main() {

    char Design[22][22] = {
                            { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    };
    int block = 5;
    short pos = 7;
    short pos2 = 1;

    char key = ' ';
    int value = 0;


    loadBlock(Design, block, pos, pos2);

    void(*loadptr)(char(&)[22][22], int(&), short(&), short(&), int(&), char(&));
    loadptr = loadtetris;

    void(*fallptr)(char(&)[22][22], int(&), short(&), short(&));
    fallptr = fallBlock;

    void(*sidewayptr)(char(&)[22][22], int(&), short(&), short(&), int(&), char(&));
    sidewayptr = sideways;

    std::thread load(loadptr, std::ref(Design), std::ref(block), std::ref(pos), std::ref(pos2), std::ref(value), std::ref(key));
    std::thread move(sidewayptr, std::ref(Design), std::ref(block), std::ref(pos), std::ref(pos2), std::ref(value), std::ref(key));
    std::thread fall(fallptr, std::ref(Design), std::ref(block), std::ref(pos), std::ref(pos2));


    fall.join();
    move.join();
    load.join();

    system("cls");
    std::cout << "Game Over";
	system("pause");
    return 0;
}

bool checkUnder(char(&Design)[22][22], int(&block), short(&pos), short(&pos2)) {

    if (block == 1 && Design[pos2 + 2][pos] == ' ' && Design[pos2 + 2][pos + 1] == ' ' && Design[pos2 + 2][pos + 2] == ' ' && Design[pos2 + 2][pos + 3] == ' ') {
        return true;
    }
    else if (block == 2 && Design[pos2 + 1][pos + 4] == ' ' && Design[pos2 + 1][pos + 5] == ' ' && Design[pos2 + 1][pos] == ' ' && Design[pos2 + 1][pos + 1] == ' ' && Design[pos2 + 2][pos + 2] == 32 && Design[pos2 + 2][pos + 3] == 32 && Design[pos2 + 1][pos] == 32 && Design[pos2 + 1][pos + 1] == 32 && Design[pos2 + 1][pos + 4] == 32 && Design[pos2 + 1][pos + 5] == 32) {
        return true;
    }
    else if (block == 3 && Design[pos2 + 4][pos] == 32 && Design[pos2 + 4][pos + 1] == 32) {
        return true;
    }
    else if (block == 4 && Design[pos2 + 1][pos] == 32 && Design[pos2 + 1][pos + 1] == 32 && Design[pos2 + 2][pos + 2] == 32 && Design[pos2 + 2][pos + 3] == 32 && Design[pos2 + 2][pos + 4] == 32 && Design[pos2 + 2][pos + 5] == 32) {
        return true;
    }
    else if (block == 5 && Design[pos2 + 4][pos] == 32 && Design[pos2 + 4][pos + 1] == 32 && Design[pos2 + 4][pos + 2] == 32 && Design[pos2 + 4][pos + 3] == 32) {
        return true;
    }
    return false;
}

bool Game_Over(char(&Design)[22][22], int(&block), short(&pos), short(&pos2)) {

    return true;
}

//load empty block or remove block
void loadEmptyBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2)) {

    if (block == 1) {
        //square
        Design[pos2][pos] = ' '; Design[pos2][pos + 1] = ' '; Design[pos2][pos + 2] = ' '; Design[pos2][pos + 3] = ' ';
        Design[pos2 + 1][pos] = ' '; Design[pos2 + 1][pos + 1] = ' '; Design[pos2 + 1][pos + 2] = ' '; Design[pos2 + 1][pos + 3] = ' ';
    }
    if (block == 2) {
        //Tblock
        Design[pos2][pos] = ' '; Design[pos2][pos + 1] = ' '; Design[pos2][pos + 2] = ' '; Design[pos2][pos + 3] = ' '; Design[pos2][pos + 4] = ' '; Design[pos2][pos + 5] = ' ';
        Design[pos2 + 1][pos + 2] = ' '; Design[pos2 + 1][pos + 3] = ' ';
    }
    if (block == 3) {
        //rod
        Design[pos2][pos] = ' '; Design[pos2][pos + 1] = ' ';
        Design[pos2 + 1][pos] = ' '; Design[pos2 + 1][pos + 1] = ' ';
        Design[pos2 + 2][pos] = ' '; Design[pos2 + 2][pos + 1] = ' ';
        Design[pos2 + 3][pos] = ' '; Design[pos2 + 3][pos + 1] = ' ';
    }
    if (block == 4) {
        //zigzag
        Design[pos2][pos] = ' '; Design[pos2][pos + 1] = ' '; Design[pos2][pos + 2] = ' '; Design[pos2][pos + 3] = ' ';
        Design[pos2 + 1][pos + 2] = ' '; Design[pos2 + 1][pos + 3] = ' '; Design[pos2 + 1][pos + 4] = ' '; Design[pos2 + 1][pos + 5] = ' ';
    }
    if (block == 5) {
        //L
        Design[pos2][pos] = ' '; Design[pos2][pos + 1] = ' ';
        Design[pos2 + 1][pos] = ' '; Design[pos2 + 1][pos + 1] = ' ';
        Design[pos2 + 2][pos] = ' '; Design[pos2 + 2][pos + 1] = ' ';
        Design[pos2 + 3][pos] = ' '; Design[pos2 + 3][pos + 1] = ' '; Design[pos2 + 3][pos + 2] = ' '; Design[pos2 + 3][pos + 3] = ' ';
    }
}
//get random num
int getrandom() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 4);
    int randomnum = dist(rd);

    return randomnum;
}
//load the page
void loadtetris(char(&Design)[22][22], int(&block), short(&pos), short(&pos2), int(&value), char(&key)) {//load the game
    COORD position = { 0, 0 };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    std::string gamerz = "";
    while (key != ESC && stop == 0) {
        
        SetConsoleCursorPosition(output, position);

        gamerz = "";
        for (int i = 0; i <= 21; i++)
        {
            for (int j = 0; j <= 21; j++) {
                gamerz += Design[i][j];
            }
            gamerz += '\n';
        }
        std::cout << gamerz << '\n' << "Score: WLA PA\n";
        std::cout << "poss1 : " << pos << '\n' << "pos2 : " << pos2<<' ';
        
        } 
    SetConsoleCursorPosition(output, position);

    gamerz = "";
    for (int i = 0; i <= 21; i++)
    {
        for (int j = 0; j <= 21; j++) {
            gamerz += Design[i][j];
        }
        gamerz += '\n';
    }

    std::cout << gamerz << '\n' << "Score: WLA PA\n";
    std::cout << "poss1 : " << pos << '\n' << "pos2 : " << pos2 << ' ';


    
}

//get and load the block
void loadBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2)) {
    if (block == 1) {
        //square
        Design[pos2][pos] = '['; Design[pos2][pos + 1] = ']'; Design[pos2][pos + 2] = '['; Design[pos2][pos + 3] = ']';
        Design[pos2 + 1][pos] = '['; Design[pos2 + 1][pos + 1] = ']'; Design[pos2 + 1][pos + 2] = '['; Design[pos2 + 1][pos + 3] = ']';
    }
    if (block == 2) {
        //Tblock
        Design[pos2][pos] = '['; Design[pos2][pos + 1] = ']'; Design[pos2][pos + 2] = '['; Design[pos2][pos + 3] = ']'; Design[pos2][pos + 4] = '['; Design[pos2][pos + 5] = ']';
        Design[pos2 + 1][pos + 2] = '['; Design[pos2 + 1][pos + 3] = ']';
    }
    if (block == 3) {
        //rod
        Design[pos2][pos] = '['; Design[pos2][pos + 1] = ']';
        Design[pos2 + 1][pos] = '['; Design[pos2 + 1][pos + 1] = ']';
        Design[pos2 + 2][pos] = '['; Design[pos2 + 2][pos + 1] = ']';
        Design[pos2 + 3][pos] = '['; Design[pos2 + 3][pos + 1] = ']';
    }
    if (block == 4) {
        //zigzag
        Design[pos2][pos] = '['; Design[pos2][pos + 1] = ']'; Design[pos2][pos + 2] = '['; Design[pos2][pos + 3] = ']';
        Design[pos2 + 1][pos + 2] = '['; Design[pos2 + 1][pos + 3] = ']'; Design[pos2 + 1][pos + 4] = '['; Design[pos2 + 1][pos + 5] = ']';
    }
    if (block == 5) {
        //L
        Design[pos2][pos] = '['; Design[pos2][pos + 1] = ']';
        Design[pos2 + 1][pos] = '['; Design[pos2 + 1][pos + 1] = ']';
        Design[pos2 + 2][pos] = '['; Design[pos2 + 2][pos + 1] = ']';
        Design[pos2 + 3][pos] = '['; Design[pos2 + 3][pos + 1] = ']'; Design[pos2 + 3][pos + 2] = '['; Design[pos2 + 3][pos + 3] = ']';
    }
}

//movement
void moveBlockright(char(&Design)[22][22], int(&block), short(&pos), short(&pos2)) {
    bool move = false;
    switch (block) {
    case 1:
        if (Design[pos2][pos + 4] != ' ' || Design[pos2 + 1][pos + 4] != ' ') {

            break;
        }move = 1;
        break;
    case 2:
        if (Design[pos2 + 1][pos + 4] != ' ' || Design[pos2][pos + 6] != ' ') {
            break;
        }move = 1;
        break;
    case 3:
        if (Design[pos2][pos + 2] != ' ' || Design[pos2 + 1][pos + 2] != ' ' || Design[pos2 + 2][pos + 2] != ' ' || Design[pos2 + 3][pos + 2] != ' ') {
            break;
        }move = 1;
        break;
    case 4:
        if (Design[pos2][pos + 4] != ' ' || Design[pos2 + 1][pos + 6] != ' ') {
            break;
        }move = 1;
        break;
    case 5:
        if (Design[pos2][pos] != ' ' || Design[pos2 + 1][pos] != ' ' || Design[pos2 + 2][pos] != ' ' || Design[pos2 + 3][pos + 2] != ' ') {
            break;
        }move = 1;
        break;
    }
    if (move == true) {

        loadEmptyBlock(Design, block, pos, pos2);
        pos += 2;
        loadBlock(Design, block, pos, pos2);
    }
}

void moveBlockleft(char(&Design)[22][22], int(&block), short(&pos), short(&pos2)) {
    bool move = false;
    switch (block) {
    case 1:
        if (Design[pos2][pos - 1] != ' ' || Design[pos2 + 1][pos - 1] != ' ') {
            break;
        }
        move = 1;

        break;
    case 2:
        if (Design[pos2][pos - 1] != ' ' || Design[pos2 + 1][pos + 1] != ' ') {
            break;
        }move = 1;
        break;
    case 3:
        if (Design[pos2][pos - 1] != ' ' || Design[pos2 + 1][pos - 1] != ' ' || Design[pos2 + 2][pos - 1] != ' ' || Design[pos2 + 3][pos - 1] != ' ') {
            break;
        }move = 1;
        break;
    case 4:
        if (Design[pos2][pos - 1] != ' ' || Design[pos2 + 1][pos + 1] != ' ' || !checkUnder(Design, block, pos, pos2)) {
            break;
        }move = 1;
        break;
    case 5:
        if (Design[pos2][pos - 1] != ' ' || Design[pos2 + 1][pos - 1] != ' ' || Design[pos2 + 2][pos - 1] != ' ' || Design[pos2 + 3][pos - 1] != ' ') {
            break;
        }move = 1;
        break;
    }
    if (move == true) {
        loadEmptyBlock(Design, block, pos, pos2);
        pos -= 2;
        loadBlock(Design, block, pos, pos2);
    }
}


void sideways(char(&Design)[22][22], int(&block), short(&pos), short(&pos2), int(&value), char(&key)) {
    

         key = _getch();
         value = key;

        while (stop == 0) {

            
            switch (key) {
            case KEY_RIGHT:
                moveBlockright(Design, block, pos, pos2);
                break;
            case KEY_LEFT:
                moveBlockleft(Design, block, pos, pos2);
                break;
            }

            key = _getch();
            value = key;
        }


    
}

void fallBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2)) {
   
    while (checkUnder(Design, block, pos, pos2)) {
        loadBlock(Design, block, pos, pos2);
        Sleep(10);

        while (checkUnder(Design, block, pos, pos2)) {

            loadEmptyBlock(Design, block, pos, pos2);
            pos2++;
            loadBlock(Design, block, pos, pos2);
            Sleep(100);
        }
        pos = 7;
        pos2 = 1;
        block = 5;
    }
    loadBlock(Design, block, pos, pos2);
    stop = 1;
	
}

