#ifndef CURL_EVENTS_H
#define CURL_EVENTS_H

#include <string>
int curl_query(std::string url, std::string &str);
void curl_query_text(std::string url, std::string &str);

#endif // CURL_EVENTS_H
