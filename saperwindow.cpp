#include "saperwindow.h"
#include "ui_saperwindow.h"

SaperWindow::SaperWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SaperWindow)
{
    ui->setupUi(this);
    model = new gameBoardModel(this);
    ui->GameView->horizontalHeader()->hide();
    ui->GameView->verticalHeader()->hide();
    ui->GameView->setModel(model);
    ui->GameView->setItemDelegate(new FieldDelegate);
    connect(ui->actionBest_Results,&QAction::triggered,this, &SaperWindow::showBestResults);
    connect(ui->action_New_game, &QAction::triggered,model,&gameBoardModel::startNewGame);
    connect(model, &gameBoardModel::newGame, this, &SaperWindow::newGame);
    connect(model, &gameBoardModel::gameOver, this, &SaperWindow::gameOver);
    connect(model, &gameBoardModel::winGame,this, &SaperWindow::gameWon);
    connect(model,&gameBoardModel::pointsChanged,ui->pointsLabel, &QLabel::setText);
    connect(ui->actionSave_Result, &QAction::triggered, this, &SaperWindow::saveResult);
    ui->gameState->hide();
    QSizePolicy sp_retain = ui->gameState->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->gameState->setSizePolicy(sp_retain);
    ui->GameView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->GameView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

SaperWindow::~SaperWindow()
{
    delete ui;
}

void SaperWindow::setEasy()
{
    ui->actionEasy->setChecked(true);
    ui->actionMedium->setChecked(false);
    ui->actionHard->setChecked(false);
    model->changeDifficulty(GameDifficulty::EASY);
}

void SaperWindow::setMedium()
{
    ui->actionEasy->setChecked(false);
    ui->actionMedium->setChecked(true);
    ui->actionHard->setChecked(false);
    model->changeDifficulty(GameDifficulty::MEDIUM);
}

void SaperWindow::setHard()
{
    ui->actionEasy->setChecked(false);
    ui->actionMedium->setChecked(false);
    ui->actionHard->setChecked(true);
    model->changeDifficulty(GameDifficulty::HARD);
}

void SaperWindow::showBestResults()
{
    BestResultsDialog* results = new BestResultsDialog(this);
    results->setModal(true);
    results->exec();
}

void SaperWindow::gameOver()
{
    ui->gameState->show();
    ui->gameState->setText("Game Over!");
    ui->gameState->setStyleSheet("color: red");
    canBeSaved = false;
}

void SaperWindow::saveResult()
{
    if(!canBeSaved)
        return;
    SaveDialog* savedial = new SaveDialog(this);
    savedial->setPoints(model->getPoints());
    savedial->setModal(true);
    savedial->exec();
    canBeSaved = false;
}

void SaperWindow::newGame()
{
    ui->gameState->hide();
    canBeSaved = false;
}

void SaperWindow::gameWon()
{
    ui->gameState->show();
    ui->gameState->setText("You Win!");
    ui->gameState->setStyleSheet("color: green");
    canBeSaved = true;
}
