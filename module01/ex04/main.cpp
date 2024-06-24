/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:26:12 by bjacobs           #+#    #+#             */
/*   Updated: 2023/11/10 19:03:38 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void	putUsage(void) {

	std::cerr << "replace: usage: [filename] [string1] [string2]" << std::endl;
}

static void	putError(std::string name) {

	std::string	errorMessage = "replace: ";

	errorMessage.append(name);
	std::perror(errorMessage.data());
	errorMessage.clear();
}

static void	replaceBuff(std::string& buff, std::string needle, std::string needleReplacement) {

	std::size_t	found;
	std::size_t	strLength[2];

	strLength[0] = needle.length();
	if (!strLength[0])
		return;
	strLength[1] = needleReplacement.length();

	found = buff.find(needle);
	while (found != std::string::npos && found) {

		buff.erase(found, strLength[0]);
		buff.insert(found, needleReplacement);
		found = buff.find(needle, found + strLength[1]);
	}
}

static void fillOutFile(std::ifstream& inFile, std::ofstream& outFile,
		std::string needle, std::string needleReplacement) {

	std::string	buff;

	while (std::getline(inFile, buff))
	{
		replaceBuff(buff, needle, needleReplacement);
		outFile << buff << std::endl;
		buff.clear();
	}
}

int	main(int ac, char **av) {

	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		outFileName;

	if (ac < 4)
		return (putUsage(), EXIT_FAILURE);

	inFile.open(av[1], std::ifstream::in);
	if (!inFile)
		return (putError(av[1]), EXIT_FAILURE);

	outFileName = av[1];
	outFile.open(outFileName.append(".replace"), std::ofstream::out);
	if (!outFile)
		return (putError(av[1]), inFile.close(), EXIT_FAILURE);

	fillOutFile(inFile, outFile, av[2], av[3]);
	inFile.close();
	outFile.close();
	return (EXIT_SUCCESS);
}
