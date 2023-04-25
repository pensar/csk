// author : Mauricio Gomes
// license: MIT (https://opensource.org/licenses/MIT)

#ifndef CSKPROGRAM_HPP
#define CSKPROGRAM_HPP

#include "../cpplib/name.hpp"
#include "../cpplib/string_def.hpp"
#include <list>
#include <string>

namespace pensar_digital
{
    namespace csk
    {
        using namespace cpplib;

        class Type: public Name
        {
            public:
                const static Version VERSION           = 1;
                const static Version INTERFACE_VERSION = 1;
                Type (const String& aname = ""): Name (aname) {};
                static Type NULL_TYPE;
                Type (const Type& t): Name (t) {}

                Type& assign (const Type& t)
                {
                    Name::assign (t.get_name());
                    Object::assign (t);
                    return *this;
                }

                Type& operator = (const Type& t) {return assign(t);}

            protected:
                virtual std::istream& ReadFromStream (std::istream& is, const Version v)
                {
                    Name::ReadFromStream (is, Name::VERSION);
                    switch (v)
                    {
                        case 1:;
                    };
                    return is;
                };

                virtual std::ostream& WriteToStream (std::ostream& os, const Version v) const
                {
                    Name::WriteToStream (os, Name::VERSION);
                    switch (v)
                    {
                        case 1:;
                    };
                    return os;
                };
            public:
                std::istream& operator >> (std::istream& is)       { return ReadFromStream (is, Type::VERSION);};
                std::ostream& operator << (std::ostream& os) const { return WriteToStream  (os, Type::VERSION);};
         };

        csk::Type Type::NULL_TYPE = Type ();

        class Class: Type
        {
            public:

                const static Version VERSION           = 1;
                const static Version INTERFACE_VERSION = 1;
                Class () {};
                Class (const Class& o): Type(o) {};

                Class& assign (const Class& c) {Name::assign (c.get_name()); Object::assign (c); return *this;};

                Class& operator = (const Class& c) {return assign(c);}

            protected:
                virtual std::istream& ReadFromStream (std::istream& is, const Version v)
                {
                    Type::ReadFromStream (is, Type::VERSION);
                    switch (v)
                    {
                        case 1:;
                    };
                    return is;
                };

                virtual std::ostream& WriteToStream (std::ostream& os, const Version v) const
                {
                    Type::WriteToStream (os, Type::VERSION);
                    switch (v)
                    {
                        case 1:;
                    };
                    return os;
                };

            public:
                std::istream& operator >> (std::istream& is)       { return ReadFromStream (is, Class::VERSION);};
                std::ostream& operator << (std::ostream& os) const { return WriteToStream  (os, Class::VERSION);};
        };
        //extern std::istream& operator
        class Parameter: Object
        {
            public:
                Parameter(const Type& atype = Type::NULL_TYPE, std::string aname = ""): type(atype), name(aname) {};
                Parameter(const Parameter& p) {assign (p);};

                virtual Parameter& assign (const Parameter& p) {type = p.type; name = p.name; return *this;};

                Parameter& operator = (const Parameter& p) {return assign (p);};
            protected:
                virtual std::istream& ReadFromStream (std::istream& is, const Version v)
                {
                    Object::ReadFromStream (is, Object::VERSION);
                    switch (v)
                    {
                        case 1:
                            type.operator >> (is);
                            name.operator >> (is);
                    };
                    return is;
                };

                virtual std::ostream& WriteToStream (std::ostream& os, const Version v) const
                {
                    Object::WriteToStream (os, Object::VERSION);

                    switch (v)
                    {
                        case 1:
                            name.operator << (os);
                            type.operator << (os);
                    };
                    return os;
                };

            public:
                std::istream& operator >> (std::istream& is)       { return ReadFromStream (is, Parameter::VERSION);};
                std::ostream& operator << (std::ostream& os) const { return WriteToStream  (os, Parameter::VERSION);};
            private:
                Type type;
                Name name;
        };

        typedef std::list<Parameter> ParametersList;

        class Method: Object
        {
            Method () {};
            //Method (Type: areturn_type, std::string aname, Parameters: aparams): return_type (areturn_type), name(aname), params(aparams) {};
            Method (const Method& m) { assign (m);};

            Method& assign (const Method& m) {Object::assign (m); return *this;}
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
