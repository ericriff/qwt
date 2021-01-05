/*****************************************************************************
* Qwt Examples - Copyright (C) 2002 Uwe Rathmann
* This file may be used under the terms of the 3-clause BSD License
*****************************************************************************/

#include "tvplot.h"

#include <QApplication>
#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QComboBox>

class MainWindow : public QMainWindow
{
  public:
    MainWindow( QWidget* = NULL );

  private:
    TVPlot* d_plot;
};

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent )
{
    d_plot = new TVPlot( this );
    setCentralWidget( d_plot );

    QToolBar* toolBar = new QToolBar( this );

    QComboBox* typeBox = new QComboBox( toolBar );
    typeBox->addItem( "Outline" );
    typeBox->addItem( "Columns" );
    typeBox->addItem( "Lines" );
    typeBox->addItem( "Column Symbol" );
    typeBox->setCurrentIndex( typeBox->count() - 1 );
    typeBox->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    QToolButton* btnExport = new QToolButton( toolBar );
    btnExport->setText( "Export" );
    btnExport->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
    connect( btnExport, SIGNAL(clicked()), d_plot, SLOT(exportPlot()) );

    toolBar->addWidget( typeBox );
    toolBar->addWidget( btnExport );
    addToolBar( toolBar );

    d_plot->setMode( typeBox->currentIndex() );
    connect( typeBox, SIGNAL(currentIndexChanged(int)),
        d_plot, SLOT(setMode(int)) );
}

int main( int argc, char** argv )
{
    QApplication a( argc, argv );

    MainWindow mainWindow;

    mainWindow.resize( 600, 400 );
    mainWindow.show();

    return a.exec();
}
