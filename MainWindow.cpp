#include "MainWindow.hpp"
#include <QPixmap>
#include <QBuffer>
#include <mutex>
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
	QFont progListFont("Segoe UI");
	progListFont.setBold(false);
	progListFont.setPixelSize(100);
	setFont(progListFont);
	ui->setupUi(this);

	buttonList << ui->but00;
	buttonList << ui->but01;
	buttonList << ui->but02;
	buttonList << ui->but03;
	buttonList << ui->but04;
	buttonList << ui->but05;
	buttonList << ui->but06;
	buttonList << ui->but07;
	buttonList << ui->but08;
	buttonList << ui->but09;
	buttonList << ui->but10;
	buttonList << ui->but11;
	buttonList << ui->but12;
	buttonList << ui->but13;
	buttonList << ui->but14;
	buttonList << ui->but15;
}

MainWindow::~MainWindow() {
	delete ui;
	// GifEnd(&g);
}

void MainWindow::on_pushButton_clicked() {
	std::call_once(started,
				   [this] { startGif(ui->groupBox->size(), "bwgif.gif"); });


	auto first = rand() % 16;
	auto second = rand() % 16;

	auto t1 = buttonList[first]->text();
	buttonList[first]->setText(buttonList[second]->text());
	buttonList[second]->setText(t1);

	QPixmap pixmap(ui->groupBox->size());

	ui->groupBox->render(&pixmap);

	pixmap.save("test.png");


	QByteArray bytes;
	QBuffer buffer(&bytes);
	buffer.open(QIODevice::WriteOnly);
	pixmap.save(&buffer, "PNG");
}

void MainWindow::startGif(QSize size, QString name) {
	auto width = size.width();
	auto height = size.height();
	unsigned int delay = 100;

	// GifBegin(&g, name.toLocal8Bit(), width, height, delay);
}


void MainWindow::addGifLayer(QBuffer &buf) {
	/*
	GifWriteFrame(&g, black.data(), width, height, delay);

	GifWriteFrame(&g, bmp0.data.data(), width, height, delay);
	GifWriteFrame(&g, bmp1.data.data(), width, height, delay);
	GifWriteFrame(&g, bmp2.data.data(), width, height, delay);
	GifWriteFrame(&g, bmp3.data.data(), width, height, delay);
	GifWriteFrame(&g, bmp4.data.data(), width, height, delay);

	GifWriteFrame(&g, white.data(), width, height, delay);
	*/
}
