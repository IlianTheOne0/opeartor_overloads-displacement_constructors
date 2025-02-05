#ifndef PERSON_INTERFACE_H
#define PERSON_INTERFACE_H

template<typename TReturn>
class IPerson
{
public:
	virtual TReturn getName() const = 0;
	virtual void setName(const TReturn& value) = 0;
};

#endif