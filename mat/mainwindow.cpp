#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #808080");
    ui->label_3->setStyleSheet("QLabel{font-size: 14pt;}");
    ui->label_4->setStyleSheet("QLabel{font-size: 14pt;}");

    ui->frame->setStyleSheet("");
    ui->frame->setStyleSheet("background-color: #afeeee");
    ui->frame_2->setStyleSheet("");
    ui->frame_2->setStyleSheet("background-color: #afeeee");
    ui->frame_3->setStyleSheet("");
    ui->frame_3->setStyleSheet("background-color: #afeeee");

    ui->ok->setStyleSheet("background-color: #E0FFFF");
    ui->clear->setStyleSheet("background-color: #E0FFFF");
    ui->push->setStyleSheet("background-color: #E0FFFF");
    ui->Col->setStyleSheet("background-color: #E0FFFF");
    ui->Row->setStyleSheet("background-color: #E0FFFF");
    ui->Col2->setStyleSheet("background-color: #E0FFFF");
    ui->Row2->setStyleSheet("background-color: #E0FFFF");

    ui->ok->setDefault(true);

    connect(ui->rb1, SIGNAL(clicked()), this,SLOT(on_rb1()));
    connect(ui->rb2, SIGNAL(clicked()), this,SLOT(on_rb2()));
    connect(ui->ok, SIGNAL(clicked()), this,SLOT(on_ok()));
    connect(ui->clear, SIGNAL(clicked()), this,SLOT(on_clear()));
    connect(ui->push, SIGNAL(clicked()), this,SLOT(on_push()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rb1()
{
    ui->cb1->setEnabled(true);
    ui->cb2->setEnabled(false);
    ui->Col2->setEnabled(false);
    ui->Row2->setEnabled(false);
    ui->label_2->setEnabled(false);
}


void MainWindow::on_rb2()
{
    ui->cb2->setEnabled(true);
    ui->cb1->setEnabled(false);
    ui->Col2->setEnabled(true);
    ui->Row2->setEnabled(true);
    ui->label_2->setEnabled(true);


}

void MainWindow::on_push()
{
    bool ok=true;
    int c, r, c1, r1;
    QString str=ui->Col->text();
    c=str.toDouble(&ok);
    QString str2=ui->Row->text();
    r=str2.toDouble(&ok);
    get_A(r, c);
    if (ui->cb1->isEnabled()){
        Only_matrix();}
    else if (ui->cb2->isEnabled()){
        QString strb=ui->Col2->text();
        c1=strb.toDouble(&ok);
        QString strb2=ui->Row2->text();
        r1=strb2.toDouble(&ok);
        get_B(r1, c1);
        Two_matrix();}
}

void MainWindow::on_ok()
{
    bool ok=true;
    int c, r, c1, r1;
    QString str=ui->Col->text();
    c=str.toDouble(&ok);
    QString str2=ui->Row->text();
    r=str2.toDouble(&ok);
    if((c>4) || (r>4)){
        QMessageBox::warning(this, "Ошибка!", "Размер матрицы больше 4");
    }
    else{
    matrix_A(r,c);


    ui->Row->setEnabled(false);
    ui->Col->setEnabled(false);

    if (ui->cb2->isEnabled()){
        QString strb=ui->Col2->text();
        c1=strb.toDouble(&ok);
        QString strb2=ui->Row2->text();
        r1=strb2.toDouble(&ok);
        matrix_B(r1, c1);

        ui->Row2->setEnabled(false);
        ui->Col2->setEnabled(false);
    }
    ui->ok->setEnabled(false);}
}


void MainWindow::on_clear()
{
    bool ok=true;
    int c, r, c1, r1;
    QString str=ui->Col->text();
    c=str.toDouble(&ok);
    QString str2=ui->Row->text();
    r=str2.toDouble(&ok);
    if (!(ui->gridLayout_4->isEmpty())){
        if(ui->cb1->currentIndex()==0 && ui->cb1->isEnabled()){
            matrix_clearing_0();
        }
        else if(ui->cb2->currentIndex()==2 && ui->cb2->isEnabled()){
            matrix_clearing_2(r);
        }
        else if(ui->cb1->currentIndex()==1 && ui->cb1->isEnabled()){
            matrix_clearing1(r, c);
        }
        else{
            matrix_clearing(r, c);}
    }

    ui->Col->clear();
    ui->Row->clear();
    ui->Row->setEnabled(true);
    ui->Col->setEnabled(true);

    clear_matrix_A(r, c);
    if (ui->cb2->isEnabled()){
        QString strb=ui->Col2->text();
        c1=strb.toDouble(&ok);
        QString strb2=ui->Row2->text();
        r1=strb2.toDouble(&ok);
        ui->Col2->clear();
        ui->Row2->clear();
        ui->Row2->setEnabled(true);
        ui->Col2->setEnabled(true);
        clear_matrix_B(r1, c1);
    }

    ui->ok->setEnabled(true);
}


void MainWindow::get_det(double& d){
    QString strd;
    strd.setNum(d);
    QLabel* lab = new QLabel;
    lab->setText(strd);
    lab->setStyleSheet("background-color: rgb(255, 253, 208)");
    lab->setAlignment(Qt::AlignCenter);
    ui->gridLayout_4->addWidget(lab, 0, 0);
}


void MainWindow::get_trans(int c, int r){
    double v;
    QString strd;
    for (int i=0; i<c; i++){
        for (int j=0; j<r; j++){
            v = Vec[i][j];
            strd.setNum(v);
            QLabel* lab = new QLabel(this);
            lab->setStyleSheet("background-color: rgb(255, 253, 208)");
            lab->setText(strd);
            ui->gridLayout_4->addWidget(lab, i, j);
        }}

}

void MainWindow::get_pow(int c, int r){
    double v;
    QString strd;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            v = Vec[i][j];
            strd.setNum(v);
            QLabel* lab = new QLabel(this);
            lab->setStyleSheet("background-color: rgb(255, 253, 208)");
            lab->setText(strd);
            ui->gridLayout_4->addWidget(lab, i, j);
        }}
}

void MainWindow::get_plus(int r, int c){
    double v;
    QString strd;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            v = Vec[i][j];
            strd.setNum(v);
            QLabel* lab = new QLabel(this);
            lab->setStyleSheet("background-color: rgb(255, 253, 208)");
            lab->setText(strd);
            ui->gridLayout_4->addWidget(lab, i, j);
        }}
}

void MainWindow::get_minus(int r, int c){
    double v;
    QString strd;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            v = Vec[i][j];
            strd.setNum(v);
            QLabel* lab = new QLabel(this);
            lab->setStyleSheet("background-color: rgb(255, 253, 208)");
            lab->setText(strd);
            ui->gridLayout_4->addWidget(lab, i, j);
        }}
}

void MainWindow::get_mult(int r, int c1){
    double v;
    QString strd;
    for (int i=0; i<r; i++){
        for (int j=0; j<c1; j++){
            v = Vec[i][j];
            strd.setNum(v);
            QLabel* lab = new QLabel(this);
            lab->setStyleSheet("background-color: rgb(255, 253, 208)");
            lab->setText(strd);
            ui->gridLayout_4->addWidget(lab, i, j);
        }}
}


void MainWindow::matrix_A(int c, int r)
{
    for(int i = 0;  i<r; i++){
        for(int j=0; j<c; j++){

            QLineEdit *el = new QLineEdit(this);
            el->setStyleSheet("background-color: rgb(255, 253, 208)");
            ui->gridL->addWidget(el, j, i);
        }
    }
}

void MainWindow::matrix_B(int c1, int r1)
{
    for(int i = 0;i<r1; i++){
        for(int j=0; j<c1; j++){
            QLineEdit *el = new QLineEdit(this);
            el->setStyleSheet("background-color: rgb(255, 253, 208)");
            ui->gridL_2->addWidget(el, j, i);
        }
    }
}

void MainWindow::clear_matrix_A(int r, int c){
    for(int i = 0;i<r; i++){
        for(int j=0; j<c; j++){
            delete ui->gridL->itemAtPosition(i,j)->widget();

        }
    }
}

void MainWindow::clear_matrix_B(int r1, int c1){
    for(int i = 0;i<r1; i++){
        for(int j=0; j<c1; j++){

            delete ui->gridL_2->itemAtPosition(i,j)->widget();

        }
    }
}

void MainWindow::matrix_clearing1(int r,int c){


    for(int i = 0;i<c; i++){
        for(int j=0; j<r; j++){

            delete ui->gridLayout_4->itemAtPosition(i,j)->widget();

        }
    }
}
void MainWindow::matrix_clearing(int r,int c){


    for(int i = 0;i<r; i++){
        for(int j=0; j<c; j++){

            delete ui->gridLayout_4->itemAtPosition(i,j)->widget();

        }
    }
}

void MainWindow::matrix_clearing_0(){
    delete ui->gridLayout_4->itemAtPosition(0,0)->widget();
}

void MainWindow::matrix_clearing_2(int r){
    int c1;
    bool ok = true;
    QString strb=ui->Col2->text();
    c1=strb.toDouble(&ok);
    for (int i=0; i<r; i++){
        for (int j=0; j<c1; j++){
            delete ui->gridLayout_4->itemAtPosition(i,j)->widget();
        }
        }
}


void MainWindow::get_A(int r, int c){
    bool oke=true;
    double per;
    for(int i = 0;i<r; i++){
        for(int j=0; j<c; j++){
            QLayoutItem *child = ui->gridL->itemAtPosition(i,j);
            QLineEdit* le = static_cast<QLineEdit*>(child->widget());
            QString ss=le->text();
            per=ss.toDouble(&oke);
            VecA[i][j] = per;
        }
    }
}

void MainWindow::get_B(int r1, int c1){
    bool oke=true;
    double pera;
    for(int i = 0;i<r1; i++){
        for(int j=0; j<c1; j++){
            QLayoutItem *child = ui->gridL_2->itemAtPosition(i,j);
            QLineEdit* le = static_cast<QLineEdit*>(child->widget());
            QString ss=le->text();
            pera=ss.toDouble(&oke);
            VecB[i][j] = pera;
        }
    }
}


void MainWindow:: res_0(double& k, int c, int r){
    if (r == c){
        if (r == 2){
            k = VecA.at(0).at(0) 	* 	VecA.at(1).at(1) 	- VecA.at(0).at(1) * VecA.at(1).at(0);
            get_det(k);

        }
        else if (r == 3){
            k = (VecA.at(0).at(0) * VecA.at(1).at(1) * VecA.at(2).at(2)) + (VecA.at(2).at(0) * VecA.at(0).at(1) * VecA.at(1).at(2)) + (VecA.at(1).at(0) * VecA.at(2).at(1) * VecA.at(0).at(2));
            k = k - (VecA.at(2).at(0) * VecA.at(1).at(1) * VecA.at(0).at(2)) - (VecA.at(0).at(0) * VecA.at(2).at(1) * VecA.at(1).at(2)) - (VecA.at(1).at(0) * VecA.at(0).at(1) * VecA.at(2).at(2));
            get_det(k);
        }
        else{QMessageBox::warning(this, "Ошибка!", "");}}
     else{
         QMessageBox::warning(this, "Ошибка!", "");
    }
}


void MainWindow:: res_1(int c, int r){
    for (int i=0; i<ui->gridL->columnCount(); i++){
        for (int j=0; j<ui->gridL->rowCount(); j++){
            Vec[i][j] = VecA[j][i];
        }}
    get_trans(c, r);
}

void MainWindow:: res_2(int c, int r){
    int w;
    double t;
    if (r==c){
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                t = 0;
                w = 0;
                while (w<c){
                    t += VecA[i][w]*VecA[w][j];
                    w++;
                }
                Vec[i][j]=t;
            }}
    get_pow(c, r);}
    else{
        QMessageBox::warning(this, "Ошибка!", "");
    }
}


void MainWindow:: res_00(int r, int c, int r1, int c1){
    if (r==r1 && c==c1){
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                Vec[i][j] = VecA[i][j] + VecB[i][j];
            }}
    get_plus(r,c);}
    else{
        QMessageBox::warning(this, "Ошибка!", "");
    }
}

void MainWindow:: res_01(int r, int c, int r1, int c1){
    if (r==r1 && c==c1){
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                Vec[i][j] = VecA[i][j] - VecB[i][j];
            }}
    get_minus(r,c);}
    else{
        QMessageBox::warning(this, "Ошибка!", "");
    }
}


void MainWindow:: res_02(int r, int c, int r1, int c1){
    int p;
    double z;
    if (c==r1){
        for (int i=0; i<r; i++){
            for (int j=0; j<c1; j++){
                z = 0;
                p = 0;
                while (p<c){
                    z += VecA[i][p]*VecB[p][j];
                    p++;
                }
                Vec[i][j]=z;
            }}
    get_mult(r, c1);}
    else{
        QMessageBox::warning(this, "Ошибка!", "");
    }
}


void MainWindow::Only_matrix(){
    bool ok=true;
    int c, r;
    QString str=ui->Col->text();
    c=str.toDouble(&ok);
    QString str2=ui->Row->text();
    r=str2.toDouble(&ok);
    int val;
    double d;
    val = ui->cb1->currentIndex();
    switch(val){
        case 0:{
            res_0(d, c, r);
            break;
            }
        case 1:{
            res_1(c, r);
            break;}
        case 2:{
            res_2(c, r);
            break;}
         }
}

void MainWindow::Two_matrix(){
    bool ok=true;
    int c, r, c1, r1;
    QString str=ui->Col->text();
    c=str.toDouble(&ok);
    QString str2=ui->Row->text();
    r=str2.toDouble(&ok);
    QString strb=ui->Col2->text();
    c1=strb.toDouble(&ok);
    QString strb2=ui->Row2->text();
    r1=strb2.toDouble(&ok);
    int val;
    val = ui->cb2->currentIndex();
    switch(val){
        case 0:
            res_00(r,c, r1,c1);
            break;
        case 1:
            res_01(r, c,r1,c1);
            break;
        case  2:
            res_02(r, c, r1, c1);
            break;
        }
}



