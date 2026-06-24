#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
private slots:
    void onSubmitClicked();
private:
    QLineEdit *m_nameEdit;
    QComboBox *m_genderCombo;
    QCheckBox *m_hobbyBasketball;
    QCheckBox *m_hobbyMovie;
    QCheckBox *m_hobbyCode;
    QPushButton *m_submitBtn;
    QTextEdit *m_logDisplay;

};
#endif // MAINWINDOW_H
