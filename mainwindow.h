#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameModel.h"
#include "ViewText.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include "textcommands.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void processTextCommand(QString userCommand);
    void createTextCommandToClassMap();

private slots:
    void on_radioButton_Text_clicked();  
    void on_executeButton_clicked();
    void selectWorld(int index);
   // void on_comboBox_activated(int index);

public slots:
    void updateEnergy(float value);
    void updateHealth(float value);
    void gameOverSlot(const QString &message);
    void updateMainWindowViewSlot(QString buildview);
    //void selectWorld(int number);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    std::shared_ptr<World> world;
    std::shared_ptr<GameModel> gameModel;
    std::shared_ptr<ViewText>gameTextView;
    QGraphicsItem* textViewItem;
    std::map<std::string,std::shared_ptr<TextCommands>>textCommandToClassMap;

};
#endif // MAINWINDOW_H
