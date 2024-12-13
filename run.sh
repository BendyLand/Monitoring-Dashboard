#!/bin/bash

# Full compilation command:
# g++ -std=c++20 \
# -I/Users/benlandrette/Qt/6.8.1/macos/lib/QtWidgets.framework/Headers \
# -I/Users/benlandrette/Qt/6.8.1/macos/lib/QtGui.framework/Headers \
# -I/Users/benlandrette/Qt/6.8.1/macos/lib/QtCore.framework/Headers \
# src/main.cpp \
# -F/Users/benlandrette/Qt/6.8.1/macos/lib \
# -framework QtWidgets -framework QtGui -framework QtCore \
# -o out/main

install_name_tool -add_rpath /Users/benlandrette/Qt/6.8.1/macos/lib out/main
./out/main
