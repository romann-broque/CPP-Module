/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:36:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 19:07:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mySed.hpp"

static void	replaceAll(
	std::string &content,
	std::string searchPattern,
	std::string replacePattern
	)
{
	size_t	startPos = 0;
	size_t	patternPos = content.find(searchPattern, startPos);

	while (patternPos != std::string::npos)
	{
		content = content.substr(0, patternPos)
			+ replacePattern + content.substr(patternPos + searchPattern.length());
		startPos = patternPos + replacePattern.length();
		patternPos = content.find(searchPattern, startPos);
	}
}

void	dupReplace(
	std::ifstream &inputFile,
	std::ofstream &outputFile,
	std::string &searchPattern,
	std::string &replacePattern
	)
{
	std::string	content((std::istreambuf_iterator<char>(inputFile)),
						std::istreambuf_iterator<char>());
	if (searchPattern.length() > 0)
		replaceAll(content, searchPattern, replacePattern);
	outputFile << content;	
}

int	mySed(
	std::string filename,
	std::string searchPattern,
	std::string replacePattern
	)
{
	std::ifstream	inputFile(filename.c_str());

	if (!inputFile)
	{
		std::cerr << "Invalid infile" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string		outputFileName = filename + FILE_EXTENSION;
	std::ofstream	outputFile(outputFileName.c_str(), std::ios::trunc);
	if (!outputFile)
	{
		std::cerr << "Invalid outfile" << std::endl;
		return (EXIT_FAILURE);
	}

	dupReplace(inputFile, outputFile, searchPattern, replacePattern);	
	inputFile.close();
	outputFile.close();
	return (EXIT_SUCCESS);
}