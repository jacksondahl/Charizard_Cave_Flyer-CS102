#include "mainwindow.h"
#include <iostream>
#include <sstream>

using namespace std;

void MainWindow::closeGame()
{
	QWidget::close();
}


void MainWindow::startGame()
{
/*
	if (userName_.length() == 0)
	{
		outputLabel->setText("You must enter your name before beginning the game.\n Type your name and press enter or click start to begin.");
		return;
	}
*/
	gameStarted = true;
	score = 0;
	timer = new QTimer(this);
	timer->setInterval(1000/24);
	userName_ = userName->text(); //storing user name
	outputLabel->setText("Player: "+userName_+"\n Score:"+score+"\n Press shift to fly, P to pause and Q to quit.");
	outputLabel->setAlignment(Qt::AlignCenter);
	userName->hide();
	startButton->hide();
	game = new GraphicWindow(this);
	this->setCentralWidget(game);
	connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
	timer->start();
	bottomPanel->hide();
} 

void MainWindow::pauseGame()
{
	if (!gameStarted)
	{
		return;
	}
	timer->stop();
	pauseButton->setText("Resume");
	connect(pauseButton, SIGNAL(clicked()), this, SLOT(resumeGame()));
	isPaused = true;
	bottomPanel->show();
}

void MainWindow::resumeGame()
{
	timer->start();
	pauseButton->setText("Pause");
	connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
	isPaused = false;
	bottomPanel->hide();
}

void MainWindow::keyPause()
{
	if (!gameStarted)
	{
		return;
	}
	if (!isPaused)
	{
		timer->stop();
		isPaused = true;
		pauseGame();
		bottomPanel->show();
	}
	else if (isPaused)
	{
		timer->start();
		isPaused = false;
		resumeGame();
		bottomPanel->hide();
	}	
}

void MainWindow::loop()
{
	if (game->player->invincible)
	{
		QString score_ = QString::number(score);
		outputLabel->setText("Player: "+userName_+"\n Score:"+score_+"\n Press shift to fly, P to pause and Q to quit.\n Currently invincible");
		
		invincibilityCounter++;
		if (invincibilityCounter == 200)
		{
			game->player->invincible = false;
			game->fireHold=false;
		}
	}
	game->moveBG();
	
	if ((!spacePressed && game->playerPos < 312) || (spacePressed && game->playerPos < 30))
	{
		game->player->setPos(150, game->playerPos+3);
		game->playerPos+=3;
	}
	else
	{
		game->flyUp();
	}
	
	if(game->checkForSpikes() || game->checkForCollision())
	{
		death();
		return;
	}
	
	
	
	game->generateObject();
	game->objectMovement();
	
	score++;
	QString score_ = QString::number(score);
	outputLabel->setText("Player: "+userName_+"\n Score:"+score_+"\n Press shift to fly, P to pause and Q to quit.");
	
	//speed up
	
	if (score == 750)
	{
		game->changeBGToRiver(); //level 2
		timer->setInterval(900/24);
	}
	
	if (score == 1500)
	{
		game->changeBGToSky(); //level 3
		timer->setInterval(600/24);
	}
	if (score == 2000)
	{
		timer->setInterval(550/24);
	}
	if (score == 3000)
	{
		timer->setInterval(400/24);
	}
	if (score == 5000)
	{
		timer->setInterval(250/24);
	}
	
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
		if (e->key() == Qt::Key_Shift)
		{
			spacePressed = true;
			//game->flyUp();
		}
		if (e->key() == Qt::Key_P)
		{
			keyPause();
		}
		if (e->key() == Qt::Key_Q)
		{
			QWidget::close();
		}
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
	spacePressed = false;
}

void MainWindow::death()
{
	if (game->player->invincible)
	{
		return;
	}
	timer->stop();
	gameStarted = false;
	game->hide();
	delete game;
	QString score_ = QString::number(score);
	outputLabel->setText("GAME OVER.\n Player: "+userName_+"\n Score: "+score_+"");
	startButton->setText("Restart Game");
	startButton->show();
	bottomPanel->show();
	pauseButton->hide();
}


MainWindow::MainWindow()
{
	gameStarted = false;
	spacePressed = false;
	isPaused = false;
	
	score = 0;
	
	//timer
	//start when start is clicked
	timer = new QTimer(this);
	timer->setInterval(1000/24);
	
	
  	bottomPanel = new QDockWidget;
  	topPanel = new QDockWidget;
  	
  	bottomPanel->setFeatures(0);
  	topPanel->setFeatures(0);
  	
  	input = new QWidget;
  	output = new QWidget;
  	
   
    
    inputLayout = new QVBoxLayout;
    outputLayout = new QVBoxLayout;
    
	//Board Size input box
    userName = new QLineEdit;
    userName->setPlaceholderText("Enter Your Name");
	inputLayout->addWidget(userName);
    
    //Start Game button: starts a tile game
    startButton = new QPushButton();
    startButton->setText("Start Game");
    inputLayout->addWidget(startButton);
    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    
    connect(userName, SIGNAL(returnPressed()),startButton,SIGNAL(clicked())); //used so enter can be pressed when in line edit
    
    //Cheat button: runs A* Algorithm
    pauseButton = new QPushButton();
    pauseButton->setText("Pause");
    inputLayout->addWidget(pauseButton);
    connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
    
    //quit button: closes program
    quitButton = new QPushButton();
    quitButton->setText("Quit");
    inputLayout->addWidget(quitButton);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(closeGame()));
    
	//Qlabel output
	outputLabel = new QLabel(this);
	outputLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	outputLabel->setText("Enter your name and press enter or click start to begin the game.");
	outputLayout->addWidget(outputLabel);
	
	input->setLayout(inputLayout);
	output->setLayout(outputLayout);
	bottomPanel->setWidget(input);
	topPanel->setWidget(output);
    
	this->addDockWidget(Qt::BottomDockWidgetArea,bottomPanel);
	this->addDockWidget(Qt::TopDockWidgetArea,topPanel);

	
    
}

MainWindow::~MainWindow()
{
 
}

