#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
using namespace std;

#include <iostream>

//MainWindow constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tempx.play(); //Starts the game

    //Hide the images of the keys and others
    ui->Key->hide();
    ui->Key1->hide();
    ui->MasterKey->hide();
    ui->pushButton->hide();
    ui->EvilCorp->hide();

    //Print text at the output Screen welcome()
    ui->OutputScreenMw->append(tempx.printWelcome().c_str());  //Appen text to an output screen and covert it to C-style string
}

MainWindow::~MainWindow()
{
    //Free the pointers created with "new" in the creatRooms()
    for(int i=0;i < tempx.Rooms.size(); i++) //Using vector methods to loop through the Rooms vector
        free(tempx.Rooms[i]); //Free the pointers created with "new"

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string letter;
    string blocked = {"Room blocked, find the keys!!!"};

    //If teleport return me the room, I could change the bg!!!
    letter = tempx.teleport();

    ChangeBackground(letter);
    ui->OutputScreenMw->append((tempx.GetLongDescription() + "\n").c_str()); //Show the description on the label

    if(letter == "Blocked") //Check if room is blocked
        ui->OutputScreenMw->append(blocked.c_str());
    if (tempx.GetMagicBoxBool() != 0){  //MagicBox return 0 if there isn't a box in the room
        MagicKey(letter[0]); //We are passing letter[0] because we need a char not a string
    }

    if(letter[0] == 'i') //Statement to recognize the final room
        FinalRoom();
  }


void MainWindow::on_northButton_clicked()
{
    string letter;
    Command north("go","north");
    cout << " "<<endl;

   letter = tempx.goRoom(north);
   //goRoom returns "0" if there is no room in the direction
   Check(letter);
}

void MainWindow::on_southButton_clicked()
{
    string letter;
    Command south("go","south");
    cout << " "<<endl;

    letter = tempx.goRoom(south);
    Check(letter);
}


void MainWindow::on_eastButton_clicked()
{
    string letter;
    Command east("go","east");
    cout << " "<<endl;

    letter = tempx.goRoom(east);
    Check(letter);
}


void MainWindow::on_wesButton_clicked()
{
    string letter;
    Command west("go","west");
    cout << " "<<endl;

    letter = tempx.goRoom(west);
    Check(letter);
}

void MainWindow::ChangeBackground(string direction)
{
    if(direction == "a")
    this->setStyleSheet("background-image: url(:/images/images/main.jpg)");
    else if(direction == "b")
        this->setStyleSheet("background-image: url(:/images/images/room-b.jpg)");
    else if(direction == "c")
        this->setStyleSheet("background-image: url(:/images/images/room-c.jpg)");
    else if(direction == "d")
        this->setStyleSheet("background-image: url(:/images/images/room-d.png)");
    else if(direction == "e")
        this->setStyleSheet("background-image: url(:/images/images/room-e.jpg)");
    else if(direction == "f")
        this->setStyleSheet("background-image: url(:/images/images/room-f.jpg)");
    else if(direction == "g")
        this->setStyleSheet("background-image: url(:/images/images/room-g.png)");
    else if(direction == "h")
        this->setStyleSheet("background-image: url(:/images/images/room-h.jpg)");
    else if(direction == "i")
        this->setStyleSheet("background-image: url(:/images/images/you-won.png); background-repeat:no-repeat;");
    else if(direction == "j")
        this->setStyleSheet("background-image: url(:/images/images/room-j.jpg)");
    else if(direction == "k")
        this->setStyleSheet("background-image: url(:/images/images/room-k.jpg)");
    else if(direction == "l")
        this->setStyleSheet("background-image: url(:/images/images/room-l.jpg)");
}

void MainWindow::MagicKey(char room)
{
    switch (room)   //Menu to choose the key to display knowing the room where the player is
    {
    case 'b':
        ui->Key1->show();

        //Key Animation
        KeyAnimation = new QPropertyAnimation(ui->Key1,"geometry");
        KeyAnimation->setDuration(8000);
        KeyAnimation->setStartValue(ui->Key1->geometry());
        KeyAnimation->setEndValue(QRect(500,500,20,20));
        KeyAnimation->setEasingCurve(QEasingCurve::Linear); //Trajectory
        KeyAnimation->start();
        break;
    case 'g':
        ui->Key->show();

        //Key Animation
        KeyAnimation = new QPropertyAnimation(ui->Key,"geometry");
        KeyAnimation->setDuration(8000);
        KeyAnimation->setStartValue(ui->Key->geometry());
        KeyAnimation->setEndValue(QRect(500,500,20,20));
        KeyAnimation->setEasingCurve(QEasingCurve::Linear);
        KeyAnimation->start();
        break;
    }
}



void MainWindow::on_Key_clicked()
{
  string x = "You've found a key!!!\n Adding the key to your bag...\n";
  string y = "\nYou've found the MASTER key!!! Go open the final room...\n";

  ui->OutputScreenMw->append(x.c_str());
  ui->Key->blockSignals(true); //So we could get just one key

  //Add key to your bag
  tempx.player.SetKey1();

 //Hide the red cross key
  ui->redcross1->hide();

  if(tempx.player.GetKey1() + tempx.player.GetKey2() == 2) //Use of the overload + operator to combine the keys
  {
      MasterKey();
      ui->OutputScreenMw->append(y.c_str());
  }
}

void MainWindow::on_Key1_clicked()
{
    string x = "You've found a key!!!\n Adding the key to your bag...\n";
    string y = "\nYou've found the MASTER key!!! Go open the final room...\n";
    ui->OutputScreenMw->append(x.c_str());
    ui->Key1->blockSignals(true); //So we could get just one key

    //Add key to your bag
    tempx.player.SetKey2();

   //Hide the red cross key
    ui->redcross2->hide();

   if(tempx.player.GetKey1() + tempx.player.GetKey2() == 2) //Use of the overload + operator to combine the keys
   {
       MasterKey();
       ui->OutputScreenMw->append(y.c_str());
   }
}

void MainWindow::MasterKey()
{
    ui->key1->hide();
    ui->key2->hide();

    ui->MasterKey->show();

    //Unlock the final room
    tempx.UnlockRoom();
}

void MainWindow::on_Help_clicked()
{
    ui->OutputScreenMw->append((tempx.printHelp() + tempx.PrintMap()).c_str());
    if (CheatMode() == 5)
        ui->pushButton->show(); //Show the teleport if you ask 5 times for help
}

int MainWindow::CheatMode()
{
    x += 1;
    return x;
}

void MainWindow::FinalRoom() //Hide everything except some pictures and we changed the bg
{
    string y = "This is the final room!!!\n You win!!! :)\n Developed by A-TEAM from EvilCorp";

    ui->Key->hide();
    ui->Key1->hide();
    ui->key1->hide();
    ui->key2->hide();
    ui->redcross1->hide();
    ui->redcross2->hide();
    ui->controller->hide();
    ui->MasterKey->hide();
    ui->pushButton->hide();
    ui->eastButton->hide();
    ui->wesButton->hide();
    ui->northButton->hide();
    ui->southButton->hide();
    ui->EvilCorp->show();
    ui->OutputScreenMw->append(( y + "\n").c_str());
}

void MainWindow::Check(string letter)
{
    string blocked = {"Room blocked, find the keys!!!"};

    if(letter != "0" && letter !="Blocked"){   //If you have exits and isn't locked go to the room
    ChangeBackground(letter);
    ui->OutputScreenMw->append(tempx.GetLongDescription().c_str());
    }
    else if(letter == "Blocked")
         ui->OutputScreenMw->append(blocked.c_str());

    if (tempx.GetMagicBoxBool() != 0){  //MagicBox return 0 if there isn't a box in the room
        MagicKey(letter[0]);
    }
    if(letter[0] == 'i') //Statement to recognize the final room
        FinalRoom();
}
