#include "init.hpp"

void initWindowSettings(QWidget& window)
{
	window.resize(1280, 720);
	window.setWindowTitle("Monitoring Dashboard");
	window.setStyleSheet("background-color: grey;");
}

QGridLayout* initLayout(QWidget& window)
{
	QGridLayout* layout = new QGridLayout(&window);
	layout->addWidget(createSection("CPU Monitoring"), 0, 0);
	layout->addWidget(createSection("Memory Monitoring"), 0, 1);
	layout->addWidget(createSection("Network Monitoring"), 0, 2);
	layout->addWidget(createSection("Storage Monitoring"), 1, 0);
	layout->addWidget(createSection("Device Info"), 1, 2);
	return layout;
}

QGroupBox* createSection(const QString& title)
{
	QGroupBox* groupBox = new QGroupBox(title);
	QVBoxLayout* layout = new QVBoxLayout(groupBox);
	layout->addWidget(new QLabel("Details here..."));
	layout->addWidget(new QProgressBar());
	return groupBox;
}
