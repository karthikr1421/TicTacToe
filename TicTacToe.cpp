
#include<iostream>
#include<ctime>

#define RESET   "\033[0m"      
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"   
#define YELLOW  "\033[1;33m"   
#define BLUE    "\033[1;34m"   

void drawBoard(char spaces[]);
void playerMove(char spaces[], char &player);
bool checkWinner(char spaces[]);
int main(){

    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    bool running = true;
    int moves = 0; 
    bool win ;

    std::cout<<GREEN<<"***********************************************\n"<<RESET;
    std::cout<<GREEN<<" Welcome to TIC-TAC-TOE \n"<<RESET;
    std::cout<<GREEN<<"***********************************************\n"<<RESET;


    while(running && moves < 9 && !win ){

        drawBoard(spaces);
        playerMove(spaces,player);
        win = checkWinner(spaces);
            
        if(win){

            drawBoard(spaces);  

            std::cout<<"\n";
            std::cout<<player<<" WON! ";
            std::cout<<"\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
        moves ++;
    }

    if(!win && moves >= 9){

        drawBoard(spaces);
        std::cout<<GREEN<<"It's a TIE!\n"<<RESET;
    }


    std::cout<<RED<<"**************************\n"<<RESET;
    std::cout<<RED<<"GAME OVER!\n"<<RESET;
    std::cout<<RED<<"**************************\n"<<RESET;

    
    return 0;

    
}
void drawBoard(char spaces[]){


    std::cout<<"\n";
    std::cout<<GREEN<<"     |     |      \n"<<RESET;
    std::cout<<" "<<spaces[0]<<GREEN<<"   | "<<RESET<<spaces[1] <<GREEN<<"   | "<<RESET<<spaces[2]<<"     \n";
    std::cout<<GREEN<<"_____|_____|_____ \n"<<RESET;
    std::cout<<GREEN<<"     |     |      \n"<<RESET;
    std::cout<<" "<<spaces[3]<<GREEN<<"   | "<<RESET<<spaces[4] <<GREEN<<"   | "<<RESET<<spaces[5]<<"     \n";
    std::cout<<GREEN<<"_____|_____|_____ \n"<<RESET;
    std::cout<<GREEN<<"     |     |      \n"<<RESET;
    std::cout<<" "<<spaces[6]<<GREEN<<"   | "<<RESET<<spaces[7] <<GREEN<<"   | "<<RESET<<spaces[8]<<RESET"     \n";
    std::cout<<GREEN<<"     |     |      \n"<<RESET;
    std::cout<<"\n";


}
void playerMove(char spaces[], char &player){

    int number=0;
    do{
        std::cout<<"Enter the position you want to place the marker (1-9): ";
        std::cin>>number;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Invalid Entry!";
        }
    }while(number<0 || number>9 || spaces[number-1] != ' ');
    number--;
    spaces[number] =  player;
    

}bool checkWinner(char spaces[]) {
    // Horizontal
    if ((spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0] != ' ') ||
        (spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3] != ' ') ||
        (spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[6] != ' '))
        return true;

    // Vertical
    if ((spaces[0] == spaces[3] && spaces[3] == spaces[6] && spaces[0] != ' ') ||
        (spaces[1] == spaces[4] && spaces[4] == spaces[7] && spaces[1] != ' ') ||
        (spaces[2] == spaces[5] && spaces[5] == spaces[8] && spaces[2] != ' '))
        return true;

    // Diagonal
    if ((spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' ') ||
        (spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' '))
        return true;

    return false;
}
       