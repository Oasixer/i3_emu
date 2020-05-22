#pragma once
#include <string>
#include <utility>

#include "str_utils.h"
#include "framework.h"
#include "pch.h"

namespace utils{
  inline std::string getLastErrorStr(){
    // LPTSTR errorText = NULL;
    const DWORD ERROR_TEXT_SIZE = 1024;
    WCHAR errorText[1024];
    auto lastErr = GetLastError();

    FormatMessage(
      // use system message tables to retrieve error text
      FORMAT_MESSAGE_FROM_SYSTEM
      // allocate buffer on local heap for error text
      // |FORMAT_MESSAGE_ALLOCATE_BUFFER
      // Important! will fail otherwise, since we're not 
      // (and CANNOT) pass insertion parameters
      |FORMAT_MESSAGE_IGNORE_INSERTS,  
      NULL,    // unused with FORMAT_MESSAGE_FROM_SYSTEM
      lastErr,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
      errorText,  // output 
      ERROR_TEXT_SIZE, // minimum size for output buffer
      NULL
    );   // arguments - see note 
    std::string errorStr;

    if ( NULL != errorText )
    {
      std::wstring errorWStr(errorText);
      errorStr = wstringToString(errorWStr);
      // release memory allocated by FormatMessage()
      //LocalFree(errorText);
      //errorText = NULL;
    }
    return errorStr;
  }
}
