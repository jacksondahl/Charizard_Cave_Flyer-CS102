#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDockWidget>
#include <QLabel>
#include "GraphicWindow.h"
#include <QTimer>
#include <string>
#include <QKeyEvent>

class GraphicWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
 
    
    //flags
    bool gameStarted;
    bool spacePressed;
    
    //timer
	QTimer* timer;
	
	
protected:
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);

	
private:
	//widgets
	QDockWidget *rightPanel;
	QDockWidget *leftPanel;
	QDockWidget *topPanel;
	QDockWidget *bottomPanel;
	QWidget *buttons;
	QWidget *controls;
	
	//layouts
	QVBoxLayout *controlLayout;
	QVBoxLayout *buttonLayout;

	//scenes/views
   	GraphicWindow *game;
    
    //buttons
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
  
  	//parameter input boxes
    QLineEdit *userName;
    
    //parameters
    std::string userName_;
    
    //QLabel
    QLabel *outputLabel;
    
    
    
public slots:
void closeGame();
void startGame();
void pauseGame();
void resumeGame();
void loop();
};

#endif
