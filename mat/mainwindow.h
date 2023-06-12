#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector <QVector <double> > VecA = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    QVector <QVector <double> > VecB = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    QVector <QVector <double> > Vec = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};



private slots:
    void on_rb1();

    void on_rb2();
    void matrix_A(int c, int n1);
    void matrix_B(int c1, int r1);

    void get_det(double& f);
    void get_trans(int c, int r);
    void get_pow(int c, int r);
    void get_plus(int r, int c);
    void get_minus(int r, int c);
    void get_mult(int r, int c1);

    void clear_matrix_A(int r, int c);
    void clear_matrix_B(int r1, int c1);
    void matrix_clearing(int r,int c);
    void matrix_clearing_0();
    void matrix_clearing1(int r,int c);
    void matrix_clearing_2(int r);

    void on_ok();
    void on_clear();
    void get_A(int r, int c);
    void get_B(int r1, int c1);

    void res_0(double& f, int c, int r);
    void res_1(int c, int r);
    void res_2(int c, int r);
    void res_00(int r, int c, int r1, int c1);
    void res_01(int r, int c, int r1, int c1);
    void res_02(int r, int c, int r1, int c1);

    void Only_matrix();
    void Two_matrix();

    void on_push();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
