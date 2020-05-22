#pragma once

// #ifndef STR_UTILS_H_
// #define STR_UTILS_H_
#include <string>
#include <locale>
#include <codecvt>

namespace utils{

  inline std::wstring stringToWString(std::string narrow_utf8_source_string){
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    // std::string narrow = converter.to_bytes(wide_utf16_source_string);
    std::wstring wide = converter.from_bytes(narrow_utf8_source_string);
    return wide;
  }

  inline std::string wstringToString(std::wstring string_to_convert){
    //setup converter
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    //use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
    std::string converted_str = converter.to_bytes( string_to_convert );
    return converted_str;
  }
  
  inline std::string replaceChar(std::string str, const char ch1, const char ch2) {
  for (auto i = 0u; i < str.length(); i++) {
    if (str[i] == ch1)
      str[i] = ch2;
  }

  return str;
}
  inline std::string parseNameFromFullExePath(std::string fullExePath){
    std::string s = fullExePath;
    std::string delimiter = "\\"; // TODO: Make sure this actually works
    std::string token = s.substr(s.find_last_of(delimiter)+1);
    std::string trimmedEnding = token.substr(0, token.length() - 4);
    std::string removedSpaces = replaceChar(trimmedEnding, ' ', '_');
    return removedSpaces;
  }
}

//#endif
