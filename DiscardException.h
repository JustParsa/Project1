#ifndef DISCARDEXCEPTION_H
#define	DISCARDEXCEPTION_H

#include "Exception.h"

/**
* Thrown when the given card may not be discarded
*/

class DiscardException : public Exception {
public:
	DiscardException();
};

#endif	/* ILLEGALDISCARDEXCEPTION_H */

