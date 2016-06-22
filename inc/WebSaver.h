/*
 * WebSaver.h
 *
 *  Created on: Jun 21, 2016
 *      Author: developer
 */

#ifndef INC_WEBSAVER_H_
#define INC_WEBSAVER_H_

#include <iostream>
#include <string>
#include <curl/curl.h>

namespace Mitrais
{
	namespace util
	{
		class WebSaver
		{
		public:
			WebSaver();
			WebSaver(std::string url);
			~WebSaver();

			void setUrl(std::string url);
//			static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
			static size_t writeCallback(void *ptr, size_t size, size_t nmemb, FILE *stream);
			int saveWebsite();
			int saveWebsite(std::string url);
		private:
			std::string _url;
		};
	}
}



#endif /* INC_WEBSAVER_H_ */
