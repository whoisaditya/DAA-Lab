#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

// struct for the player
struct character
{
    int pos_X;
    int pos_Y;
    char symbol;
    int hp;
} player;

// struct for the enemies
struct enemies
{
    int pos_X;
    int pos_Y;
    char enemy_symbol;
};

// function for when the player hits an enemy
void player_hit()
{
    player.pos_X = 1;
    player.pos_Y = 1;
    player.hp--;
}

// Driver Function
int main()
{
    enemies E_Horizontal = {13, 9, 'H'}; // placing E_Horizontal at location [9][13] and gives it the sign H
    enemies E_Vertical = {11, 9, 'V'};
    enemies E_Jump = {1, 15, 'J'};

    const char HEIGHT = 18, WIDTH = 18; // the maze width and height
    bool update = false;                // boolean to control when the map needs to be updated
    char move_key = 'd';

    player.pos_X = 1;
    player.pos_Y = 1;
    
    unsigned char maze[WIDTH][HEIGHT] = 
    {
        '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
        '#',' ','#',' ',' ',' ','#','#','#',' ',' ','#','#',' ','#',' ','#','#',
        '#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#',' ', 
        '#',' ','#','#',' ',' ',' ',' ','#',' ','#','#',' ','#','#',' ',' ',' ',
        '#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',
        '#',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ','#',' ',' ','#',
        '#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
        '#','#',' ',' ','#','#','#','#',' ',' ','#',' ',' ','#','#',' ','#','#',
        '#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#','#',
        '#',' ','#',' ',' ',' ','#','#','#',' ',' ',' ','#',' ','#',' ','#','#',
        '#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#','#', 
        '#',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#',
        '#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ','#','#','#',' ','#',
        '#',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#',
        '#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
        '#','#','#','#',' ','#','#','#','#',' ','#',' ',' ','#','#',' ','#','#',
        '#','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#','#',' ','#','#',
        '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
    };

    player.symbol = 'O';

    player.hp = 3; // players different attributes

    cout << "Aditya Mitra 20BCE2044"<< endl; 
    cout << "Maze: " << endl;
    for (int y = 0; y < HEIGHT; y++)
    {
        cout << endl;
        for (int x = 0; x < WIDTH; x++)
        {
            cout << maze[x][y];
        }
    }

    cout << endl;
    cout << "Press (d) (a) (w) or (s) and then return to start the game" << endl;
    cout << "Press (q) then return to quit the game" << endl;

    while (move_key != 'q') // as long as move_key is not q then this loop will run and thereby everysingle little thing, which is happening in the maze
    {

        srand(time(NULL));                // random seed based on some time thingy
        int random_move = rand() % 2 + 1; // random number between 1 and 2

        cout << "Input: ";
        cin >> move_key;
        update = true; // map updates

        // if map is updated, then the enemies will be printed onto the map and the player
        // the maze will be created by a nested for loop, but the x and y are at the wrong places in order to create the map I have "painted" with #
        // the health will be outputted, so the gamer can see the life of the "player"
        // update stopped

        if (update == true)
        {
            system("CLS");

            maze[E_Horizontal.pos_X][E_Horizontal.pos_Y] = E_Horizontal.enemy_symbol;
            maze[E_Vertical.pos_X][E_Vertical.pos_Y] = E_Vertical.enemy_symbol;
            maze[E_Jump.pos_X][E_Jump.pos_Y] = E_Jump.enemy_symbol;

            maze[player.pos_X][player.pos_Y] = player.symbol;

            for (int y = 0; y < HEIGHT; y++)
            {
                cout << endl;
                for (int x = 0; x < WIDTH; x++)
                {
                    cout << maze[x][y];
                }
            }
            cout << endl
                 << endl
                 << "    Health: " << player.hp << endl
                 << "____________________\n \n";
            update = false;
        }

        // different key pressed in order to move the player and to see if the player collides with a # or an enemy
        // it will be printed out the "player's" location, because the game are asynchron
        // it will also be printed if the player hits a wall

        switch (move_key)
        {
        case 'w':
        {
            update = true;
            if (maze[player.pos_X][player.pos_Y - 1] != '#')
            {
                maze[player.pos_X][player.pos_Y] = ' ';
                player.pos_Y--;

                if (maze[player.pos_X][player.pos_Y] == maze[E_Horizontal.pos_X][E_Horizontal.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Vertical.pos_X][E_Vertical.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Jump.pos_X][E_Jump.pos_Y])
                {
                    player_hit();
                }

                cout << player.pos_X << " " << player.pos_Y << endl;
            }
            else
                cout << "  you hit a wall\n";
            break;
        }
        case 's':
        {
            update = true;
            if (maze[player.pos_X][player.pos_Y + 1] != '#')
            {
                maze[player.pos_X][player.pos_Y] = ' ';
                player.pos_Y++;

                if (maze[player.pos_X][player.pos_Y] == maze[E_Horizontal.pos_X][E_Horizontal.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Vertical.pos_X][E_Vertical.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Jump.pos_X][E_Jump.pos_Y])
                {
                    player_hit();
                }

                cout << player.pos_X << " " << player.pos_Y << endl;
            }
            else
                cout << "  You hit a wall\n";
            break;
        }

        case 'a':
        {
            update = true;
            if (maze[player.pos_X - 1][player.pos_Y] != '#')
            {
                maze[player.pos_X][player.pos_Y] = ' ';
                player.pos_X--;

                if (maze[player.pos_X][player.pos_Y] == maze[E_Horizontal.pos_X][E_Horizontal.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Vertical.pos_X][E_Vertical.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Jump.pos_X][E_Jump.pos_Y])
                {
                    player_hit();
                }

                cout << player.pos_X << " " << player.pos_Y << endl;
            }
            else
            {
                cout << "  You hit a wall\n";
            }

            break;
        }

        case 'd':
        {
            update = true;
            if (maze[player.pos_X + 1][player.pos_Y] != '#')
            {
                maze[player.pos_X][player.pos_Y] = ' ';
                player.pos_X++;

                if (maze[player.pos_X][player.pos_Y] == maze[E_Horizontal.pos_X][E_Horizontal.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Vertical.pos_X][E_Vertical.pos_Y] ||
                    maze[player.pos_X][player.pos_Y] == maze[E_Jump.pos_X][E_Jump.pos_Y])
                {
                    player_hit();
                }

                cout << player.pos_X << " " << player.pos_Y << endl;
            }
            else
            {
                cout << " You hit a wall\n";
            }
            break;
        }
        }

        // the horizontal moving enemy H moves in a random pattern do to the rand() function and thereby making him unpredictable.
        switch (random_move)
        {
        case 1:
        {
            if (maze[E_Horizontal.pos_X + 1][E_Horizontal.pos_Y] != '#')
            {
                maze[E_Horizontal.pos_X][E_Horizontal.pos_Y] = ' ';
                E_Horizontal.pos_X++;
            }

            break;
        }
        case 2:
        {
            if (maze[E_Horizontal.pos_X - 1][E_Horizontal.pos_Y] != '#')
            {
                maze[E_Horizontal.pos_X][E_Horizontal.pos_Y] = ' ';
                E_Horizontal.pos_X--;
            }
            break;
        }
        }

        // the vertical moving enemy he returns to his stsarting point if he híts a wall, seeing that he only moves in one simple pattern (downwards) he is predictable.
        if (maze[E_Vertical.pos_X][E_Vertical.pos_Y + 1] != '#')
        {
            maze[E_Vertical.pos_X][E_Vertical.pos_Y] = ' ';
            E_Vertical.pos_Y++;
        }
        else if (maze[E_Vertical.pos_X][E_Vertical.pos_Y - 5] != '#')
        {
            maze[E_Vertical.pos_X][E_Vertical.pos_Y] = ' ';
            E_Vertical.pos_Y -= 6;
        }

        // this enemy jumps every seconf tile over, so you have to be aware of where he is and the location there have been printed out in order to avoid him.
        // he also returns to his starting point when he can't get any further do to #

        if (maze[E_Jump.pos_X + 2][E_Jump.pos_Y] != '#')
        {
            maze[E_Jump.pos_X][E_Jump.pos_Y] = ' ';
            E_Jump.pos_X += 2;
        }
        else if (maze[E_Jump.pos_X - 14][E_Jump.pos_Y] != '#')
        {
            maze[E_Jump.pos_X][E_Jump.pos_Y] = ' ';
            E_Jump.pos_X -= 14;
        }

        if (player.hp == 0) // when the player rund out of hp the game stops and print out you have lost the game.
        {
            move_key = 'q';
            cout << "You have lost the game \n";
        }

        if (player.pos_Y == 17) // when the player reach the bottom line he winsd the game
        {
            cout << "\nCongrats!!! you have won the game\n";
        }
    }
    return 0;
}