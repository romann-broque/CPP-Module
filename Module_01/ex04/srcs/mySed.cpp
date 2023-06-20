/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:36:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 17:24:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mySed.hpp"

static void	replaceAll(
	std::string &line,
	std::string searchPattern,
	std::string replacePattern
	)
{
	size_t	startPos = 0;
	size_t	patternPos = line.find(searchPattern, startPos);

	while (patternPos != std::string::npos)
	{
		line = line.substr(startPos, patternPos) + replacePattern + line.substr(patternPos + searchPattern.length());
		startPos = patternPos + replacePattern.length();
		patternPos = line.find(searchPattern, startPos);
	}
}

void	dupReplace(
	std::ifstream &inputFile,
	std::ofstream &outputFile,
	std::string &searchPattern,
	std::string &replacePattern
	)
{
	std::string	line;

	while (std::getline(inputFile, line))
	{
		(void)searchPattern;
		(void)replacePattern;
		replaceAll(line, searchPattern, replacePattern);
		outputFile << line << std::endl;	
	}
}

int	mySed(
	std::string filename,
	std::string searchPattern,
	std::string replacePattern
	)
{
	std::string		outputFileName = filename + ".replace";
	std::ifstream	inputFile(filename.c_str());
	std::ofstream	outputFile(outputFileName.c_str());

	if (!inputFile.is_open())
		return (EXIT_FAILURE);
	dupReplace(inputFile, outputFile, searchPattern, replacePattern);	
	inputFile.close();
	outputFile.close();
	return (EXIT_SUCCESS);
}