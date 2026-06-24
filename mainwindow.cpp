#include "mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    QLabel *namelabel = new QLabel("姓名",this);
    m_nameEdit = new QLineEdit(this);
    m_nameEdit->setPlaceholderText("请输入姓名");

    QLabel *genderlabel = new QLabel("性别",this);
    m_genderCombo = new QComboBox(this);
    m_genderCombo->addItem("男");
    m_genderCombo->addItem("女");

    m_hobbyBasketball = new QCheckBox("篮球",this);
    m_hobbyCode = new QCheckBox("代码",this);
    m_hobbyMovie = new QCheckBox("电影",this);

    QHBoxLayout *hobbylaout = new QHBoxLayout;
    hobbylaout->addWidget(m_hobbyBasketball);
    hobbylaout->addWidget(m_hobbyCode);
    hobbylaout->addWidget(m_hobbyMovie);
    hobbylaout->addStretch();

    m_submitBtn = new QPushButton("提交信息",this);

    m_logDisplay = new QTextEdit(this);
    m_logDisplay->setReadOnly(true);
    m_logDisplay->setPlaceholderText("暂无记录");

    QGridLayout *gridlayout = new QGridLayout;
    gridlayout->addWidget(namelabel,0,0);
    gridlayout->addWidget(m_nameEdit,0,1);
    gridlayout->addWidget(genderlabel,1,0);
    gridlayout->addWidget(m_genderCombo,1,1);


    QLabel *hobbylabel = new QLabel("爱好",this);
    gridlayout->addWidget(hobbylabel,2,0);
    gridlayout->addLayout(hobbylaout,2,1);

    gridlayout->addWidget(m_submitBtn,3,0,1,2);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addLayout(gridlayout);
    mainlayout->addWidget(m_logDisplay);

    QWidget * central = new QWidget(this);
    central->setLayout(mainlayout);
    setCentralWidget(central);


    connect(m_submitBtn,&QPushButton::clicked,this,&MainWindow::onSubmitClicked);


    resize(500,400);
    setWindowTitle("第二天学习 - 个人信息收集者");


}

MainWindow::~MainWindow(){}

void MainWindow::onSubmitClicked()
{
    QString name = m_nameEdit->text().trimmed();
    QString gender = m_genderCombo->currentText();

    if(name.isEmpty()){
        QMessageBox::warning(this,"提示","请输入姓名！");
        m_nameEdit->setFocus();
        return;
    }

    QStringList hobbies;
    if(m_hobbyBasketball->isChecked()) hobbies<<"篮球";
    if(m_hobbyCode->isChecked()) hobbies<<"代码";
    if(m_hobbyMovie->isChecked()) hobbies<<"电影";

    QString hobbystr = hobbies.isEmpty() ? "无" :hobbies.join("，");

    QString record = QString("%1|%2|%3|")
                        .arg(name)
                        .arg(gender)
                        .arg(hobbystr);

    m_logDisplay->append(record);

    QMessageBox::information(this,"成功","信息已提交！");

    m_nameEdit->clear();
    m_nameEdit->setFocus();
}






