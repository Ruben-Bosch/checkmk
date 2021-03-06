// +------------------------------------------------------------------+
// |             ____ _               _        __  __ _  __           |
// |            / ___| |__   ___  ___| | __   |  \/  | |/ /           |
// |           | |   | '_ \ / _ \/ __| |/ /   | |\/| | ' /            |
// |           | |___| | | |  __/ (__|   <    | |  | | . \            |
// |            \____|_| |_|\___|\___|_|\_\___|_|  |_|_|\_\           |
// |                                                                  |
// | Copyright Mathias Kettner 2017             mk@mathias-kettner.de |
// +------------------------------------------------------------------+
//
// This file is part of Check_MK.
// The official homepage is at http://mathias-kettner.de/check_mk.
//
// check_mk is free software;  you can redistribute it and/or modify it
// under the  terms of the  GNU General Public License  as published by
// the Free Software Foundation in version 2.  check_mk is  distributed
// in the hope that it will be useful, but WITHOUT ANY WARRANTY;  with-
// out even the implied warranty of  MERCHANTABILITY  or  FITNESS FOR A
// PARTICULAR PURPOSE. See the  GNU General Public License for more de-
// ails.  You should have  received  a copy of the  GNU  General Public
// License along with GNU Make; see the file  COPYING.  If  not,  write
// to the Free Software Foundation, Inc., 51 Franklin St,  Fifth Floor,
// Boston, MA 02110-1301 USA.

#ifndef SectionPerfcounter_h
#define SectionPerfcounter_h

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "Section.h"

class NameBaseNumberMap {
public:
    NameBaseNumberMap(Logger *logger, const WinApiInterface &winapi)
        : _logger(logger), _winapi(winapi) {}
    NameBaseNumberMap(const NameBaseNumberMap &) = delete;
    NameBaseNumberMap &operator=(const NameBaseNumberMap &) = delete;

    int getCounterBaseNumber(const std::string &counterName);

private:
    // Fill name -> counter ID maps lazily when first needed.
    std::vector<std::unordered_map<std::string, DWORD>> _nameIdMaps;

    Logger *_logger;
    const WinApiInterface &_winapi;
};

class SectionPerfcounter : public Section {
public:
    SectionPerfcounter(const std::string &outputName,
                       const std::string &configName, const Environment &env,
                       NameBaseNumberMap &nameNumberMap, Logger *logger,
                       const WinApiInterface &winapi);

protected:
    virtual bool produceOutputInner(
        std::ostream &out, const std::optional<std::string> &) override;

private:
    time_t _disabled_until{0};
    NameBaseNumberMap &_nameNumberMap;
};

#endif  // SectionPerfcounter_h
