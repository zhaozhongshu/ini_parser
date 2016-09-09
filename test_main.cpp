#include "ini_parser.h"

int main(int argc, char **argv)
{

	ini_parser parser(argv[1]);
	std::string ret;
	parser.get_str("objects", "ASPNET_APP_OBJECT_009_NAME", "", ret);
	printf("%s\n", ret.c_str());
}