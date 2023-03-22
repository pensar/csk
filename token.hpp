#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <name.hpp>


class Token : public Name
{
    public:
        /** Default constructor */
        Token(const Id atoken_id = NULL_ID, const std::string& stoken = ""): Object (atoken_id), Name(stoken) {}

        /** Default destructor */
        virtual ~Token() {}

        Token& assign (const Token& o) {set_id (o.get_id ()); set_name (o.get_name ());}

        /** Copy constructor
         *  \param other Object to copy from
         */
        Token(const Token& o) {assign (o);}

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Token& operator=(const Token& o) {return assign (o); }

    private:
        unsigned int64_t line;
        unsigned int64_t column;
 };

 class Keyword: Token
 {
     Keyword (const Id akeyword_id = NULL_ID, const std::string& skeyword = ""): Token (akeyword_id, skeyword) {}
 };

#endif // TOKEN_HPP
