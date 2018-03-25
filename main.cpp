
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<functional>

using namespace std;
ofstream ofc("Chabuk_Midterm.txt");


//Global Vars
int tempArray[6];



//*******************************
//Serial generator using        *
//the same exact pattern        *
//*******************************
void genSerial()
{

    int spc[33];
    for (int i=0;i<33;i++)
    {
        spc[i]=rand()%9+1;
        ofc<<spc[i];
        if(i==5)
        {
            ofc<<" ";
        }
        else if(i==9)
        {
            ofc<<"-";
        }
        else if(i==17)
        {
            ofc<<"-";
        }

        else if(i==24)
        {
          ofc<<" ";
        }

        else if(i==30)
        {
            ofc<<"-";
        }

    }


}






//***************
//quit function *
//***************


void quit()
{
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"                 $-*-**-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*$"<<endl;
    cout<<"                 $ *-> $$           GOOD BYE          $$ <-*$"<<endl;
    cout<<"                 $-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*$"<<endl;
    cout<<"                 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"                 --           Waubonsee Community college  --"<<endl;
    cout<<"                 --           CIS 230.600  c++             --"<<endl;
    cout<<"                 --           Pf. Vince Spina.             --"<<endl;
    cout<<"                 --           Chabuk, NullTechs 2016       --"<<endl;
    cout<<"                 |___________________________________________|"<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"POWER BALL VER 1.0 "<<endl;
    cout<<"Please check Chabuk_Midterm.txt "<<endl;
    cout<<"PROGRAM TERMINATED...";
    delete tempArray;

    system("PAUSE");

}





int sortme(int tempArray[])
{




    for (int startIndex = 0; startIndex < 6; ++startIndex)
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < 6; ++currentIndex)
        {

            if (tempArray[currentIndex] < tempArray[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(tempArray[startIndex], tempArray[smallestIndex]);
    }
    return *tempArray;
}





int removedub(int tempArray[])
{
    for(int i = 0; i <6 ; i++)

                for(int j = i+1; j  <6; j++)
                    {
                        if(tempArray[i]==tempArray[j])
                        {
                            tempArray[i]=rand()%68+1;

                        }
                    }

return *tempArray;
}




//*******************************************************************
//This function uses recursion to generate an array based on the   *
//number of picks                                                  *
//a boolean is used to check if the array is based on user input   *
//*******************************************************************

void arrayOutput(unsigned long int picks,bool check)
{

    ofc<<setw(10)<<" ";

//check if this is a random generated array
// then fill it with random values


        if(check==true)
        {
          //filling array with random values
          for(int i=0;i<6;i++)
          {
              tempArray[i] = rand()%68+1;
          }


//remove doubles
            removedub(tempArray);

//then sort
            sortme(tempArray);
//make sure powerball is between 1-26
            tempArray[5]=rand()%26+1;
        }




//print out

    for (int x=0;x<6;x++)
        {


//if the element value is less than 10
//add a zero to the left to prevent
//the ticket from deforming
        if(tempArray[x]<10)

            {
                ofc<<"  "<<0<<tempArray[x];
            }
        else
            {
                ofc<<"  "<<tempArray[x];
            }


        }




//check if its a random array
//with quick picks
//insert QP after the output

    if(check==true)
    {
      ofc<<" -QP"<<setw(5)<<"|"<<endl<<"| |";
    }

    else
    {
       ofc<<setw(9)<<"|"<<endl<<"| |";
    }



//when the pc reaches the end of the picks
//it prints the withdraw date

    if (picks==1)
        {
        ofc<<setw(43)<<"|"<<endl<<"| |";
        ofc<<setw(13)<<""<<"1 Draw on 08/07/2018"<<setw(10)<<"|";

        }


//if not then it returns the total pick number -1
//recursion !

    else
    {

        return arrayOutput(picks-1,check);
    }



}








//******************
//Main ticket body *
//******************

//boolean value is used to determine the type of the array
//user defined or random

void printticket(unsigned long int picks,bool check)
{

double cost=picks*2;

//current system time
time_t now = time(0);
char* tnow = ctime(&now);

//main body

ofc<<"|-|*-**-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-* |"<<endl;
ofc<<"| |*->     $$ P O W E R   B A L L $$      <-*|"<<endl;
ofc<<"| |*->                   (POWER PLAY)     <-*|"<<endl;
ofc<<"| |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* |"<<endl;
ofc<<"|C|          POWER BALL JACKPOT IS 422       |"<<endl;
ofc<<"|H|          MILLION IN THE WORDS OF         |"<<endl;
ofc<<"|A|          MOTHER 'EAT YOU VEGGIES'        |"<<endl;
ofc<<"|B|          AND GO PLAY                     |"<<endl;
ofc<<"|U|                                          |"<<endl;
ofc<<"|K|                                          |"<<endl;
ofc<<"| |              POWER PLAY -NO              |"<<endl;
ofc<<"| |                                PBall     |"<<endl;
ofc<<"| |";arrayOutput(picks,check);ofc<<"         "<<endl;
ofc<<"| |"<<setw(20)<<"total $"<<cost<<".00"<<setw(18)<<"|"<<endl;
ofc<<"|L|                                          |"<<endl;
ofc<<"|O|                                          |"<<endl;
ofc<<"|T|"<<"            LOTO   08/08/2018"<<" $4.95 MILL  "<<"|"<<endl;
ofc<<"|T|"<<"            PWRB   08/07/2018"<<" $425  Mill  "<<"|"<<endl;
ofc<<"|E|"<<"            MEGA   08/09/2018"<<" $28   MILL  "<<"|"<<endl;
ofc<<"|R|                                          |"<<endl;
ofc<<"|Y|                                          |"<<endl;
ofc<<"| |   ";genSerial();ofc<<setw(2)<<"|"<<endl;
ofc<<"| |"<<"          "<<tnow;
ofc<<"| |       ||||||| ||||||||||||||||| |||||    |"<<endl;
ofc<<"| |       |||  |||||| ||||||| ||||||||| |    |"<<endl;
ofc<<"|_|__________________________________________|"<<endl;

}


//************************************
//an array based on chosen numbers   *
//************************************
void luckynumbers(int picks)
{

    cout<<"Please your favorite numbers then hit return :) ,"<<endl;
    int nums;
    for(int i=0; i<6;i++)
    {
       if (i==5)
       {
           cout<<"And your power ball number please...";
           cin>>nums;

           while((nums >26 || nums<1))

            {

                cout<<"Error !! "<<endl;
                cout<<"Power ball can not be less than 1 or more than 26"<<endl;
                cin.clear();
                cin.ignore();
                cin>>nums;


            }

       }
       else
       {


        cin>>nums;
            while((nums >69 || nums<1))
                {

                    cout<<"Error !! "<<endl;
                    cout<<"Please select numbers from 1 to 69"<<endl;
                    cin.clear();
                    cin.ignore();
                    cin>> nums;
                }
       }

        tempArray[i]=nums;


    }

    //Sending to printing with false boolean value to prevent the array from
    //being filled with random numbers

    printticket(1,false);
    cout<<"Ticket has been generated with your lucky numbers"<<endl;
    quit();
}






//************************
//Main menu function     *
//************************

void mainMenu()
{
    cout<<"                 |__________________________________________|"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 |-*-**-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*|"<<endl;
    cout<<"                 |      *-> $$ P O W E R   B A L L $$ <-*   |"<<endl;
    cout<<"                 |-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 |__________________________________________|"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 | Please select from the following menu    |"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 |1-One quick pick    :)                    |"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 |2-Five quick picks                        |"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 |3-Any number of quick picks               |"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 |4-Your selected numbers, with Power Ball  |"<<endl;
    cout<<"                 |                                          |"<<endl;
    cout<<"                 |5-Quit :(                                 |"<<endl;
    cout<<"                 |__________________________________________|"<<endl;


    int choice;
    cout<<endl;
    cout<<"waiting for selection    ";
    cin>>choice;
    system("CLS");

//validating user input


    while((choice >5) && (choice !=5 ||!cin))
    {

       cout<<"Error invalid selection"<<endl;
       cout<<"Please select from 1 to 5 only !"<<endl;
       cin.clear();
       cin.ignore();

       cin>> choice;
    }

    switch(choice)
    {

        case 1:
            cout<<endl;
            cout<<endl;
            cout<<endl;
            system("CLS");
            cout<<"One ticket with one pick has been generated successfully."<<endl;
            printticket(1,true);
            quit();

        break;

        case 2:
            system("CLS");
            cout<<endl;
            cout<<endl;
            cout<<"((*-One ticket with 5 picks has been generated successfully.-*))"<<endl;
            printticket(5,true);
            quit();
        break;

        case 3:
                system("CLS");
                cout<<"I'll take your money no worries"<<endl;
                cout<<"How many picks  ? "<<endl;
                unsigned long int x;
                cin>>x;
                cout<<endl;
                cout<<endl;
                cout<<x<<" Picks has been generated successfully :) "<<endl;
                cout<<endl;
                printticket(x,true);
                quit();
            break;
        case 4:
            luckynumbers(1);
            break;
        case 5 :
            quit();
            break;

    }



}

void Greeting()
{

  cout<<"                 #####################################"<<endl;
  cout<<"                 *************************************"<<endl;
  cout<<"                 |              CHABUK, MO           |"<<endl;
  cout<<"                 |              CIS 230.600          |"<<endl;
  cout<<"                 |              MIDTERM TEST         |"<<endl;
  cout<<"                 |              10/13/2015           |"<<endl;
  cout<<"                 |                                   |"<<endl;
  cout<<"                 |Power ball ver 1.0                 |"<<endl;
  cout<<"                 *************************************"<<endl;
  cout<<"                 #####################################"<<endl;
  cout<<endl;
  system("PAUSE");
  system("CLS");
  mainMenu();


}



int main()
{

    srand(time(NULL));
    Greeting();


    return 0;
}
