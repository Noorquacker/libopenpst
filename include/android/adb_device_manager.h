/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file adb.h
* @package openpst/libopenpst
* @brief ADB helper functions definitions
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

namespace OpenPST {
    namespace Android {

        enum AdbCommandType {
            kAdbCommandTypeDefault = 0,
            kAdbCommandTypeShell = 1,
            kAdbCommandTypeRootShell = 2
        };

        struct AdbDevice {
            std::string serial;
            std::string model;
            std::string state;
        };

        struct AdbCommand {
            AdbCommandType type;
            std::string command;
        };



        class AdbDeviceManager {
            public:
                AdbDeviceManager(std::string adbPath);
                ~AdbDeviceManager();

                void startServer();

                void killServer();

                int getDeviceCount();

                std::vector<AdbDevice> getDevices();

                bool installApk(std::string path);

                bool push(std::string src, std::string dest);

                bool pull(std::string src, std::string dest);

                std::string getCurrentWorkingDir();

                void sendCommand(std::string command);
                
                std::list<std::string> sendCommand(AdbCommand command);

                std::vector<std::list<std::string>> sendCommands(std::vector<AdbCommand> commands);

                std::list<std::string> sendCommand(AdbCommand command, AdbDevice device);

                std::vector<std::list<std::string>> sendCommands(std::vector<AdbCommand> commands, AdbDevice device);

        };
    }
}