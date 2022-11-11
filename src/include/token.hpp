#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <object.hpp>


class Token : public Object
{
    public:
        /** Default constructor */
        Token(const int64_t atoken_id, const std::string& stoken): name(stoken) {}

        /** Default destructor */
        virtual ~Token() {}

        /** Copy constructor
         *  \param other Object to copy from
         */
        Token(const Token& o) {token_id = o.token_id; name = o.name;}

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Token& operator=(const Token& o) {token_id = o.token_id; name = o.name; return *this; }

    protected:

    private:
        int64_t token_id;
        std::string name;
};

#endif // TOKEN_HPP
