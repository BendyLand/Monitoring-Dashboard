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

#include "init.hpp"
#include "device.hpp"

using std::cout; using std::endl; using std::string;

int main(int argc, char** argv)
{
	// QApplication app(argc, argv);
	// QWidget window;
	// initWindowSettings(window);
	// QGridLayout* layout = initLayout(window);
	// window.show();
	// return app.exec();
	Device test = Device("test");
	cout << "Name: " << test.getName() << endl;
	cout << "Id: " << test.getId() << endl;
	cout << test.getMetrics() << endl;
	test.updateMetric(Metric::CPU, 75.5);
	cout << test.getMetrics() << endl;
	test.resetMetrics();
	cout << test.getMetrics() << endl;

	Device test2 = Device("test2");
	cout << "Name: " << test2.getName() << endl;
	cout << "Id: " << test2.getId() << endl;
	cout << test2.getMetrics() << endl;

	Device test3 = Device("test3");
	cout << "Name: " << test3.getName() << endl;
	cout << "Id: " << test3.getId() << endl;
	cout << test3.getMetrics() << endl;

	return 0;
}
