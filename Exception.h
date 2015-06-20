
#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include<string>

class Exception {
public:

	std::string getMessage() const;
protected:

	Exception(std::string msg);
private:
	std::string msg_;
};

std::ostream& operator<<(std::ostream&, Exception&);

#endif	/* EXCEPTION_H */

