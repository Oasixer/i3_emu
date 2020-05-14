#pragma once

#include <string>
#include <locale>
#include <codecvt>

std::string wstringToString(std::wstring string_to_convert){
  //setup converter
  using convert_type = std::codecvt_utf8<wchar_t>;
  std::wstring_convert<convert_type, wchar_t> converter;

  //use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
  std::string converted_str = converter.to_bytes( string_to_convert );
  return converted_str;
}
