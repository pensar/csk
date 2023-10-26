// author : Mauricio Gomes
// license: MIT (https://opensource.org/licenses/MIT)

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

        Token& assign (const Token& o) {set_id (o.id ()); set_name (o.get_name ());}

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

 /// Keywords are words that have special meaning to the CSK compiler.
 /// These are reserved words and they cannot be used as identifiers.
 class Keyword: Token
 {
    public:
        Keyword (const Id akeyword_id = NULL_ID, const std::string& skeyword = ""): Token (akeyword_id, skeyword) {}
 };

 /// Identifiers are the names for variables, types, functions, and labels in a CSK program.
 class Identifier: Token
 {
    public:
        Identifier (const Id aidentifier_id = NULL_ID, const std::string& sidentifier = ""): Token (aidentifier_id, sidentifier) {}
 };

 /// A string literal is a sequence of characters enclosed in double quotation marks (" ").
 class StringLiteral: Token
 {
    public:
        StringLiteral (const Id astring_literal_id = NULL_ID, const std::string& astr = ""): Token (astring_literal_id, astr) {}
 };

 /// A constant is a number, character, or character string that can be used as a value in a program and cannot be changed.
 /// \see FloatingPointConstant
 /// \see IntegerConstant
 /// \see ListConstant
 /// \see CharacterConstant
 class Constant: Token
 {
    public:
        Constant (const Id aconstant_id = NULL_ID, const std::string& sconstant = ""): Token (aconstant_id, sconstant) {}
 };

 /// Operators specify an evaluation to be performed on one or more operands.
 class Operator: Token
 {
    public:
        Operator (const Id aoperator_id = NULL_ID, const std::string& soperator = ""): Token (aoperator_id, aoperator_id) {}
 };


 /// Punctuators and special characters are used to
 /// They are:  ( ) [ ] { } * , : ...
 class Punctuator: Token
 {
    public:
        Punctuator (const Id apunctuator_id = NULL_ID, const std::string& spunctuator = ""): Token (apunctuator_id, spunctuator) {}
 };

#endif // TOKEN_HPP

