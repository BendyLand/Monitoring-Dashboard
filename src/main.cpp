/** 
 *  Monitoring Dashboard - A simple custom monitoring dashboard.
 *  Copyright (C) 2024 Ben Landrette
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it may be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see https://www.gnu.org/licenses.
 */

#include <QApplication>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>

QGroupBox* createSection(const QString& title);

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QWidget window;
	window.resize(1280, 720);
	window.setWindowTitle("Monitoring Dashboard");
	QGridLayout* layout = new QGridLayout(&window);
	// Create sections
	layout->addWidget(createSection("CPU Monitoring"), 0, 0);
	layout->addWidget(createSection("Memory Monitoring"), 0, 1);
	layout->addWidget(createSection("Network Monitoring"), 0, 2);
	layout->addWidget(createSection("Storage Monitoring"), 1, 0);
	layout->addWidget(createSection("Device Info"), 1, 2);
	window.setStyleSheet("background-color: grey;");
	window.show();
	return app.exec();
}

QGroupBox* createSection(const QString& title)
{
	QGroupBox* groupBox = new QGroupBox(title);
	QVBoxLayout* layout = new QVBoxLayout(groupBox);
	layout->addWidget(new QLabel("Details here..."));
	layout->addWidget(new QProgressBar());
	return groupBox;
}