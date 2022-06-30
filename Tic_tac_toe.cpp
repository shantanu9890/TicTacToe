#include<iostream>
#include<unordered_map>
using namespace std;


class Tictactoe{
    public:
    Tictactoe(){
        cout<<"* NEW GAME *"<<endl;
        cout<<"Player 1 : X && Player 2 : O"<<endl;
        unordered_map<int,char>map;
        for (int i = 1; i < 10; i++)
        {
           map[i]=(char)(i+48);
        }
        displayBoard(map);
        cout<<endl;
        while (true)
        {
            takeInputP1(map);
            displayBoard(map);
            if (isOver(map))
            {
                 
                cout<<"** Player 1 is WINNER! **"<<endl;
                map.clear();
                break;
            }
            if (isDraw(map))
            {
                cout<<"** The game is DRAW **"<<endl;
                map.clear();
                break;
            }    
            takeInputP2(map);
            displayBoard(map);
            if (isOver(map))
            {
                cout<<"** Player 2 is WINNER! **"<<endl;
                map.clear();
                break;
            }
            if (isDraw(map))
            {
                cout<<"** The game is DRAW **"<<endl;
                map.clear();
                break;
            } 
        }
    }

    void displayBoard(unordered_map<int,char>&map);
    void takeInputP1(unordered_map<int,char>&map);
    void takeInputP2(unordered_map<int,char>&map);
    bool isOver(unordered_map<int,char>&map);
    bool isDraw(unordered_map<int,char>&map);
};

void Tictactoe::displayBoard(unordered_map<int,char>&map){
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<map[1]<<"  |  "<<map[2]<<"  |  "<<map[3]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<map[4]<<"  |  "<<map[5]<<"  |  "<<map[6]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<map[7]<<"  |  "<<map[8]<<"  |  "<<map[9]<<" \n";
    cout<<"\t\t     |     |     \n";
}

void Tictactoe::takeInputP1(unordered_map<int,char>&map){
    cout<<"Player 1's turn: "<<endl;
    int input1;cin>>input1;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(512, '\n');
        cout<<"Enter appropriate value!"<<endl;
        takeInputP1(map);
    }
    if (map[input1]=='O'||map[input1]=='X')
    {
       cout<<"The box is already filled choose another one!"<<endl;
       takeInputP1(map);
    }
    else{
        map[input1]='X';
    }
}

void Tictactoe::takeInputP2(unordered_map<int,char>&map){
    cout<<"Player 2's turn: "<<endl;
    int input2;cin>>input2;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(512, '\n');
        cout<<"Enter appropriate value!"<<endl;
        takeInputP2(map);
    }
    if (map[input2]=='O'||map[input2]=='X')
    {
       cout<<"The box is already filled choose another one!"<<endl;
       takeInputP2(map);
    }
    else{
        map[input2]='O';
    }
}

bool Tictactoe::isOver(unordered_map<int,char>&map){
      for (int i = 1; i < 10; i+=3)
      {
        if (map[i]==map[i+1]&&map[i+1]==map[i+2])
        {
            return true;
        }
      }
      for (int i = 1; i < 4; i++)
      {
        if (map[i]==map[i+3]&&map[i+3]==map[i+6])
        {
           return true;
        }
      }
      if (map[1]==map[5]&&map[5]==map[9]||map[3]==map[5]&&map[5]==map[7])
      {
        return true;
      }
      return false;
}

bool Tictactoe::isDraw(unordered_map<int,char>&map){
     for (int i = 1; i < 10; i++)
     {
        if (map[i]!='O'&&map[i]!='X')
        {
           return false;
        }
        
     }
     return true;
     
}


int main(){
    while (true)
    {
       Tictactoe t;
    }
    
}