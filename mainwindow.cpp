#include "mainwindow.h"
#include <iostream>

using namespace std;

void MainWindow::closeGame()
{
	QWidget::close();
}

void MainWindow::startGame()
{
	gameStarted = true;
	//userName_ = userName->text(); //storing user name
} 


MainWindow::MainWindow()
{
	gameStarted = false;
	
	
  	bottomPanel = new QDockWidget;
  	topPanel = new QDockWidget;
  	
  	bottomPanel->setFeatures(0);
  	topPanel->setFeatures(0);
  	
  	buttons = new QWidget;
  	controls = new QWidget;
  	
   	game = new GraphicWindow(this);
    
    buttonLayout = new QVBoxLayout;
    controlLayout = new QVBoxLayout;
    
	//Board Size input box
    userName = new QLineEdit;
    userName->setPlaceholderText("Enter Your Name");
	buttonLayout->addWidget(userName);
    
    //Start Game button: starts a tile game
    startButton = new QPushButton();
    startButton->setText("Start Game");
    buttonLayout->addWidget(startButton);
    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    
    //Cheat button: runs A* Algorithm
    pauseButton = new QPushButton();
    pauseButton->setText("Pause");
    buttonLayout->addWidget(pauseButton);
    
    //quit button: closes program
    quitButton = new QPushButton();
    quitButton->setText("Quit");
    buttonLayout->addWidget(quitButton);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(closeGame()));
    
	//Qlabel output
	outputLabel = new QLabel(this);
	outputLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	outputLabel->setText("Enter your name and click start to begin the game.");
	controlLayout->addWidget(outputLabel);
	
    buttons->setLayout(buttonLayout);
    controls->setLayout(controlLayout);
    bottomPanel->setWidget(buttons);
   	topPanel->setWidget(controls);
    
    this->addDockWidget(Qt::BottomDockWidgetArea,bottomPanel);
    this->addDockWidget(Qt::TopDockWidgetArea,topPanel);
    this->setCentralWidget(game);
    
    this->setFixedSize(600,600);
    
}

MainWindow::~MainWindow()
{
 
}

