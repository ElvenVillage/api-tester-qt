#include "curl_events.h"

#include <iostream>
#include <string>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int curl_query(std::string url,std::string &answer){
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &answer);
    res = curl_easy_perform(curl);
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE,&response_code);
    if (res == CURLE_OK){
       curl_easy_cleanup(curl);// maybe err
       return (int)response_code;
    }
  }
  return 0;
}
void curl_query_text(std::string url,std::string &answer){
    answer="curl -X GET \""+url+"\"";
}
