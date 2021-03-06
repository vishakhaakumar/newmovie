#ifndef MOVIES_MICROSERVICES_UTILS_H
#define MOVIES_MICROSERVICES_UTILS_H

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "logger.h"

namespace movies{
using json = nlohmann::json;

int load_config_file(const std::string &file_name, json *config_json) {
  std::ifstream json_file;
  json_file.open(file_name);
  if (json_file.is_open()) {
    json_file >> *config_json;
    json_file.close();
    return 0;
  }
  else {
    LOG(error) << "Cannot open service-config.json";
    return -1;
  }
};

} //namespace movies

#endif //MOVIES_MICROSERVICES_UTILS_H
