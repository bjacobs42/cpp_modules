/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:34:49 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/15 21:06:46 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

enum levels {
	
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

# define DEBUG_MSG " I love my 1S-brown-short-fur-sick puppy a lot."
# define INFO_MSG " I cannot believe this puppy didn't get enough training.\
\n\t You didn't train it enough! If you did, I wouldn't be asking for more training!"

# define WARNING_MSG " I think my dog deserves more training for free.\
\n\t    It's been pooping all over the place for years while you didn't train it!"

# define ERROR_MSG " That's it, I can't take this anymore! I'm killing this dog."
# define DEFAULT_MSG "[ probably complaining about insignificant dog problems ]"

class Harl {

    private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

    public:
		void	complain(std::string level);
};

#endif
