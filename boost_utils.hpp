#pragma once
#include <boost/filesystem.hpp>
#include "rapidjson/document.h"
// #include "rapidjson/writer.h"
// #include "rapidjson/stringbuffer.h"
// #include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

namespace bfs = boost::filesystem;

std::string readFile(const std::string &fileName)
{
  std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

  std::ifstream::pos_type fileSize = ifs.tellg();
  if (fileSize < 0){
    return std::string();
  }

  ifs.seekg(0, std::ios::beg);

  std::vector<char> bytes(fileSize);
  ifs.read(&bytes[0], fileSize);

  return std::string(&bytes[0], fileSize);
}

rapidjson::Document* pathStrToDoc(std::string pathStr){
  auto jsonStr = readFile(pathStr);
  auto jsonCStr = jsonStr.c_str();
  rapidjson::Document d;
  d.Parse(jsonCStr);
  return &d;
}



