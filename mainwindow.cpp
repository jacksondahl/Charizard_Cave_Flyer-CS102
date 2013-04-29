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
	game = new GraphicWindow(this);
	this->setCentralWidget(game);
	connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
	timer->start();
	//userName_ = userName->text(); //storing user name
} 

void MainWindow::pauseGame()
{
	timer->stop();
	pauseButton->setText("Resume");
	connect(pauseButton, SIGNAL(clicked()), this, SLOT(resumeGame()));
}

void MainWindow::resumeGame()
{
	timer->start();
	pauseButton->setText("Pause");
	connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
}

void MainWindow::loop()
{
	game->moveBG();
	if (!spacePressed)
	{
		game->player->setPos(150, game->playerPos+1);
		game->playerPos+=1;
	}
	else
	{
		game->flyUp();
	}
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	spacePressed = true;
		if (e->key() == Qt::Key_Space)
		{
			//game->flyUp();
		}
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
	spacePressed = false;
}


MainWindow::MainWindow()
{
	gameStarted = false;
	spacePressed = false;
	
	//timer
	//start when start is clicked
	timer = new QTimer(this);
	timer->setInterval(1000/24);
	
	
  	bottomPanel = new QDockWidget;
  	topPanel = new QDockWidget;
  	
  	bottomPanel->setFeatures(0);
  	topPanel->setFeatures(0);
  	
  	buttons = new QWidget;
  	controls = new QWidget;
  	
   //	game = new GraphicWindow(this);
    
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
    connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
    
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
	//this->setCentralWidget(game);
	
	//this->setFixedSize(800,400);
    
}

MainWindow::~MainWindow()
{
 
}

