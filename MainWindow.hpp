#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>


//#include "GifHeaders.hpp"

class QToolButton;
class QBuffer;
namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

private:
	void startGif(QSize size, QString name);
	void addGifLayer(QBuffer &buf);
	void endGif();

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_pushButton_clicked();

private:
	QList<QToolButton *> buttonList;
	Ui::MainWindow *ui;
	std::once_flag started;
	// GifWriter g;
};

#endif // MAINWINDOW_HPP
