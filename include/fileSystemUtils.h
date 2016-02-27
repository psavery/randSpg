/**********************************************************************
  fileSystemUtils.h - File system utilities

  Copyright (C) 2015 - 2016 by Patrick S. Avery

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

 ***********************************************************************/

#ifndef FILE_SYSTEM_UTILS_H
#define FILE_SYSTEM_UTILS_H

#include <iostream>
#include <string>
#include <sys/types.h> // required for stat.h
#include <sys/stat.h>

bool mkDir(std::string path, bool printErrorMessage = false) {
  if (path == ".") return true;
  mode_t nMode = 0733; // UNIX style permissions
  int errNo = 0;
#if defined(_WIN32)
  errNo = _mkdir(path.c_str());
#else
  errNo = mkdir(path.c_str(), nMode);
#endif
  if (errNo != 0) {
    if (printErrorMessage) {
      std::cout << "error in mkDir(): directory could not be made. Error number is: "
                << errNo << "\n";
    }
    return false;
  }
  return true;
}
#endif
