#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	const std::string& sentence=argv[1];
	std::cout << "sentence: " << sentence << std::endl;

	std::string search;
	size_t pos;

	search = "printer";
	pos = sentence.find(search);
	if (pos != std::string::npos)
		std::cout << "sentence contains " << search << std::endl;
	else
		std::cout << "sentence does not contains " << search << std::endl;

	search = "scanner";
	pos = sentence.find(search);
	if (pos != std::string::npos)
		std::cout << "sentence contains " << search << std::endl;
	else
		std::cout << "sentence does not contains " << search << std::endl;

	return 0;
}
