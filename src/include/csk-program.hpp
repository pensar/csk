#ifndef CSKPROGRAM_HPP
#define CSKPROGRAM_HPP

#include "object.hpp"
#include "name.hpp"
#include <list>
#include <string>

namespace pensar_digital
{
    namespace csk
    {
        using namespace cpplib;

        class RO_Type: public virtual RO_Name
        {

        };
        class Type: public RO_Type
        {
            public:
                Type () {};
                Type (const Type& t) {assign (t);}

                virtual Type& assign (const Type& t) {Object::assign (t); Name::assign (t); return *this;};

                Type& operator = (const Type& t) {return assign(t);}
        };

        class Class: Type
        {
            Class () {};
            Class (const Class& o): Type(o) {};
        };

        class Parameter: Type
        {
            public:
                Parameter() {};
                //Parameter(const Type& atype; std::string aname): type(atype), name(aname) {};
                Parameter(const Parameter& p) {assign (p);};

                virtual Parameter& assign (const Parameter& p) {type = p.type; name = p.name; return *this;};

                Parameter& operator = (const Parameter& p) {return assign (p);};
            private:
                Type type;
                std::string name;
        };

        typedef std::list<Parameter> ParametersList;

        class Method: Object
        {
            Method () {};
            //Method (Type: areturn_type, std::string aname, Parameters: aparams): return_type (areturn_type), name(aname), params(aparams) {};
            Method (const Method& m) {Object::assign (m); assign (m);};

            virtual Method& assign (const Method& m) {Object::assign(m); }
            private:
                Type return_type;
                std::string name;
                ParametersList params;
        };

        typedef std::list<Method> MethodsList;

        class CSKProgram: Object
        {
            public:
                /** Default constructor */
                CSKProgram(): private_methods(), protected_methods(), public_methods() {};

                /** Default destructor */
                virtual ~CSKProgram();
                /** Copy constructor
                 *  \param other Object to copy from
                 */

                CSKProgram(const CSKProgram& other);
                /** Assignment operator
                 *  \param other Object to assign from
                 *  \return A reference to this
                 */

                CSKProgram& operator=(const CSKProgram& other);

            protected:

            private:
                MethodsList private_methods;
                MethodsList protected_methods;
                MethodsList public_methods;
        };
    }
}

#endif // CSKPROGRAM_HPP
