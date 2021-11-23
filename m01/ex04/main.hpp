#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <fstream>
#include <string>

# define ERROR_VALID_AC "Error: wrong number of arguments (specify a filename and two strings)."
# define ERROR_VALID_AV_EMPTY "Error: empty filename or string (s1 or s2)."
# define ERROR_VALID_AV_FILE_OPEN "Error: the file can't be opened."
# define ERROR_FILE_REPLACE_OPEN "Error: the file FILENAME.replace can't be opened or created."

int	        check_validity_ac(int &ac);
int	        check_validity_av(char** &av, std::ifstream &filename);
int	        check_validity_av_empty_entry(char** &av);
int	        check_validity_av_file(std::ifstream &fin);
void        replace_in_file(char** &av, std::ifstream &fin);
void	    replace_and_write(std::ifstream &fin, std::ofstream &fout, char** &av);
std::string	&replace_one_string(std::string	&fin_str, char* &s1, char* &s2);

#endif
