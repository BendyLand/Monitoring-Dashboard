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
	Device test2 = Device("test2", Metrics{0, 75, 0, 2});
	Device test3 = Device("test3");
	std::vector<Device> devices = {test, test2, test3};
	DeviceManager manager = DeviceManager(devices);
	manager.printConnectedDevices();
	manager.removeDevice(test2.getId());
	manager.printConnectedDevices();

	return 0;
}
