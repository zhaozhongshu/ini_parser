/******************************************************************
* author: zhaozhongshu@baidu.com
*******************************************************************/
#pragma once
#include <stdio.h>
#include <string>
#include <map>

#ifndef snprintf
#define snprintf _snprintf
#endif

class ini_parser
{
protected:
	ini_parser(const ini_parser &ref);
	const ini_parser& operator=(const ini_parser&);
public:
	ini_parser(const char* path = NULL);
	~ini_parser(void);
	bool load(const char* path = NULL);

	size_t get_int(const char* app, const char* key, size_t default_v)
	{
		char key1[1024];
		snprintf(key1, 1024, "%s#%s", app, key);
		std::map<std::string, std::string>::const_iterator it = pairs.find(key1);
		if( it != pairs.end() )
		{
			return atol(it->second.c_str());
		}
		else
		{
			return default_v;
		}
	}

	std::string& get_str(const char* app, const char* key, const char* default_v, std::string& ret)
	{
		char key1[1024];
		snprintf(key1, 1024, "%s#%s", app, key);
		std::map<std::string, std::string>::const_iterator it = pairs.find(key1);
		if( it != pairs.end() )
		{
			ret = it->second;
		}
		else
		{
			ret = default_v;
		}
		return ret;
	}

	static std::string& read_file_contents(const char* fpath, std::string& buffer)
	{
		FILE* fp = fopen(fpath, "r");
		if( !fp )
		{
			return buffer;
		}
		fseek(fp, 0, SEEK_END);
		size_t bytes = ftell(fp);

		if( bytes == 0 || bytes == -1 )
		{
			fclose(fp);
			return buffer;
		}
		fseek(fp, 0, SEEK_SET);

		buffer.resize(bytes + 1);
		bytes = fread((char*)buffer.c_str(), 1, bytes, fp);
		fclose(fp);
		buffer.resize(bytes);
		return buffer;
	}

	static std::string& str_strip(std::string& str)
	{
		str.erase(0, str.find_first_not_of(" \t\r\n"));
		str.erase(str.find_last_not_of(" \t\r\n") + 1);
		return str;
	}

	void print()
	{
		for (std::map<std::string, std::string>::iterator it = pairs.begin(); it != pairs.end(); it++)
		{
			printf("%s ==> %s\n", it->first.c_str(), it->second.c_str());
		}
	}

protected:
	std::string fpath;
	std::map<std::string, std::string> pairs;
};

