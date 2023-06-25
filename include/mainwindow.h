#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer.h>
#include "appinit.h"
#include "appevent.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    AppInit*    appInit;
    AppEvent*   appEvent;
    Ui::MainWindow *ui;
    QTimer*     m_timer = nullptr;
    int         fps = 30;
    void onTimer();

private slots:
    void on_m_btn_open_camera_clicked(bool checked);
    void showFrame(cv::Mat frame);
    void on_m_btn_graypro_clicked(bool checked);
    void on_m_btn_hflip_clicked(bool checked);
    void on_m_btn_Hist_clicked(bool checked);
    void on_m_btn_rgbHist_clicked(bool checked);
    //    void on_m_btn_AWF_clicked(bool checked);
    void on_m_btn_hsvpro_clicked(bool checked);
    void on_m_btn_Bchannel_clicked(bool checked);
    void on_m_btn_binarythre_clicked(bool checked);
    void on_m_btn_binarythre_inv_clicked(bool checked);
    void on_m_btn_thtr_clicked(bool checked);
    void on_m_btn_thtoinv_clicked(bool checked);
    void on_m_btn_thto_clicked(bool checked);
    void on_m_btn_adTh_clicked(bool checked);
    void on_m_btn_Gchannel_clicked(bool checked);
    void on_m_btn_Rchannel_clicked(bool checked);
    void on_m_btn_avblur_clicked(bool checked);
    void on_m_btn_bofil_clicked(bool checked);
    void on_m_btn_gabl_clicked(bool checked);
    void on_m_btn_mebl_clicked(bool checked);
    void on_m_btn_bifi_clicked(bool checked);
    void on_m_btn_2Dfi_clicked(bool checked);

    void readFrame() ;

    //滑动条
    void on_horizontalSlider_binarythre_valueChanged(int value);
    void on_horizontalSlider_binarythre_inv_valueChanged(int value);
    void on_horizontalSlider_thtr_valueChanged(int value);
    void on_horizontalSlider_thtoinv_valueChanged(int value);
    void on_horizontalSlider_thto_valueChanged(int value);
    void on_horizontalSlider_bifi_valueChanged(int value);
    void on_exit_action_triggered();
    void on_pushButton_clicked();
    void on_action_2_triggered();
    void on_action_7_triggered();
};
#endif // MAINWINDOW_H
