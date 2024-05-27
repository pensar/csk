// author : Mauricio Gomes
// license: MIT (https://opensource.org/licenses/MIT)

#ifndef CSKPROGRAM_HPP
#define CSKPROGRAM_HPP

#include "../cpplib/cpp/s.hpp"
#include "../cpplib/cpp/object.hpp"

#include <list>
#include <string>

namespace pensar_digital
{
    namespace csk
    {
        using namespace pensar_digital::cpplib;

        class Type: public Object
        {
            private:
                S mname;

            public:
                inline static const VersionPtr VERSION = pd::Version::get (1, 1, 1);
                Type (const S& aname = W("")): mname (aname) {};
                static Type NULL_TYPE;
                Type (const Type& t): mname (t) {}
                const S& get_name() const { return mname; }

                void set_name(const S& sname) { mname = sname; }

                Type& assign (const Type& t)
                {
                    set_name (t.get_name());
                    Object::assign (t);
                    return *this;
                }

                Type& operator = (const Type& t) {return assign(t);}

            protected:
                virtual InStream& read (InStream& is)
                {
                    //Name::read (is);
                    is >> mname;
                    switch (VERSION->get_public ())
                    {
                        case 1:;
                    };
                    return is;
                };

                virtual OutStream& write (OutStream& os, const std::endian& byte_order = std::endian::native) const
                {
                    //Name::write(os);
                    os << mname;
                    switch (VERSION->get_public())
                    {
                        case 1:;
                    };
                    return os;
                };
            public:
                InStream&  operator >> (InStream& is)        { return read  (is);}
                OutStream& operator << (OutStream& os) const { return write (os);}
         };

        csk::Type Type::NULL_TYPE = Type ();

        class Class: Type
        {
            public:
                inline static const VersionPtr VERSION = pd::Version::get (1, 1, 1);
                Class () {};
                Class (const Class& o): Type(o) {};

                Class& assign (const Class& c) {set_name (c.get_name()); Object::assign (c); return *this;};

                Class& operator = (const Class& c) {return assign(c);}

            protected:
                virtual InStream& read (InStream& is)
                {
                    Type::read (is);
                    switch (VERSION->get_public())
                    {
                        case 1:;
                    };
                    return is;
                };

                virtual OutStream& write (OutStream& os) const
                {
                    Type::write(os);
                    switch (VERSION->get_public())
                    {
                        case 1:;
                    };
                    return os;
                };

            public:
                InStream& operator >> (InStream& is)       { return read  (is);};
                OutStream& operator << (OutStream& os) const { return write (os);};
        };
        //extern std::istream& operator
        class Parameter: Object
        {
            public:
                Parameter(const Type& atype = Type::NULL_TYPE, S aname = W("")): type(atype), mname(aname) {};
                Parameter(const Parameter& p) {assign (p);};

                virtual Parameter& assign (const Parameter& p) {type = p.type; mname = p.mname; return *this;};

                Parameter& operator = (const Parameter& p) {return assign (p);};
            protected:
                virtual InStream& read (InStream& is)
                {
                    Object::read (is);
                    switch (VERSION->get_public())
                    {
                        default:
                            type.operator >> (is);
                            is >> mname;
                    };
                    return is;
                };

                virtual OutStream& write (OutStream& os) const
                {
                    Object::write (os);

                    switch (VERSION->get_public())
                    {
                        case 1:
                            os << mname;
                            type.operator << (os);
                    };
                    return os;
                };

            public:
                InStream& operator >> (InStream& is)       { return read  (is);};
                OutStream& operator << (OutStream& os) const { return write (os);};
            private:
                Type type;
                S mname;
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
