#include "DiscardException.h"
#include "Exception.h"

DiscardException::DiscardException() : Exception::Exception("You have a legal play. You may not discard.") {}
