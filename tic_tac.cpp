#include <iostream>
#include <stdlib.h> // need to be include beacuse i can use system "cls" function.
using namespace std;

class tic
{
public:
    int index = 9; // for running for loop in int main up to required length.
    char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    string Player = "Player X ";
    char player_ch = 'x';
    void toggel_player()
    {
        if (Player == "Player X ")
        {
            Player = "Player O ";
            player_ch = 'o';
        }
        else
        {
            Player = "Player X ";
            player_ch = 'x';
        }
    }
    virtual void display() = 0;
};
class tac : public tic
{
public:
    void display()
    {
        cout << "*_* Tic Tac Tao *_*\n"
             << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrix[i][j] << "   ";
            }
            cout << "\n\n";
        }
        cout << "\n";
    }

    void input()
    {

        int a;
        cout << Player << "Enter Your Postion : ";
        cin >> a;
        if (a == 1)
        {
            if (matrix[0][0] == '1')
            {
                matrix[0][0] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player(); // use because if space already occupied then player need to be same.
            }
        }
        if (a == 2)
        {
            if (matrix[0][1] == '2')
            {
                matrix[0][1] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        if (a == 3)
        {
            if (matrix[0][2] == '3')
            {
                matrix[0][2] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        if (a == 4)
        {
            if (matrix[1][0] == '4')
            {
                matrix[1][0] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        if (a == 5)
        {
            if (matrix[1][1] == '5')
            {
                matrix[1][1] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        if (a == 6)
        {
            if (matrix[1][2] == '6')
            {
                matrix[1][2] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        if (a == 7)
        {
            if (matrix[2][0] == '7')
            {
                matrix[2][0] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        if (a == 8)
        {
            if (matrix[2][1] == '8')
            {
                matrix[2][1] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        if (a == 9)
        {
            if (matrix[2][2] == '9')
            {
                matrix[2][2] = player_ch;
            }
            else
            {
                cout << "\nPosition is already Aquired !! please choose different.";
                index++;
                toggel_player();
            }
        }
        cout << endl;
    }
    int check(char a[3][3])
    { // Check if any of possible combination match or not
        if (a[0][0] == 'x' && a[0][1] == 'x' && a[0][2] == 'x')
            return 1;
        else if (a[0][0] == 'o' && a[0][1] == 'o' && a[0][2] == 'o')
            return 0;
        else if (a[1][0] == 'o' && a[1][1] == 'o' && a[1][2] == 'o')
            return 0;
        else if (a[1][0] == 'x' && a[1][1] == 'x' && a[1][2] == 'x')
            return 1;
        else if (a[2][0] == 'o' && a[2][1] == 'o' && a[2][2] == 'o')
            return 0;
        else if (a[2][0] == 'x' && a[2][1] == 'x' && a[2][2] == 'x')
            return 1;
        else if (a[0][0] == 'o' && a[1][0] == 'o' && a[2][0] == 'o')
            return 0;
        else if (a[0][0] == 'x' && a[1][0] == 'x' && a[2][0] == 'x')
            return 1;
        else if (a[0][1] == 'o' && a[1][1] == 'o' && a[2][1] == 'o')
            return 0;
        else if (a[0][1] == 'x' && a[1][1] == 'x' && a[2][1] == 'x')
            return 1;
        else if (a[0][2] == 'o' && a[1][2] == 'o' && a[2][2] == 'o')
            return 0;
        else if (a[0][2] == 'x' && a[1][2] == 'x' && a[2][2] == 'x')
            return 1;
        else if (a[0][0] == 'o' && a[1][1] == 'o' && a[2][2] == 'o')
            return 0;
        else if (a[0][0] == 'x' && a[1][1] == 'x' && a[2][2] == 'x')
            return 1;
        else if (a[0][2] == 'o' && a[1][1] == 'o' && a[2][0] == 'o')
            return 0;
        else if (a[0][2] == 'x' && a[1][1] == 'x' && a[2][0] == 'x')
            return 1;
        return 2;
    }
};

int main()
{
    tac obj;
    for (int k = 0; k < obj.index; k++)
    {
        system("CLS  ");
        obj.display();
        obj.input();
        int holder = obj.check(obj.matrix); // holds the value of check function either it is zero(player o) or one(player x).
        if (holder == 1)
        {
            cout << "--> Player X win <--";
            obj.display();
            return 0;
        }
        else if (holder == 0)
        {
            cout << "--> Player O win <--";
            obj.display();
            return 0;
        }
        obj.toggel_player();
    }
    obj.display();
    cout << "--> Match Draw <--";
    return 0;
}
