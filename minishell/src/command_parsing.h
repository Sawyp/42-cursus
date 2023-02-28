/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:39:01 by aronez            #+#    #+#             */
/*   Updated: 2022/12/07 17:39:01 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PARSING_H
# define COMMAND_PARSING_H

# include "parsed_command.h"

# include "command_parsing/command_line_sections.h"
# include "variable_registry.h"

/**
 * Takes in the program arguments and wraps them all except the first in
 * structures set with a single quote quoting mode. The strings are duped so
 * that they can be freed later. The array of structures returned contains these
 * structure spaced by single unquoted spaces. If there is only one program
 * argument, no spacing structure is added.
 * @brief Dupes, single-quotes and spaces with unquoted space characters the
 * program arguments.
 * @param argv The program argument strings.
 * @param argc The number of program argument strings.
 * @return An array of alternating quoted program arguments and spaces.
 */
t_command_line_section_list	quote_argv(char **argv, size_t argc);
/**
 * Takes in what's expected to be a command line. Breaks it into structures
 * based on the quotes surrounding each subsequence of characters. Inner quotes
 * are preserved as is. If the command line has an unclosed quote, behaves as if
 * that quoted subsequence was closed.
 * @brief Extracts from the given sequence a list of quoted subsequences.
 * @param command_line A sequence of characters to split.
 * @return An array of sequences associated with their original quoting.
 */
t_command_line_section_list	quote_command_line(const char *command_line);

/**
 * Takes in a list of quoted command line subsequences. Interprets unquoted
 * control characters to generate a list of elements which contain the various
 * elements that make up commands in textual form. If a syntax element is
 * malformed, returns -1.
 * @brief Parses the control characters and associated strings in a command line
 * into a list of commands.
 * @param section_list A list of quoted sections of a command line.
 * @param previous_return_code The return code of the last executed command.
 * @param parsed_commands The resulting sequence of commands to try to execute.
 * @return 0 if the parsing succeeded, -1 otherwise.
 */
int							parse_quoted_command_line(
								t_command_line_section_list section_list,
								int previous_return_code,
								const t_variable_registry *variable_registry,
								t_parsed_commands *parsed_commands
								);

#endif //COMMAND_PARSING_H
