/* 
 * File:   Data.hpp
 * Author: Hang
 *
 * Created on July 3, 2016, 10:39 AM
 */

#ifndef DATA_HPP
#define	DATA_HPP

class Data {
public:
    virtual bool equals(Data other) const; 
    virtual Data clone() const;
};

#endif	/* DATA_HPP */

