/*
 * WebSaver.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: Ari Suarkadipa
 */

#include "../inc/WebSaver.h"

namespace Mitrais
{
	namespace util
	{
		WebSaver::WebSaver()
		{

		}

		WebSaver::WebSaver(std::string url) :
				_url(url)
		{

		}

		WebSaver::~WebSaver()
		{

		}

		void WebSaver::setUrl(std::string url)
		{
			_url = url;
		}

//		static size_t WebSaver::writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
//		{
//			((std::string*)userp)->append((char*)contents, size * nmemb);
//			return size * nmemb;
//		}

		static size_t writeCallback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
		    size_t written = fwrite(ptr, size, nmemb, stream);
		    return written;
		}

		int WebSaver::saveWebsite()
		{
			CURL *curl;
			CURLcode res;
			std::string readBuffer;

			curl = curl_easy_init();
			if(curl)
			{
				curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
				res = curl_easy_perform(curl);
				curl_easy_cleanup(curl);

				std::cout << readBuffer << std::endl;
			}

//			CURL *curl;
//			FILE *fp;
//			CURLcode res;
////			char *url = _url;
//			char *url = "www.google.com";
//			char outfilename[FILENAME_MAX] = "\home\developer\bbb.txt";
//			curl = curl_easy_init();
//			if (curl) {
//				fp = fopen(outfilename,"wb");
//				curl_easy_setopt(curl, CURLOPT_URL, url);
//				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
//				curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
//				res = curl_easy_perform(curl);
//				/* always cleanup */
//				curl_easy_cleanup(curl);
//				fclose(fp);
//			}

			return 0;
		}

		int WebSaver::saveWebsite(std::string url)
		{
			setUrl(url);

			return saveWebsite();
		}
	}
}



